/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:06:34 by dkros             #+#    #+#             */
/*   Updated: 2023/11/03 15:27:18 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*u_dest;
	unsigned char	*u_src;

	i = 0;
	u_dest = (unsigned char *)dest;
	u_src = (unsigned char *)src;
	if (!src)
		return (dest);
	if (!dest)
		return (NULL);
	while (i < n)
	{
		u_dest[i] = u_src[i];
		i++;
	}
	return (dest);
}

// int main(void)
// {
// 	const char src[50] = "It worked!!";
// 	char dest[50] = "empty spaceeeeeeeee";
// 	char dest2[50] = "empty spaceeeeeeeee";

// 	ft_memcpy(dest, src, 11);
// 	memcpy(dest2, src, 11);
// 	printf("%s\n%s\n", dest, dest2);
// 	return (0);
// }
