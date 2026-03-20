#!/usr/bin/env bash

set -u

PUSH_SWAP="./push_swap"
CHECKER="./checker"

TOTAL_TESTS="${1:-1000}"
SIZES="${2:-2 3 5 10 20 50 100 200 300 400 500}"
MAX_ABS="${3:-10000}"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

ok_count=0
ko_count=0
perf_ok_count=0
perf_ko_count=0
test_index=0
total_ops=0
total_time_ns=0
total_instructions_printed=0

declare -A size_tests
declare -A size_ops
declare -A size_time_ns
declare -A size_perf_ko
declare -A size_min_ops
declare -A size_max_ops

script_start_ns=$(date +%s%N)

perf_limit() {
	local size="$1"
	if ((size <= 3)); then echo 3; return; fi
	if ((size <= 5)); then echo 12; return; fi
	if ((size <= 10)); then echo 40; return; fi
	if ((size <= 20)); then echo 140; return; fi
	if ((size <= 50)); then echo 350; return; fi
	if ((size <= 100)); then echo 700; return; fi
	if ((size <= 500)); then echo 5500; return; fi
	echo $((size * 15))
}

require_bins() {
	if [[ ! -x "$PUSH_SWAP" ]]; then
		echo -e "${RED}Erreur:${NC} $PUSH_SWAP introuvable ou non exécutable"
		exit 1
	fi
	if [[ ! -x "$CHECKER" ]]; then
		echo -e "${YELLOW}Info:${NC} $CHECKER introuvable. Le script lancera seulement push_swap."
	fi
}

run_one() {
	local input="$1"
	local size="$2"
	local ops op_count status checker_out limit perf_tag
	local start_ns end_ns elapsed_ns elapsed_ms
	local cost_nlogn cost_n2 instructions_printed

	((test_index++))
	start_ns=$(date +%s%N)
	ops="$($PUSH_SWAP $input 2>/dev/null)"
	status=$?
	end_ns=$(date +%s%N)
	elapsed_ns=$((end_ns - start_ns))
	elapsed_ms=$(awk "BEGIN {printf \"%.3f\", $elapsed_ns / 1000000}")

	if [[ $status -ne 0 ]]; then
		echo -e "${RED}[KO]${NC} #$test_index size=$size Exit=$status time=${elapsed_ms}ms | input: $input"
		((ko_count++))
		return
	fi

	op_count=$(echo "$ops" | sed '/^$/d' | wc -l)
	instructions_printed=$op_count
	total_ops=$((total_ops + op_count))
	total_instructions_printed=$((total_instructions_printed + instructions_printed))
	total_time_ns=$((total_time_ns + elapsed_ns))
	size_tests[$size]=$(( ${size_tests[$size]:-0} + 1 ))
	size_ops[$size]=$(( ${size_ops[$size]:-0} + op_count ))
	size_time_ns[$size]=$(( ${size_time_ns[$size]:-0} + elapsed_ns ))
	if [[ -z "${size_min_ops[$size]:-}" || $op_count -lt ${size_min_ops[$size]} ]]; then
		size_min_ops[$size]=$op_count
	fi
	if [[ -z "${size_max_ops[$size]:-}" || $op_count -gt ${size_max_ops[$size]} ]]; then
		size_max_ops[$size]=$op_count
	fi
	cost_nlogn=$(awk "BEGIN {n=$size; if (n<2) n=2; printf \"%.3f\", $op_count/(n*(log(n)/log(2)))}")
	cost_n2=$(awk "BEGIN {n=$size; if (n<1) n=1; printf \"%.6f\", $op_count/(n*n)}")
	limit=$(perf_limit "$size")
	if ((op_count <= limit)); then
		perf_tag="${GREEN}PERF_OK${NC}"
		((perf_ok_count++))
	else
		perf_tag="${RED}PERF_KO${NC}"
		((perf_ko_count++))
		size_perf_ko[$size]=$(( ${size_perf_ko[$size]:-0} + 1 ))
	fi

	if [[ -x "$CHECKER" ]]; then
		checker_out=$(echo "$ops" | $CHECKER $input 2>/dev/null)
		if [[ "$checker_out" == "OK" ]]; then
			echo -e "${GREEN}[OK]${NC} #$test_index size=$size instr=$instructions_printed ops=$op_count/$limit time=${elapsed_ms}ms c_nlogn=$cost_nlogn c_n2=$cost_n2 $perf_tag | input: $input"
			((ok_count++))
		else
			echo -e "${RED}[KO]${NC} #$test_index size=$size checker=$checker_out instr=$instructions_printed ops=$op_count/$limit time=${elapsed_ms}ms c_nlogn=$cost_nlogn c_n2=$cost_n2 $perf_tag | input: $input"
			((ko_count++))
		fi
	else
		echo -e "${GREEN}[RUN]${NC} #$test_index size=$size instr=$instructions_printed ops=$op_count/$limit time=${elapsed_ms}ms c_nlogn=$cost_nlogn c_n2=$cost_n2 $perf_tag | input: $input"
		((ok_count++))
	fi
}

random_unique_list() {
	local n="$1"
	local min max range

	min=$((-MAX_ABS))
	max=$MAX_ABS
	range=$((max - min + 1))
	if ((n > range)); then
		echo "Erreur: impossible de générer $n uniques dans [$min,$max]" >&2
		return 1
	fi
	shuf -i "${min}-${max}" -n "$n" | tr '\n' ' '
}

edge_tests() {
	echo -e "\n${YELLOW}=== Edge tests ===${NC}"
	run_one "2 1" 2
	run_one "3 2 1" 3
	run_one "5 1 4 2 3" 5
	run_one "42" 1
	run_one "0 -1 1" 3
	run_one "2147483647 -2147483648 0" 3

	echo -e "\n${YELLOW}=== Error tests (doivent afficher Error + exit 1) ===${NC}"
	$PUSH_SWAP 1 2 three >/dev/null 2>&1 && echo -e "${RED}[KO]${NC} three accepté" || echo -e "${GREEN}[OK]${NC} non-numérique rejeté"
	$PUSH_SWAP 1 2 1 >/dev/null 2>&1 && echo -e "${RED}[KO]${NC} doublon accepté" || echo -e "${GREEN}[OK]${NC} doublon rejeté"
	$PUSH_SWAP 2147483648 >/dev/null 2>&1 && echo -e "${RED}[KO]${NC} overflow accepté" || echo -e "${GREEN}[OK]${NC} overflow rejeté"
}

mass_tests() {
	local size input

	echo -e "\n${YELLOW}=== Random tests ===${NC}"
	echo -e "${YELLOW}Objectif:${NC} $TOTAL_TESTS tests aléatoires minimum"
	for size in $SIZES; do
		if ((test_index >= TOTAL_TESTS)); then
			break
		fi
		echo -e "\n${YELLOW}-- size=$size --${NC}"
		while ((test_index < TOTAL_TESTS)); do
			if ! input="$(random_unique_list "$size")"; then
				exit 1
			fi
			echo -e "${YELLOW}[INPUT]${NC} size=$size -> $input"
			run_one "$input" "$size"
			if ((test_index % 100 == 0)); then
				break
			fi
		done
	done
	while ((test_index < TOTAL_TESTS)); do
		if ! input="$(random_unique_list "500")"; then
			exit 1
		fi
		echo -e "${YELLOW}[INPUT]${NC} size=500 -> $input"
		run_one "$input" 500
	done
}

summary() {
	local avg_ops avg_ms total_ms elapsed_script_ms
	local s tests ops time_ns min_ops max_ops avg_ops_s avg_ms_s ko_s

	elapsed_script_ms=$(awk "BEGIN {printf \"%.3f\", $(( $(date +%s%N) - script_start_ns ))/1000000}")
	avg_ops=$(awk "BEGIN {if ($test_index==0) print 0; else printf \"%.3f\", $total_ops/$test_index}")
	avg_ms=$(awk "BEGIN {if ($test_index==0) print 0; else printf \"%.3f\", ($total_time_ns/1000000)/$test_index}")
	total_ms=$(awk "BEGIN {printf \"%.3f\", $total_time_ns/1000000}")

	echo -e "\n${YELLOW}=== Summary ===${NC}"
	echo -e "Tests exécutés : ${YELLOW}$test_index${NC}"
	echo -e "OK : ${GREEN}$ok_count${NC}"
	echo -e "KO : ${RED}$ko_count${NC}"
	echo -e "Perf OK : ${GREEN}$perf_ok_count${NC}"
	echo -e "Perf KO : ${RED}$perf_ko_count${NC}"
	echo -e "Ops total : ${YELLOW}$total_ops${NC}"
	echo -e "Instructions affichées (stdout) : ${YELLOW}$total_instructions_printed${NC}"
	echo -e "Ops moyen/test : ${YELLOW}$avg_ops${NC}"
	echo -e "Temps total push_swap : ${YELLOW}${total_ms}ms${NC}"
	echo -e "Temps moyen/test : ${YELLOW}${avg_ms}ms${NC}"
	echo -e "Temps script global : ${YELLOW}${elapsed_script_ms}ms${NC}"

	echo -e "\n${YELLOW}=== Détail par taille ===${NC}"
	for s in $SIZES; do
		tests=${size_tests[$s]:-0}
		if ((tests == 0)); then
			continue
		fi
		ops=${size_ops[$s]:-0}
		time_ns=${size_time_ns[$s]:-0}
		min_ops=${size_min_ops[$s]:-0}
		max_ops=${size_max_ops[$s]:-0}
		ko_s=${size_perf_ko[$s]:-0}
		avg_ops_s=$(awk "BEGIN {printf \"%.3f\", $ops/$tests}")
		avg_ms_s=$(awk "BEGIN {printf \"%.3f\", ($time_ns/1000000)/$tests}")
		echo -e "size=$s tests=$tests avg_ops=$avg_ops_s min_ops=$min_ops max_ops=$max_ops avg_time=${avg_ms_s}ms perf_ko=$ko_s"
	done

	if [[ $ko_count -eq 0 && $perf_ko_count -eq 0 ]]; then
		echo -e "${GREEN}Tous les tests sont passés.${NC}"
		exit 0
	fi
	echo -e "${RED}Des tests ont échoué.${NC}"
	exit 1
}

require_bins
edge_tests
mass_tests
summary
