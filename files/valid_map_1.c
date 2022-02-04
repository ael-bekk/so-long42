/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:42:19 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	valid(char **map, char *name)
{
	check_shape(map, name);
	check_walls(map, name);
	check_char(map, name);
}

void	valid_map(char *map)
{
	int		fd;
	char	*line;
	char	*join;
	char	**split;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_map("file doesn't exist.\n", map);
	line = get_next_line(fd);
	if (line == NULL || line[0] == '\n')
		error_map("empty file.\n", map);
	join = NULL;
	while (line)
	{
		join = ft_gnl_strjoin(join, line);
		line = get_next_line(fd);
	}
	split = ft_split(join, '\n');
	free(join);
	valid(split, map);
	free_split(split);
	close(fd);
}

void	test_all_maps_valid(char **maps, int ac)
{
	int	i;

	i = -1;
	while (++i < ac)
		if (!ft_strnstr(maps[i], ".ber", ft_strlen(maps[i])))
			error_map("map have a wrong extention.\n", maps[i]);
	i = -1;
	while (++i < ac)
		valid_map(maps[i]);
}
