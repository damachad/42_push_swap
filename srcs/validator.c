/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:31:04 by damachad          #+#    #+#             */
/*   Updated: 2023/08/17 11:21:19 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Converts a string to a long

long	long_atoi(char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}

// Checks if all numbers are within the limits for an integer

bool	valid_range(char *str)
{
	int	digits;

	digits = ft_strlen(str);
	if (str[0] == '-' || str[0] == '+')
		digits--;
	if (digits > 10)
		return (false);
	else if (long_atoi(str) > INT_MAX || long_atoi(str) < INT_MIN)
		return (false);
	else
		return (true);
}

// Evaluates if the numbers are on the right format
// by checking if there is only one sign (+/-) and if 
// there are only digits (besides the possible signs)

bool	valid_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (false);
	}
	return (true);
}

// Checks if there are duplicate numbers on the stack

bool	exist_duplicates(t_stack *nbrs)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = nbrs;
	while (temp1->next)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->val == temp2->val)
				return (true);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (false);
}

// Calling function to check if provided list
// of numbers is valid for the program to run

t_stack	*check_data(int size, char **nbrs)
{
	t_stack		*list;
	int			i;

	i = size - 1;
	list = NULL;
	while (i >= 0)
	{
		if (!valid_format(nbrs[i]) || !valid_range(nbrs[i]))
			error(list);
		push_new_val(&list, ft_atoi(nbrs[i--]));
	}
	if (exist_duplicates(list))
		error(list);
	return (list);
}
