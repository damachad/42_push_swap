/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:15:06 by damachad          #+#    #+#             */
/*   Updated: 2023/08/09 11:55:13 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*top_a;
	int		*list;
	int		i;

	i = -1;
	top_a = NULL;
	if (argc == 1)
		return (0);
	list = check_data(argc - 1, ++argv);
	if (!list)
		error_msg("Arguments not valid");
	if (exist_duplicates(argc - 1, list))
		error_msg("No duplicates allowed");
	top_a = fill_stack(list, argc - 1);
	ft_printf("List:\n[");
	while (top_a)
	{
		ft_printf("%d, ", top_a->data);
		top_a = top_a->next;
	}
	ft_printf("]\n");
	free(list);
	free_stack(top_a);
	return (0);
}
