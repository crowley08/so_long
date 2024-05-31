/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_low_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:04:29 by saandria          #+#    #+#             */
/*   Updated: 2024/03/10 15:38:57 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_low_hex(unsigned long n, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_put_low_hex(n / 16, len);
		ft_put_low_hex(n % 16, len);
	}
	else
		ft_putchar(base[n], len);
}
