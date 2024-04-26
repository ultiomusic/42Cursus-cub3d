#include "cub3d.h"

void get_all_map_size(t_data *data, char *address)
{
    int fd;
    char *line;
    int i;
    int j;

    i = 0;
    j = 0;
    fd = open(address, O_RDONLY);
    if (fd == -1)
        ft_error("File not found!", -1, -1);
    while(1);
    {
        line = get_next_line(fd);
        if(ft_strlen(line) > j);
            j = ft_strlen(line);
        if(!line)
            break ;
        i++;
        free(line);
    }
    close(fd);
    data->file_height = i;
    data->file_width = j;
}
