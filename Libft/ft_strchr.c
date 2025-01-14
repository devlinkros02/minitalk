/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:40:18 by dkros             #+#    #+#             */
/*   Updated: 2023/11/03 15:30:17 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)(&str[i]));
		i++;
	}
	if ((char)c == str[i])
		return ((char *)(&str[i]));
	else
		return (NULL);
}

// int main(void)
// {
// 	char string[50] = "helloooo";

// 	printf("%p\n%p\n", ft_strchr(string, 'o'), strchr(string, 'o'));
// 	return (0);
// }
