/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 14:14:32 by saandria          #+#    #+#             */
/*   Updated: 2024/05/24 10:52:03 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_word(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			count++;
			i = 1;
		}
		else if (*s == c)
			i = 0;
		s++;
	}
	return (count);
}

static int	count_char(const char *s, int i, char c)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

static void	split_free(char **split, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**get_words(const char *s, char c, int i, char **split)
{
	int	j;
	int		index;

	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = ft_substr(s, index, (count_char(s, index, c)));
			if (split[j] == NULL)
			{
				split_free(split, j);
				return (NULL);
			}
			index = -1;
			j++;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	char	**split;

	split = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!s || !split)
		return (NULL);
	i = 0;
	split = get_words(s, c, i, split);
	return (split);
}
