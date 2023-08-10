/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:23:33 by damachad          #+#    #+#             */
/*   Updated: 2023/08/10 12:24:21 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*new_node(int data, t_stack *top)
{
	t_stack	*new_node;
	
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		error(top);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*push(t_stack **top, int data)
{
	t_stack	*new_top;

	new_top = new_node(data, *top);
	new_top->next = *top;
	*top = new_top;
	return (new_top);
}

t_stack	*fill_stack(int *nbrs, int size)
{
	t_stack	*top;
	int	i;
	
	top = NULL;
	i = size - 1;
	while (i >= 0)
		push(&top, nbrs[i--]);
	return (top);
}
