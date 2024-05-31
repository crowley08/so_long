/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:42:50 by saandria          #+#    #+#             */
/*   Updated: 2024/05/31 15:22:46 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
*/
static void	check_ext(char *arg)
{
	int		i;
	int		len;
	char	*s;

	i = ft_strlen(arg) - 4;
	len = 4;
	s = ft_substr(arg, i, len);
	if (ft_memcmp(s, ".ber", 4) != 0)
	{
		free(s);
		ft_error(3);
	}
	free(s);
}

int	main(int argc, char *argv[])
{
	t_window	w;

	if (argc != 2)
		ft_error(-1);
	check_ext(argv[1]);
	w.tmp = ft_map(argv);
	flood_fill(&w);
	free_split(w.tmp);
	w.score = 0;
	w.move = 0;
	w.maps = ft_map(argv);
	w.mlx = mlx_init();
	w.win_mlx = create_window(w.maps, w, w.mlx);
	draw_map(w.maps, &w);
	mlx_hook(w.win_mlx, KeyPress, KeyPressMask, &handle_key, &w);
	mlx_hook(w.win_mlx, 17, 0, close_window, &w);
	mlx_loop(w.mlx);
}
