/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:36:44 by letumany          #+#    #+#             */
/*   Updated: 2022/01/07 02:40:44 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(void)
{
	mlx_destroy_image(data.mlx, data.img);
	print_map();
	return (0);
}

void	go_left(void)
{
	player.x -= 50;
	printf("Step: %d\n", ++player.steps);
}

void	go_right(void)
{
	player.x += 50;
	printf("Step: %d\n", ++player.steps);
}

void	move_left(void)
{
	if (map.maps[player.y / 50][player.x / 50 - 1] == '0')
		go_left();
	else if (map.maps[player.y / 50][player.x / 50 - 1] == 'C')
	{
		map.maps[player.y / 50][player.x / 50 - 1] = '0';
		go_left();
		map.col--;
	}
	else if (map.maps[player.y / 50][player.x / 50 - 1] == 'E')
	{
		if (map.col == 0)
		{
			go_left();
			printf("You finished with %d steps, congrats\n", ++player.steps);
			close_win();
		}
		else
			go_left();
	}
}

void	move_right(void)
{
	if (map.maps[player.y / 50][player.x / 50 + 1] == '0')
		go_right();
	else if (map.maps[player.y / 50][player.x / 50 + 1] == 'C')
	{
		map.maps[player.y / 50][player.x / 50 + 1] = '0';
		go_right();
		map.col--;
	}
	else if (map.maps[player.y / 50][player.x / 50 + 1] == 'E')
	{
		go_right();
		if (map.col == 0)
		{
			printf("You finished with %d steps, congrats\n", ++player.steps);
			close_win();
		}
	}
}
