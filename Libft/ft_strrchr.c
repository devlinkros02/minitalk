/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:00:57 by dkros             #+#    #+#             */
/*   Updated: 2023/11/03 15:49:43 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)(&str[i]));
		i--;
	}
	return (NULL);
}

// int main(void)
// {
// 	char string[50] = "helloooo";

// 	printf("%p\n%p\n", ft_strrchr(string, '\0'), strrchr(string, '\0'));
// 	return (0);
// }
