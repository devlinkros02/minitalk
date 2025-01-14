/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:49:10 by dkros             #+#    #+#             */
/*   Updated: 2023/10/27 19:07:56 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	num;

	c = 1;
	num = 0;
	while (*str && ((str[0] >= 9 && str[0] <= 13) || str[0] == 32))
		str++;
	if ((str[0] == 43 || str[0] == 45) && *str)
	{
		if (str[0] == 45)
			c = -1;
		str++;
	}
	while (str[0] >= '0' && str[0] <= '9' && *str)
	{
		num = num * 10 + (str[0] - '0');
		str++;
	}
	return (num * c);
}

// int main(void)
// {
// 	char str[20] = "-2147483648";

// 	printf("%d\n%d\n", atoi(str), ft_atoi(str));
// 	return (0);
// }
