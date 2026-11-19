# Empirical Analysis of Sorting Algorithms

## Student Information
* **Name:** Majd A H Alzuhri
* **SAP ID:** 71591
* **Course:** Analysis of Algorithms

---

## Overview
This repository contains the C++ source code used for the empirical time complexity analysis of six sorting algorithms[cite: 1, 2, 3]. The program measures the execution time of each algorithm across different input sizes and input arrangements to compare practical performance with theoretical Big-O complexity[cite: 1, 2, 3].

### Algorithms Implemented
1. **Bubble Sort** ($O(n^2)$)[cite: 3]
2. **Selection Sort** ($O(n^2)$)[cite: 3]
3. **Quick Sort** ($O(n \log n)$ average, $O(n^2)$ worst-case)[cite: 3]
4. **Merge Sort** ($O(n \log n)$)[cite: 3]
5. **Radix Sort** ($O(d \cdot (n + k))$)[cite: 3]
6. **Counting Sort** ($O(n + k)$)[cite: 3]

---

## Test Cases & Input Sizes
Each algorithm is tested on four input sizes: **N = 5, 10, 50, and 100**[cite: 1, 3], across three input cases:
* **Case A (Already Sorted):** Elements arranged in ascending order (`1` to `N`)[cite: 1, 3].
* **Case B (Reverse Sorted):** Elements arranged in descending order (`N` down to `1`)[cite: 3].
* **Case C (Random Order):** Elements arranged randomly.

To ensure accurate and consistent measurements, each test is executed **5 times**, and the average execution time is recorded in **microseconds ($\mu s$)** using C++'s `<chrono>` high-resolution clock.

---

## Repository Structure
* `main.cpp` — Complete C++ implementation of all six sorting algorithms and timing benchmarks[cite: 2, 3].
* `README.md` — Project documentation and execution instructions[cite: 2].

---

## How to Compile and Run

### 1. Using Command Line (g++)
Make sure you have a C++ compiler (such as `g++` via MinGW or GCC) installed, then run:

```bash
g++ -O2 main.cpp -o sorting_analysis
./sorting_analysis
