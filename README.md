*This project has been created as part of the 42 curriculum by sahrandr, mny-aro-*

## Description

`push_swap` sorts a stack of integers using two stacks (`a` and `b`) and only
the allowed operations (`sa`, `pb`, `ra`, etc.).

The objective is to output a valid sequence of instructions that sorts the
input while minimizing the number of operations.

Implemented strategies:
- **Simple**: target complexity `O(n^2)`
- **Medium**: target complexity `O(n * sqrt(n))`
- **Complex**: target complexity `O(n log n)`
- **Adaptive**: automatically selects a strategy from initial disorder.

## Group contribution

### `sahrandr`: The Architect (Tools & Moves)

Responsibilities:
1. **Linked-list structure and foundations**
   - node creation,
   - back/front insertion primitives,
   - stack memory cleanup,
   - list size and low-level utilities.

2. **Stack movements (subject instructions)**
   - `sa`, `sb`, `ss`
   - `pa`, `pb`
   - `ra`, `rb`, `rr`
   - `rra`, `rrb`, `rrr`

3. **Debug support**
   - operation-level checks and pointer behavior validation.

### `mny-aro-`: The Brain (Parsing & Algorithm)

Responsibilities:
1. **Parsing and input validation**
   - numeric validation,
   - `int` range checks (`MIN_INT` / `MAX_INT`),
   - duplicate detection,
   - centralized error handling (`"Error\n"`).

2. **Indexation**
   - value compression from raw values to ordered indices.

3. **Sorting algorithms**
   - sort for 3 numbers,
   - sort for 5 numbers,
   - large sort for 100/500 inputs (chunk/radix-based logic).

### 📅 Team workflow (planning)

**Phase 1 (Week 1)**
- Shared: build `push_swap.h` together (structs + prototypes).
- sahrandr: base list functions and first moves.
- mny-aro-: parsing, error handling, and `main` skeleton.

**Phase 2 (Week 2)**
- sahrandr: finish all move functions.
- mny-aro-: integrate and complete small-sort logic.

**Phase 3 (Week 3)**
-sahrandr: debugging support and utility optimization help.
- mny-aro-: implement and optimize large-sort strategy.

Both learners reviewed and validated all critical code paths together.

## Instructions

### Compilation
- `make`
- `make clean`
- `make fclean`
- `make re`

### Execution
- Default (adaptive):
  - `./push_swap 4 67 3 87 23`
- Force strategy:
  - `./push_swap --simple 4 67 3 87 23`
  - `./push_swap --medium 4 67 3 87 23`
  - `./push_swap --complex 4 67 3 87 23`
  - `./push_swap --adaptive 4 67 3 87 23`
- Benchmark mode:
  - `./push_swap --bench --adaptive 4 67 3 87 23`

### Checker
- Internal checker:
  - `ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG`
- Linux checker:
  - `ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG`

## Algorithm choices and justification

### 1) Simple strategy (`O(n^2)`)
Repeated max extraction with rotations and pushes.
Straightforward implementation, but quadratic in the worst case.

### 2) Medium strategy (`O(n * sqrt(n))`)
Chunk-based approach:
- split index space into chunk intervals,
- push chunk elements from `a` to `b`,
- rebuild `a` from `b` in sorted order.

This generally reduces average rotation overhead.

### 3) Complex strategy (`O(n log n)`)
Binary radix on compressed indices:
- process one bit per pass,
- push/rotate according to bit value,
- merge all back to `a` each pass.

Efficient for larger inputs.

### 4) Adaptive strategy
Selects one of the three strategies from the initial disorder ratio.

Disorder metric:

$$
D = \frac{\text{inversions}}{\binom{n}{2}}\in[0,1]
$$

Policy:
- low disorder → `Simple`
- medium disorder → `Medium`
- high disorder → `Complex`

## Benchmark notes

`--bench` prints to `stderr`:
- disorder percentage,
- selected strategy and complexity class,
- total operation count,
- per-operation counters (`sa`..`rrr`).

## Resources

- 42 subject: Push_swap
- Big-O notation: https://www.geeksforgeeks.org/dsa/analysis-algorithms-big-o-analysis/
- Radix sort reference: https://en.wikipedia.org/wiki/Radix_sort
- Linked lists: https://en.wikipedia.org/wiki/Linked_list

### AI usage

AI assistance was used for:
- validation checklist preparation,
- edge-case review (leaks/tests),
- documentation rewriting.

All integrated changes were manually reviewed, tested, and adjusted by our team.
