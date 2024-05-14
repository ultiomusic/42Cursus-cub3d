#include "cub3d.h"

void	ft_render_map(t_data *data)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			ft_fill_pixel(data, j * 64, i * 64, data->map->map[i][j]);
			j++;
		}
		i++;
	}
}
