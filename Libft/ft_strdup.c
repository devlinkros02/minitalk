/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:27:20 by dkros             #+#    #+#             */
/*   Updated: 2023/10/27 19:17:00 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int main(void)
// {
// 	char str[20] = "helloooo";
// 	char *str2;

// 	str2 = ft_strdup(str);
// 	printf("%s", str2);
// 	free(str2);
// 	return (0);
// }
