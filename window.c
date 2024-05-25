/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:11:41 by saandria          #+#    #+#             */
/*   Updated: 2024/05/24 15:58:24 by saandria         ###   ########.fr       */
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

void	draw_map(char **maps, void *mlx, void *win_mlx, void *img)
{
	t_coord		map;
	t_coord		image;
	int			width;
	int			height;

	map.y = 0;
	image.y = 0;
	while (maps[map.y] != NULL)
	{
		map.x = 0;
		image.x = 0;
		while (maps[map.y][map.x]!= '\0')
		{
			if (maps[map.y][map.x] == '1')
				img = mlx_xpm_file_to_image(mlx, "sprites/wallblue.xpm", &width, &height);
			else if (maps[map.y][map.x] == 'C')
				img = mlx_xpm_file_to_image(mlx, "sprites/Vente d esclaves icon.xpm", &width, &height);
			else if (maps[map.y][map.x] == 'E')
				img = mlx_xpm_file_to_image(mlx, "sprites/Luffys flag.xpm", &width, &height);
			else if (maps[map.y][map.x] == 'P')
				img = mlx_xpm_file_to_image(mlx, "sprites/luffy.xpm", &width, &height);
			else if (maps[map.y][map.x] == '0')
				img = mlx_xpm_file_to_image(mlx, "sprites/black.xpm", &width, &height);
			mlx_put_image_to_window(mlx, win_mlx, img, image.x, image.y);
			map.x += 1;
			image.x += 64;
		}
		map.y += 1;
		image.y += 64;
	}
}
