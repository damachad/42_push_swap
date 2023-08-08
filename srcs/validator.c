/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:31:04 by damachad          #+#    #+#             */
/*   Updated: 2023/08/08 17:08:34 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

bool	exist_duplicates(int size, int *nbrs)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (nbrs[i] == nbrs[j++])
				return (true);
		}
	}
	return (false);
}

int	*check_data(int size, char **nbrs)
{
	int		*list;
	int		i;

	i = -1;
	list = malloc(size + sizeof(int));
	if (!list)
		return (NULL);
	while (++i < size)
	{
		if (!valid_format(nbrs[i]) || !valid_range(nbrs[i]))
		{
			free(list);
			return (NULL);
		}
		list[i] = ft_atoi(nbrs[i]);
	}
	return (list);
}
