#!/usr/bin/env python3

import argparse
import math
import random
import shutil
import subprocess
import sys
import time
from collections import defaultdict

PUSH_SWAP = "./push_swap"
CHECKER = "./checker"

RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[1;33m"
NC = "\033[0m"
SEP = "-" * 110


def perf_limit(size: int) -> int:
    if size <= 3:
        return 3
    if size <= 5:
        return 12
    if size <= 10:
        return 40
    if size <= 20:
        return 140
    if size <= 50:
        return 350
    if size <= 100:
        return 700
    if size <= 500:
        return 5500
    return size * 15


def parse_sizes(raw: str) -> list[int]:
    parts = raw.replace(",", " ").split()
    sizes = [int(x) for x in parts]
    if not sizes:
        raise ValueError("Aucune taille fournie")
    if any(s <= 0 for s in sizes):
        raise ValueError("Toutes les tailles doivent être > 0")
    return sizes


def random_unique_list(n: int, max_abs: int) -> list[int]:
    low = -max_abs
    high = max_abs
    space = high - low + 1
    if n > space:
        raise ValueError(f"Impossible de générer {n} uniques dans [{low}, {high}]")
    return random.sample(range(low, high + 1), n)


def run_cmd(args: list[str], stdin_data: str | None = None) -> subprocess.CompletedProcess:
    return subprocess.run(
        args,
        input=stdin_data,
        capture_output=True,
        text=True,
        check=False,
    )


def print_ko_details(title: str, details: list[str]) -> None:
    print(f"    {RED}↳ {title}{NC}")
    for line in details:
        print(f"      - {line}")


def main() -> int:
    parser = argparse.ArgumentParser(description="Stress/perf tester for push_swap")
    parser.add_argument("tests", nargs="?", type=int, default=1000, help="Nombre de tests random (min conseillé: 1000)")
    parser.add_argument(
        "sizes",
        nargs="?",
        default="2 3 5 10 20 50 100 200 300 400 500",
        help="Tailles, ex: '3 5 100 500'",
    )
    parser.add_argument("max_abs", nargs="?", type=int, default=10000, help="Valeur absolue max pour les nombres random")
    args = parser.parse_args()

    if not shutil.which(PUSH_SWAP) and not (PUSH_SWAP.startswith("./") and shutil.which(PUSH_SWAP[2:])):
        pass
    if not shutil.which(PUSH_SWAP) and not subprocess.run(["test", "-x", PUSH_SWAP]).returncode == 0:
        print(f"{RED}Erreur:{NC} {PUSH_SWAP} introuvable ou non exécutable")
        return 1

    checker_available = subprocess.run(["test", "-x", CHECKER]).returncode == 0
    if not checker_available:
        print(f"{YELLOW}Info:{NC} {CHECKER} introuvable. Vérification checker désactivée.")

    try:
        sizes = parse_sizes(args.sizes)
    except ValueError as exc:
        print(f"{RED}Erreur:{NC} {exc}")
        return 1

    test_index = 0
    ok_count = 0
    ko_count = 0
    perf_ok_count = 0
    perf_ko_count = 0
    total_ops = 0
    total_instr = 0
    total_time_ns = 0

    per_size_tests = defaultdict(int)
    per_size_ops = defaultdict(int)
    per_size_time_ns = defaultdict(int)
    per_size_perf_ko = defaultdict(int)
    per_size_min_ops = {}
    per_size_max_ops = {}

    script_start_ns = time.perf_counter_ns()

    def register_case(input_vals: list[int], size: int) -> None:
        nonlocal test_index, ok_count, ko_count, perf_ok_count, perf_ko_count
        nonlocal total_ops, total_instr, total_time_ns

        input_str = " ".join(map(str, input_vals))
        print(SEP)
        print(f"{YELLOW}[INPUT]{NC} size={size} -> {input_str}")

        test_index += 1
        t0 = time.perf_counter_ns()
        ps = run_cmd([PUSH_SWAP, *map(str, input_vals)])
        t1 = time.perf_counter_ns()
        elapsed_ns = t1 - t0
        elapsed_ms = elapsed_ns / 1_000_000

        if ps.returncode != 0:
            print(f"{RED}[KO]{NC} #{test_index} size={size} Exit={ps.returncode} time={elapsed_ms:.3f}ms | input: {input_str}")
            details = [
                "push_swap a retourné un code non nul.",
                f"exit_code={ps.returncode}",
            ]
            if ps.stderr.strip():
                details.append(f"stderr={ps.stderr.strip()[:200]}")
            if ps.stdout.strip():
                details.append(f"stdout={ps.stdout.strip()[:200]}")
            print_ko_details("Pourquoi ce test a échoué", details)
            ko_count += 1
            return

        ops_lines = [line for line in ps.stdout.splitlines() if line.strip()]
        op_count = len(ops_lines)
        instr_count = op_count
        limit = perf_limit(size)
        c_nlogn = op_count / (max(size, 2) * math.log2(max(size, 2)))
        c_n2 = op_count / (max(size, 1) ** 2)

        total_ops += op_count
        total_instr += instr_count
        total_time_ns += elapsed_ns

        per_size_tests[size] += 1
        per_size_ops[size] += op_count
        per_size_time_ns[size] += elapsed_ns
        per_size_min_ops[size] = min(op_count, per_size_min_ops.get(size, op_count))
        per_size_max_ops[size] = max(op_count, per_size_max_ops.get(size, op_count))

        if op_count <= limit:
            perf_ok_count += 1
            perf_tag = f"{GREEN}PERF_OK{NC}"
        else:
            perf_ko_count += 1
            per_size_perf_ko[size] += 1
            perf_tag = f"{RED}PERF_KO{NC}"

        if checker_available:
            ck = run_cmd([CHECKER, *map(str, input_vals)], stdin_data=ps.stdout)
            checker_out = ck.stdout.strip()
            if checker_out == "OK":
                ok_count += 1
                state = f"{GREEN}[OK]{NC}"
                extra = ""
            else:
                ko_count += 1
                state = f"{RED}[KO]{NC}"
                extra = f" checker={checker_out or 'EMPTY'}"
            print(
                f"{state} #{test_index} size={size} instr={instr_count} ops={op_count}/{limit}"
                f" time={elapsed_ms:.3f}ms c_nlogn={c_nlogn:.3f} c_n2={c_n2:.6f} {perf_tag}{extra} | input: {input_str}"
            )
            if checker_out != "OK":
                details = [
                    "checker n'a pas validé la séquence d'instructions.",
                    f"checker_stdout={checker_out or 'EMPTY'}",
                    f"checker_exit_code={ck.returncode}",
                ]
                if ck.stderr.strip():
                    details.append(f"checker_stderr={ck.stderr.strip()[:200]}")
                print_ko_details("Pourquoi ce test a échoué", details)
            elif op_count > limit:
                print_ko_details(
                    "Pourquoi ce test est PERF_KO",
                    [
                        f"op_count={op_count} > limit={limit}",
                        f"ratio_over_limit={(op_count / limit):.3f}x",
                    ],
                )
        else:
            ok_count += 1
            print(
                f"{GREEN}[RUN]{NC} #{test_index} size={size} instr={instr_count} ops={op_count}/{limit}"
                f" time={elapsed_ms:.3f}ms c_nlogn={c_nlogn:.3f} c_n2={c_n2:.6f} {perf_tag} | input: {input_str}"
            )
            if op_count > limit:
                print_ko_details(
                    "Pourquoi ce test est PERF_KO",
                    [
                        f"op_count={op_count} > limit={limit}",
                        f"ratio_over_limit={(op_count / limit):.3f}x",
                    ],
                )

    print(f"\n{YELLOW}=== Edge tests ==={NC}")
    for edge in ([2, 1], [3, 2, 1], [5, 1, 4, 2, 3], [42], [0, -1, 1], [2147483647, -2147483648, 0]):
        register_case(edge, len(edge))

    print(f"\n{YELLOW}=== Error tests (attendu: Error + exit 1) ==={NC}")
    err_cases = (["1", "2", "three"], ["1", "2", "1"], ["2147483648"])
    for case in err_cases:
        p = run_cmd([PUSH_SWAP, *case])
        if p.returncode != 0:
            print(f"{GREEN}[OK]{NC} rejeté: {' '.join(case)}")
        else:
            print(f"{RED}[KO]{NC} accepté à tort: {' '.join(case)}")
            print_ko_details(
                "Pourquoi ce test a échoué",
                [
                    "Le programme aurait dû retourner Error + exit code non nul.",
                    f"exit_code={p.returncode}",
                    f"stdout={p.stdout.strip()[:200] or 'EMPTY'}",
                    f"stderr={p.stderr.strip()[:200] or 'EMPTY'}",
                ],
            )

    print(f"\n{YELLOW}=== Random tests ==={NC}")
    print(f"{YELLOW}Objectif:{NC} {args.tests} tests random minimum")

    while test_index < args.tests:
        for size in sizes:
            if test_index >= args.tests:
                break
            try:
                vals = random_unique_list(size, args.max_abs)
            except ValueError as exc:
                print(f"{RED}Erreur:{NC} {exc}")
                return 1
            register_case(vals, size)

    total_ms = total_time_ns / 1_000_000
    avg_ops = (total_ops / test_index) if test_index else 0
    avg_ms = (total_ms / test_index) if test_index else 0
    script_elapsed_ms = (time.perf_counter_ns() - script_start_ns) / 1_000_000

    print(f"\n{YELLOW}=== Summary ==={NC}")
    print(f"Tests exécutés : {YELLOW}{test_index}{NC}")
    print(f"OK : {GREEN}{ok_count}{NC}")
    print(f"KO : {RED}{ko_count}{NC}")
    print(f"Perf OK : {GREEN}{perf_ok_count}{NC}")
    print(f"Perf KO : {RED}{perf_ko_count}{NC}")
    print(f"Instructions affichées (stdout) : {YELLOW}{total_instr}{NC}")
    print(f"Ops total : {YELLOW}{total_ops}{NC}")
    print(f"Ops moyen/test : {YELLOW}{avg_ops:.3f}{NC}")
    print(f"Temps total push_swap : {YELLOW}{total_ms:.3f}ms{NC}")
    print(f"Temps moyen/test : {YELLOW}{avg_ms:.3f}ms{NC}")
    print(f"Temps script global : {YELLOW}{script_elapsed_ms:.3f}ms{NC}")

    print(f"\n{YELLOW}=== Détail par taille ==={NC}")
    for s in sizes:
        t = per_size_tests.get(s, 0)
        if t == 0:
            continue
        ops = per_size_ops[s]
        t_ms = per_size_time_ns[s] / 1_000_000
        avg_ops_s = ops / t
        avg_ms_s = t_ms / t
        print(
            f"size={s} tests={t} avg_ops={avg_ops_s:.3f} min_ops={per_size_min_ops[s]}"
            f" max_ops={per_size_max_ops[s]} avg_time={avg_ms_s:.3f}ms perf_ko={per_size_perf_ko.get(s, 0)}"
        )

    if ko_count == 0 and perf_ko_count == 0:
        print(f"{GREEN}Tous les tests sont passés.{NC}")
        return 0

    print(f"{RED}Des tests ont échoué.{NC}")
    return 1


if __name__ == "__main__":
    sys.exit(main())
