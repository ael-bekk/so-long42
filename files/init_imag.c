/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:27:39 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	all_floor(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			pimg(data, data->img_floor, j * 45, (i + 1) * 45);
	}
}

void	init_imgs_3(t_data *data, char **map, int i, int j)
{
	if (map[i][j] == 'C')
		pimg(data, data->img_coll, j * 45 + 10, (i + 1) * 45 + 10);
	if (map[i][j] == 'E')
		pimg(data, data->img_door, j * 45, (i + 1) * 45 + 5);
	if (map[i][j] == 'Y')
		pimg(data, data->enemy_l.fly->img, j * 45, (i + 1) * 45);
	if (map[i][j] == '0')
		pimg(data, data->img_floor, j * 45, (i + 1) * 45 + 5);
}

void	init_imgs_2(t_data *data, char **map, int i, int j)
{
	void	*img;

	if (map[i][j] == '1')
	{
		if (i && map[i - 1][j] != '1' && map[i - 1][j] != 'E')
			img = data->img_wall2;
		else
			img = data->img_wall;
	}
	if (map[i][j] == 'P')
	{
		img = data->count->img;
		data->player.x = j;
		data->player.y = i + 1;
	}
	if (map[i][j] == 'P' || map[i][j] == '1')
		pimg(data, img, j * 45, (i + 1) * 45);
	init_imgs_3(data, map, i, j);
}

void	init_imgs(char **map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	all_floor(map, data);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			init_imgs_2(data, map, i, j);
	}
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
			if (data->map[i][j] == 'E')
				pimg(data, data->img_door, j * 45, (i + 1) * 45 + 5);
	}
	pimg(data, data->pause, 0, 45);
	pimg(data, data->restart, 0, 100);
	pimg(data, data->set, (data->width - 1) * 45, 45);
	if (data->width > 12)
		pimg(data, pxpm(data, "characters/heart.xpm"), 4 * 45 + 25, 18);
}
