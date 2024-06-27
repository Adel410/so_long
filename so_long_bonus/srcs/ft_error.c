/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:01:03 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/06/24 15:11:58 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_error(int i, t_long *so_long)
{
	if (i == 1)
	{
		ft_putstr("Error\nWrong map extension\n");
	}
	else if (i == 2)
	{
		ft_putstr("Error\nWrong number of player\n");
		ft_free(so_long);
	}
	else if (i == 3)
	{
		ft_putstr("Error\nWrong number of exit\n");
		ft_free(so_long);
	}
	else if (i == 4)
	{
		ft_putstr("Error\nNot enough collectible\n");
		ft_free(so_long);
	}
	else if (i == 5)
	{
		ft_putstr("Error\nMap is not a rectangle\n");
		ft_free(so_long);
	}
	exit(0);
}

int	ft_error2(int i, t_long *so_long)
{
	if (i == 6)
	{
		ft_putstr("Error\nMap is not closed\n");
		ft_free(so_long);
	}
	if (i == 7)
	{
		ft_putstr("Error\nMap contain wrong character(s)\n");
		ft_free(so_long);
	}
	if (i == 8)
	{
		ft_putstr("Error\nMap is impossible\n");
		ft_free(so_long);
		ft_free2(so_long);
	}
	if (i == 9)
	{
		ft_free(so_long);
		ft_free2(so_long);
	}
	if (i == 10)
		ft_printf("Error\nMap not found\n");
	exit(0);
}

int	ft_finish(t_long *so_long)
{
	ft_printf("Congratulations !!!\n");
	ft_cleanup_images(so_long);
	ft_free(so_long);
	ft_free2(so_long);
	exit(0);
}

int	ft_game_over(t_long *so_long)
{
	ft_printf("Game Over\n");
	ft_cleanup_images(so_long);
	ft_free(so_long);
	ft_free2(so_long);
	exit(0);
}
