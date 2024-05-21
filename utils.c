/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:01:03 by burkaya           #+#    #+#             */
/*   Updated: 2024/05/21 17:00:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_ray(t_data *data, int x, int y, int x2, int y2, int i)
{
	data->ray->log[i] = (int *)malloc(sizeof(int) * 4);
	data->ray->log[i][0] = x;
	data->ray->log[i][1] = y;
	data->ray->log[i][2] = x2;
	data->ray->log[i][3] = y2;
}

double	ft_ray_length(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

void	ft_fill_floor_and_ceiling(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < 1080 / 2)
	{
		n = 0;
		while (n < 1920)
		{
			data->mlx_o_data[i * 1920 + n] = 0x00575757;
			n++;
		}
		i++;
	}
	while (i < 1080)
	{
		n = 0;
		while (n < 1920)
		{
			data->mlx_o_data[i * 1920 + n] = 0x005b95b0;
			n++;
		}
		i++;
	}
}
