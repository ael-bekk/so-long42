/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:08:25 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/03 12:23:25 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	init_struct(t_data *data, char **map)
{
	data->width = ft_strlen(map[0]);
	data->height = count_y(map) + 1;
	data->mlx = mlx_init();
	data->img_width = 45;
	data->img_height = 45;
	init_images(data);
	data->skull_count = data->skull;
	data->map = map;
	control(data, 2);
	init_vars(data);
	find_all_enm(data);
	data->player.coll = count_c(map, 'C');
	data->player.enemy = count_c(map, 'Y');
	data->win = mlxnw(data, "so_long");
}

void	display_map(char **map, char *file_to_map)
{
	t_data	data;

	init_struct(&data, map);
	data.file_map = file_to_map;
	put_header(&data);
	init_imgs(map, &data);
	put_heart(&data);
	mlx_hook(data.win, 3, 0, releas_press, &data);
	mlx_hook(data.win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_mouse_hook(data.win, mous_click, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
}
