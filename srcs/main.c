/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:15:06 by damachad          #+#    #+#             */
/*   Updated: 2023/08/16 18:21:35 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	stack_a = check_data(argc - 1, ++argv);
	if (!stack_a)
		error(stack_a);
	size = stack_size(stack_a);
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b, size);
	free_stack(stack_a);
	return (0);
}

/*
void	print_stack(t_stack *stack, char c)
{
	ft_printf("Stack %c:\n", c);
	while (stack)
	{
		ft_printf("%d\n", stack->val);
		stack = stack->next;
	}
}
*/
