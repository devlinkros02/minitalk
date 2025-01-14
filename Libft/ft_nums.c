/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nums.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:26:49 by dkros             #+#    #+#             */
/*   Updated: 2024/04/04 14:44:49 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_di(int di)
{
	int	count;

	count = 0;
	if (di == -2147483648)
	{
		count += ft_print_s("-2147483648");
		return (count);
	}
	if (di < 0)
	{
		di = -di;
		count += ft_print_c('-');
	}
	if (di > 9)
		count += ft_print_di(di / 10);
	count += ft_print_c((di % 10) + '0');
	return (count);
}

int	ft_print_u(unsigned int u)
{
	int	count;

	count = 0;
	if (u > 9)
		count += ft_print_di((u / 10));
	count += ft_print_c((u % 10) + '0');
	return (count);
}
