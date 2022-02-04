/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:55:38 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	en_top(t_data *data, t_en_pos *enemy)
{
	int	y;

	y = enemy->y;
	if (data->map[enemy->y - 2][enemy->x] == '1'
	|| data->map[enemy->y - 2][enemy->x] == 'E'
	|| data->map[enemy->y - 2][enemy->x] == 'Y')
	{
		chang_down(enemy);
		if (data->map[enemy->y][enemy->x] != '1'
		&& data->map[enemy->y][enemy->x] != 'E'
		&& data->map[enemy->y][enemy->x] != 'Y')
			enemy->y++;
	}
	else
		enemy->y--;
	if (data->map[enemy->y - 1][enemy->x] == 'P')
		data->heart--;
	if (data->map[enemy->y - 1][enemy->x] == 'C' && y != enemy->y)
		enemy->save = 1;
	else if (y != enemy->y)
		enemy->save = 0;
	data->map[enemy->y - 1][enemy->x] = 'Y';
}

void	en_down(t_data *data, t_en_pos *enemy)
{
	int	y;

	y = enemy->y;
	if (data->map[enemy->y][enemy->x] == '1'
	|| data->map[enemy->y][enemy->x] == 'E'
	|| data->map[enemy->y][enemy->x] == 'Y')
	{
		chang_top(enemy);
		if (data->map[enemy->y - 2][enemy->x] != '1'
		&& data->map[enemy->y - 2][enemy->x] != 'E'
		&& data->map[enemy->y - 2][enemy->x] != 'Y')
			enemy->y--;
	}
	else
		enemy->y++;
	if (data->map[enemy->y - 1][enemy->x] == 'P')
		data->heart--;
	if (data->map[enemy->y - 1][enemy->x] == 'C' && y != enemy->y)
		enemy->save = 1;
	else if (y != enemy->y)
		enemy->save = 0;
	data->map[enemy->y - 1][enemy->x] = 'Y';
}

void	en_right(t_data *data, t_en_pos *enemy)
{
	int	x;

	x = enemy->x;
	if (data->map[enemy->y - 1][enemy->x + 1] == '1'
	|| data->map[enemy->y - 1][enemy->x + 1] == 'E'
	|| data->map[enemy->y - 1][enemy->x + 1] == 'Y')
	{
		chang_left(data, enemy);
		if (data->map[enemy->y - 1][enemy->x - 1] != '1'
		&& data->map[enemy->y - 1][enemy->x - 1] != 'E'
		&& data->map[enemy->y - 1][enemy->x - 1] != 'Y')
			enemy->x--;
	}
	else
		enemy->x++;
	if (data->map[enemy->y - 1][enemy->x] == 'P')
		data->heart--;
	if (data->map[enemy->y - 1][enemy->x] == 'C' && x != enemy->x)
		enemy->save = 1;
	else if (x != enemy->x)
		enemy->save = 0;
	data->map[enemy->y - 1][enemy->x] = 'Y';
}

void	en_left(t_data *data, t_en_pos *enemy)
{
	int	x;

	x = enemy->x;
	if (data->map[enemy->y - 1][enemy->x - 1] == '1'
	|| data->map[enemy->y - 1][enemy->x - 1] == 'E'
	|| data->map[enemy->y - 1][enemy->x - 1] == 'Y')
	{
		chang_right(data, enemy);
		if (data->map[enemy->y - 1][enemy->x + 1] != '1'
		&& data->map[enemy->y - 1][enemy->x + 1] != 'E'
		&& data->map[enemy->y - 1][enemy->x + 1] != 'Y')
			enemy->x++;
	}
	else
		enemy->x--;
	if (data->map[enemy->y - 1][enemy->x] == 'P')
		data->heart--;
	if (data->map[enemy->y - 1][enemy->x] == 'C' && x != enemy->x)
		enemy->save = 1;
	else if (x != enemy->x)
		enemy->save = 0;
	data->map[enemy->y - 1][enemy->x] = 'Y';
}

int	attack_types(t_data *data, t_en_pos *enm, int dir)
{
	if (dir == 4)
	{
		chang_right(data, enm);
		enm->cour = data->enemy_l.att1;
	}
	if (dir == 6)
	{
		chang_left(data, enm);
		enm->cour = data->enemy_r.att1;
	}
	if (dir == 8 && enm->right)
		enm->cour = data->enemy_l.att2;
	if (dir == 8 && enm->left)
		enm->cour = data->enemy_r.att2;
	if (dir == 2 && enm->right)
		enm->cour = data->enemy_l.att3;
	if (dir == 2 && enm->left)
		enm->cour = data->enemy_r.att3;
	enm->dir = dir;
	enm->att = 1;
	return (1);
}
