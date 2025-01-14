/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:29:01 by dkros             #+#    #+#             */
/*   Updated: 2023/10/31 13:49:10 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	strings;
	int	check;

	strings = 0;
	check = 0;
	while (*s != '\0')
	{
		if (*s != c && check == 0)
		{
			strings++;
			check = 1;
		}
		if (*s == c)
		{
			check = 0;
		}
		s++;
	}
	return (strings);
}

static int	ft_word_length(const char *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

static void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	str = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	i = 0;
	j = 0;
	if (!str || !s)
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		while (s[j] == c)
			j++;
		str[i] = ft_substr(s, j, ft_word_length(s, c, j));
		if (str[i] == NULL)
		{
			ft_free_split(str);
			return (NULL);
		}
		j += ft_word_length(s, c, j);
		i++;
	}
	str[i] = NULL;
	return (str);
}

// int main(void)
// {
// 	char string[20] = "hey hoe gaat het";
// 	char *string1;
// 	char *string2;
// 	char *string3;

// 	string1 = ft_split(string, 32)[1];
// 	string2 = ft_split(string, 32)[2];
// 	string3 = ft_split(string, 32)[3];
// 	printf("%s%s%s", string1, string2, string3);
// 	return (0);
// }
