/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:42:11 by saandria          #+#    #+#             */
/*   Updated: 2024/05/31 15:43:55 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int n)
{
	write(1, "Error\n", 6);
	if (n == 0)
		write(1, "map no rectangular\n", 19);
	else if (n == 1)
		write(1, "map not surrounded by walls\n", 28);
	else if (n == 2)
		write(1, "map invalid\n", 12);
	else if (n == 3)
		write(1, "invalid extension\n", 17);
	else if (n == -1)
		write(1, "invalid arguments\n", 17);
	exit(EXIT_FAILURE);
}

void	increase_move(t_window *w)
{
	w->move++;
	ft_printf("\033[1;91mMOVE = [%d]\033[0m\n", w->move);
}
