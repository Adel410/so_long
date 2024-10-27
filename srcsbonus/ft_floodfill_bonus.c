/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:08:04 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/01 14:04:24 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_floodfill(t_long *so_long, int x, int y, char **checker)
{
	static int	nb_item;

	if (!nb_item)
		nb_item = 0;
	if (x < 0 || x >= so_long->line_nb || y < 0 || y >= so_long->line_len
		|| so_long->map[x][y] == '1' || checker[x][y] == 'X')
		return (-1);
	if ((so_long->map[x][y] == 'E' && nb_item != so_long->count_item)
		|| so_long->map[x][y] == 'F')
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

static int	ft_get_str_len(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count ++;
	else if (n == 0)
		count ++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	long	num;

	num = n;
	i = ft_get_str_len(n);
	ptr = (char *)ft_calloc(i + 1, 1);
	if (ptr == NULL)
		return (NULL);
	ptr[i] = '\0';
	i = ft_get_str_len(n) - 1;
	if (num == 0)
		ptr[0] = '0';
	if (num < 0)
	{
		ptr[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		ptr[i] = (num % 10) + '0';
		num = num / 10;
		i--;
	}
	return (ptr);
}
