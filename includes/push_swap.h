/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:16:42 by damachad          #+#    #+#             */
/*   Updated: 2023/08/10 14:56:29 by damachad         ###   ########.fr       */
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

/*------------------------operations------------------------*/
t_stack		*new_node(int data);
void		push(t_stack **top, int data);
bool		is_sorted(t_stack *stack);

/*---------------------------clean---------------------------*/
void		error(t_stack *stack);
void		free_stack(t_stack *top);

#endif