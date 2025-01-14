/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:42:05 by dkros             #+#    #+#             */
/*   Updated: 2024/02/27 14:42:40 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_nl(char *string)
{
	int	i;

	if (!string)
		return (0);
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlenn(char *string)
{
	int	i;

	if (!string)
		return (0);
	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	j = 0;
	if (!s1)
		i = ft_strlenn(s2);
	else
		i = ft_strlenn(s1) + ft_strlenn(s2);
	new = malloc(i + 1);
	if (!new)
		return (free_func(&s1));
	i = 0;
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free_func (&s1);
	return (new);
}

void	*free_func(char	**target)
{
	free(*target);
	*target = NULL;
	return (NULL);
}
