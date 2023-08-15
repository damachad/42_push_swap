/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:35:59 by damachad          #+#    #+#             */
/*   Updated: 2023/08/10 15:38:08 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(t_stack *stack)
{
	free_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

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
