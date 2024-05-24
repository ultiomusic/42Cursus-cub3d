/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 02:04:53 by beeligul          #+#    #+#             */
/*   Updated: 2024/05/24 02:04:54 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_pixel(t_data *data, int x, int y, char type)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (type == '1')
				data->mlx_o_data[(y + j) * SCREENWIDTH + (x + i)] = 0x80FFFFFF;
			else if (type == '2')
				data->mlx_o_data[(y + j) * SCREENWIDTH + (x + i)] = 0x8000FF00;
			else if (type == '*')
				data->mlx_o_data[(y + j) * SCREENWIDTH + (x + i)] = 0x80FF0000;
			else if (type == 'P')
				data->mlx_o_data[(y + j) * SCREENWIDTH + (x + i)] = 0x800000FF;
			else
				data->mlx_o_data[(y + j) * SCREENWIDTH + (x + i)] = 0x80000000;
			j++;
		}
		i++;
	}
}

void	ft_render_map_helper(t_data *data, int i, int j)
{
	if (data->ray->user_x - (MINIMAPHEIGHT / 2) + j < 0
		|| data->ray->user_y - (MINIMAPHEIGHT / 2) + i < 0
		|| data->ray->user_x - (MINIMAPHEIGHT / 2) + j >= data->map->map_x
		|| data->ray->user_y - (MINIMAPHEIGHT / 2) + i >= data->map->map_y
		|| data->map->map[data->ray->user_y - (MINIMAPHEIGHT / 2) \
		+ i][data->ray->user_x - (MINIMAPHEIGHT / 2) + j] == '*'
	)
		ft_fill_pixel(data, j * TILE_SIZE, i * TILE_SIZE, '*');
	else if (data->map->map[data->ray->user_y - (MINIMAPHEIGHT / 2) + i]
		[data->ray->user_x - (MINIMAPHEIGHT / 2) + j] == '1')
		ft_fill_pixel(data, j * TILE_SIZE, i * TILE_SIZE, '1');
	else if (data->map->map[data->ray->user_y - (MINIMAPHEIGHT / 2) + i]
		[data->ray->user_x - (MINIMAPHEIGHT / 2) + j] == '2')
		ft_fill_pixel(data, j * TILE_SIZE, i * TILE_SIZE, '2');
	else
		ft_fill_pixel(data, j * TILE_SIZE, i * TILE_SIZE, '0');
}

void	ft_render_map(t_data *data, int render_fc)
{
	int	i;
	int	j;

	i = 0;
	if (render_fc)
		ft_fill_floor_and_ceiling(data);
	data->ray->user_x = (int)data->ray->posy;
	data->ray->user_y = (int)data->ray->posx;
	while (i < MINIMAPHEIGHT)
	{
		j = 0;
		while (j < MINIMAPWIDTH)
		{
			ft_render_map_helper(data, i, j);
			j++;
		}
		i++;
	}
	ft_fill_pixel(data, (MINIMAPWIDTH / 2) * TILE_SIZE, \
		(MINIMAPHEIGHT / 2) * TILE_SIZE, 'P');
}
