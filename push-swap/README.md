# push-swap

**★ Favorite Project** — A sorting algorithm challenge where you have two stacks (A and B) and can only use a limited set of operations. The goal: sort the numbers in stack A using the fewest moves possible.

This implementation uses an **adaptive, pivot-based algorithm** that scales efficiently from 2 to 1100+ elements, with a clean modular structure.

## Operations

| Op | Description |
|----|-------------|
| `sa` | Swap top 2 elements of A |
| `sb` | Swap top 2 elements of B |
| `ss` | `sa` + `sb` |
| `pa` | Push top of B onto A |
| `pb` | Push top of A onto B |
| `ra` | Rotate A (top goes to bottom) |
| `rb` | Rotate B |
| `rr` | `ra` + `rb` |
| `rra` | Reverse rotate A |
| `rrb` | Reverse rotate B |
| `rrr` | `rra` + `rrb` |

## Build & Run

```bash
make
./push_swap 4 2 1 3 5
# Or with a single quoted string:
./push_swap "4 2 1 3 5"
```

To visualize the result (requires a checker program):

```bash
./push_swap 4 2 1 3 5 | ./checker 4 2 1 3 5
```

---

## Algorithm Overview

The algorithm **adapts to stack size**:

| Size | Strategy |
|------|----------|
| 2–8 | **Simple**: Push smallest to B, sort both stacks, merge |
| 9–12 | **Complex** with 1 partition |
| 13–50 | **Complex** with 2 partitions |
| 51–200 | **Complex** with 4 partitions |
| 201–1100 | **Complex** with 8 partitions |
| 1100+ | **Complex** with 20 partitions |

### Preprocessing: Value Simplification

Before sorting, numbers are **normalized to 0..n-1** (`convert_arg_to_stack.c`). This makes pivots and comparisons independent of the actual input range (e.g. `-500, 3, 1000` → `0, 1, 2`).

```c
// calc_simplified_num: for each number, count how many are smaller
// Result: each value becomes its rank in sorted order
```

---

## Simple Algorithm (2–8 elements)

**File:** `algorithm_simple.c`

1. **Split**: Push the smallest k elements to B (k = 0 for size≤4, 3 for size≤6, 4 for size≤8). Use `ra` to bring small values to the top, then `pb`.
2. **Sort A and B**: Use `sort2`, `sort3`, or `sort4` depending on stack size. Stack A is sorted ascending; B is sorted descending.
3. **Merge**: Push all from B back to A with `pa`.

### Small-stack sorting (sort2, sort3, sort4)

- **sort2**: One swap if needed.
- **sort3**: Swap once if unsorted, then `reset_stack` to rotate the sorted triple into the correct position (e.g. `[2,0,1]` → swap → `[0,2,1]` → rotate so 0 is at top).
- **sort4**: Repeatedly find a **swapable** pair (two adjacent values that are out of order and can be fixed with one swap), rotate to bring it to top, swap, then reset. Uses `search_swap` and `are_swapable` to identify beneficial swaps.

**Swapable** means: swapping them improves order. The logic in `are_swapable.c` checks:
- If `a < b` (ascending): they’re already correct, unless they’re the min/max pair wrapping around.
- If `a > b`: they’re swapable only if they’re **immediate** (no value should sit between them in the final order).

---

## Complex Algorithm (9+ elements)

**Files:** `algorithm_complex.c`, `split_num.c`, `execute_moves.c`

### Phase 1: Split (`split_stack`)

Partition A into B using **pivots**:

- `pivot_top = a->size / split + b->size` — upper bound for the current chunk
- `pivot_bot = a->size / (split * 2) + b->size` — mid-point of the chunk

For each element at the top of A:

- If `value < pivot_top` → `pb`. If also `value < pivot_bot` → `rb` (keeps smaller values at bottom of B).
- Else → `ra` (keep in A for the next chunk).

This creates **sorted chunks** in B: smaller values end up lower, larger values higher. More partitions (`split`) = finer chunks = better locality when pushing back.

### Phase 2: Reorder (`reorder`)

Push from B back to A in **descending order** (largest first):

1. Find the current largest (value `i` from `size-1` down to 0) in B.
2. Calculate optimal moves: `calc_moves_by_num` returns positive for `ra`-style, negative for `rra`-style (whichever is shorter).
3. `execute_moves_complex`: While rotating B to bring the target to top, **opportunistically** push from B to A when the top of B is greater than the bottom of A (or when it’s the max). This reduces total moves.
4. `pa` to push the target onto A.
5. If the new top of A is out of order with the next element, `sa` and adjust.
6. **Chunk optimization**: If `a->bot == a->top - 1`, reverse-rotate to bring the next value up without extra pushes.

---

## Code Structure

```
push-swap/
├── push_swap.h          # Stack types, prototypes
├── srcs/
│   ├── main.c           # Entry, init, call push_swap
│   ├── push_swap.c      # Algorithm selection by size
│   ├── convert_arg_to_stack.c  # Parse, validate, simplify
│   ├── init_finish.c    # Stack init/free
│   ├── operation_handler.c    # sa, pa, ra, etc.
│   ├── stack_operations.c     # Low-level stack ops
│   ├── algorithm_simple.c    # 2–8 elements
│   ├── algorithm_complex.c    # 9+ elements
│   └── utils/
│       ├── split_num.c       # Pivot-based push to B
│       ├── calc_moves.c      # Move count for rotate/rra
│       ├── execute_moves.c   # Apply moves (simple + complex)
│       ├── decide_move_flow.c # ra vs rra, rb vs rrb
│       ├── are_swapable.c    # Swap optimization for sort4
│       ├── reset_stack.c     # Rotate sorted stack into place
│       └── ...
└── Libft/               # Dependency
```

### Data Structures

```c
typedef struct s_node {
    int         value;
    t_node      *next;
    t_node      *prev;   // Doubly linked for O(1) bottom access
} t_node;

typedef struct s_stack {
    t_node      *top;    // Head
    t_node      *bot;    // Tail
    int         size;
} t_stack;
```

The doubly-linked list allows O(1) `rra`/`rrb` by moving `bot` to `top`.

---

## Testing

A test script is included in `tests/`:

```bash
./tests/push_swap_test_linux.sh
```

You can also use the official 42 checker or community visualizers to validate and compare move counts.
