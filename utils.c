/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:26:08 by saandria          #+#    #+#             */
/*   Updated: 2024/05/25 10:38:17 by saandria         ###   ########.fr       */
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

void	init_assets(t_window *w)
{
	w->img.coin = mlx_xpm_file_to_image(w->mlx, "sprites/Vente d esclaves icon.xpm", &w->width, &w->height);
	w->img.exit = mlx_xpm_file_to_image(w->mlx, "sprites/Luffys flag.xpm", &w->width, &w->height);
	w->img.wall = mlx_xpm_file_to_image(w->mlx, "sprites/wallblue.xpm", &w->width, &w->height);
	w->img.player = mlx_xpm_file_to_image(w->mlx, "sprites/luffy.xpm", &w->width, &w->height);
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