/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:15:06 by damachad          #+#    #+#             */
/*   Updated: 2023/08/08 16:32:30 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_msg(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
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
		error_msg("Arguments not valid");
	if (exist_duplicates(argc - 1, list))
		error_msg("No duplicates allowed");
	ft_printf("List:\n[");
	while (++i < (argc - 1))
		ft_printf("%d, ", list[i]);
	ft_printf("]\n");
	free(list);
	return (0);
}
