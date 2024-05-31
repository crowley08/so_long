/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:10:02 by saandria          #+#    #+#             */
/*   Updated: 2024/03/10 15:37:19 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = -1;
	va_start(args, s);
	while (s[++i])
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]))
		{
			ft_format(s[i + 1], &len, args);
			i++;
		}
		else if (s[i] != '%')
			ft_putchar(s[i], &len);
		else
			return (len);
	}
	va_end(args);
	return (len);
}
