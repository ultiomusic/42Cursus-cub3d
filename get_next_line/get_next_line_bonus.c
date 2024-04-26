#include "get_next_line_bonus.h"

char	*read_line(char *str, int fd)
{
	char	*line;
	int		line_i;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	line_i = 1;
	while (ft_strchr(str, '\n') == 0 && line_i != 0)
	{
		line_i = read(fd, line, BUFFER_SIZE);
		if (line_i == -1)
		{
			free(str);
			free(line);
			return (0);
		}
		line[line_i] = '\0';
		str = ft_strjoin(str, line);
	}
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str[fd] = read_line(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = read_first_line(str[fd]);
	str[fd] = next_read(str[fd]);
	return (line);
}