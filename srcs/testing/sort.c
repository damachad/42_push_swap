/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:52:15 by damachad          #+#    #+#             */
/*   Updated: 2023/08/16 12:02:35 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack **stack_a)
{
	t_stack	*last;

	last = (*stack_a)->next->next;
	if (is_sorted(*stack_a))
		return ;
	if ((*stack_a)->val > (*stack_a)->next->val && (*stack_a)->val > last->val)
		do_op(rotate, stack_a, 'a');
	else if ((*stack_a)->next->val > last->val)
		do_op(rev_rotate, stack_a, 'a');
	if ((*stack_a)->val > (*stack_a)->next->val)
		do_op(swap, stack_a, 'a');
}

void	big_sort(t_stack **a, t_stack **b, size_t size)
{
	t_stack	*first;

	while (size-- > 3)
		push_to_b(a, b);
	sort_3(a);
	while (*b)
	{
		calculate_costs(a, b);
		move_nodes(a, b);
	}
	set_cur_position(*a);
	first = smallest(*a);
	if (first->up_median)
	{
		while (*a != first)
			do_op(rotate, a, 'a');
	}
	else
	{
		while (*a != first)
			do_op(rev_rotate, a, 'a');
	}
}

void	finish_rot(t_stack **stack, t_stack *top, char list)
{
	while (*stack != top)
	{
		if (top->up_median)
			do_op(rotate, stack, list);
		else
			do_op(rev_rotate, stack, list);
	}
}

void	move_top(t_stack **a, t_stack **b, t_stack *cheapest, \
		void (*rot)(t_stack**, t_stack**))
{
	while (*a != cheapest->target && *b != cheapest)
		rot(a, b);
	set_cur_position(*a);
	set_cur_position(*b);
}

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = set_cheapest(*b);
	if (cheapest_node->up_median && cheapest_node->target->up_median)
		move_top(a, b, cheapest_node, rr);
	else if (!cheapest_node->up_median && !cheapest_node->target->up_median)
		move_top(a, b, cheapest_node, rrr);
	finish_rot(b, cheapest_node, 'b');
	finish_rot(a, cheapest_node->target, 'a');
	push_to_a(a, b);
}
