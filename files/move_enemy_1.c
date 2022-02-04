/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:53:43 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	mv_enemy_top_down(t_data *data, t_en_pos *enemy)
{
	int	y;
	int	save;

	save = enemy->save;
	y = enemy->y;
	if (enemy->top)
		en_top(data, enemy);
	else
		en_down(data, enemy);
	if (save && y != enemy->y)
		data->map[y - 1][enemy->x] = 'C';
	else if (y != enemy->y)
		data->map[y - 1][enemy->x] = '0';
	pimg(data, data->img_floor, enemy->x * 45, y * 45);
	pimg(data, enemy->cour->img, enemy->x * 45, enemy->y * 45);
	data->map[data->player.y - 1][data->player.x] = 'P';
}

void	mv_enemy_left_right(t_data *data, t_en_pos *enemy)
{
	int	x;
	int	save;

	save = enemy->save;
	x = enemy->x;
	if (enemy->right)
		en_right(data, enemy);
	else
		en_left(data, enemy);
	if (save && x != enemy->x)
		data->map[enemy->y - 1][x] = 'C';
	else if (x != enemy->x)
		data->map[enemy->y - 1][x] = '0';
	pimg(data, data->img_floor, x * 45, enemy->y * 45);
	pimg(data, enemy->cour->img, enemy->x * 45, enemy->y * 45);
	data->map[data->player.y - 1][data->player.x] = 'P';
}

int	player_near2(t_data *data, t_en_pos *enm, int valid)
{
	if (enm->x - data->player.x >= -3 && enm->x - data->player.x < 0
		&& enm->y == data->player.y && ++valid)
	{
		if (enm->x - data->player.x == -1)
			return (attack_types(data, enm, 4));
		chang_right(data, enm);
		mv_enemy_left_right(data, enm);
	}
	if (enm->x - data->player.x <= 3 && enm->x - data->player.x > 0
		&& enm->y == data->player.y && ++valid)
	{
		if (enm->x - data->player.x == 1)
			return (attack_types(data, enm, 6));
		chang_left(data, enm);
		mv_enemy_left_right(data, enm);
	}
	return (valid);
}

int	player_near(t_data *data, t_en_pos *enm, int valid)
{
	valid = player_near2(data, enm, valid);
	if (enm->y - data->player.y >= -3 && enm->y - data->player.y < 0
		&& enm->x == data->player.x && ++valid)
	{
		if (enm->y - data->player.y == -1)
			return (attack_types(data, enm, 2));
		chang_down(enm);
		mv_enemy_top_down(data, enm);
	}
	if (enm->y - data->player.y <= 3 && enm->y - data->player.y > 0
		&& enm->x == data->player.x && ++valid)
	{
		if (enm->y - data->player.y == 1)
			return (attack_types(data, enm, 8));
		chang_top(enm);
		mv_enemy_top_down(data, enm);
	}
	return (valid);
}

void	move_enemy(t_data *data)
{
	t_en_pos	*enm;

	enm = data->enm;
	while (enm)
	{
		if (!player_near(data, enm, 0))
		{
			if (data->dir % 5)
				mv_enemy_top_down(data, enm);
			else
				mv_enemy_left_right(data, enm);
		}
		data->dir++;
		enm = enm->next;
	}
	put_heart(data);
}
