/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:35:59 by damachad          #+#    #+#             */
/*   Updated: 2023/08/17 12:30:06 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_split_result(char **words)
{
	int	i;

	i = -1;
	if (!words)
		return ;
	while (words[++i])
		free(words[i]);
	free(words);
}

// Calls function to free the stack and writes 
// "Error\n" on the standard error

void	error(t_stack *stack)
{
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