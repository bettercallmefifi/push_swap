*This project has been created as part of the 42 curriculum by feel-idr.*

---

# 🌀 push_swap

**push_swap** is a sorting algorithm project from the 42/1337 curriculum.
The goal is to sort a list of integers using **two stacks** (`a` and `b`) and a **limited set of operations**, while producing the **smallest number of moves possible**.

---

## 📌 Project Rules

* You start with all numbers in **stack A**
* **Stack B** is empty
* You must sort stack A in **ascending order**
* Only the following operations are allowed:

| Operation     | Description                                  |
| ------------- | -------------------------------------------- |
| `sa` / `sb`   | Swap the first two elements                  |
| `pa` / `pb`   | Push top element from one stack to the other |
| `ra` / `rb`   | Rotate stack up                              |
| `rra` / `rrb` | Reverse rotate stack                         |

---

## ⚙️ How the Program Works

### 1️⃣ Input & Error Handling

The program checks:

* Valid numbers (digits with optional `+` or `-`)
* No overflow (`INT_MIN` → `INT_MAX`)
* No duplicates
* Already sorted input (program exits silently)

Relevant files:

* `check_errors.c`
* `check_acending.c`

---

### 2️⃣ Stack Creation

* Arguments are split (supports `"1 2 3"` format)
* Values are stored in a **linked list**
* Each node contains:

  ```c
  int value;
  int rank;
  ```

Relevant files:

* `ft_split.c`
* `linked_data.c`
* `push_swap.c`

---

## 🧠 Sorting Strategy

### 🔹 Small Inputs

#### 3 numbers → `sort_3`

Optimized logic using:

* swap
* rotate
* reverse rotate

#### 5 numbers → `sort_5`

1. Push the **two smallest numbers** to stack B
2. Sort the remaining 3
3. Push back from B to A

Files:

* `ft_sort.c`

---

### 🔹 Big Inputs ( > 5 numbers )

This project uses a **chunk / range based algorithm**.

---

## 📊 Ranking System

Each value gets a **rank** based on its position in the sorted array.

Example:

```
Input:  42  -5  17
Sorted: -5  17  42
Ranks:   1   2   3
```

Implemented in:

* `position.c`
* `fill_rank()`

---

## 📦 Chunk Algorithm (Core Logic)

### Step 1: Push from A → B (`to_stack_b`)

* Values are pushed in **ranges (chunks)** instead of one by one
* Chunk size depends on input size:

  * `< 500 numbers` → range = **15**
  * `≥ 500 numbers` → range = **35**

Function:

```c
int range(int check, int i, int current_rank);
```

Behavior:

* ✅ Inside range → `pb`
* ⬇️ Smaller than range → `pb` + `rb`
* ⬆️ Bigger → `ra`

This spreads values efficiently in stack B.

---

### Step 2: Push back from B → A (`to_stack_a`)

* Always push the **highest ranked value** from B
* Choose the shortest path:

  * rotate (`rb`)
  * or reverse rotate (`rrb`)

This rebuilds stack A in sorted order.

---

## 🔧 Stack Operations

All allowed operations are implemented manually:

| File            | Purpose                                    |
| --------------- | ------------------------------------------ |
| `actions.c`     | `pa`, `pb`, `ra`, `rb`, `sa`, `rra`, `rrb` |
| `linked_data.c` | Linked list utilities                      |
| `position.c`    | Rank calculations                          |

---

## 🧪 Example

```bash
./push_swap 5 2 8 1 3
```

Output:

```text
pb
ra
pb
sa
pa
pa
```

(Operations may vary depending on the algorithm)

---

## 🛠️ Compilation

```bash
make
```

Clean:

```bash
make clean
make fclean
```

Recompile:

```bash
make re
```

---

## 📁 Project Structure

```
push_swap/
├── actions.c
├── check_acending.c
├── check_errors.c
├── ft_sort.c
├── ft_split.c
├── linked_data.c
├── position.c
├── push_swap.c
├── push_swap.h
├── Makefile
└── README.md
```

---

## ✅ Key Features

* Efficient chunk-based sorting
* Optimized rotations
* Handles large inputs
* Clean memory management
* Fully compliant with 42 rules

---

## 👩‍💻 Author

**feel-idr**
42 / 1337 Student

---
