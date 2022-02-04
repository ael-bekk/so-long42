/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:40:11 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	frame_player(t_data *data)
{
	if (data->i > TIME_FRAME_1)
	{
		data->count = data->count->next;
		if (!data->count)
			data->count = data->courent;
		pimg(data, data->img_floor, data->player.x * 45, data->player.y * 45);
	}
	pimg(data, data->count->img, data->player.x * 45, data->player.y * 45);
}

void	frame_collection(t_data *data)
{
	if (data->i > TIME_FRAME_1)
	{
		data->c_col = data->c_col->next;
		if (!data->c_col)
			data->c_col = data->mv_coll;
	}
}

void	frame_attack(t_data *data)
{
	if (data->i % TIME_FRAME_2 == 0)
	{
		if (data->count_attack)
			attack_mv(data);
		else if (data->atk.x_final)
		{
			if (data->atk.dir == 1)
				past_char(data, data->map, data->atk.y - 1,
					data->atk.x + data->atk.x_final / 45);
			else
				past_char(data, data->map, data->atk.y - 1,
					data->atk.x - data->atk.x_final / 45);
			data->atk.x_final = 0;
		}
	}
}
