/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:23:33 by damachad          #+#    #+#             */
/*   Updated: 2023/08/10 17:20:54 by damachad         ###   ########.fr       */
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

void	push_to_b(t_stack **top_a, t_stack **top_b)
{
	t_stack	*temp;

	push_new_data(top_b, (*top_a)->data);
	temp = (*top_a);
	*top_a = (*top_a)->next;
	free(temp);
	ft_printf("pb\n");
}

void	push_to_a(t_stack **top_a, t_stack **top_b)
{
	t_stack	*temp;

	push_new_data(top_a, (*top_b)->data);
	temp = (*top_b);
	*top_b = (*top_b)->next;
	free(temp);
	ft_printf("pa\n");
}
