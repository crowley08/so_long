/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:11:41 by saandria          #+#    #+#             */
/*   Updated: 2024/05/27 15:48:44 by saandria         ###   ########.fr       */
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
	w.width = j * 64;
	w.height = i * 64;
	w.win_mlx = mlx_new_window(mlx, w.width, w.height, "so_long");
	return (w.win_mlx);
}

void	draw_map(char **maps, t_window *w)
{
	t_coord		map;
	t_coord		image;

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
			image.x += 64;
		}
		map.y += 1;
		image.y += 64;
	}
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
	else if (c == '0' || c == 'E')
		mlx_put_image_to_window(w->mlx, w->win_mlx, w->img.ground, x, y);
//	if (there_is_coin(w) == 0)
//		display_exit(w);
}


void	init_assets(t_window *w)
{
	w->img.coin = mlx_xpm_file_to_image(w->mlx, "sprites/Compass.xpm", &w->width, &w->height);
	w->img.exit = mlx_xpm_file_to_image(w->mlx, "sprites/Luffys flag.xpm", &w->width, &w->height);
	w->img.wall = mlx_xpm_file_to_image(w->mlx, "sprites/wallblue.xpm", &w->width, &w->height);
	w->img.player = mlx_xpm_file_to_image(w->mlx, "sprites/sunny.xpm", &w->width, &w->height);
	w->img.ground = mlx_xpm_file_to_image(w->mlx, "sprites/black.xpm", &w->width, &w->height);
}
void	free_assets(t_window *w)
{
	mlx_destroy_image(w->mlx, w->img.coin);
	mlx_destroy_image(w->mlx, w->img.exit);
	mlx_destroy_image(w->mlx, w->img.wall);
	mlx_destroy_image(w->mlx, w->img.player);
	mlx_destroy_image(w->mlx, w->img.ground);
}
