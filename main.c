/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:42:50 by saandria          #+#    #+#             */
/*   Updated: 2024/05/28 08:33:49 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
static int	invalid_map_ext(char *arg)
{
	int	i;

	i = ft_strlen(arg);
	printf("\n%c\n", arg[i]);
	if (arg[i] != 'r' || arg[i - 1] != 'e' || arg[i - 2] != 'b' || arg[i - 3] != '.')
		return (1);
	return (0);
}
*/

int	main(int argc, char *argv[])
{
	t_window	w;

	if (argc != 2)
		ft_error();
	w.score = 0;
	w.move = 0;
	w.maps = ft_map(argc, argv);
	w.mlx = mlx_init();
	w.win_mlx = create_window(w.maps, w, w.mlx);
	init_assets(&w);
	draw_map(w.maps, &w);
	mlx_key_hook(w.win_mlx, handle_key, &w);
	mlx_hook(w.win_mlx, 17, 0, close_window, &w);
	mlx_loop(w.mlx);
}
