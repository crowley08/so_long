/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 02:39:37 by saandria          #+#    #+#             */
/*   Updated: 2024/05/18 07:26:29 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(int fd)
{
	static char	*map;
	char		*buffer;
	char		*true_map;
	buffer = 0;
	if (!fd)
		return (NULL);
	true_map = get_next_line(fd);
	while (map = get_next_line(fd))
	{
		true_map = ft_strjoin(true_map, map);
		free(map);
	}
//	printf("%s\n", true_map);
	check_error_map(true_map);
	return (true_map);
}

void	check_error_map(char *map)
{
	int	i;
	int	count_exit;
	int	count_start;

	i = 0;
	count_exit = 0;
	count_start = 0;
	while (map && map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'C'
			 && map[i] != 'P' && map[i] != 'E' && map[i] != '\n')
		{
			write(1, "error", 5);
			free(map);
			exit (EXIT_FAILURE);
		}
		if (map[i] == 'E')
			count_exit++;
		if (map[i] == 'P')
			count_start++;
		i++;
	}
	printf("%s\n", map);
	if (count_exit != 1 || count_start != 1)
	{
		write(1, "errorato", 8);
		free(map);
		exit (EXIT_FAILURE);
	}
}

char	**get_map(char *m)
{
	char	**map;
	
	map = ft_split(m, '\n');
	free(m);
	return (map);
}

void	ft_map(int argc, char *argv[])
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
		printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	close (fd);
}
