/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:56:39 by dkros             #+#    #+#             */
/*   Updated: 2023/11/03 13:20:17 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s;

	i = 0;
	s = str;
	while (i < n)
	{
		if (*(unsigned char *)(str + i) == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	char str[20] = "hello";

// 	printf("%p\n%p\n", ft_memchr(str, 'l', 5), memchr(str, 'l', 5));
// 	return (0);
// }
