/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:51:39 by codespace         #+#    #+#             */
/*   Updated: 2024/05/21 17:47:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_casting(t_data *data)
{
	int	x;

	x = 0;
	while (x < SCREENWIDTH)
	{
		data->ray->camerax = 2 * x / (double)SCREENWIDTH - 1;
		data->ray->raydirx = data->ray->dirx + data->ray->planex
			* data->ray->camerax;
		data->ray->raydiry = data->ray->diry + data->ray->planey
			* data->ray->camerax;
		data->ray->map_x = (int)data->ray->posx;
		data->ray->map_y = (int)data->ray->posy;
		data->ray->deltadistx = fabs(1 / data->ray->raydirx);
		data->ray->deltadisty = fabs(1 / data->ray->raydiry);
		ft_send_ray(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->mlx_img, 0, 0);
}
