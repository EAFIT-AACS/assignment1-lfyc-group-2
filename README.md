# DFA Minimization - README

## Student´s Information
- **Full Name:** [Simón Mazo Gómez - Andrés Felipe Vélez Alvarez]
- **Class Number:** [Monday SI2002-1 (7308)]

## Development Environment
- **Operating System:** [macOS Sonoma 14.7.2]
- **Programming Language:** C++, the compiler used was: Clang++ 16.00
- **Tools Used:** Visual Studio, GitHub, Git, GitHub Desktop, and a text editor.

## How to Run the Implementation
```bash
# Ensure you have a C++ compiler installed (Clang++, g++ or Visual Studio)

# Place the input file named 'file.txt' in the same directory as the program

# Run the programm making sure that the ´file.txt´ is running correctly 

# The program will read the DFA description from 'file.txt' and output the minimized DFA
```

## Algorithm Explanation
This implementation performs **DFA minimization** using **state equivalence classes**. The steps are:
1. **Read the input file**: The program reads the number of DFAs, their states, alphabet, final states, and transition tables saving them in differents data structures in order of their characteristics (will see this forward).
2. **Mark non-equivalent states**: If one state is final and the other is not, they are marked as different.
3. **Iterate to refine partitions**: The algorithm checks for state transitions to further mark non-equivalent states.
4. **Find equivalent states**: Remaining unmarked states are equivalent and can be merged.
5. **Print results**: The program outputs the pairs of equivalent states.

The key data structures used are:
- **Vectors** to store the alphabet, final states, and transition table.
- **A 2D boolean matrix** (`marked[i][j]`) to track state equivalence.
- **A loop** to iteratively refine partitions until no further changes occur.

This method efficiently minimizes the DFA by merging equivalent states, reducing the number of states without affecting language recognition.

---

