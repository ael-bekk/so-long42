/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:23:54 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	frame_skull(t_data *data)
{
	if (data->i > TIME_FRAME_1)
	{
		if (data->width > 12)
		{
			pimg(data, data->bg, (data->width - 7) * 45, 0);
			data->skull_count = data->skull_count->next;
			if (!data->skull_count)
				data->skull_count = data->skull;
		}
		animat(data);
	}
	if (data->width > 12)
		pimg(data, data->skull_count->img, (data->width - 7) * 45 + 15, 10);
}

void	frame_death(t_data *data)
{
	if (data->i > TIME_FRAME_1 && data->death.img)
	{
		pimg(data, data->img_floor, data->death.x * 45, data->death.y * 45);
		pimg(data, data->death.img->img, data->death.x * 45,
			data->death.y * 45);
		data->death.img = data->death.img->next;
	}
}

void	frame_enemy(t_data *data)
{
	if (data->i > TIME_FRAME_1)
	{
		data->enemy_mv++;
		enemy_rise(data);
		data->i = 0;
	}
	if (data->enemy_mv == 10)
	{
		move_enemy(data);
		data->enemy_mv = 0;
	}
}
