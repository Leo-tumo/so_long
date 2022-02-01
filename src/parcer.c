/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:35:13 by letumany          #+#    #+#             */
/*   Updated: 2022/01/07 02:40:03 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_walls(void)
{
	int	i;

	i = 0;
	while (i < map.width)
	{
		if (map.maps[0][i] != '1' || map.maps[map.height - 1][i] != '1')
		{
			xerror("Map is not walled");
		}
		i++;
	}
	i = 0;
	while (i < map.height)
	{
		if (map.maps[i][0] != '1' || map.maps[i][map.width - 1] != '1')
		{
			xerror("Map is not walled");
		}
		i++;
	}
}

int	check_av_map(char *av)
{
	if (av[ft_strlen(av) - 1] == 'r' && av[ft_strlen(av) - 2] == 'e'
		&& av[ft_strlen(av) - 3] == 'b' && av[ft_strlen(av) - 4] == '.')
		return (0);
	else
		return (1);
}

void	check_all_data(void)
{
	check_walls();
	if (parce.exit == 0 || parce.food == 0
		|| parce.zero == 0 || parce.wall == 0
		|| parce.pos != 1)
	{
		xerror("Was not set all edificatory or there are repetitions");
	}
}

void	check_errors_arg(int ac, char **av)
{
	if (ac != 2)
		xerror("Less or more than 2 arguments were submitted\n");
	else if (ac == 2)
	{
		if (check_av_map(av[1]))
			xerror("Map is not '.ber' format");
	}
}

void	counter(char c)
{
	if (c == 'C')
	{
		parce.food++;
		map.col++;
	}
	else if (c == 'P')
		parce.pos++;
	else if (c == 'E')
		parce.exit++;
	else if (c == '0')
		parce.zero++;
	else if (c == '1')
		parce.wall++;
}
