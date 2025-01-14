/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:29:00 by dkros             #+#    #+#             */
/*   Updated: 2023/11/03 15:56:48 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*source;

	if (src == NULL)
		return (dest);
	dst = dest;
	source = src;
	if (dest > src)
	{
		while (n--)
			((char *)dst)[n] = ((char *)source)[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

// int	main(void)
// {
// 	char	dest[50];

// 	if (dest != ft_memmove(dest, "lorem ipum dolor sit amet", 8))
// 		write(1, "dest's adress was not returned\n", 31);
// 	write(1, dest, 22);
// 	return (0);
// }
