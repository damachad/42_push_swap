/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:52:15 by damachad          #+#    #+#             */
/*   Updated: 2023/08/14 15:13:16 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(t_stack **stack_a)
{
	t_stack	*last;

	last = (*stack_a)->next->next;
	if (is_sorted(*stack_a))
		return ;
	if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data > last->data)
		process_a(rotate, stack_a);
	else if ((*stack_a)->next->data > last->data)
		process_a(rev_rotate, stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		process_a(swap, stack_a);
}
