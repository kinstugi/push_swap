# push_swap

42 school project: sort a stack of integers using a restricted set of stack
operations, in as few moves as possible.

## Status

Work in progress. Implemented so far:

- Argument parsing and validation (`--simple` / `--medium` / `--complex` /
  `--bench` mode flags, plus the numeric arguments)
- Overflow/format validation via round-tripping each argument through
  `ft_atoi` → `ft_itoa`
- Duplicate detection (`has_duplicates`)
- Disorder heuristic (`compute_disorder`) — normalized inversion count in
  `[0, 1]`, used to help pick a sorting strategy
- Rank normalization (`set_ranks`) — maps input values to a dense `0..n-1`
  range
- Doubly linked list stack (`t_dll` / `t_node`) with `create_node`,
  `lst_add_front`, `lst_pop_front`, `lst_rotate`, `lst_clear`
- Stack operation primitives: `px` (push), `rx`/`rrx` (rotate/reverse
  rotate), `sx` (swap)

Not yet implemented:

- The actual sorting algorithms (`sorting_manual.c` for ≤3 elements,
  `sorting_simple_algo.c`, `sorting_medium_algo.c`,
  `sorting_complex_algo.c` — currently stub files)
- Printing operation names (`pa`, `pb`, `sa`, `ra`, ...) to stdout as they
  execute
- The `checker` bonus program

## Build

```sh
make        # build push_swap
make re     # rebuild from scratch
make clean  # remove object files
make fclean # remove object files and the binary
make debug  # rebuild with -g
```

## Usage

```sh
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
```

Numbers must be valid, non-duplicate integers within `int` range. Input is
capped at 600 numbers. On invalid input, the program prints `Error` and
exits with status 1.

## Layout

| File                     | Purpose                                        |
|--------------------------|-------------------------------------------------|
| `main.c`                 | Entry point, input parsing, orchestration       |
| `helper_funcs_1.c`       | `ft_strcmp`, `ft_atoi`, `ft_itoa`, `ft_strlen`   |
| `helper_funcs_2.c`       | Duplicate check, rank normalization, `ft_putstr`|
| `helper_funcs_3.c`       | Stack operation primitives (`px`, `rx`, `sx`, ...) |
| `helper_funcs_4.c`       | `compute_disorder`, `populate_stack`             |
| `dl_list_utils.c`        | Doubly linked list implementation               |
| `sorting_manual.c`       | Sorting for small stacks (≤3) — stub            |
| `sorting_simple_algo.c`  | Sorting strategy — stub                          |
| `sorting_medium_algo.c`  | Sorting strategy — stub                          |
| `sorting_complex_algo.c` | Sorting strategy — stub                          |
| `push_swap.h`            | Shared types and prototypes                      |
