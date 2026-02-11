# Recursion and Stack Behavior in C

This project explores the concepts of recursion and stack behavior in the C programming language. It provides examples and explanations of how recursive functions work, their advantages and disadvantages, and the stack memory allocation during their execution.

## Contents
- Introduction to Recursion
- Stack Memory in C
- Examples of Recursive Functions
- Advantages and Disadvantages of Recursion
- Project Files Information

## Introduction to Recursion
Recursion is a programming technique where a function calls itself to solve a problem. It is often used for tasks that can be broken down into smaller, similar sub-tasks.

## Stack Memory in C
When a function is called in C, a new block of memory called a stack frame is allocated on the stack. This frame contains parameters, return addresses, and local variables for that function. When the function returns, the frame is removed from the stack.

## Examples of Recursive Functions
Here are some common examples of recursive functions in C:

1. **Factorial Calculation**  
   A classic example of recursion is calculating the factorial of a number.

   ```c
   int factorial(int n) {
       if (n == 0) {
           return 1;
       }
       return n * factorial(n - 1);
   }
   ```

2. **Fibonacci Sequence**  
   Another example is generating Fibonacci numbers.

   ```c
   int fibonacci(int n) {
       if (n <= 1) {
           return n;
       }
       return fibonacci(n - 1) + fibonacci(n - 2);
   }
   ```

## Advantages and Disadvantages of Recursion
### Advantages:
- Simple and easy to understand.
- Reduces code length and complexity for tasks like tree traversals.

### Disadvantages:
- Can lead to high memory usage due to multiple function calls on the stack.
- Risk of stack overflow if the recursion is too deep.

## Project Files Information
This repository contains the following files:
- `main.c`: The main file that executes the program.
- `functions.c`: Contains the recursive function implementations.
- `functions.h`: Header file for function declarations.

Feel free to explore the code and experiment with different recursive functions!