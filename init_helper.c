/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:46:45 by codespace         #+#    #+#             */
/*   Updated: 2024/05/24 01:39:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_floor_ceiling(t_data *data)
{
	data->map->floor = ft_split(data->map->floor_str + 2, ',');
	data->map->ceiling = ft_split(data->map->ceiling_str + 2, ',');
	data->map->floor_color = ft_atoi(data->map->floor[0]) * 65536 + \
		ft_atoi(data->map->floor[1]) * 256 + ft_atoi(data->map->floor[2]);
	data->map->ceiling_color = ft_atoi(data->map->ceiling[0]) * 65536 + \
		ft_atoi(data->map->ceiling[1]) * 256 + ft_atoi(data->map->ceiling[2]);
}

int	ft_get_longest_index(char **map)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

void	ft_create_map(t_data *data)
{
	char		*tmp;

	tmp = ft_strdup("");
	if (ft_is_multiple_map(data->map->map_str))
	{
		printf("Error\nMultiple maps detected\n");
		exit(1);
	}
	data->map->map = ft_split(data->map->map_str, '\n');
	data->map->flood_fill = ft_split(data->map->map_str, '\n');
	data->map->map_x = ft_get_longest_index(data->map->map);
	data->map->map_y = ft_tab_len(data->map->map);
}

void	ft_free_images(t_data *data, int max)
{
	int	i;

	i = 1;
	while (i < max)
	{
		if (data->images[i])
			free(data->images[i]);
		i++;
	}
	free(data->images);
}

void	ft_init_ray(t_ray *ray)
{
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->perpwalldist = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side = 0;
	ray->wall = 0;
	ray->raydirx = 0;
	ray->raydiry = 0;
}
