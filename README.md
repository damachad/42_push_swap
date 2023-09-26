# push_swap :bulb: 

**push_swap** is a program designed to efficiently sort a list of integers in ascending order. This project is a part of the curriculum at 42 School and demonstrates a unique approach to sorting using two stacks and a limited set of operations.

## Introduction :rocket:

When you provide **push_swap** with a list of integers, it organizes them into two stacks, labeled as stack A and stack B. The objective is to sort stack A in ascending order. To achieve this, the program employs a restricted pool of operations that can be performed on these stacks.

### Available Operations :memo:

- **sa (swap a):** Swap the first two elements at the top of stack A. No action is taken if there's only one or zero elements.
- **sb (swap b):** Swap the first two elements at the top of stack B. No action is taken if there's only one or zero elements.
- **ss:** Execute both sa and sb simultaneously.
- **pa (push a):** Move the first element from the top of stack B and place it at the top of stack A. No action is taken if stack B is empty.
- **pb (push b):** Move the first element from the top of stack A and place it at the top of stack B. No action is taken if stack A is empty.
- **ra (rotate a):** Shift all elements in stack A upwards by one position. The first element becomes the last one.
- **rb (rotate b):** Shift all elements in stack B upwards by one position. The first element becomes the last one.
- **rr:** Perform ra and rb simultaneously.
- **rra (reverse rotate a):** Shift all elements in stack A downwards by one position. The last element becomes the first one.
- **rrb (reverse rotate b):** Shift all elements in stack B downwards by one position. The last element becomes the first one.
- **rrr:** Perform rra and rrb simultaneously.

## Objective :white_check_mark:

The main goal of this project is to sort the elements in stack A while minimizing the number of operations required. **push_swap** aims to achieve the most efficient sorting possible using the provided operations.

## How to Use :page_with_curl:

To use **push_swap**, follow these steps:

1. Clone the repository to your local machine.
2. Compile the program using the provided Makefile.
3. Run the program with a list of integers as an argument.

Example:

```shell
$ make
$ ./push_swap 5 2 9 1 5
```
The program will generate a list of operations that can be applied to stack A to sort the input integers.

## Testing :mag:

To verify the correctness and efficiency of your implementation, you can use the checker program provided. The checker will evaluate whether the generated operations correctly sort the input list and ensure that the number of operations used is minimal.

## Acknowledgments :sparkles: 

This project was created as part of the curriculum at 42 School.
