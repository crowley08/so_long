/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:42:50 by saandria          #+#    #+#             */
/*   Updated: 2024/05/27 15:53:02 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_window	w;

	w.score = 0;
	w.move = 0;
	w.mlx = mlx_init();
	w.maps = ft_map(argc, argv);
//	printf("\n\033[1;91mX = [%d]\033[0m\n", get_player_x(w.maps));
//	printf("\n\033[1;91mY = [%d]\033[0m\n", get_player_y(w.maps));
	w.win_mlx = create_window(w.maps, w, w.mlx);
	init_assets(&w);
	draw_map(w.maps, &w);
	mlx_key_hook(w.win_mlx, handle_key, &w);
	mlx_hook(w.win_mlx, 17, 0, close_window, &w);
	mlx_loop(w.mlx);
}
