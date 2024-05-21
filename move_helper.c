/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:41:50 by codespace         #+#    #+#             */
/*   Updated: 2024/05/21 16:43:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_character(char c, t_data *data)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	printf("data->is_door_open: %d\n", data->is_door_open);
	if (c == '2' && data->is_door_open)
		return (1);
	return (0);
}

static void	key_w(t_data *data)
{
	if (data->map->map[(int)(data->ray->posx + data->ray->dirx
			* 0.15)][(int)(data->ray->posy)] == '0'
		|| is_character(data->map->map[(int)(data->ray->posx + data->ray->dirx
				* 0.15)][(int)(data->ray->posy)], data))
		data->ray->posx += data->ray->dirx * 0.15;
	if (data->map->map[(int)data->ray->posx][(int)(data->ray->posy
		+ data->ray->diry * 0.15)] == '0'
		|| is_character(data->map->map[(int)data->ray->posx] \
		[(int)(data->ray->posy + data->ray->diry * 0.15)], data))
		data->ray->posy += data->ray->diry * 0.15;
}

static void	key_s(t_data *data)
{
	if (data->map->map[(int)(data->ray->posx - data->ray->dirx
			* 0.15)][(int)(data->ray->posy)] == '0'
		|| is_character(data->map->map[(int)(data->ray->posx - data->ray->dirx
				* 0.15)][(int)(data->ray->posy)], data))
		data->ray->posx -= data->ray->dirx * 0.15;
	if (data->map->map[(int)(data->ray->posx)][(int)(data->ray->posy
			- data->ray->diry * 0.15)] == '0'
		|| is_character(data->map->map[(int)(data->ray->posx)][
			(int)(data->ray->posy - data->ray->diry * 0.15)], data))
		data->ray->posy -= data->ray->diry * 0.15;
}

static void	key_d(t_data *data)
{
	if (data->map->map[(int)(data->ray->posx + data->ray->diry
			* 0.15)][(int)(data->ray->posy)] == '0'
		|| is_character(data->map->map[(int)(data->ray->posx + data->ray->diry
				* 0.15)][(int)(data->ray->posy)], data))
		data->ray->posx += data->ray->diry * 0.15;
	if (data->map->map[(int)(data->ray->posx)][(int)(data->ray->posy
			- data->ray->dirx * 0.15)] == '0'
		|| is_character(data->map->map[(int)(data->ray->posx)]
		[(int)(data->ray->posy - data->ray->dirx * 0.15)], data))
		data->ray->posy -= data->ray->dirx * 0.15;
}

static void	key_a(t_data *data)
{
	if (data->map->map[(int)(data->ray->posx - data->ray->diry
			* 0.15)][(int)(data->ray->posy)] == '0'
		|| is_character(data->map->map[(int)(data->ray->posx - data->ray->diry
				* 0.15)][(int)(data->ray->posy)], data))
		data->ray->posx -= data->ray->diry * 0.15;
	if (data->map->map[(int)(data->ray->posx)][(int)(data->ray->posy
			+ data->ray->dirx * 0.15)] == '0'
		|| is_character(data->map->map[(int)(data->ray->posx)]
		[(int)(data->ray->posy + data->ray->dirx * 0.15)], data))
		data->ray->posy += data->ray->dirx * 0.15;
}
