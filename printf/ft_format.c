/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:42:35 by saandria          #+#    #+#             */
/*   Updated: 2024/03/11 09:33:40 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(char c, int *len, va_list args)
{
	if (c == 'c')
		ft_putchar((char)va_arg(args, int), len);
	else if (c == 's')
		ft_putstr((char *)va_arg(args, char *), len);
	else if (c == 'p')
		ft_putadd((char *)va_arg(args, unsigned long), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr((long)va_arg(args, int), len);
	else if (c == 'u')
		ft_put_u_nbr((unsigned long)va_arg(args, unsigned int), len);
	else if (c == 'x')
		ft_put_low_hex((unsigned long)va_arg(args, unsigned int), len);
	else if (c == 'X')
		ft_put_up_hex((unsigned long)va_arg(args, unsigned int), len);
	else if (c == '%')
		ft_putchar('%', len);
}
