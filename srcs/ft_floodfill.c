/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:08:04 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/06/23 17:08:26 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_floodfill(t_long *so_long, int x, int y, char **checker)
{
	static int	nb_item;

	if (!nb_item)
		nb_item = 0;
	if (x < 0 || x >= so_long->line_nb || y < 0 || y >= so_long->line_len
		|| so_long->map[x][y] == '1' || checker[x][y] == 'X')
		return (-1);
	if (so_long->map[x][y] == 'E' && nb_item != so_long->count_item)
		return (-1);
	checker[x][y] = 'X';
	if (so_long->map[x][y] == 'E' && nb_item == so_long->count_item)
		return (0);
	if (so_long->map[x][y] == 'C')
		nb_item++;
	if (ft_floodfill(so_long, x + 1, y, checker) == 0 || ft_floodfill(so_long, x
			- 1, y, checker) == 0 || ft_floodfill(so_long, x, y + 1,
			checker) == 0 || ft_floodfill(so_long, x, y - 1, checker) == 0)
		return (0);
	else
		return (-1);
}

char	**ft_duplicate(t_long *so_long)
{
	char	**checker;
	int		i;

	i = 0;
	checker = ft_calloc(sizeof(char *), so_long->line_nb + 1);
	while (so_long->map[i])
	{
		checker[i] = ft_strdup(so_long->map[i]);
		i++;
	}
	return (checker);
}

void	ft_floodcall(t_long *so_long)
{
	int	res;

	so_long->checker = ft_duplicate(so_long);
	res = 0;
	res = ft_floodfill(so_long, so_long->player_y, so_long->player_x,
			so_long->checker);
	if (res == -1)
		ft_error2(8, so_long);
}
