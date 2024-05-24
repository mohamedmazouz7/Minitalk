/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momazouz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:09:35 by momazouz          #+#    #+#             */
/*   Updated: 2024/04/06 13:12:51 by momazouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putcharacter_len(char c, int *len);
void	ft_string(char *str, int *len);

void	ft_number(int number, int *len);
void	ft_unsigned_int(unsigned int u, int *len);
void	ft_hexadecimal(unsigned long x, int *len, char x_X_p);
int		ft_printf(const char *format, ...);
int		ft_atoi(const char *str);

#endif
