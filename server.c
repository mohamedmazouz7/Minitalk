/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:12:00 by momazouz          #+#    #+#             */
/*   Updated: 2024/03/22 17:12:04 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf/ft_printf.h"
#include <signal.h>
#include <stdlib.h>

void	ft_bit_handler(int signal)
{
	static int	c;
	static int	bit;
	int			sig;

	if (signal == SIGUSR1)
		sig = 1;
	else
		sig = 0;
	c = (c << 1) + sig;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("My server PID is: %d\n", getpid());
	signal(SIGUSR1, ft_bit_handler);
	signal(SIGUSR2, ft_bit_handler);
	while (1)
		;
	return (0);
}
