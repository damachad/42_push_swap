/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:23:33 by damachad          #+#    #+#             */
/*   Updated: 2023/08/16 14:43:56 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **top)
{
	t_stack	*temp;

	temp = (*top)->next;
	(*top)->next = (*top)->next->next;
	temp->next = (*top);
	(*top) = temp;
}

void	rotate(t_stack **top)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *top;
	(*top) = (*top)->next;
	temp->next = NULL;
	last = last_node(*top);
	last->next = temp;
}

void	rev_rotate(t_stack **top)
{
	t_stack	*last;
	t_stack	*second_last;

	last = last_node(*top);
	second_last = second_last_node(*top);
	second_last->next = NULL;
	last->next = *top;
	*top = last;
}

void	push_to(t_stack **top_1, t_stack **top_2, char list)
{
	t_stack	*temp;

	push_new_val(top_2, (*top_1)->val);
	temp = (*top_1);
	*top_1 = (*top_1)->next;
	free(temp);
	write(1, "p", 1);
	write(1, &list, 1);
	write(1, "\n", 1);
}
