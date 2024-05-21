/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 02:08:21 by burkaya           #+#    #+#             */
/*   Updated: 2024/05/21 20:18:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_wallhit(t_data *data)
{
	if (data->map->map[data->ray->map_x][data->ray->map_y] == '1' ||
		data->map->map[data->ray->map_x][data->ray->map_y] == '2')
	{
		if (data->map->map[data->ray->map_x][data->ray->map_y] == '2')
		{
			if (!data->is_door_open)
				data->ray->wall = 2;
			else
				data->ray->wall = 3;
		}
		else
			data->ray->wall = 1;
	}
}

void	ft_wallhit(t_data *data)
{
	data->ray->wall = 0;
	while (!data->ray->wall)
	{
		if (data->ray->sidedistx < data->ray->sidedisty)
		{
			data->ray->sidedistx += data->ray->deltadistx;
			data->ray->map_x += data->ray->stepx;
			data->ray->side = 0;
		}
		else
		{
			data->ray->sidedisty += data->ray->deltadisty;
			data->ray->map_y += data->ray->stepy;
			data->ray->side = 1;
		}
		ft_check_wallhit(data);
	}
}

void	ft_raydist(t_data *data)
{
	if (data->ray->side == 0)
		data->ray->perpwalldist = data->ray->sidedistx - data->ray->deltadistx;
	else
		data->ray->perpwalldist = data->ray->sidedisty - data->ray->deltadisty;
	data->ray->lineheight = (int)(1080 / data->ray->perpwalldist * 2);
	data->ray->drawstart = -data->ray->lineheight / 2 + 1080 / 2;
	if (data->ray->drawstart < 0)
		data->ray->drawstart = 0;
	data->ray->drawend = data->ray->lineheight / 2 + 1080 / 2;
	if (data->ray->drawend >= 1080)
		data->ray->drawend = 1080 - 1;
}

void	ft_handle_door_interaction(t_data *data)
{
	if (data->ray->wall == 3 && data->ray->perpwalldist
		< 1.5 && !data->e_pressed)
	{
		data->ray->wall = 0;
		data->is_door_open = 0;
		ft_wallhit(data);
		ft_raydist(data);
	}
	else if (data->e_pressed && data->ray->wall == 2
		&& data->ray->perpwalldist < 1.5)
	{
		data->ray->wall = 0;
		data->is_door_open = 1;
		ft_wallhit(data);
		ft_raydist(data);
	}
	else if (data->e_pressed && data->ray->wall == 3
		&& data->ray->perpwalldist < 1.5)
	{
		ft_wallhit(data);
		ft_raydist(data);
	}
}

void	ft_send_ray(t_data *data, int x)
{
	ft_direction(data);
	ft_wallhit(data);
	ft_raydist(data);
	ft_handle_door_interaction(data);
	ft_texture(data, x);
}
