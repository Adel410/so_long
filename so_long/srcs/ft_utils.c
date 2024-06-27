/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:01:27 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/06/22 23:05:49 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_free(t_long *so_long)
{
	int	i;

	i = 0;
	if (so_long->map)
	{
		while (so_long->map[i])
		{
			free(so_long->map[i]);
			i++;
		}
		free(so_long->map);
		so_long->map = NULL;
	}
	if (so_long->mlx)
	{
		if (so_long->mlx_win)
		{
			mlx_destroy_window(so_long->mlx, so_long->mlx_win);
			so_long->mlx_win = NULL;
		}
		mlx_destroy_display(so_long->mlx);
		free(so_long->mlx);
		so_long->mlx = NULL;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	size_t			i;
	unsigned char	*tab;

	total_size = nmemb * size;
	tab = malloc(total_size);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t						i;
	unsigned char				*dest_char;
	unsigned char				*src_char;

	if (!dest && !src)
	{
		return (NULL);
	}
	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		i++;
	}
	return (dest);
}

void	ft_init_struct(t_long *so_long)
{
	so_long->count_item = 0;
	so_long->count_exit = 0;
	so_long->count_player = 0;
	so_long->line_nb = 0;
	so_long->line_len = 0;
	so_long->mlx = NULL;
	so_long->mlx_win = NULL;
	so_long->direction = 'S';
}
