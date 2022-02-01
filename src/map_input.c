/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:16:46 by letumany          #+#    #+#             */
/*   Updated: 2022/01/05 13:48:31 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_length(int fd)
{
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		i++;
	}
	map.width = i;
}

void	map_height(int fd)
{
	char	*line;
	int		i;

	i = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if ((int)ft_strlen(line) != map.width)
		{
			xerror("Map ain't rectangular");
		}
		free(line);
		++i;
	}
	map.height = ++i;
	if ((int)ft_strlen(line) != map.width)
		xerror("Map ain't rectangular");
	free(line);
}

void	map_init(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	map_length(fd);
	map_height(fd);
	map.x = map.width * 50;
	map.y = map.height * 50;
	close(fd);
}

void	count_food(void)
{
	int		i;
	int		j;

	player.steps = 0;
	map.col = 0;
	parce.exit = 0;
	parce.pos = 0;
	parce.food = 0;
	parce.zero = 0;
	parce.wall = 0;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			counter(map.maps[i][j]);
			++j;
		}
		++i;
	}
}

void	map_buffer(char *filename)
{
	int		i;
	int		fd;

	fd = open(filename, O_RDONLY);
	i = 0;
	map.maps = (char **)malloc(sizeof(char *) * map.height + 1);
	while (i < map.height)
	{
		get_next_line(fd, &map.maps[i]);
		++i;
	}
	count_food();
	close(fd);
}
