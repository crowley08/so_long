/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:30:12 by saandria          #+#    #+#             */
/*   Updated: 2024/05/28 08:02:07 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_window *w)
{
	t_coord	map;

	map.x = get_player_x(w->maps);
	map.y = get_player_y(w->maps);
	if (w->maps[map.y][map.x + 1])
	{
		if (w->maps[map.y][map.x + 1] == '1'
			|| (w->maps[map.y][map.x + 1] == 'E' && there_is_coin(w) == 1 && w->maps[map.y][map.x + 2] == '1'))
			return ;
		check_char_before_move(w, w->maps[map.y][map.x + 1]);
		if (w->maps[map.y][map.x + 1] == 'E')
		{
			if (w->maps[map.y][map.x + 2] == 'C')
			{
				w->score++;
				printf("\033[1;93mSCORE = [%d]\033[0m\n", w->score);
			}
			w->maps[map.y][map.x + 2] = 'P';
		}
		else
			w->maps[map.y][map.x + 1] = 'P';
		w->maps[map.y][map.x] = '0';
	}
	draw_map(w->maps, w);
	w->move++;
	printf("\033[1;91mMOVE = [%d]\033[0m\n", w->move);
}

void	move_left(t_window *w)
{
	t_coord	map;

	map.x = get_player_x(w->maps);
	map.y = get_player_y(w->maps);
	if (w->maps[map.y][map.x - 1])
	{
		if (w->maps[map.y][map.x - 1] == '1'
			|| (w->maps[map.y][map.x - 1] == 'E' && there_is_coin(w) == 1 && w->maps[map.y][map.x - 2] == '1'))
			return ;
		check_char_before_move(w, w->maps[map.y][map.x - 1]);
		if (w->maps[map.y][map.x - 1] == 'E')
		{
			if (w->maps[map.y][map.x - 2] == 'C')
			{
				w->score++;
				printf("\033[1;93mSCORE = [%d]\033[0m\n", w->score);
			}
			w->maps[map.y][map.x - 2] = 'P';
		}
		else
			w->maps[map.y][map.x - 1] = 'P';
		w->maps[map.y][map.x] = '0';
	}
	draw_map(w->maps, w);
	w->move++;
	printf("\033[1;91mMOVE = [%d]\033[0m\n", w->move);
}

void	move_up(t_window *w)
{
	t_coord	map;

	map.x = get_player_x(w->maps);
	map.y = get_player_y(w->maps);
	if (w->maps[map.y - 1][map.x])
	{
		if (w->maps[map.y - 1][map.x] == '1'
			|| (w->maps[map.y - 1][map.x] == 'E' && there_is_coin(w) == 1 && w->maps[map.y - 2][map.x] == '1'))
			return ;
		check_char_before_move(w, w->maps[map.y - 1][map.x]);
		if (w->maps[map.y - 1][map.x] == 'E')
		{
			if (w->maps[map.y - 2][map.x] == 'C')
			{
				w->score++;
				printf("\033[1;93mSCORE = [%d]\033[0m\n", w->score);
			}
			w->maps[map.y - 2][map.x] = 'P';
		}
		else
			w->maps[map.y - 1][map.x] = 'P';
		w->maps[map.y][map.x] = '0';
	}
	draw_map(w->maps, w);
	w->move++;
	printf("\033[1;91mMOVE = [%d]\033[0m\n", w->move);
}

void	move_down(t_window *w)
{
	t_coord	map;

	map.x = get_player_x(w->maps);
	map.y = get_player_y(w->maps);
	if (w->maps[map.y + 1][map.x])
	{
		if (w->maps[map.y + 1][map.x] == '1'
			|| (w->maps[map.y + 1][map.x] == 'E' && there_is_coin(w) == 1 && w->maps[map.y + 2][map.x] == '1'))
			return ;
		check_char_before_move(w, w->maps[map.y + 1][map.x]);
		if (w->maps[map.y + 1][map.x] == 'E')
		{
			if (w->maps[map.y + 2][map.x] == 'C')
			{
				w->score++;
				printf("\033[1;93mSCORE = [%d]\033[0m\n", w->score);
			}
			w->maps[map.y + 2][map.x] = 'P';
		}
		else
			w->maps[map.y + 1][map.x] = 'P';
		w->maps[map.y][map.x] = '0';
	}
	draw_map(w->maps, w);
	w->move++;
	printf("\033[1;91mMOVE = [%d]\033[0m\n", w->move);
}
