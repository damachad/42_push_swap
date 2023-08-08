/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damachad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:35:10 by damachad          #+#    #+#             */
/*   Updated: 2023/04/12 14:35:48 by damachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const str_i, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == str_i)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	beg;
	size_t	end;
	size_t	i;

	i = 0;
	beg = 0;
	end = ft_strlen(s1);
	while (is_set(s1[beg], set) == 1 && s1[beg])
		beg++;
	while (is_set(s1[end - 1], set) == 1 && end > beg)
		end--;
	trim = (char *)malloc((end - beg + 1) * sizeof(char));
	if (!trim)
		return (0);
	while (beg < end)
	{
		trim[i] = s1[beg];
		beg++;
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
