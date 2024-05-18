/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:40:00 by saandria          #+#    #+#             */
/*   Updated: 2024/05/18 07:26:12 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"

/*****MAP*****/
void	ft_map(int argc, char *argv[]);
char	**ft_split(char const *s, char c);
char	**get_map(char *m);
void	check_error_map(char *map);
char	*read_map(int fd);

#endif