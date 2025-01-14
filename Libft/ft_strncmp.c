/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:11:08 by dkros             #+#    #+#             */
/*   Updated: 2023/11/02 23:50:47 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	*string2;

	string = (unsigned char *)str1;
	string2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	i = 0;
	while ((string[i] || string2[i]) && i < n)
	{
		if (string[i] != string2[i])
			return (string[i] - string2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char s1[50] = "abcdefgh";
// 	char s2[50] = "test\0";

// 	printf("%d\n%d\n", ft_strncmp(s1, s2, 6), strncmp(s1, s2, 6));
// 	return (0);
// }
