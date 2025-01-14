/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:35:15 by dkros             #+#    #+#             */
/*   Updated: 2023/11/03 16:05:17 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_char_check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!set || !s1)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_char_check(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	if (start == end)
		return (ft_strdup(""));
	while (end > start && ft_char_check(s1[end - 1], set) == 1)
		end--;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 && end > start)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

// int main(void)
// {
//   char str[20] = "loijebvdlokslkllo";
//   char set[10] = "lo";
//   char *final = ft_strtrim(str, set);
//   printf("%s", final);
//   if (final)
// 	free(final);
//   return (0);
// }
