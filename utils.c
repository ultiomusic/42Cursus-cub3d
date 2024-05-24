/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 02:05:09 by beeligul          #+#    #+#             */
/*   Updated: 2024/05/24 02:05:10 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_floor_and_ceiling(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < SCREENHEIGHT / 2)
	{
		n = 0;
		while (n < SCREENWIDTH)
		{
			data->mlx_o_data[i * SCREENWIDTH + n] = data->map->ceiling_color;
			n++;
		}
		i++;
	}
	while (i < SCREENHEIGHT)
	{
		n = 0;
		while (n < SCREENWIDTH)
		{
			data->mlx_o_data[i * SCREENWIDTH + n] = data->map->floor_color;
			n++;
		}
		i++;
	}
}

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
