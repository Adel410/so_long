/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:43:37 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/03 13:48:14 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_update(t_long *so_long)
{
	ft_animate_banana(so_long);
	ft_animate_tiger(so_long);
	ft_draw_map(so_long);
	return (0);
}

void	ft_frame_tiger(t_long *so_long, int frame)
{
	mlx_destroy_image(so_long->mlx, so_long->img_enemy);
	if (frame == 0)
		so_long->img_enemy = mlx_xpm_file_to_image(so_long->mlx,
				"./sprites/tiger-1.xpm", &so_long->width, &so_long->height);
	else if (frame == 1)
		so_long->img_enemy = mlx_xpm_file_to_image(so_long->mlx,
				"./sprites/tiger-2.xpm", &so_long->width, &so_long->height);
	else if (frame == 2)
		so_long->img_enemy = mlx_xpm_file_to_image(so_long->mlx,
				"./sprites/tiger-3.xpm", &so_long->width, &so_long->height);
	else if (frame == 3)
		so_long->img_enemy = mlx_xpm_file_to_image(so_long->mlx,
				"./sprites/tiger-4.xpm", &so_long->width, &so_long->height);
}

void	ft_animate_tiger(t_long *so_long)
{
	static int		frame;
	static time_t	last_time;
	time_t			current_time;

	if (!frame || !last_time)
	{
		frame = 0;
		last_time = 0;
	}
	time(&current_time);
	if (difftime(current_time, last_time) >= 0.05)
	{
		ft_frame_tiger(so_long, frame);
		frame = (frame + 1) % 4;
		last_time = current_time;
	}
}

void	ft_frame_banana(t_long *so_long, int frame)
{
	mlx_destroy_image(so_long->mlx, so_long->img_item);
	if (frame == 0)
		so_long->img_item = mlx_xpm_file_to_image(so_long->mlx,
				"./sprites/banana1_64x64.xpm", &so_long->width,
				&so_long->height);
	else if (frame == 1)
		so_long->img_item = mlx_xpm_file_to_image(so_long->mlx,
				"./sprites/banana2_64x64.xpm", &so_long->width,
				&so_long->height);
	else if (frame == 2)
		so_long->img_item = mlx_xpm_file_to_image(so_long->mlx,
				"./sprites/banana3_64x64.xpm", &so_long->width,
				&so_long->height);
	else if (frame == 3)
		so_long->img_item = mlx_xpm_file_to_image(so_long->mlx,
				"./sprites/banana4_64x64.xpm", &so_long->width,
				&so_long->height);
	else if (frame == 4)
		so_long->img_item = mlx_xpm_file_to_image(so_long->mlx,
				"./sprites/banana5_64x64.xpm", &so_long->width,
				&so_long->height);
	else if (frame == 5)
		so_long->img_item = mlx_xpm_file_to_image(so_long->mlx,
				"./sprites/banana6_64x64.xpm", &so_long->width,
				&so_long->height);
}

void	ft_animate_banana(t_long *so_long)
{
	static int		frame;
	static time_t	last_time;
	time_t			current_time;

	if (!frame || !last_time)
	{
		frame = 0;
		last_time = 0;
	}
	time(&current_time);
	if (difftime(current_time, last_time) >= 0.05)
	{
		ft_frame_banana(so_long, frame);
		frame = (frame + 1) % 6;
		last_time = current_time;
	}
}
