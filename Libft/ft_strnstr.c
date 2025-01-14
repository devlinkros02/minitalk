/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:16:06 by dkros             #+#    #+#             */
/*   Updated: 2023/11/03 16:07:52 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && big[i + j]
			&& little[j] && i + j < len)
			j++;
		if (j == ft_strlen(little))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char big[20] = "1234567890";
// 	char little[20] = "";

// 	printf("%s\n\n", ft_strnstr("lorem fhewu dehuw", "lorem", 15));
// 	return (0);
// }
