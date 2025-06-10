# 🔄 push_swap – Sorting Data with Limited Operations

This project is part of the 42 curriculum. The goal is to sort a list of integers using only two stacks (`a` and `b`) and a limited set of operations, aiming to minimize the total number of instructions.  

My implementation uses a **radix sort** algorithm adapted for stack operations, offering **stable, safe, and consistent performance**.

---

## 📚 Project Overview

- 📌 Language: C  
- 💡 Authorized: `libft`, `malloc`, `free`, `write`, `read`, `exit`  
- 🚫 Forbidden: Global variables  
- 🔐 All input is validated:
  - Duplicates → return `"Error\n"`
  - Non-integers or overflow → return `"Error\n"`
  - Handles full `INT_MIN` / `INT_MAX` range safely

---

## 🧠 Algorithm

### ✅ **Radix Sort (Binary)**
- Operates on **index-based ranks** (not raw values) to handle negative, large, and sparse input sets correctly.
- Sorts by individual bits from LSB to MSB.
- Time complexity: O(n * log n), space-efficient and well-suited for push_swap constraints.

### 🔒 Stability & Safety
- Protects against:
  - Integer overflows / underflows
  - Duplicate values
  - Invalid characters / empty input

---

## 📊 Performance

Tested using the official benchmarking method via `wc -l`:

| Input size | Operations (avg) |
|------------|------------------|
| 100 nums   | **1084 ops** ✅ |
| 500 nums   | **6784 ops** ✅ |

This meets 42's minimum requirement for project validation and earns a solid score.

---

## ⚙️ Usage

### Compilation

```bash
make
```

## Run example
```bash
./push_swap 3 2 1
sa
rra
```

## Benchmark & Validate
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```

## 🛑 Errors & Edge Cases
```bash
./push_swap 3 2 1 2     # ➜ Error (duplicate)
./push_swap 9999999999  # ➜ Error (overflow)
./push_swap             # ➜ No output
```

## ✅ Project Status
- Input parsing and validation

- Error handling for non-integer and duplicates

- Efficient radix-based sorting

- Performance within required limits

- Fully Norm-compliant and leak-free

## 🖼️ Visualizer (Optional)
This project includes a visualizer to help you see how your push_swap instructions work in real time.

The visualizer is added as a Git submodule in the visualizer/ folder:

```bash
git submodule update --init --recursive
```

## ▶️ How to run
 For Debian-based systems, you can install the necessary packages using the following commands:

```bash
sudo apt-get update
sudo apt-get install cmake
sudo apt-get install g++
sudo apt-get install clang
sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev
sudo apt-get install libx11-dev libxrandr-dev
sudo apt-get install libudev-dev
sudo apt-get install libfreetype-dev
```

- Navigate to the `push_swap_visualizer` directory, create `build` directory, and navigate into the build directory:

```bash
cd push_swap_visualizer
mkdir build
cd build
```

- Generate the build files using CMake and compile the visualizer:

```bash
cmake ..
make
```

- Run the visualizer:

```bash
./bin/visualizer
```

✅ You'll see a graphical representation of the stacks and the operations step by step.

## 🙏 Credits
The visualizer used in this project was not developed by me.
Special thanks to @o-reo for creating the amazing [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer), which helped a lot in testing and debugging.

## ⚠️ Notes
- Make sure push_swap prints only instructions (no extra text).

- The visualizer reads input from stdin, so pipe your program's output directly into it.

- You can explore the visualizer/ folder for additional options or code tweaks.

## 🔚 Conclusion
The push_swap project was a deep dive into data structures, sorting algorithms, and writing optimized, clean C code under real constraints. My radix sort solution offers a great balance between simplicity and performance for mid-sized inputs.

Thanks for reading! 🧠🚀
