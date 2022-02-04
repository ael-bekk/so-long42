/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:42:51 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_char_cond(char map, t_char *check, char *name)
{
	if (map != '0' && map != '1' && map != 'E'
		&& map != 'C' && map != 'P' && map != 'Y')
	{
		write(2, "character doesn't exist : ", 27);
		write(2, &map, 1);
		write(2, ".\n", 2);
		exit(1);
	}
	if (map == 'P' && !check->p)
		error_map("more than one player.\n", name);
	if (map == 'P' && check->p)
		check->p = 0;
	if (map == 'E' && check->e)
		check->e = 0;
	if (map == 'C' && check->c)
		check->c = 0;
}

void	check_char(char **map, char *name)
{
	t_char	check;
	int		i;
	int		j;

	i = -1;
	check.p = 1;
	check.e = 1;
	check.c = 1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			check_char_cond(map[i][j], &check, name);
	}
	if (check.p || check.e || check.c)
		error_map("player/coins/exit missing.\n", name);
}

void	check_wall(char *wall, char *name)
{
	int	i;

	i = 0;
	while (wall[i] && wall[i] == '1')
		i++;
	if (wall[i])
		error_map("wall missing\n", name);
}

void	check_walls(char **map, char *name)
{
	int	i;

	i = 0;
	check_wall(map[0], name);
	if (map[1])
	{
		while (map[++i] && map[i + 1])
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				error_map("wall missing\n", name);
		check_wall(map[i], name);
	}
}

void	check_shape(char **map, char *name)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[++i])
		if (len != ft_strlen(map[i]))
			error_map("the map is not in the good shape\n", name);
}
