/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:44:35 by devlinkros        #+#    #+#             */
/*   Updated: 2023/11/02 23:24:48 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (!size)
		return (i);
	while (--size && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (i);
}

// int main(void)
// {
// 	char	dest[50];

// 	printf("%zu\n", strlcpy(dest, "lorem", 15));
//     write(1, "\n", 1);
//     write(1, dest, 15);
// 	return(0);
// }
