/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:55:37 by dkros             #+#    #+#             */
/*   Updated: 2024/04/04 14:44:28 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_s(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s != '\0')
	{
		count += ft_print_c(*s);
		s++;
	}
	return (count);
}
