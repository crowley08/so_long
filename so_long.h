/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:40:00 by saandria          #+#    #+#             */
/*   Updated: 2024/05/27 15:10:26 by saandria         ###   ########.fr       */
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
	char	**maps;
	int	score;
	int	move;
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
int		get_player_y(char **maps);
int		get_player_x(char **maps);
void	move_right(t_window *w);
void	move_left(t_window *w);
void	move_down(t_window *w);
void	move_up(t_window *w);
void	check_char_before_move(t_window *w, char c);
int	get_exit_y(char **maps);
int	get_exit_x(char **maps);
int	there_is_coin(t_window *w);
void	display_exit(t_window *w);

#endif