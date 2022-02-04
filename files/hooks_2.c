/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:33:47 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	str_pos_rest(t_data *data, int y)
{
	if (y >= 45 && y <= 90)
	{
		if (data->show)
			pimg(data, data->start, 0, 45);
		else
			pimg(data, data->pause, 0, 45);
		data->show = !data->show;
	}
	if (y >= 100 && y <= 145)
		init_from_beggin(data);
}

void	setting_first_click(t_data *data)
{
	if (!data->seting)
	{
		pimg(data, data->asdw, (data->width - 2) * 45, 90);
		pimg(data, data->flech, (data->width - 2) * 45, 180);
	}
	else
	{
		past_char(data, data->map, 1, data->width - 1);
		past_char(data, data->map, 1, data->width - 2);
		past_char(data, data->map, 2, data->width - 1);
		past_char(data, data->map, 2, data->width - 2);
		past_char(data, data->map, 3, data->width - 1);
		past_char(data, data->map, 3, data->width - 2);
		past_char(data, data->map, 4, data->width - 1);
		past_char(data, data->map, 4, data->width - 2);
	}
	data->show = !data->show;
	data->seting = !data->seting;
}

void	setting_second_click(t_data *data, int y)
{
	if (y >= 90 && y <= 180)
		control(data, 1);
	if (y >= 180 && y <= 270)
		control(data, 2);
	if (y >= 90 && y <= 270)
	{
		data->seting = !data->seting;
		data->show = !data->show;
		past_char(data, data->map, 1, data->width - 1);
		past_char(data, data->map, 1, data->width - 2);
		past_char(data, data->map, 2, data->width - 1);
		past_char(data, data->map, 2, data->width - 2);
		past_char(data, data->map, 3, data->width - 1);
		past_char(data, data->map, 3, data->width - 2);
		past_char(data, data->map, 4, data->width - 1);
		past_char(data, data->map, 4, data->width - 2);
	}
}
