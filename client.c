/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:11:35 by momazouz          #+#    #+#             */
/*   Updated: 2024/03/22 17:11:43 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>

static void	ft_check_pid(void)
{
	ft_printf("\x1b[1;31mInvalid PID!!\n");
	exit(0);
}

static void	ft_check_message(void)
{
	ft_printf("\x1b[1;31mInvalid message\n");
	exit(0);
}

static int	ft_check_argv1(char *argv1)
{
	int	i;

	i = 0;
	while (argv1[i])
	{
		if (argv1[i] >= 48 && argv1[i] <= 57)
			i++;
		else
			ft_check_pid();
	}
	return (0);
}

static void	send_binary(int pid, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if ((str[j] >> i) & 1)
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
		j++;
		usleep(400);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("\x1b[1;35mEnter <./client> <PID> <'Message'>\n");
		return (0);
	}
	ft_check_argv1(argv[1]);
	if (argv[2][0] == '\0')
		ft_check_message();
	if (argv[1][0] == 48)
		ft_check_pid();
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_check_pid();
	send_binary(pid, argv[2]);
	send_binary(pid, "\n");
	return (0);
}
