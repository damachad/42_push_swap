/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:55:59 by damachad          #+#    #+#             */
/*   Updated: 2023/08/16 14:57:49 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Set cur_position to the index in the list and
// set the up_median flag appropriately

void	set_cur_position(t_stack *stack)
{
	unsigned int	median;
	unsigned int	i;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		if (i <= median)
			stack->up_median = true;
		else
			stack->up_median = false;
		stack->cur_position = i++;
		stack = stack->next;
	}
}

void	set_targets(t_stack *a, t_stack *b)
{
	int		best_match;
	t_stack	*target;
	t_stack	*curr_a;

	while (b)
	{
		best_match = INT_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->val > b->val && curr_a->val < best_match)
			{
				best_match = curr_a->val;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match == INT_MAX)
			b->target = smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_cost(t_stack *a, t_stack *b)
{
	size_t	size_a;
	size_t	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		b->move_cost = b->cur_position;
		if (!b->up_median)
			b->move_cost = size_b - b->cur_position;
		if (b->target->up_median)
			b->move_cost += b->target->cur_position;
		else
			b->move_cost += size_a - b->target->cur_position;
		b = b->next;
	}
}

t_stack	*set_cheapest(t_stack *b)
{
	unsigned int	cheapest_move;
	t_stack			*cheapest_node;

	cheapest_move = INT_MAX;
	while (b)
	{
		if (b->move_cost < cheapest_move)
		{
			cheapest_move = b->move_cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
	return (cheapest_node);
}

void	calculate_costs(t_stack *a, t_stack *b)
{
	set_cur_position(a);
	set_cur_position(b);
	set_targets(a, b);
	set_cost(a, b);
}
