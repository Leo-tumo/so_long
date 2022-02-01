/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:44:50 by letumany          #+#    #+#             */
/*   Updated: 2022/01/05 13:45:49 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	go_up(void)
{
	player.y -= 50;
	printf("Step: %d\n", ++player.steps);
}

void	go_down(void)
{
	player.y += 50;
	printf("Step: %d\n", ++player.steps);
}

int	key_press_hook(int keycode)
{
	if (keycode == 13)
		move_up();
	if (keycode == 1)
		move_down();
	if (keycode == 0)
		move_left();
	if (keycode == 2)
		move_right();
	if (keycode == 53)
		close_win();
	return (0);
}

void	move_up(void)
{
	if (map.maps[player.y / 50 - 1][player.x / 50] == '0')
		go_up();
	else if (map.maps[player.y / 50 - 1][player.x / 50] == 'C')
	{
		map.maps[player.y / 50 - 1][player.x / 50] = '0';
		go_up();
		map.col--;
	}
	else if (map.maps[player.y / 50 - 1][player.x / 50] == 'E')
	{
		go_up();
		if (map.col == 0)
		{
			printf("You finished with %d steps, congrats\n", ++player.steps);
			close_win();
		}
	}
}

void	move_down(void)
{
	if (map.maps[player.y / 50 + 1][player.x / 50] == '0')
		go_down();
	else if (map.maps[player.y / 50 + 1][player.x / 50] == 'C')
	{
		map.maps[player.y / 50 + 1][player.x / 50] = '0';
		go_down();
		map.col--;
	}
	else if (map.maps[player.y / 50 + 1][player.x / 50] == 'E')
	{
		if (map.col == 0)
		{
			go_down();
			printf("You finished with %d steps, congrats\n", ++player.steps);
			close_win();
		}
		else
			go_down();
	}
}
