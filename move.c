/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:30:12 by saandria          #+#    #+#             */
/*   Updated: 2024/05/31 15:37:34 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_window *w)
{
	t_coord	m;

	m.x = get_player_x(w->maps);
	m.y = get_player_y(w->maps);
	if (w->maps[m.y][m.x + 1])
	{
		if (w->maps[m.y][m.x + 1] == '1'
			|| (w->maps[m.y][m.x + 1] == 'E' && there_is_coin(w) == 1
			&& w->maps[m.y][m.x + 2] == '1'))
			return ;
		check_char_before_move(w, w->maps[m.y][m.x + 1]);
		if (w->maps[m.y][m.x + 1] == 'E')
		{
			if (w->maps[m.y][m.x + 2] == 'C')
				w->score++;
			w->maps[m.y][m.x + 2] = 'P';
		}
		else
			w->maps[m.y][m.x + 1] = 'P';
		w->maps[m.y][m.x] = '0';
	}
	draw_map(w->maps, w);
	increase_move(w);
}

void	move_left(t_window *w)
{
	t_coord	m;

	m.x = get_player_x(w->maps);
	m.y = get_player_y(w->maps);
	if (w->maps[m.y][m.x - 1])
	{
		if (w->maps[m.y][m.x - 1] == '1'
			|| (w->maps[m.y][m.x - 1] == 'E' && there_is_coin(w) == 1
			&& w->maps[m.y][m.x - 2] == '1'))
			return ;
		check_char_before_move(w, w->maps[m.y][m.x - 1]);
		if (w->maps[m.y][m.x - 1] == 'E')
		{
			if (w->maps[m.y][m.x - 2] == 'C')
				w->score++;
			w->maps[m.y][m.x - 2] = 'P';
		}
		else
			w->maps[m.y][m.x - 1] = 'P';
		w->maps[m.y][m.x] = '0';
	}
	draw_map(w->maps, w);
	increase_move(w);
}

void	move_up(t_window *w)
{
	t_coord	m;

	m.x = get_player_x(w->maps);
	m.y = get_player_y(w->maps);
	if (w->maps[m.y - 1][m.x])
	{
		if (w->maps[m.y - 1][m.x] == '1'
			|| (w->maps[m.y - 1][m.x] == 'E' && there_is_coin(w) == 1
			&& w->maps[m.y - 2][m.x] == '1'))
			return ;
		check_char_before_move(w, w->maps[m.y - 1][m.x]);
		if (w->maps[m.y - 1][m.x] == 'E')
		{
			if (w->maps[m.y - 2][m.x] == 'C')
				w->score++;
			w->maps[m.y - 2][m.x] = 'P';
		}
		else
			w->maps[m.y - 1][m.x] = 'P';
		w->maps[m.y][m.x] = '0';
	}
	draw_map(w->maps, w);
	increase_move(w);
}

void	move_down(t_window *w)
{
	t_coord	m;

	m.x = get_player_x(w->maps);
	m.y = get_player_y(w->maps);
	if (w->maps[m.y + 1][m.x])
	{
		if (w->maps[m.y + 1][m.x] == '1'
			|| (w->maps[m.y + 1][m.x] == 'E' && there_is_coin(w) == 1
			&& w->maps[m.y + 2][m.x] == '1'))
			return ;
		check_char_before_move(w, w->maps[m.y + 1][m.x]);
		if (w->maps[m.y + 1][m.x] == 'E')
		{
			if (w->maps[m.y + 2][m.x] == 'C')
				w->score++;
			w->maps[m.y + 2][m.x] = 'P';
		}
		else
			w->maps[m.y + 1][m.x] = 'P';
		w->maps[m.y][m.x] = '0';
	}
	draw_map(w->maps, w);
	increase_move(w);
}
