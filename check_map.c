/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:39:37 by saandria          #+#    #+#             */
/*   Updated: 2024/05/31 15:19:56 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(int fd)
{
	static char	*map;
	char		*true_map;

	if (!fd)
		return (NULL);
	true_map = get_next_line(fd);
	map = get_next_line(fd);
	true_map = ft_strjoin(true_map, map);
	free(map);
	while (map)
	{
		map = get_next_line(fd);
		true_map = ft_strjoin(true_map, map);
		free(map);
	}
	if (check_error_map(true_map) == 0)
	{
		free(true_map);
		ft_error(2);
	}
	return (true_map);
}

char	**get_map(char *m)
{
	char	**map;

	map = ft_split(m, '\n');
	free(m);
	check_error(map);
	return (map);
}

char	**ft_map(char *argv[])
{
	int		fd;
	char	*m;
	char	**map;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		ft_error(2);
	m = read_map(fd);
	map = get_map(m);
	close (fd);
	return (map);
}
