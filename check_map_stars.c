/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_stars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 01:00:12 by codespace         #+#    #+#             */
/*   Updated: 2024/05/24 01:06:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_star_neighbors(t_data *data, int i, int j)
{
	char	*line;

	line = data->map->map[i];
	if (j > 0 && !(line[j - 1] == '*' || line[j - 1] == '1'))
		ft_error("Map is not closed from left", data);
	if (j < (int)ft_strlen(line) - 1 && !(line[j + 1] == '*' \
		|| line[j + 1] == '1'))
		ft_error("Map is not closed from right", data);
	if (i > 0 && !(data->map->map[i - 1][j] == '*' \
		|| data->map->map[i - 1][j] == '1'))
		ft_error("Map is not closed from up", data);
	if (i < data->map->map_y - 1 && !(data->map->map[i + 1][j] == '*' \
		|| data->map->map[i + 1][j] == '1'))
		ft_error("Map is not closed from down", data);
}

void	ft_check_stars(t_data *data)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < data->map->map_y)
	{
		j = 0;
		line = data->map->map[i];
		while (j < (int)ft_strlen(line))
		{
			if (line[j] == '*')
			{
				ft_check_star_neighbors(data, i, j);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_border(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->map_y)
	{
		j = 0;
		while (j < (int)ft_strlen(data->map->map[i]))
		{
			if (i == 0 || i == data->map->map_y - 1 || j == 0 \
				|| j == (int)ft_strlen(data->map->map[i]) - 1)
			{
				if (data->map->map[i][j] != '1' && data->map->map[i][j] != '*')
					ft_error("Map is not closed from border", data);
			}
			j++;
		}
		i++;
	}
}
