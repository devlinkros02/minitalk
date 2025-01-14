/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:58:18 by dkros             #+#    #+#             */
/*   Updated: 2023/10/27 19:16:09 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int a, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(str + i) = a;
		i++;
	}
	return (str);
}

// int main(void)
// {
// 	char str[50] = "Hello world!!!20399485";
// 	char str2[50] = "Hello world!!!20399485";

// 	printf("%s\n%s\n", ((char *)ft_memset(str, '*', 9)), 
//	((char *)memset(str2, '*', 9)));
// 	return (0);
// }
