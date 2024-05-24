/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:02:49 by momazouz          #+#    #+#             */
/*   Updated: 2023/12/04 21:42:29 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_prefix_p(int *len, char **base_char)
{
	write(1, "0x", 2);
	(*len) += 2;
	*base_char = "0123456789abcdef";
}

void	ft_hexadecimal(unsigned long x, int *len, char x_X_p)
{
	char	str[sizeof(unsigned long) * 3];
	char	*base_char;
	int		i;

	if (x_X_p == 'X')
		base_char = "0123456789ABCDEF";
	else if (x_X_p == 'p')
		ft_put_prefix_p(len, &base_char);
	else
		base_char = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putcharacter_len('0', len);
		return ;
	}
	while (x != 0)
	{
		str[i] = base_char[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putcharacter_len(str[i], len);
}
