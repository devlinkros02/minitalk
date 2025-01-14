/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:42:28 by dkros             #+#    #+#             */
/*   Updated: 2023/11/03 14:35:08 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nums(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
		i += 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_put_min(char *str)
{
	int		i;
	char	*minn;

	i = 0;
	minn = "-2147483648";
	while (minn[i])
	{
		str[i] = minn[i];
		i++;
	}
	return ;
}

char	*ft_itoa(int n)
{
	char	*str;
	int		c;

	c = count_nums(n);
	str = (char *)malloc((c + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		ft_put_min(str);
	else if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	str[c] = '\0';
	while (n > 0)
	{
		str[c - 1] = (n % 10) + '0';
		n /= 10;
		c--;
	}
	return (str);
}

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	printf("%s", ft_itoa(i));
// 	return (0);
// }
