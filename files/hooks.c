/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:07:16 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (data->show)
	{
		if (!data->lose)
		{
			if (keycode == data->ctl.left)
				left(data);
			if (keycode == data->ctl.up)
				up(data);
			if (keycode == data->ctl.right)
				right(data);
			if (keycode == data->ctl.down)
				down(data);
			if (keycode == ESP && !data->count_attack)
				attack_on_enemy(data);
		}
		if (data->lose && keycode == ENTRE)
		{
			init_from_beggin(data);
			data->lose = 0;
		}
	}
	if (keycode == ESC)
		exit(0);
	return (0);
}

int	render_next_frame(t_data *data)
{
	if (data->show)
	{
		if (!data->lose)
		{
			frame_player(data);
			frame_collection(data);
			frame_skull(data);
			frame_death(data);
			frame_enemy(data);
			frame_attack(data);
			frem_door(data);
			data->i++;
		}
		else
			lose_the_game(data);
		if (!data->heart && !data->lose)
			data->lose = 1;
	}
	win_the_game(data);
	return (0);
}

int	close_win(void)
{
	exit(0);
}

int	releas_press(int keycode, t_data *data)
{
	if (!data->lose)
	{
		if (keycode == LEFT1 || keycode == LEFT2)
			data->courent = data->left;
		if (keycode == RIGHT1 || keycode == RIGHT2)
			data->courent = data->right;
		data->count = data->courent;
	}
	return (1);
}

int	mous_click(int button, int x, int y, t_data *data)
{
	if (x <= 45 && button == 1)
		str_pos_rest(data, y);
	if (data->height > 7)
	{
		if (x >= (data->width - 1) * 45 && button == 1 && y >= 45 && y <= 90)
			setting_first_click(data);
		if (x >= (data->width - 2) * 45 && button == 1 && data->seting)
			setting_second_click(data, y);
	}
	return (0);
}
