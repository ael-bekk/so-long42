/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:56:06 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/03 13:24:19 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	attack_mv(t_data *data)
{
	if (data->atk.dir == 1)
	{
		if (data->atk.x_final)
			pimg(data, data->img_floor, data->atk.x * 45
				+ data->atk.x_final - 5, data->atk.y * 45);
		pimg(data, data->count_attack->img, data->atk.x * 45
			+ data->atk.x_final, data->atk.y * 45);
	}
	else
	{
		if (data->atk.x_final)
			pimg(data, data->img_floor, data->atk.x * 45
				- data->atk.x_final + 5, data->atk.y * 45);
		pimg(data, data->count_attack->img, data->atk.x * 45
			- data->atk.x_final, data->atk.y * 45);
	}
	if (data->atk.x_final && data->atk.x_final % 45 == 0
		&& ((data->map[data->atk.y - 1][data->atk.x + data->atk.x_final
				/ 45] != '0' && data->atk.dir == 1)
		|| (data->map[data->atk.y -1][data->atk.x - data->atk.x_final
			/ 45] != '0' && data->atk.dir == -1)))
		data->count_attack = data->count_attack->next;
	else
		data->atk.x_final += 5;
}

void	freed(t_data *data, t_en_pos *tmp)
{
	data->death.x = tmp->x;
	data->death.y = tmp->y;
	data->map[tmp->y - 1][tmp->x] = '0';
	if (tmp->save)
		data->map[tmp->y - 1][tmp->x] = 'C';
	data->death.img = data->enemy_l.dht;
	free(tmp);
	data->player.enemy--;
	put_heart(data);
}

int	del_from_front(t_data *data, t_en_pos **enm, int y, int x)
{
	t_en_pos	*enms;
	t_en_pos	*tmp;

	tmp = NULL;
	enms = *enm;
	if (enms->y == y && enms->x == x)
	{
		tmp = enms;
		if (tmp->heart != 1)
		{
			tmp->cour = data->enemy_l.hit;
			if (tmp->courent == data->enemy_r.fly)
				tmp->cour = data->enemy_r.hit;
			tmp->heart--;
			return (1);
		}
		*enm = enms->next;
		freed(data, tmp);
		return (1);
	}
	return (0);
}

void	delete_enemy(t_data *data, t_en_pos **enm, int y, int x)
{
	t_en_pos	*enms;
	t_en_pos	*tmp;

	tmp = NULL;
	enms = *enm;
	while (enms->next)
	{
		if (enms->next->y == y && enms->next->x == x)
		{
			tmp = enms->next;
			if (tmp->heart != 1)
			{
				tmp->cour = data->enemy_l.hit;
				if (tmp->courent == data->enemy_r.fly)
					tmp->cour = data->enemy_r.hit;
				tmp->heart--;
				return ;
			}
			enms->next = enms->next->next;
			break ;
		}
		enms = enms->next;
	}
	freed(data, tmp);
}

void	attack_on_enemy(t_data *data)
{
	if (data->courent == data->left || data->courent == data->right)
	{
		if (data->courent == data->left)
			data->atk.dir = -1;
		else
			data->atk.dir = 1;
		data->atk.x = data->player.x;
		data->atk.y = data->player.y;
		data->atk.x_final = 0;
		data->count_attack = data->atk.attack;
	}
}
