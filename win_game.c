/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:15:41 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/03 14:37:51 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	win_the_game(t_data *data)
{
	int	i;
	int	j;

	if (data->win_game)
	{
		i = -1;
		data->show = 0;
		while (++i < data->height)
		{
			j = -1;
			while (++j < data->width)
				pimg(data, data->bg, j * 45, i * 45);
		}
		pimg(data, data->game_win, (data->width * 45) / 2 - 84,
			(data->height * 45) / 2 - 59);
		data->win_game++;
	}
	if (data->win_game == 100)
		exit(0);
}

void	lose_the_game(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->height)
	{
		j = -1;
		while (++j < data->width)
			pimg(data, data->bg, j * 45, i * 45);
	}
	pimg(data, data->game_over, (data->width * 45) / 2 - 84,
		(data->height * 45) / 2 - 56);
}
