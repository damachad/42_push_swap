/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:52:15 by damachad          #+#    #+#             */
/*   Updated: 2023/08/15 11:00:21 by damachad         ###   ########.fr       */
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
		process_a(rotate, stack_a);
	else if ((*stack_a)->next->val > last->val)
		process_a(rev_rotate, stack_a);
	if ((*stack_a)->val > (*stack_a)->next->val)
		process_a(swap, stack_a);
}
