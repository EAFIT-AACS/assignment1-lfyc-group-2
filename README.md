# 🚀 DFA Minimization - Assignment 1

## 📌 Student Information
- **Full Name:** Simón Mazo Gómez - Andrés Felipe Vélez Alvarez
- **Class Number:** Monday SI2002-1 (7308)

---

## 🛠️ Development Environment
- **Operating System:** macOS Sonoma 14.7.2
- **Programming Language:** C++ (Compiler: Clang++ 16.00)
- **Tools Used:** Visual Studio Code, GitHub, Git, GitHub Desktop.

---

## 📖 About This Project
This project focuses on **DFA (Deterministic Finite Automaton) minimization** using an optimization technique based on Kozen's algorithm.

The goal is to reduce the number of states in a DFA while maintaining its language recognition capabilities.

---

## 🚀 How to Run the Implementation
### 🔹 Steps to execute the DFA Minimizer
1. **Ensure you have a C++ compiler installed** (Clang++, g++ or Visual Studio).
2. **Clone the repository (optional but recommended)**
   ```bash
   git clone https://github.com/EAFIT-AACS/assignment1-lfyc-group-2
   cd assignment1-lfyc-group-2
   ```
3. **Place the input file named 'file.txt'** in the same directory as the program.
4. **Compile the C++ code**
   ```bash
   g++ -std=c++17 -o Main Main.cpp
   ```
5. **Run the program**
   ```bash
   ./Main
   ```
6. **Ensure that 'file.txt' is formatted correctly** and contains the DFA description.
7. **The program will read the DFA description** from 'file.txt' and output the minimized DFA.

---

## 📝 Input Format
The program reads a file (`file.txt`) that contains multiple DFAs to be minimized. The format is:
```
<number_of_DFAs>
<number_of_states>
<alphabet> (space-separated characters)
<final_states> (space-separated state numbers)
<transition_table> (each row represents a state's transitions for each symbol in order)
```
Example:
```
1
4
a b
1 3
0 1 2
1 0 3
2 3 0
3 2 1
```
---

## 🔬 Algorithm Explanation
The program minimizes a DFA using the **distinguishability table method**. Below is a step-by-step breakdown of how the algorithm works:

### 📌 Step 1: Initialize the Distinguishability Table
- A table is created to store distinguishability information for each pair of states.
- Initially, all state pairs are assumed **equivalent** (marked as `false`).

### 📌 Step 2: Mark Distinguishable State Pairs
- If one state in a pair is **final** and the other is **non-final**, they are marked as **distinguishable** (`true`).

### 📌 Step 3: Refinement Process (Iterative Marking)
- The algorithm refines the table iteratively:
  - For each pair `(p, q)`, check their transitions for all symbols.
  - If the target states `(p', q')` are distinguishable, then `(p, q)` is also marked as distinguishable.
  - This process repeats until no more changes occur.

### 📌 Step 4: Identify Equivalent States
- The remaining **unmarked** state pairs are equivalent.
- These states can be merged, reducing the number of states in the DFA.

### 📌 Step 5: Construct the Minimized DFA
- A new DFA is built by merging equivalent states.
- The transition table is updated to reflect the new state groupings.

### 📌 Step 6: Output the Minimized DFA
- The program prints **equivalent state pairs** that can be merged.
- The minimized DFA is displayed as output.

---

## 📌 Example Output
After running the program, the output displays **equivalent state pairs**:
```
Number of automata to minimize: 1
Equivalent state pairs:
Automaton 1: (0,2) (1,3)
```

These pairs represent states that can be merged to create a smaller, optimized DFA.

---


