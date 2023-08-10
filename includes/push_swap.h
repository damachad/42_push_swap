/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:16:42 by damachad          #+#    #+#             */
/*   Updated: 2023/08/10 16:51:25 by damachad         ###   ########.fr       */
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

/*------------------------operations------------------------*/
void		swap(t_stack **top);
void		rotate(t_stack **top);
void		rev_rotate(t_stack **top);
void		push_to_b(t_stack **top_a, t_stack **top_b);

/*---------------------------stack---------------------------*/
bool		is_sorted(t_stack *stack);
t_stack		*last_node(t_stack *top);
t_stack 	*second_last_node(t_stack *top);

/*---------------------------clean---------------------------*/
void		error(t_stack *stack);
void		free_stack(t_stack *top);

#endif