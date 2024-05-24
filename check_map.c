/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 02:03:31 by beeligul          #+#    #+#             */
/*   Updated: 2024/05/24 02:03:32 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_flood(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map->map_y)
	{
		j = 0;
		while (j < (int)ft_strlen(data->map->map[i]))
		{
			if (player(data->map->flood_fill[i][j])
			|| data->map->flood_fill[i][j] == '0'
			|| data->map->flood_fill[i][j] == '1')
			{
				ft_print_map(data->map->flood_fill);
				printf("data->map->flood_fill[%d][%d]: %c\n", i, j, \
						data->map->flood_fill[i][j]);
				ft_error("hata", data);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_data *data, int y, int x)
{
	if (y < 0 || x < 0 || y >= data->map->map_y \
	|| x >= (int)ft_strlen(data->map->map[y]) \
	|| data->map->flood_fill[y][x] == 'F')
		return ;
	if (data->map->flood_fill[y][x] == '0' || data->map->flood_fill[y][x] == 'U'
	|| data->map->flood_fill[y][x] == '2' || data->map->flood_fill[y][x] == 'N'
	|| data->map->flood_fill[y][x] == 'S' || data->map->flood_fill[y][x] == 'W'
	|| data->map->flood_fill[y][x] == 'E' || data->map->flood_fill[y][x] == '1')
	{
		data->map->flood_fill[y][x] = 'F';
		flood_fill(data, y + 1, x);
		flood_fill(data, y - 1, x);
		flood_fill(data, y, x + 1);
		flood_fill(data, y, x - 1);
	}
}

void	initialize_and_process_map(t_data *data)
{
	int		i;
	int		j;
	char	**mapp;

	i = 0;
	mapp = malloc(sizeof(char *) * (data->map->map_y + 1));
	while (i < data->map->map_y)
	{
		j = 0;
		mapp[i] = ft_calloc(sizeof(char), (data->map->map_x + 1));
		ft_memset(mapp[i], '*', data->map->map_x);
		ft_memcpy(mapp[i], data->map->map[i], ft_strlen(data->map->map[i]));
		while (j < (int)data->map->map_x)
		{
			if (mapp[i][j] == ' ')
				mapp[i][j] = '*';
			j++;
		}
		i++;
	}
	mapp[i] = NULL;
	data->map->map = mapp;
}

void	validate_map(t_data *data)
{
	flood_fill(data, (int)data->ray->posy, (int)data->ray->posx);
	check_flood(data);
	check_player_amount(data);
	check_map_characters(data);
	ft_check_stars(data);
	ft_check_border(data);
}

void	process_and_validate_map(t_data *data)
{
	initialize_and_process_map(data);
	validate_map(data);
}
