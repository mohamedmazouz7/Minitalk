/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 05:43:17 by momazouz          #+#    #+#             */
/*   Updated: 2024/05/24 17:42:39 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>

static void	ft_check_pid(void)
{
	ft_printf("\033[1;31mInvalid PID!!\n");
	exit(0);
}

static void	ft_received_message(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("\033[1;32mMessage received by server✅\n");
		exit(0);
	}
}

static void	send_back_zero(int pid)
{
	int	i;
	int	c;

	i = 7;
	c = '\0';
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_check_pid();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_check_pid();
		}
		i--;
		usleep(100);
	}
	usleep(100);
}

static void	send_binary(int pid, char *str)
{
	int	i;

	while (*str != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if ((*str >> i) & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_check_pid();
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_check_pid();
			}
			i--;
			usleep(400);
		}
		str++;
		usleep(400);
	}
	send_back_zero(pid);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
	{
		ft_printf("\033[1;35mEnter <./client> <PID> <'Message'>\n");
		return (0);
	}
	if (argv[2][0] == '\0')
	{
		ft_printf("\033[1;31mInvalid message\n");
		exit(0);
	}
	if (argv[1][0] == 48)
		ft_check_pid();
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_check_pid();
	signal(SIGUSR1, ft_received_message);
	send_binary(pid, argv[2]);
	while (1)
		;
	return (0);
}
