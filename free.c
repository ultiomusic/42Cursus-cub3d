/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:23:49 by burkaya           #+#    #+#             */
/*   Updated: 2024/05/25 01:21:24 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_map(t_map *map)
{
	if (map->floor)
		ft_free_array(map->floor);
	if (map->ceiling)
		ft_free_array(map->ceiling);
	if (map->map)
		ft_free_array(map->map);
	if (map->flood_fill)
		ft_free_array(map->flood_fill);
	free(map);
}

void	ft_free_data(t_data *data)
{
	int	i;

	i = 1;
	if (data->map)
		ft_free_map(data->map);
	if (data->ray)
		free(data->ray);
	if (data->images)
	{
		while (data->images[i])
		{
			if (data->images[i]->img)
				mlx_destroy_image(data->mlx_ptr, data->images[i]->img);
			free(data->images[i]);
			i++;
		}
		free(data->images[0]);
		free(data->images);
	}
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	free(data);
}

void	ft_error(char *str, t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	if (data)
		ft_free_data(data);
	exit(0);
}
