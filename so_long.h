/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:58:11 by letumany          #+#    #+#             */
/*   Updated: 2022/01/05 20:59:39 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define WALL "png/wall.xpm"
# define EXIT "png/exit2.xpm"
# define FOOD "png/food2.xpm"
# define PLAYA "png/playa.xpm"

# include "./libs/minilibx_mms/mlx.h"
# include "./libs/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

struct		s_data_norm
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
} data;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

struct		s_parce
{
	int		food;
	int		wall;
	int		pos;
	int		exit;
	int		zero;
}	parce;

struct		s_map
{
	int		width;
	int		height;
	int		x;
	int		y;
	int		col;
	char	**maps;
}	map;

struct		s_player
{
	int		x;
	int		y;
	void	*img;
	int		steps;
}	player;

struct		s_asset_paths
{
	char		*wall;
	void		*w_img;
	t_data		w_data;
	char		*exit;
	void		*e_img;
	t_data		e_data;
	char		*collectable;
	void		*c_img;
	t_data		c_data;
}	assets;

int				close_win(void);
void			xerror(char *s);
void			start_so_long(void);
void			my_mlx_pixel_put(int x, int y, int color);
int				key_press_hook(int keycode);
int				key_hook(void);
void			print_map(void);
void			map_init(char *filename);
void			map_buffer(char *filename);
void			draw_map(void);
void			move_up(void);
void			move_down(void);
void			move_left(void);
void			move_right(void);
void			draw_walls(void);
unsigned int	get_pixel(t_data *data, int x, int y);
void			draw_asset(int x, int y, char asset);
void			get_sprites(void);
void			check_errors_arg(int ac, char **av);
void			check_all_data(void);
void			counter(char c);

#endif