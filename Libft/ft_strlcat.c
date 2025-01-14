/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:29:02 by dkros             #+#    #+#             */
/*   Updated: 2023/11/03 13:35:29 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dest_len;
	size_t		src_len;
	size_t		i;

	if (!dst || !src)
		return (0);
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	if (dest_len >= size)
		return (src_len + size);
	i = 0;
	while (dest_len + i < size - 1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// int main(void)
// {
// 	char dest[50];
// 	char src[6] = "lorem";
//     printf("%zu", ft_strlcat(dest, src, 15));
//     write(1, "\n", 1);
//     write(1, dest, 15);
// }
