/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:02:59 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/01 14:04:24 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_check_ber(char *av, t_long *so_long)
{
	int	i;

	i = ft_strlen(av);
	if (av[i - 1] == 'r' && av[i - 2] == 'e' && av[i - 3] == 'b' && av[i
			- 4] == '.')
		return (0);
	else
		return (ft_error(1, so_long));
}

void	ft_check_elements(t_long *so_long)
{
	if (so_long->count_player != 1)
		ft_error(2, so_long);
	if (so_long->count_exit != 1)
		ft_error(3, so_long);
	if (so_long->count_item <= 0)
		ft_error(4, so_long);
}

void	ft_check_rectangle(t_long *so_long)
{
	int	i;
	int	j;

	i = 1;
	while (so_long->map[i])
	{
		j = 0;
		while (so_long->map[i][j])
			j++;
		if ((so_long->line_len) != j)
			ft_error(5, so_long);
		i++;
	}
}

void	ft_check_valid_char(t_long *so_long)
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
			if (so_long->map[i][j] != '1' && so_long->map[i][j] != '0'
				&& so_long->map[i][j] != 'E' && so_long->map[i][j] != 'P'
				&& so_long->map[i][j] != 'C' && so_long->map[i][j] != '\n'
				&& so_long->map[i][j] != '\n' && so_long->map[i][j] != 'F')
			{
				ft_error2(7, so_long);
			}
			j++;
		}
		i++;
	}
}

void	ft_map_checker(t_long *so_long)
{
	ft_check_elements(so_long);
	ft_check_rectangle(so_long);
	ft_toplane(so_long);
	ft_sidelane(so_long);
	ft_botlane(so_long);
	ft_check_valid_char(so_long);
}
