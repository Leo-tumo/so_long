/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 19:47:37 by letumany          #+#    #+#             */
/*   Updated: 2022/01/05 15:05:36 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	check_errors_arg(argc, argv);
	map_init(argv[1]);
	map_buffer(argv[1]);
	check_all_data();
	start_so_long();
}

void	draw_background(void)
{
	int		x;
	int		y;

	y = 0;
	while (y < map.height * 50)
	{
		x = 0;
		while (x < map.width * 50)
		{
			my_mlx_pixel_put(x, y, 0x38b1c2);
			++x;
		}
		++y;
	}
}

void	draw_norm(int i, int j)
{
	if (map.maps[i][j] == '1')
		draw_asset(j * 50, i * 50, 'w');
	else if (map.maps[i][j] == 'P')
	{
		player.x = j * 50;
		player.y = i * 50;
		map.maps[i][j] = '0';
	}
	else if (map.maps[i][j] == 'C')
		draw_asset(j * 50, i * 50, 'c');
	else if (map.maps[i][j] == 'E')
		draw_asset(j * 50, i * 50, 'e');
	else if (map.maps[i][j] == '0')
		parce.zero++;
	else
	{
		xerror("Unsupported character found in map");
	}	
}

void	draw_map(void)
{
	int		i;
	int		j;

	draw_background();
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			draw_norm(i, j);
			++j;
		}
		++i;
	}
}
