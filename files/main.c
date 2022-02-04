/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:39:08 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	entre_map(char *map)
{
	int		fd;
	char	*line;
	char	*join;
	char	**split;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	join = NULL;
	while (line)
	{
		join = ft_gnl_strjoin(join, line);
		line = get_next_line(fd);
	}
	split = ft_split(join, '\n');
	free(join);
	display_map(split, map);
	free_split(split);
	close(fd);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		error_map("you need a map.\n", "no map");
	if (ac > 2)
		error_map("you need just one map.\n", "no map");
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
		error_map("map have a wrong extention.\n", av[1]);
	valid_map(av[1]);
	entre_map(av[1]);
	return (0);
}
