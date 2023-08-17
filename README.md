# push_swap
This program takes as an argument a list of integers and has to sort if from lowest
to highest. For this, the numbers are put into a stack (first element on top)
and them sorted, using only two stacks (a and b) and a restrict pool of **operations**:   
- sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
- sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
- rrr : rra and rrb at the same time.
