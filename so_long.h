/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:40:00 by saandria          #+#    #+#             */
/*   Updated: 2024/05/25 10:54:19 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_assets
{
	void	*coin;
	void	*exit;
	void	*wall;
	void	*ground;
	void	*player;
}			t_assets;

typedef struct s_window
{
	void	*mlx;
	void	*win_mlx;
	t_assets	img;
	int		width;
	int		height;
}			t_window;

char	**ft_map(int argc, char *argv[]);
char	**ft_split(char const *s, char c);
char	**get_map(char *m);
void	check_error_map(char *map);
void	*create_window(char **map, t_window w, void *mlx);
void	free_split(char **spl);
void	draw_map(char **maps, t_window *w);
char	*read_map(int fd);
void	init_assets(t_window *w);
void	free_assets(t_window *w);
int		close_window(t_window *w);
void	check_map_char(char c, t_window *w, int x, int y);
int		handle_key(int keycode, t_window *w);


#endif