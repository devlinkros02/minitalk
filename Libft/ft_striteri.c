/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:06:35 by dkros             #+#    #+#             */
/*   Updated: 2023/10/27 19:17:07 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// test function:
// void uppercase(unsigned int index, char *ch)
// {
//     *ch = toupper(*ch);
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		(*f)(i, s);
		i++;
		s++;
	}
	return ;
}

// int main(void)
// {
// 	char str[20] = "hellooooo";

// 	ft_striteri(str, uppercase);
// 	printf("%s\n", str);
// 	return (0);
// }
