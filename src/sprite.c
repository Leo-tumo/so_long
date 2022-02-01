/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:12:21 by letumany          #+#    #+#             */
/*   Updated: 2022/01/07 02:41:34 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_sprites(void)
{
	int	width;
	int	height;

	assets.w_img = mlx_xpm_file_to_image(data.mlx, WALL, &width, &height);
	if (!assets.w_img)
		xerror("No texture found for wall");
	assets.w_data.addr = mlx_get_data_addr(assets.w_img, &assets.w_data.bpp,
			&assets.w_data.line_length, &assets.w_data.endian);
	assets.e_img = mlx_xpm_file_to_image(data.mlx, EXIT, &width, &height);
	if (!assets.e_img)
		xerror("No texture found for exit");
	assets.e_data.addr = mlx_get_data_addr(assets.e_img, &assets.e_data.bpp,
			&assets.e_data.line_length, &assets.e_data.endian);
	assets.c_img = mlx_xpm_file_to_image(data.mlx, FOOD, &width, &height);
	if (!assets.c_img)
		xerror("No texture found for collectable");
	assets.c_data.addr = mlx_get_data_addr(assets.c_img, &assets.c_data.bpp,
			&assets.c_data.line_length, &assets.c_data.endian);
}

t_data	get_asset(char c)
{
	if (c == 'e')
		return (assets.e_data);
	else if (c == 'c')
		return (assets.c_data);
	else
		return (assets.w_data);
}

void	draw_asset(int x, int y, char asset)
{
	t_data	img;
	int		y1;
	int		x1;

	y1 = 0;
	img = get_asset(asset);
	while (y1 < 50)
	{
		x1 = 0;
		while (x1 < 50)
		{
			if (!get_pixel(&img, x1, y1))
			{
				++x1;
				continue ;
			}
			my_mlx_pixel_put(x + x1, y + y1, get_pixel(&img, x1, y1));
			++x1;
		}
		++y1;
	}
}
