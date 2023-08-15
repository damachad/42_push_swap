/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:15:06 by damachad          #+#    #+#             */
/*   Updated: 2023/08/15 10:58:44 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack, char c)
{
	ft_printf("Stack %c:\n", c);
	while (stack)
	{
		ft_printf("%d\n", stack->val);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = check_data(argc - 1, ++argv);
	if (!stack_a)
		error(stack_a);
	print_stack(stack_a, 'A');
	size = stack_size(stack_a);
	ft_printf("Stack A size: %d\n", size);
	if (is_sorted(stack_a))
		ft_printf("Stack is sorted\n");
	else
	{
		ft_printf("Stack is not sorted\n");
		push_swap(&stack_a, &stack_b, size);
	}
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	return (0);
}
