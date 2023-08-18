/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:35:59 by damachad          #+#    #+#             */
/*   Updated: 2023/08/18 13:14:36 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Calls function to free the stack and writes 
// "Error\n" on the standard error

void	error(t_stack *stack)
{
	if (stack)
		free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

// Frees the given stack's memory

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/*

// Prints given stack

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