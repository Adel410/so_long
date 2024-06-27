/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:04:36 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/06/21 18:29:28 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_get_row(t_long *so_long)
{
	so_long->line_nb = 0;
	while (so_long->map[so_long->line_nb])
	{
		so_long->line_nb++;
	}
}

void	ft_get_len(t_long *so_long)
{
	int	i;

	so_long->line_len = 0;
	i = 0;
	while (so_long->map[i][so_long->line_len] != '\0')
	{
		so_long->line_len++;
	}
}

void	ft_count_element(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
		{
			if (so_long->map[i][j] == 'E')
				so_long->count_exit++;
			if (so_long->map[i][j] == 'P')
			{
				so_long->player_x = j;
				so_long->player_y = i;
				so_long->count_player++;
			}
			if (so_long->map[i][j] == 'C')
				so_long->count_item++;
			j++;
		}
		i++;
	}
}

void	ft_get_data_map(t_long *so_long)
{
	ft_get_row(so_long);
	ft_get_len(so_long);
	ft_count_element(so_long);
}
