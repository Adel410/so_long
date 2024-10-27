/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:21:21 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/01 14:04:24 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_long	so_long;

	(void)argv;
	if (argc == 2)
	{
		ft_check_ber(argv[1], &so_long);
		ft_init_struct(&so_long);
		ft_main_gnl(argv[1], &so_long);
		ft_get_data_map(&so_long);
		ft_map_checker(&so_long);
		ft_floodcall(&so_long);
		ft_window(&so_long);
	}
	else
		write(1, "Please send a map\n", 18);
}
