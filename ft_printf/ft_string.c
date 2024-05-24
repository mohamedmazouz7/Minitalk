/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:52:38 by momazouz          #+#    #+#             */
/*   Updated: 2023/12/03 14:58:29 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		*len = *len + 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putcharacter_len(str[i], len);
		i++;
	}
}
