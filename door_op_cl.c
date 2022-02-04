/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_op_cl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:05:11 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 11:16:54 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	close_door(t_data *data)
{
	int		i;
	int		j;
	void	*img;

	if (data->door_nb == 0)
		img = pxpm(data, "mv/dr/1.xpm");
	if (data->door_nb == 1)
		img = pxpm(data, "mv/dr/2.xpm");
	if (data->door_nb == 2)
		img = pxpm(data, "mv/dr/3.xpm");
	if (data->door_nb == 3)
		img = pxpm(data, "mv/dr/4.xpm");
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
			if (data->map[i][j] == 'E')
				pimg(data, img, j * 45, (i + 1) * 45 + 5);
	}
}

void	open_door(t_data *data)
{
	int		i;
	int		j;
	void	*img;

	if (data->door_nb == 5)
		img = pxpm(data, "mv/dr/4.xpm");
	if (data->door_nb == 6)
		img = pxpm(data, "mv/dr/3.xpm");
	if (data->door_nb == 7)
		img = pxpm(data, "mv/dr/2.xpm");
	if (data->door_nb == 8)
		img = pxpm(data, "mv/dr/1.xpm");
	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
			if (data->map[i][j] == 'E')
				pimg(data, img, j * 45, (i + 1) * 45 + 5);
	}
}

void	frem_door(t_data *data)
{
	if (data->door_nb != 4 && data->door_nb < 9)
	{
		if (data->door_count > TIME_FRAME_3)
		{
			data->door_count = 0;
			if (data->door_nb < 4)
				close_door(data);
			else
				open_door(data);
			data->door_nb++;
		}
		data->door_count++;
	}
}
