/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 14:35:33 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/01 14:04:24 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

char	*read_and_concat(int fd, char *line)
{
	char	buff[BUFFER_SIZE + 1];
	int		cz;

	cz = 1;
	while (cz > 0)
	{
		cz = read(fd, buff, BUFFER_SIZE);
		if (cz < 0)
		{
			if (line)
				free(line);
			return (NULL);
		}
		buff[cz] = '\0';
		line = ft_strjoin(line, buff);
		if (!line)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = ft_calloc(1, 1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_and_concat(fd, line);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

int	copy_line(char *str, char *map_line, int i)
{
	int	k;

	k = 0;
	while (str[i] && str[i] != '\n')
	{
		map_line[k] = str[i];
		k++;
		i++;
	}
	map_line[k] = '\0';
	return (i);
}

void	ft_stock_map(char *str, t_long *so_long, int count_nl)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	so_long->map = ft_calloc(sizeof(char *), count_nl + 1);
	while (str[i])
	{
		len = get_line_length(str, i);
		so_long->map[j] = ft_calloc(sizeof(char), len + 1);
		i = copy_line(str, so_long->map[j], i);
		if (str[i] == '\n')
		{
			j++;
			i++;
		}
	}
}

void	ft_main_gnl(char *str, t_long *so_long)
{
	int		fd;
	int		len;
	int		count_nl;
	char	*string;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error2(10, so_long);
	string = get_next_line(fd);
	if (string[0] == '\0')
		ft_free_string(string);
	len = 0;
	count_nl = 0;
	while (string[len])
	{
		if (string[len] == '\n')
			count_nl++;
		len++;
	}
	count_nl++;
	ft_stock_map(string, so_long, count_nl);
	free(string);
	close(fd);
}
