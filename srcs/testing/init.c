/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:35:58 by damachad          #+#    #+#             */
/*   Updated: 2023/08/15 16:17:21 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int val)
{
	t_stack	*new_node;

	new_node = ft_calloc(1, sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->val = val;
	new_node->next = NULL;
	return (new_node);
}

void	push_new_val(t_stack **top, int val)
{
	t_stack	*new_top;

	new_top = new_node(val);
	new_top->next = *top;
	*top = new_top;
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	if (size < 2 || !stack_a)
		return ;
	else if (size == 2)
		do_op(swap, stack_a, 'a');
	else if (size == 3)
		sort_3(stack_a);
	else
		big_sort(stack_a, stack_b, size);
}
