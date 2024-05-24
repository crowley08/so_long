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
