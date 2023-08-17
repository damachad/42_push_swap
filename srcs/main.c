/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <damachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:15:06 by damachad          #+#    #+#             */
/*   Updated: 2023/08/17 12:31:27 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Creates pointers to stack A and B, evaluates if
// number of arguments is valid and calls the
// functions to sort stack A, freeing its memory
// in the end of the program

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**numbers;

	stack_a = NULL;
	stack_b = NULL;
	numbers = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		stack_a = check_data(ft_count_words(argv[1]), numbers);
	}
	else
		stack_a = check_data(argc - 1, ++argv);
	if (!stack_a)
		error(stack_a);
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	if (numbers)
		free_split_result(numbers);
	free_stack(stack_a);
	return (0);
}
