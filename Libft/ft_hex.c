/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:33:30 by dkros             #+#    #+#             */
/*   Updated: 2024/04/04 14:44:37 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_x(unsigned long num, char c)
{
	int		count;
	char	*hex_low;
	char	*hex_up;

	count = 0;
	hex_low = "0123456789abcdef";
	hex_up = "0123456789ABCDEF";
	if (num / 16 > 0)
		count += ft_print_x((num / 16), c);
	if (c == 'x')
		count += ft_print_c(hex_low[num % 16]);
	else
		count += ft_print_c(hex_up[num % 16]);
	return (count);
}

int	ft_print_p(void *p)
{
	int				count;
	unsigned long	num;

	count = 0;
	num = (unsigned long)p;
	if (num == 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += ft_print_x(num, 'x');
	}
	return (count);
}
