/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:56:18 by dkros             #+#    #+#             */
/*   Updated: 2023/11/03 15:00:49 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	*string2;

	i = 0;
	string = (unsigned char *)str;
	string2 = (unsigned char *)str2;
	while (i < n)
	{
		if ((string[i] < string2[i]) || (string[i] > string2[i]))
			return (string[i] - string2[i]);
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	unsigned char string[20] = "hello34";
// 	unsigned char string2[20] = "hello43";

// 	printf("%d\n%d\n", ft_memcmp(string, string2, 0), 
//	memcmp(string, string2, 0));
// 	return (0);
// }
