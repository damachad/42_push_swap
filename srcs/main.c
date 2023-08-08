/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:15:06 by damachad          #+#    #+#             */
/*   Updated: 2023/08/08 14:27:09 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_msg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	*check_data(int size, char **nbrs)
{
	int		*list;
	int		i;
	int		j;
	
	i = -1;
	list = malloc(size + sizeof(int));
	if (!list)
		return (NULL);
	while (++i < size)
	{
		j = -1;
		while (nbrs[i][++j])
		{
			if (!ft_isdigit(nbrs[i][j]))
				return (NULL);
		}	
		list[i] = ft_atoi(nbrs[i]);
	}
	return (list);
}

int	main(int argc, char **argv)
{
	int		*list;
	int		i;

	i = -1;
	if (argc == 1)
		return (0);
	list = check_data(argc - 1, ++argv);
	if (!list)
	{
		error_msg("Arguments not valid\n");
		return (1);
	}
	ft_printf("List:\n[");
	while (++i < (argc - 1))
		ft_printf("%d, ", list[i]);
	ft_printf("]\n");
	free(list);
	return (0);
}
