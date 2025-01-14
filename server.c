/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:00:39 by dkros             #+#    #+#             */
/*   Updated: 2024/05/30 14:01:56 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "Libft/libft.h"
#include <stdbool.h>

char	write_bit_to_char(unsigned char c, int *i, int signum)
{
	unsigned char	new_bit;

	if (signum == SIGUSR1)
		new_bit = 0;
	else if (signum == SIGUSR2)
		new_bit = 1;
	else
		return (c);
	c = c | (new_bit << (*i));
	return ((*i)++, c);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;

	(void)context;
	if (signum != SIGUSR1 && signum != SIGUSR2)
		return ;
	if (i < 8)
		c = write_bit_to_char(c, &i, signum);
	if (i < 8)
	{
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	if (c == '\0')
	{
		c = '\n';
		kill(info->si_pid, SIGUSR2);
	}
	else
		kill(info->si_pid, SIGUSR1);
	ft_printf("%c", c);
	i = 0;
	c = 0;
	return ;
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("%d", getpid());
	while (true)
		pause();
	return (0);
}
