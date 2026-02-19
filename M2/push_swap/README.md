*This project has been created as part of the 42 curriculum by
rprasopk.*

# push_swap

## Description

**push_swap** is a project from the 42 curriculum designed to deepen the
understanding of **sorting algorithms**, **data structures**, and
**algorithmic complexity**.

The objective of this project is to sort a stack of integers using a
limited set of operations and to produce the smallest possible number of
moves.

The program receives a list of integers as arguments and outputs the
sequence of operations required to sort them in ascending order.

------------------------------------------------------------------------

## Instructions

Through this project, we learn and practice:

- Working with linked lists (stack implementation)
- Implementing sorting algorithms
- Understanding complexity and optimization
- Handling edge cases and error management
- Writing clean and efficient C code

------------------------------------------------------------------------

## Allowed Operations

The program must sort the stack using only the following operations:

| operation   |  Meaning |
| :----------:|:-------------|
| **sa**      | swap the first 2 elements of stack A |
| **sb**      |  swap the first 2 elements of stack B |
| **ss**      |  sa and sb at the same time |
| **pa**      |  push the first element of B to A |
| **pb**      |  push the first element of A to B |
| **ra**      |  rotate stack A (first element becomes last) |
| **rb**      |  rotate stack B |
| **rr**      |  ra and rb at the same time |
| **rra**     |  reverse rotate stack A (last element becomes first) |
|  **rrb**    |  reverse rotate stack B |
| **rrr**     |  rra and rrb at the same time |

------------------------------------------------------------------------

## Requirements

- Operating System: Linux
- Compiler: `cc`
- Make: GNU Make

------------------------------------------------------------------------

## Compilation

Compile the project using:

    make

Remove object files:

	make clean

Remove all compiled files:

	make fclean

Recompile everything:

	make re

------------------------------------------------------------------------

## Execution

Program usage:

	./push_swap 2 1 3 4

Example output:

	ra
	pb
	rra
	pa

The program outputs the sequence of operations needed to sort the stack.

------------------------------------------------------------------------

## Algorithm Strategy

Depending on the number of argument, different strategies can be used:

- Small inputs (≤ 5 numbers): 
  - brute force solutions
- Medium/Large inputs:
  - Butterfly algorithm

The goal is to minimize the total number of operations.

------------------------------------------------------------------------

## Error Handling

The program must:

- Handle invalid input
- Detect duplicates
- Handle integer overflow
- Exit with `Error` message when needed

------------------------------------------------------------------------

## AI Usage Disclosure

AI tools were used **solely as learning assistance**, specifically for:

- Understanding sorting strategies
- Clarifying algorithm optimization concepts
- Debugging logic errors
- Explaining data structure behavior
- Visualize code execution

------------------------------------------------------------------------
