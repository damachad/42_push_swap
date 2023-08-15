/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:16:42 by damachad          #+#    #+#             */
/*   Updated: 2023/08/14 14:56:00 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int					data;
	struct s_stack		*next;
}						t_stack;

/*------------------------validator------------------------*/
t_stack		*check_data(int size, char **nbrs);
bool		valid_format(char *str);
bool		exist_duplicates(t_stack *nbrs);
bool		valid_range(char *str);
long		long_atoi(char *nptr);

/*---------------------------init---------------------------*/
t_stack		*new_node(int data);
void		push_new_data(t_stack **top, int data);
void		push_swap(t_stack **stack_a, t_stack **stack_b, size_t size);

/*------------------------operations------------------------*/
void		swap(t_stack **top);
void		rotate(t_stack **top);
void		rev_rotate(t_stack **top);
void		push_to_b(t_stack **top_a, t_stack **top_b);
void		push_to_a(t_stack **top_a, t_stack **top_b);

/*------------------------operations2------------------------*/
void		ss(t_stack **stack_a, t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

/*-------------------------operator-------------------------*/
void	process_a(void (*operation)(t_stack**), t_stack **stack_a);
void	process_b(void (*operation)(t_stack**), t_stack **stack_b);
void	process_c(void (*op)(t_stack**, t_stack**), t_stack **a, t_stack **b);

/*----------------------------sort----------------------------*/
void	sort_3(t_stack **stack_a);

/*---------------------------stack---------------------------*/
bool		is_sorted(t_stack *stack);
t_stack		*last_node(t_stack *top);
t_stack		*second_last_node(t_stack *top);
size_t		stack_size(t_stack *top);

/*---------------------------clean---------------------------*/
void		error(t_stack *stack);
void		free_stack(t_stack *top);

#endif