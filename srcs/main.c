/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:15:06 by damachad          #+#    #+#             */
/*   Updated: 2023/08/10 15:00:08 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	ft_printf("Stack A:\n");
	while (stack)
	{
		ft_printf("%d\n", stack->data);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		return (0);
	stack_a = check_data(argc - 1, ++argv);
	if (!stack_a)
		error(stack_a);
	print_stack(stack_a);
	if (is_sorted(stack_a))
		ft_printf("Stack is sorted\n");
	else
		ft_printf("Stack is not sorted\n");
	free_stack(stack_a);
	return (0);
}
