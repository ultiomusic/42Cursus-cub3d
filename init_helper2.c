/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beeligul <beeligul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:56:52 by burkaya           #+#    #+#             */
/*   Updated: 2024/05/25 01:12:00 by beeligul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_is_multiple_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	read_and_concatenate_map(int fd, char **result)
{
	char	*line;
	char	*tmp;

	tmp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strjoin_gnl(tmp, line);
		free(line);
	}
	*result = tmp;
	return (0);
}

int	process_map_data(t_data *data, char *map_data)
{
	char	**t;
	char	**tmp2;
	char	*_2map;
	int		i;

	t = ft_split_new_lines(map_data);
	data->map->wall_textures = ft_split(t[0], '\n');
	if (ft_tab_len(data->map->wall_textures) != 4)
		return (ft_free_array(t), free(map_data), 1);
	tmp2 = ft_split(t[1], '\n');
	if (ft_tab_len(tmp2) != 2)
		return (ft_free_array(t), ft_free_array(tmp2), free(map_data), 1);
	data->map->floor_str = ft_strdup(tmp2[0]);
	data->map->ceiling_str = ft_strdup(tmp2[1]);
	i = 2;
	_2map = ft_strdup("");
	while (t[i])
	{
		_2map = ft_strjoin_gnl(_2map, t[i]);
		i++;
	}
	data->map->map_str = ft_strtrim(_2map, "\n");
	ft_free_array(t);
	ft_free_array(tmp2);
	return (free(map_data), free(_2map), 0);
}
