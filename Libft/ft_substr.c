/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:26:24 by dkros             #+#    #+#             */
/*   Updated: 2023/11/03 13:53:29 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	c;

	c = 0;
	i = start;
	if (start > ft_strlen(str))
		len = 0;
	if (len > (ft_strlen(str) - i))
		len = (ft_strlen(str) - i);
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (*str && c < len)
	{
		subs[c] = str[i];
		c++;
		i++;
	}
	subs[c] = '\0';
	return (subs);
}

// int main(void)
// {
// 	char str[20] = "uenshelloooo";
// 	char *out = ft_substr(str, 100, 100);
// 	printf("%s", out);
// 	if (out)
// 		free(out);
// 	return (0);
// }
