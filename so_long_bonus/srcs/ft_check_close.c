/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:31:31 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/06/21 15:12:44 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_toplane(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (so_long->map[i][j] != '\0')
	{
		if (so_long->map[i][j] != '1')
		{
			ft_error2(6, so_long);
		}
		j++;
	}
}

void	ft_sidelane(t_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->map[i])
	{
		if (so_long->map[i][0] == '1')
			i++;
		else
			ft_error2(6, so_long);
	}
	i = so_long->line_len - 1;
	j = 0;
	while (so_long->map[j])
	{
		if (so_long->map[j][i] == '1')
			j++;
		else
			ft_error2(6, so_long);
	}
}

void	ft_botlane(t_long *so_long)
{
	int	j;
	int	i;

	i = so_long->line_nb - 1;
	j = 0;
	while (so_long->map[i][j])
	{
		if (so_long->map[i][j] != '1' && so_long->map[i][j] != '\n')
			ft_error2(6, so_long);
		j++;
	}
}
