/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:10:07 by momazouz          #+#    #+#             */
/*   Updated: 2023/12/05 09:48:01 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_chek(char s, va_list *ptr, int *len, int *i)
{
	if (s == 's')
		ft_string(va_arg(*ptr, char *), len);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(*ptr, int), len);
	else if (s == 'u')
		ft_unsigned_int(va_arg(*ptr, unsigned int), len);
	else if (s == 'x')
		ft_hexadecimal(va_arg(*ptr, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hexadecimal(va_arg(*ptr, unsigned int), len, 'X');
	else if (s == 'p')
		ft_hexadecimal(va_arg(*ptr, unsigned long), len, 'p');
	else if (s == 'c')
		ft_putcharacter_len(va_arg(*ptr, int), len);
	else if (s == '%')
		ft_putcharacter_len('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_end(args);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			ft_printf_chek(format[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putcharacter_len((char)format[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
