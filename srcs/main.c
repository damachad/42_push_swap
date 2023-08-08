/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:15:06 by damachad          #+#    #+#             */
/*   Updated: 2023/08/08 12:58:50 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*check_data(char *str)
{
	int		*list;
	char 	**numbers;
	size_t	i;
	size_t	j;
	
	i = -1;
	list = NULL;
	list = malloc(count_words2(str) * sizeof(int));
	numbers = ft_split(str, ' ');
	if (!numbers)
		return (NULL);
	while (numbers[++i])
	{
		j = -1;
		while (numbers[i][++j])
		{
			if (!ft_isdigit(numbers[i][j]) && (numbers[i][j] != '-' \
			&& numbers[i][j] != '+'))
				return (NULL);
		}
		list[i] = ft_atoi(numbers[i]);
	}
	free(numbers);
	return (list);
}

int	main(int argc, char **argv)
{
	t_stack	*top_a;
	int		*list;
	size_t	i;

	i = -1;
	top_a = NULL;
	if (argc != 2)
	{
		ft_printf("Usage: ./push_swap <list of numbers>");
		return (1);
	}
	list = check_data(argv[1]);
	ft_printf("List:\n[");
	while (++i < 5)
		ft_printf("%d, ", list[i]);
	ft_printf("]\n");
	free(list);
	return (0);
}
