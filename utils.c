/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:26:08 by saandria          #+#    #+#             */
/*   Updated: 2024/05/28 07:04:13 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_split(char **spl)
{
	int	i;

	i = 0;
	while (spl[i] != NULL)
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

int	get_player_x(char **maps)
{
	t_coord	map;

	map.y = 0;
	while (maps[map.y] != NULL)
	{
		map.x = 0;
		while (maps[map.y][map.x])
		{
			if (maps[map.y][map.x] == 'P')
				return (map.x);
			map.x += 1;
		}
		map.y += 1;
	}
	return (-1);
}

int	get_player_y(char **maps)
{
	t_coord	map;

	map.y = 0;
	while (maps[map.y] != NULL)
	{
		map.x = 0;
		while (maps[map.y][map.x])
		{
			if (maps[map.y][map.x] == 'P')
				return (map.y);
			map.x += 1;
		}
		map.y += 1;
	}
	return (-1);
}

void	check_char_before_move(t_window *w, char c)
{
	if (c == 'C')
	{
		w->score++;
		printf("\033[1;93mSCORE = [%d]\033[0m\n", w->score);
	}
	if (c == 'E')
	{
		if (there_is_coin(w) == 0)
		{
			printf("\n\033[1;32m[YOU WON]\033[0m\n");
			close_window(w);
		}
		else
			printf("\nthere is more coin\n");
	}
}

int	there_is_coin(t_window *w)
{
	int	i;
	int	j;

	i = 0;
	while (w->maps[i])
	{
		j = 0;
		while (w->maps[i][j])
		{
			if (w->maps[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_exit_x(char **maps)
{
	t_coord	map;

	map.y = 0;
	while (maps[map.y] != NULL)
	{
		map.x = 0;
		while (maps[map.y][map.x])
		{
			if (maps[map.y][map.x] == 'E')
				return (map.x);
			map.x += 1;
		}
		map.y += 1;
	}
	return (-1);
}

int	get_exit_y(char **maps)
{
	t_coord	map;

	map.y = 0;
	while (maps[map.y] != NULL)
	{
		map.x = 0;
		while (maps[map.y][map.x])
		{
			if (maps[map.y][map.x] == 'E')
				return (map.y);
			map.x += 1;
		}
		map.y += 1;
	}
	return (-1);
}
