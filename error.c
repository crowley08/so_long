/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 07:20:15 by saandria          #+#    #+#             */
/*   Updated: 2024/05/28 08:11:34 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_error_map(char *map)
{
	int	i;
	int	count_exit;
	int	count_start;

	i = 0;
	count_exit = 0;
	count_start = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'C'
			&& map[i] != 'P' && map[i] != 'E' && map[i] != '\n')
			return (0);
		if (map[i] == 'E')
			count_exit++;
		if (map[i] == 'P')
			count_start++;
		if (map[i] == '\n' && map[i + 1] == '\n')
			return (0);
		i++;
	}
	printf("%s\n", map);
	if (count_exit != 1 || count_start != 1)
		return (0);
	return (1);
}

int	is_rectangular(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	if (i == j)
		return (0);
	return (1);
}

int	is_sur_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	same_line(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[j])
		{
			if (ft_strlen(map[j]) != ft_strlen(map[i]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_error(char **map)
{
	if (is_rectangular(map) == 0 || is_sur_walls(map) == 0 || same_line(map) == 0)
	{
		free_split(map);
		ft_error();
	}
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}