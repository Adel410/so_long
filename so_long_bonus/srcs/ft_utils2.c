/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:43:17 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/06/27 13:59:38 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free2(t_long *so_long)
{
	int	i;

	i = 0;
	if (so_long->checker)
	{
		while (so_long->checker[i])
		{
			free(so_long->checker[i]);
			i++;
		}
		free(so_long->checker);
	}
	if (so_long->str)
		free(so_long->str);
}

void	*ft_which_img(char c, void *img_to_draw, t_long *so_long)
{
	if (c == '1')
		img_to_draw = so_long->img_wall;
	else if (c == 'P')
	{
		if (so_long->direction == 'S')
			img_to_draw = so_long->img_pdown;
		else if (so_long->direction == 'W')
			img_to_draw = so_long->img_ptop;
		else if (so_long->direction == 'A')
			img_to_draw = so_long->img_pleft;
		else if (so_long->direction == 'D')
			img_to_draw = so_long->img_player_right;
	}
	else if (c == 'C')
		img_to_draw = so_long->img_item;
	else if (c == 'E')
		img_to_draw = so_long->img_exit;
	else if (c == '0')
		img_to_draw = so_long->img_floor;
	else if (c == 'F')
		img_to_draw = so_long->img_enemy;
	return (img_to_draw);
}

int	mouse_handler(int button, int x, int y, t_long *so_long)
{
	(void)x;
	(void)y;
	if (button == 1)
	{
		mlx_destroy_window(so_long->mlx, so_long->mlx_win);
		exit(0);
	}
	return (0);
}

int	close_window(t_long *so_long)
{
	ft_cleanup_images(so_long);
	ft_free(so_long);
	ft_free2(so_long);
	exit(0);
}

void	ft_free_string(char *str)
{
	ft_printf("Map is empty\n");
	free(str);
	exit(1);
}
