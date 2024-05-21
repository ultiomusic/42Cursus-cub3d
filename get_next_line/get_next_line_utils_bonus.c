/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:39:30 by codespace         #+#    #+#             */
/*   Updated: 2024/05/21 15:39:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	c;
	size_t	i;
	char	*new_str;

	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	new_str = malloc(sizeof(char) * ((ft_strlen(str)) + ft_strlen(buff) + 1));
	if (new_str == NULL)
		return (NULL);
	c = -1;
	i = 0;
	if (str)
		while (str[++c] != '\0')
			new_str[c] = str[c];
	while (buff[i] != '\0')
		new_str[c++] = buff[i++];
	new_str[c] = '\0';
	free(str);
	return (new_str);
}

char	*read_first_line(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	new_str = malloc(sizeof(char) * (i + 2));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new_str[i++] = '\n';
	new_str[i] = 0;
	return (new_str);
}

char	*next_read(char *str)
{
	int		i;
	int		j;
	char	*next_str;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == 0)
	{
		free(str);
		return (NULL);
	}
	next_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!next_str)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		next_str[j++] = str[i++];
	next_str[j] = 0;
	free(str);
	return (next_str);
}
