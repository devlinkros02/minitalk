/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:41:19 by dkros             #+#    #+#             */
/*   Updated: 2024/05/30 14:05:24 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "Libft/libft.h"
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int	g_status = 0;

int	ft_encoder(unsigned char c, int pid)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		g_status = 0;
		if (((c >> i++) & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_status == 0)
		{
			usleep(42);
			if (j++ > 100)
			{
				ft_printf("Error: Could't send to process\n");
				return (1);
			}
		}
		usleep(300);
	}
	return (0);
}

void	received_handler(int signum)
{
	static int	i = 0;

	if (signum != SIGUSR1 && signum != SIGUSR2)
		return ;
	g_status = 1;
	if (signum == SIGUSR1)
		i++;
	else
	{
		ft_printf("\nMessage sent successfully\n");
		ft_printf("Number of bits received: %d\n", i);
	}
}

int	pid_check(char *pid)
{
	int	i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (!ft_isdigit(pid[i++]))
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		pid;
	char	*str;

	if (argc != 3)
		return (ft_printf("Error: Invalid number of arguments.\n"), 1);
	signal(SIGUSR1, received_handler);
	signal(SIGUSR2, received_handler);
	str = argv[2];
	i = 0;
	if (pid_check(argv[1]) == 0)
		return (ft_printf("Error: PID has to be numbers only.\n"), 1);
	pid = ft_atoi(argv[1]);
	while (str[i] != '\0')
	{
		if (ft_encoder(str[i++], pid) == 1)
			return (1);
	}
	ft_encoder('\0', pid);
	return (0);
}
