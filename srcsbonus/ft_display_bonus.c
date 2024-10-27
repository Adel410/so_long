/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:48:56 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/10/27 15:25:31 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_input(int keysym, t_long *so_long)
{
	static int	i;

	if (keysym == XK_Escape)
	{
		ft_cleanup_images(so_long);
		ft_error2(9, so_long);
	}
	if (!i)
		i = 1;
	if (keysym == XK_w || keysym == XK_s || keysym == XK_a || keysym == XK_d)
	{
		ft_which_move(so_long, keysym);
		ft_printf("Number of moves : %d\n", i);
		i = i + 1;
	}
	return (0);
}

void	ft_cleanup_images(t_long *so_long)
{
	if (so_long->img_wall != NULL)
		mlx_destroy_image(so_long->mlx, so_long->img_wall);
	if (so_long->img_item != NULL)
		mlx_destroy_image(so_long->mlx, so_long->img_item);
	if (so_long->img_exit != NULL)
		mlx_destroy_image(so_long->mlx, so_long->img_exit);
	if (so_long->img_floor != NULL)
		mlx_destroy_image(so_long->mlx, so_long->img_floor);
	if (so_long->img_pdown != NULL)
		mlx_destroy_image(so_long->mlx, so_long->img_pdown);
	if (so_long->img_ptop != NULL)
		mlx_destroy_image(so_long->mlx, so_long->img_ptop);
	if (so_long->img_pleft != NULL)
		mlx_destroy_image(so_long->mlx, so_long->img_pleft);
	if (so_long->img_pright != NULL)
		mlx_destroy_image(so_long->mlx, so_long->img_pright);
	if (so_long->img_enemy != NULL)
		mlx_destroy_image(so_long->mlx, so_long->img_enemy);
}

void	ft_draw_map(t_long *so_long)
{
	int		y;
	int		x;
	void	*img_to_draw;

	x = 0;
	y = 0;
	img_to_draw = NULL;
	while (y < so_long->line_nb)
	{
		x = 0;
		while (x < ft_strlen(so_long->map[y]))
		{
			img_to_draw = ft_which_img(so_long->map[y][x], img_to_draw,
					so_long);
			if (img_to_draw != NULL)
			{
				ft_animate_tiger(so_long);
				mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,
					img_to_draw, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	ft_init_xpm(t_long *so_long, int *width, int *height)
{
	so_long->img_pdown = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/Monkey.xpm", width, height);
	so_long->img_pright = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/Right.xpm", width, height);
	so_long->img_pleft = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/Left.xpm", width, height);
	so_long->img_ptop = mlx_xpm_file_to_image(so_long->mlx, "./sprites/Top.xpm",
			width, height);
	so_long->img_floor = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/floor_64x64.xpm", width, height);
	so_long->img_wall = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/tree_wall_64x64.xpm", width, height);
	so_long->img_exit = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/exit_house_64x64.xpm", width, height);
	so_long->img_item = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/banana8_64x64.xpm", width, height);
	so_long->img_enemy = mlx_xpm_file_to_image(so_long->mlx,
			"./sprites/tigre.xpm", width, height);
	if (ft_sprite_error(so_long) == 0)
		ft_draw_map(so_long);
}

void	ft_window(t_long *so_long)
{
	int	width;
	int	height;

	width = 64;
	height = 64;
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
	{
		ft_free(so_long);
		ft_free2(so_long);
		exit(1);
	}
	so_long->mlx_win = mlx_new_window(so_long->mlx, (so_long->line_len) * 64,
			(so_long->line_nb) * 64, "so_monkey");
	if (!so_long->mlx_win)
		ft_error2(9, so_long);
	ft_init_xpm(so_long, &width, &height);
	mlx_key_hook(so_long->mlx_win, &ft_input, so_long);
	mlx_hook(so_long->mlx_win, 17, 0, close_window, so_long);
	mlx_loop_hook(so_long->mlx, &ft_update, so_long);
	mlx_loop(so_long->mlx);
}
