/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:41:44 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 11:16:54 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	pimg(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
}

void	*pxpm(t_data *data, char *path)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(data->mlx, path,
			&data->img_width, &data->img_height);
	return (ptr);
}

void	*mlxnw(t_data *data, char *title)
{
	void	*ptr;

	ptr = mlx_new_window(data->mlx, data->width * 45,
			data->height * 45, title);
	return (ptr);
}
