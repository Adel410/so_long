/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:19:01 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/01 14:04:24 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_which_move(t_long *so_long, int keysym)
{
	static int	item;

	if (!item)
		item = 0;
	if (keysym == XK_w)
		item = ft_move_up(so_long, item);
	if (keysym == XK_s)
		item = ft_move_down(so_long, item);
	if (keysym == XK_a)
		item = ft_move_left(so_long, item);
	if (keysym == XK_d)
		item = ft_move_right(so_long, item);
	ft_draw_map(so_long);
	return (item);
}

int	ft_move_up(t_long *so_long, int item)
{
	int	x;
	int	y;

	x = so_long->player_x;
	y = so_long->player_y - 1;
	if (so_long->map[y][x] != '1')
	{
		if (so_long->map[y][x] == 'E' && item != so_long->count_item)
			return (item);
		if (so_long->map[y][x] == 'C')
			item = item + 1;
		if (so_long->map[y][x] == 'F')
			ft_game_over(so_long);
		if (so_long->map[y][x] == 'E' && item == so_long->count_item)
			ft_finish(so_long);
		so_long->map[y][x] = 'P';
		so_long->map[so_long->player_y][x] = '0';
		so_long->player_y = y;
	}
	else
		ft_printf("Move not allowed.\n");
	so_long->direction = 'W';
	return (item);
}

int	ft_move_down(t_long *so_long, int item)
{
	int	x;
	int	y;

	x = so_long->player_x;
	y = so_long->player_y + 1;
	if (so_long->map[y][x] != '1')
	{
		if (so_long->map[y][x] == 'E' && item != so_long->count_item)
			return (item);
		if (so_long->map[y][x] == 'C')
			item = item + 1;
		if (so_long->map[y][x] == 'F')
			ft_game_over(so_long);
		if (so_long->map[y][x] == 'E' && item == so_long->count_item)
			ft_finish(so_long);
		so_long->map[y][x] = 'P';
		so_long->map[so_long->player_y][x] = '0';
		so_long->player_y = y;
	}
	else
		ft_printf("Move not allowed.\n");
	so_long->direction = 'S';
	return (item);
}

int	ft_move_right(t_long *so_long, int item)
{
	int	x;
	int	y;

	x = so_long->player_x + 1;
	y = so_long->player_y;
	if (so_long->map[y][x] != '1')
	{
		if (so_long->map[y][x] == 'E' && item != so_long->count_item)
			return (item);
		if (so_long->map[y][x] == 'C')
			item = item + 1;
		if (so_long->map[y][x] == 'F')
			ft_game_over(so_long);
		if (so_long->map[y][x] == 'E' && item == so_long->count_item)
			ft_finish(so_long);
		so_long->map[y][x] = 'P';
		so_long->map[y][so_long->player_x] = '0';
		so_long->player_x = x;
	}
	else
		ft_printf("Move not allowed.\n");
	so_long->direction = 'D';
	return (item);
}

int	ft_move_left(t_long *so_long, int item)
{
	int	x;
	int	y;

	x = so_long->player_x - 1;
	y = so_long->player_y;
	if (so_long->map[y][x] != '1')
	{
		if (so_long->map[y][x] == 'E' && item != so_long->count_item)
			return (item);
		if (so_long->map[y][x] == 'C')
			item = item + 1;
		if (so_long->map[y][x] == 'F')
			ft_game_over(so_long);
		if (so_long->map[y][x] == 'E' && item == so_long->count_item)
			ft_finish(so_long);
		so_long->map[y][x] = 'P';
		so_long->map[y][so_long->player_x] = '0';
		so_long->player_x = x;
	}
	else
		ft_printf("Move not allowed.\n");
	so_long->direction = 'A';
	return (item);
}
