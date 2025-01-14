/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:34:21 by dkros             #+#    #+#             */
/*   Updated: 2024/04/04 15:17:13 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_print_c(va_arg(args, int));
	else if (c == 'd' || c == 'i')
		count += ft_print_di(va_arg(args, int));
	else if (c == '%')
		count += ft_print_c('%');
	else if (c == 'x' || c == 'X')
		count += ft_print_x(va_arg(args, unsigned int), c);
	else if (c == 's')
		count += ft_print_s(va_arg(args, char *));
	else if (c == 'p')
		count += ft_print_p(va_arg(args, void *));
	else if (c == 'u')
		count += ft_print_u(va_arg(args, unsigned int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			count += ft_formats(*str, args);
			va_arg(args, int);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
