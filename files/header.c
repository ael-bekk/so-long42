/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:55:53 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_heart(t_data *data)
{
	char	*nb;

	if (data->width > 12)
	{
		nb = ft_itoa(data->heart);
		pimg(data, data->bg, 5 * 45, 0);
		pimg(data, data->bg, (data->width - 7) * 45, 0);
		pimg(data, data->bg, (data->width - 6) * 45, 0);
		mlx_string_put(data->mlx, data->win, (data->width - 6) * 45,
			15, 0xFFFF0000, "x");
		mlx_string_put(data->mlx, data->win, 5 * 45,
			15, 0xFFFF0000, "x");
		mlx_string_put(data->mlx, data->win, 5 * 45 + 12,
			15, 0xFFFF0000, nb);
		free(nb);
		nb = ft_itoa(data->player.enemy);
		mlx_string_put(data->mlx, data->win, (data->width - 6) * 45 + 12,
			15, 0xFFFF0000, nb);
		free(nb);
	}
	if (data->heart < 1)
		data->lose = 1;
}

void	put_score(t_data *data, int color)
{
	char	*nb;

	if (data->width > 8)
	{
		nb = ft_itoa(data->player.score);
		pimg(data, data->bg, 2 * 45, 0);
		pimg(data, data->bg, 3 * 45, 0);
		mlx_string_put(data->mlx, data->win, 95, 15, color, nb);
		free(nb);
	}
}

void	put_moves(t_data *data, int color)
{
	char	*nb;

	nb = ft_itoa(data->player.moves);
	pimg(data, data->bg, (data->width - 2) * 45, 0);
	pimg(data, data->bg, (data->width - 1) * 45, 0);
	mlx_string_put(data->mlx, data->win, data->width * 45 - 85, 15, color, nb);
	free(nb);
}

void	put_title(t_data *data)
{
	void	*img;

	img = pxpm(data, "characters/title.xpm");
	pimg(data, img, (data->width / 2 - 3) * 45, 3);
}

void	put_header(t_data *data)
{
	if (data->width > 8)
	{
		mlx_string_put(data->mlx, data->win, 20, 15, 0xFFFF0000, "score :");
		mlx_string_put(data->mlx, data->win, 95, 15, 0xFFFFFFFF, "0");
	}
	if (data->width > 3)
		mlx_string_put(data->mlx, data->win, data->width * 45 - 160, 15,
			0xFFFF0000, "moves :");
	else
		mlx_string_put(data->mlx, data->win, 8, 15,
			0xFFFF0000, "MV :");
	mlx_string_put(data->mlx, data->win, data->width * 45 - 85, 15,
		0xFFFFFFFF, "0");
	if (data->width > 20)
		put_title(data);
}
