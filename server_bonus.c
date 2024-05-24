/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 05:42:57 by momazouz          #+#    #+#             */
/*   Updated: 2024/04/04 05:43:03 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>

void	ft_bit_handler(int signal, siginfo_t *info, void *context)
{
	static int	c;
	static int	bit;
	int			sig;

	context = NULL;
	if (signal == SIGUSR1)
		sig = 1;
	else
		sig = 0;
	c = (c << 1) + sig;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_bit_handler;
	ft_printf("My server PID is: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
