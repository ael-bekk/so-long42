/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:12:53 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/03 11:28:22 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	animat(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'C')
			{
				pimg(data, data->img_floor, j * 45, (i + 1) * 45);
				pimg(data, data->c_col->img, j * 45 + 10, (i + 1) * 45 + 10);
			}
		}
	}
}

void	enemy_rise_2(t_data *data, t_en_pos *enm)
{
	if (enm->dir == 6)
	{
		pimg(data, data->img_floor, enm->x * 45 - enm->mv, enm->y * 45);
		pimg(data, enm->cour->img, enm->x * 45 - enm->mv - 2, enm->y * 45);
	}
	if (enm->dir == 4)
	{
		pimg(data, data->img_floor, enm->x * 45 + enm->mv, enm->y * 45);
		pimg(data, enm->cour->img, enm->x * 45 + enm->mv + 2, enm->y * 45);
	}
	if (enm->dir == 8)
	{
		pimg(data, data->img_floor, enm->x * 45, enm->y * 45 - enm->mv);
		pimg(data, enm->cour->img, enm->x * 45, enm->y * 45 - enm->mv - 2);
	}
	if (enm->dir == 2)
	{
		pimg(data, data->img_floor, enm->x * 45, enm->y * 45 + enm->mv);
		pimg(data, enm->cour->img, enm->x * 45, enm->y * 45 + enm->mv + 2);
	}
	enm->mv += 2;
}

void	enemy_rise_3(t_data *data, t_en_pos *enm)
{
	if (enm->dir == 6)
	{
		pimg(data, data->img_floor, enm->x * 45 - enm->mv, enm->y * 45);
		pimg(data, enm->courent->img, enm->x * 45, enm->y * 45);
	}
	if (enm->dir == 4)
	{
		pimg(data, data->img_floor, enm->x * 45 + enm->mv, enm->y * 45);
		pimg(data, enm->courent->img, enm->x * 45, enm->y * 45);
	}
	if (enm->dir == 8)
	{
		pimg(data, data->img_floor, enm->x * 45, enm->y * 45 - enm->mv);
		pimg(data, enm->courent->img, enm->x * 45, enm->y * 45);
	}
	if (enm->dir == 2)
	{
		pimg(data, data->img_floor, enm->x * 45, enm->y * 45 + enm->mv);
		pimg(data, enm->courent->img, enm->x * 45, enm->y * 45);
	}
	enm->mv += 2;
	data->heart--;
}

void	enemy_rise(t_data *data)
{
	t_en_pos	*enm;

	enm = data->enm;
	while (enm)
	{
		if (enm->att)
			enemy_rise_2(data, enm);
		else
		{
			pimg(data, data->img_floor, enm->x * 45, enm->y * 45);
			pimg(data, enm->cour->img, enm->x * 45, enm->y * 45);
		}
		enm->cour = enm->cour->next;
		if (!enm->cour)
		{
			if (enm->att)
			{
				enemy_rise_3(data, enm);
				enm->att = 0;
				enm->mv = 0;
			}
			enm->cour = enm->courent;
		}
		enm = enm->next;
	}
}

void	past_char(t_data *data, char **map, int i, int j)
{
	if (map[i][j] == '1')
	{
		if (i && map[i - 1][j] != '1' && map[i - 1][j] != 'E')
			pimg(data, data->img_wall2, j * 45, (i + 1) * 45);
		else
			pimg(data, data->img_wall, j * 45, (i + 1) * 45);
	}
	if (map[i][j] == 'E' && --data->door_nb)
		frem_door(data);
	if (map[i][j] == '0')
		pimg(data, data->img_floor, j * 45, (i + 1) * 45);
	if (map[i][j] == 'Y')
	{
		if (!del_from_front(data, &data->enm, i + 1, j))
			delete_enemy(data, &data->enm, i + 1, j);
		pimg(data, data->img_floor, j * 45, (i + 1) * 45);
	}
}
