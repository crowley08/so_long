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
	char	**maps;
	t_window	w;

	maps = ft_map(argc, argv);
	w.mlx = mlx_init();
	w.win_mlx = create_window(maps, w, w.mlx);
	w.img = NULL;
	draw_map(maps, w.mlx, w.win_mlx, w.img);
	free_split(maps);
	mlx_loop(w.mlx);
}
