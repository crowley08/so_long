/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:44:44 by saandria          #+#    #+#             */
/*   Updated: 2024/05/27 14:47:07 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_window *w)
{
	mlx_destroy_window(w->mlx, w->win_mlx);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
	exit(0);
	return (0);
}

int	handle_key(int keycode, t_window *w)
{
	if (keycode == XK_Escape || keycode == 65307)
		close_window(w);
	if (keycode == XK_d || keycode == XK_D)
		move_right(w);
	if (keycode == XK_a || keycode == XK_A)
		move_left(w);
	if (keycode == XK_w || keycode == XK_W)
		move_up(w);
	if (keycode == XK_s || keycode == XK_S)
		move_down(w);
	return (0);
}
