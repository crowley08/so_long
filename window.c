/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:11:41 by saandria          #+#    #+#             */
/*   Updated: 2024/05/31 15:48:05 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*create_window(char **map, t_window w, void *mlx)
{
	int			i;
	int			j;

	i = 0;
	j = ft_strlen(map[i]);
	while (map[i])
		i++;
	w.w = j * 32;
	w.h = i * 32;
	w.win_mlx = mlx_new_window(mlx, w.w, w.h, "so_long");
	return (w.win_mlx);
}

void	draw_map(char **maps, t_window *w)
{
	t_coord		map;
	t_coord		image;

	init_assets(w);
	map.y = 0;
	image.y = 0;
	while (maps[map.y] != NULL)
	{
		map.x = 0;
		image.x = 0;
		while (maps[map.y][map.x] != '\0')
		{
			check_map_char(maps[map.y][map.x], w, image.x, image.y);
			map.x += 1;
			image.x += 32;
		}
		map.y += 1;
		image.y += 32;
	}
	free_assets(w);
}

void	check_map_char(char c, t_window *w, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(w->mlx, w->win_mlx, w->img.wall, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(w->mlx, w->win_mlx, w->img.coin, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(w->mlx, w->win_mlx, w->img.exit, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(w->mlx, w->win_mlx, w->img.player, x, y);
	else if (c == '0')
		mlx_put_image_to_window(w->mlx, w->win_mlx, w->img.ground, x, y);
}

void	init_assets(t_window *w)
{
	w->img.coin = mlx_xpm_file_to_image(w->mlx, "s-32/ch.xpm", &w->w, &w->h);
	w->img.exit = mlx_xpm_file_to_image(w->mlx, "s-32/P.xpm", &w->w, &w->h);
	w->img.wall = mlx_xpm_file_to_image(w->mlx, "s-32/g.xpm", &w->w, &w->h);
	w->img.player = mlx_xpm_file_to_image(w->mlx, "s-32/lu.xpm", &w->w, &w->h);
	w->img.ground = mlx_xpm_file_to_image(w->mlx, "s-32/bl.xpm", &w->w, &w->h);
}

void	free_assets(t_window *w)
{
	mlx_destroy_image(w->mlx, w->img.coin);
	mlx_destroy_image(w->mlx, w->img.exit);
	mlx_destroy_image(w->mlx, w->img.wall);
	mlx_destroy_image(w->mlx, w->img.player);
	mlx_destroy_image(w->mlx, w->img.ground);
}
