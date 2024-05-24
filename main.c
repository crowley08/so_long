/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:42:50 by saandria          #+#    #+#             */
/*   Updated: 2024/05/24 16:49:51 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_window	w;
	char	**map;
	void	*img;
	int		width;
	int		height;

	map = ft_map(argc, argv);
	w.mlx = mlx_init();
	w.win_mlx = create_window(map, w, w.mlx);
	free_split(map);
	img = mlx_xpm_file_to_image(w.mlx, "sprites/test.xpm", &width, &height);
	mlx_put_image_to_window(w.mlx, w.win_mlx, img, 0, 128);
	mlx_loop(w.mlx);
}
