/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:15:21 by saandria          #+#    #+#             */
/*   Updated: 2024/03/10 15:37:15 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putadd(void *p, int *len)
{
	unsigned long	n;

	if (!p)
	{
		*len += 5;
		write(1, "(nil)", 5);
	}
	else
	{
		n = (unsigned long)p;
		ft_putstr("0x", len);
		ft_put_low_hex(n, len);
	}
}
