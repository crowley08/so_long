/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 11:21:45 by saandria          #+#    #+#             */
/*   Updated: 2024/05/31 15:21:56 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_way(t_window *w, int y, int x)
{
	w->tmp[y][x] = 'f';
	if (w->tmp[y][x + 1] != '1' && w->tmp[y][x + 1] != 'f')
		fill_way(w, y, x + 1);
	if (w->tmp[y][x - 1] != '1' && w->tmp[y][x - 1] != 'f')
		fill_way(w, y, x - 1);
	if (w->tmp[y + 1][x] != '1' && w->tmp[y + 1][x] != 'f')
		fill_way(w, y + 1, x);
	if (w->tmp[y - 1][x] != '1' && w->tmp[y - 1][x] != 'f')
		fill_way(w, y - 1, x);
}

void	flood_fill(t_window *w)
{
	int	x;
	int	y;

	x = get_player_x(w->tmp);
	y = get_player_y(w->tmp);
	fill_way(w, y, x);
	y = 0;
	while (w->tmp[y])
	{
		x = 0;
		while (w->tmp[y][x])
		{
			if (w->tmp[y][x] == 'E' || w->tmp[y][x] == 'C')
			{
				free_split(w->tmp);
				ft_error(2);
			}
			x++;
		}
		y++;
	}
}
