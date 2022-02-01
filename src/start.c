/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:45:03 by letumany          #+#    #+#             */
/*   Updated: 2022/01/07 02:38:23 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_player(void)
{
	int	x;
	int	y;

	player.img = mlx_xpm_file_to_image(data.mlx, PLAYA, &x, &y);
}

void	print_map(void)
{
	data.img = mlx_new_image(data.mlx, map.x, map.y);
	data.addr = mlx_get_data_addr(data.img, &data.bpp,
			&data.line_length, &data.endian);
	get_sprites();
	draw_map();
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	draw_player();
	mlx_put_image_to_window(data.mlx, data.win, player.img, player.x, player.y);
}

void	start_so_long(void)
{
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, map.x, map.y, "so_long");
	print_map();
	mlx_hook(data.win, 2, 1L << 0, key_press_hook, &data);
	mlx_hook(data.win, 17, 1L << 0, close_win, &data);
	mlx_loop_hook(data.mlx, key_hook, &data);
	mlx_loop(data.mlx);
}
