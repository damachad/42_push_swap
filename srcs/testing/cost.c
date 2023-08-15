/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 13:55:59 by damachad          #+#    #+#             */
/*   Updated: 2023/08/15 16:15:38 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_cur_position(t_stack **stack)
{
	t_stack			*tmp;
	unsigned int	median;
	unsigned int	i;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(*stack) / 2;
	tmp = *stack;
	while (tmp)
	{
		if (i < median)
			tmp->up_median = true;
		else
			tmp->up_median = false;
		tmp->cur_position = i++;
		tmp = tmp->next;
	}
}

void	set_targets(t_stack **a, t_stack **b)
{
	int		best_match;
	t_stack	*target;
	t_stack	*tmp_a;

	while (*b)
	{
		best_match = INT_MAX;
		tmp_a = *a;
		while (tmp_a)
		{
			if (tmp_a->val > (*b)->val && tmp_a->val < best_match)
			{
				best_match = tmp_a->val;
				target = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (best_match == INT_MAX)
			(*b)->target = smallest(*a);
		else
			(*b)->target = target;
		(*b) = (*b)->next;
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

void	calculate_costs(t_stack **a, t_stack **b)
{
	set_cur_position(a);
	set_cur_position(b);
	set_targets(a, b);
	set_cost(*a, *b);
}
