/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:16:42 by damachad          #+#    #+#             */
/*   Updated: 2023/08/17 12:32:26 by damachad         ###   ########.fr       */
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
	int					val;
	unsigned int		cur_position;
	unsigned int		move_cost;
	bool				up_median;
	bool				cheapest;
	struct s_stack		*target;
	struct s_stack		*next;
}						t_stack;

/*------------------------validator------------------------*/
t_stack		*check_data(int size, char **nbrs);
bool		valid_format(char *str);
bool		exist_duplicates(t_stack *nbrs);
bool		valid_range(char *str);
long		long_atoi(char *nptr);

/*---------------------------init---------------------------*/
t_stack		*new_node(int val);
void		push_new_val(t_stack **top, int val);
void		push_swap(t_stack **stack_a, t_stack **stack_b);
t_stack		*highest(t_stack *stack);

/*------------------------operations------------------------*/
void		swap(t_stack **top);
void		rotate(t_stack **top);
void		rev_rotate(t_stack **top);
void		push_to(t_stack **top_1, t_stack **top_2, char list);

/*------------------------operations2------------------------*/
void		ss(t_stack **stack_a, t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		do_op(void (*operation)(t_stack**), t_stack **stack_a, char list);

/*----------------------------sort----------------------------*/
void		sort_3(t_stack **stack_a);
void		big_sort(t_stack **a, t_stack **b, size_t size);
void		move_nodes(t_stack **a, t_stack **b);
void		move_top(t_stack **a, t_stack **b, t_stack *cheapest, \
			void (*rot)(t_stack**, t_stack**));
void		finish_rot(t_stack **stack, t_stack *top, char list);

/*----------------------------cost----------------------------*/
void		set_cur_position(t_stack *stack);
void		set_targets(t_stack *a, t_stack *b);
void		set_cost(t_stack *a, t_stack *b);
t_stack		*set_cheapest(t_stack *b);
void		calculate_costs(t_stack *a, t_stack *b);

/*---------------------------stack---------------------------*/
bool		is_sorted(t_stack *stack);
t_stack		*last_node(t_stack *top);
t_stack		*second_last_node(t_stack *top);
size_t		stack_size(t_stack *top);
t_stack		*lowest(t_stack *stack);

/*---------------------------clean---------------------------*/
void		error(t_stack *stack);
void		free_stack(t_stack *top);
void		free_split_result(char **words);
//void		print_stack(t_stack *stack, char c);

#endif