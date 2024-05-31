/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:23:59 by saandria          #+#    #+#             */
/*   Updated: 2024/03/10 15:25:51 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (nb >= 0 && nb < 10)
	{
		ft_putchar((nb + '0'), len);
	}
	else if (nb < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(-nb, len);
	}
	else
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
}
