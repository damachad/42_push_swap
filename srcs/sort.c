/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:52:15 by damachad          #+#    #+#             */
/*   Updated: 2023/08/17 11:01:00 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Sorts a stack of 3 elements (lowest to highest)

void	sort_3(t_stack **stack_a)
{
	t_stack	*highest_node;

	highest_node = highest(*stack_a);
	if (*stack_a == highest_node)
		do_op(rotate, stack_a, 'a');
	else if ((*stack_a)->next == highest_node)
		do_op(rev_rotate, stack_a, 'a');
	if ((*stack_a)->val > (*stack_a)->next->val)
		do_op(swap, stack_a, 'a');
}

// Algorithm to sort stack A (lowest to highest)

void	big_sort(t_stack **a, t_stack **b, size_t size)
{
	t_stack	*first;

	while (size-- > 3)
		push_to(a, b, 'b');
	sort_3(a);
	while (*b)
	{
		calculate_costs(*a, *b);
		move_nodes(a, b);
	}
	set_cur_position(*a);
	first = lowest(*a);
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

// Finishes rotating so that the cheapest/target is on top of
// the corresponding stack

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

// Rotates or reverse-rotates both stacks until either the
// cheapest-node is on top in B, or its target is on top in A

void	move_top(t_stack **a, t_stack **b, t_stack *cheapest, \
		void (*rot)(t_stack**, t_stack**))
{
	while (*a != cheapest->target && *b != cheapest)
		rot(a, b);
	set_cur_position(*a);
	set_cur_position(*b);
}

// Operates on each stack so as to sort stack A, moving the nodes 
// according to the associated costs, previously calculated

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
	push_to(b, a, 'a');
}
