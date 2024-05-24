/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:37:09 by momazouz          #+#    #+#             */
/*   Updated: 2023/12/03 18:22:26 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(int number, int *len)
{
	long	nbr;

	nbr = number;
	if (nbr < 0)
	{
		ft_putcharacter_len('-', len);
		nbr = nbr * -1;
	}
	if (nbr < 10)
	{
		ft_putcharacter_len(nbr + '0', len);
	}
	if (nbr >= 10)
	{
		ft_number(nbr / 10, len);
		ft_putcharacter_len(nbr % 10 + '0', len);
	}
}
