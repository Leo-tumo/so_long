/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:36:30 by letumany          #+#    #+#             */
/*   Updated: 2022/01/07 02:41:09 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_win(void)
{
	mlx_destroy_window(data.mlx, data.win);
	free(map.maps);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	dst = data.addr + (y * data.line_length + x * (data.bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned	int	get_pixel(t_data *data, int x, int y)
{
	unsigned int	color;
	char			*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

void	xerror(char *s)
{
	printf("Error :\n%s", s);
	exit (1);
}
