/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:39:37 by saandria          #+#    #+#             */
/*   Updated: 2024/05/30 13:24:57 by saandria         ###   ########.fr       */
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
	printf("%s\n", true_map);
	if (check_error_map(true_map) == 0) 
	{
		free(true_map);
		ft_error();		
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

char	**ft_map(int argc, char *argv[])
{
	int		fd;
	char	*m;
	char	**map;
	int		i;

	if (argc != 2)
	{
		write(1, "error", 5);
		exit (EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	m = read_map(fd);
	map = get_map(m);
	i = 0;
	while (map[i])
	{
		i++;
	}
	close (fd);
	return (map);
}
