/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:45:48 by momazouz          #+#    #+#             */
/*   Updated: 2023/12/04 09:54:10 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_int(unsigned int u, int *len)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, len);
	ft_putcharacter_len(u % 10 + '0', len);
}
