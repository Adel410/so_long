/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadj-ar <ahadj-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:18:30 by ahadj-ar          #+#    #+#             */
/*   Updated: 2024/07/29 13:32:54 by ahadj-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/include/ft_printf.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_long
{
	char	**map;
	char	**checker;
	char	direction;
	int		line_nb;
	int		line_len;
	int		count_player;
	int		count_item;
	int		count_exit;
	int		player_x;
	int		player_y;
	void	*mlx;
	void	*mlx_win;
	void	*img_player_down;
	void	*img_player_top;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_floor;
	void	*img_wall;
	void	*img_exit;
	void	*img_item;
}			t_long;

int			ft_check_ber(char *av, t_long *so_long);
int			main(int argc, char *argv[]);
int			ft_strlen(char *str);
int			ft_error(int i, t_long *so_long);
int			ft_error2(int i, t_long *so_long);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *str, int searched);
char		*ft_strdup(char *src);
void		ft_strncpy(char *dest, const char *src, int n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_main_gnl(char *str, t_long *so_long);
void		ft_get_row(t_long *so_long);
void		ft_free(t_long *so_long);
void		ft_secu(t_long *so_long);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_get_data_map(t_long *so_long);
void		ft_count_element(t_long *so_long);
void		ft_init_struct(t_long *so_long);
void		ft_check_elements(t_long *so_long);
void		ft_map_checker(t_long *so_long);
void		ft_toplane(t_long *so_long);
void		ft_botlane(t_long *so_long);
void		ft_sidelane(t_long *so_long);
void		ft_window(t_long *so_long);
void		ft_destroy(t_long *so_long);
void		ft_free2(t_long *so_long);
void		ft_floodcall(t_long *so_long);
void		ft_cleanup_images(t_long *so_long);
int			get_line_length(char *str, int i);
int			ft_move_down(t_long *so_long, int item);
int			ft_move_up(t_long *so_long, int item);
int			ft_move_left(t_long *so_long, int item);
int			ft_move_right(t_long *so_long, int item);
int			ft_finish(t_long *so_long);
int			ft_game_over(t_long *so_long);
void		ft_draw_map(t_long *so_long);
int			ft_which_move(t_long *so_long, int keysym);
void		*ft_which_img(char c, void *img_to_draw, t_long *so_long);
int			mouse_handler(int button, int x, int y, t_long *so_long);
int			close_window(t_long *so_long);
void		ft_free_string(char *str);
int			ft_sprite_error(t_long *so_long);
#endif