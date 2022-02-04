/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:11:47 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	need_to_exit(int y, int x, t_data *data)
{
	if (data->map[y - 1][x] == 'Y')
		data->heart--;
	if ((data->map)[y - 1][x] == 'C')
	{
		data->player.score++;
		put_score(data, 0xFFFFFFFF);
		put_heart(data);
		(data->map)[y - 1][x] = '0';
		if (data->player.coll == data->player.score)
			data->door_nb++;
	}
	if ((data->map)[y - 1][x] == 'E' && data->player.coll != data->player.score)
		return (0);
	if ((data->map)[y - 1][x] == 'E' && data->player.coll == data->player.score)
		data->win_game = 1;
	return (1);
}

void	up(t_data *data)
{
	if ((data->map)[data->player.y - 1 - 1][data->player.x] != '1'
		&& need_to_exit(data->player.y - 1, data->player.x, data))
	{
		data->map[data->player.y - 1][data->player.x] = '0';
		data->player.moves++;
		put_moves(data, 0xFFFFFFFF);
		pimg(data, data->img_floor, data->player.x * 45, data->player.y * 45);
		pimg(data, data->img_floor, data->player.x * 45, --data->player.y * 45);
		pimg(data, data->count->img, data->player.x * 45, data->player.y * 45);
		data->map[data->player.y - 1][data->player.x] = 'P';
	}
}

void	down(t_data *data)
{
	if ((data->map)[data->player.y + 1 - 1][data->player.x] != '1'
		&& need_to_exit(data->player.y + 1, data->player.x, data))
	{
		data->map[data->player.y - 1][data->player.x] = '0';
		data->player.moves++;
		put_moves(data, 0xFFFFFFFF);
		pimg(data, data->img_floor, data->player.x * 45, data->player.y * 45);
		pimg(data, data->img_floor, data->player.x * 45, ++data->player.y * 45);
		pimg(data, data->count->img, data->player.x * 45, data->player.y * 45);
		data->map[data->player.y - 1][data->player.x] = 'P';
	}
}

void	left(t_data *data)
{
	data->courent = data->run_l;
	if ((data->map)[data->player.y - 1][data->player.x - 1] != '1'
		&& need_to_exit(data->player.y, data->player.x - 1, data))
	{
		data->map[data->player.y - 1][data->player.x] = '0';
		data->player.moves++;
		put_moves(data, 0xFFFFFFFF);
		pimg(data, data->img_floor, data->player.x * 45, data->player.y * 45);
		pimg(data, data->img_floor, --data->player.x * 45, data->player.y * 45);
		pimg(data, data->count->img, data->player.x * 45, data->player.y * 45);
		data->map[data->player.y - 1][data->player.x] = 'P';
	}
}

void	right(t_data *data)
{
	data->courent = data->run_r;
	if ((data->map)[data->player.y - 1][data->player.x + 1] != '1'
		&& need_to_exit(data->player.y, data->player.x + 1, data))
	{
		data->map[data->player.y - 1][data->player.x] = '0';
		data->player.moves++;
		put_moves(data, 0xFFFFFFFF);
		pimg(data, data->img_floor, data->player.x * 45, data->player.y * 45);
		pimg(data, data->img_floor, ++data->player.x * 45, data->player.y * 45);
		pimg(data, data->count->img, data->player.x * 45, data->player.y * 45);
		data->map[data->player.y - 1][data->player.x] = 'P';
	}
}
