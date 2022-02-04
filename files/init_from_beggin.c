/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_from_beggin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 00:30:24 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**map_rese(char *map)
{
	int		fd;
	char	*line;
	char	*join;
	char	**split;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	join = NULL;
	while (line)
	{
		join = ft_gnl_strjoin(join, line);
		line = get_next_line(fd);
	}
	split = ft_split(join, '\n');
	free(join);
	close(fd);
	return (split);
}

void	del_en(t_en_pos **enms)
{
	t_en_pos	*tmp;

	while (*enms)
	{
		tmp = *enms;
		*enms = (*enms)->next;
		free(tmp);
	}
}

void	init_struct2(t_data *data, char **map)
{
	data->width = ft_strlen(map[0]);
	data->height = count_y(map) + 1;
	data->img_width = 45;
	data->img_height = 45;
	data->map = map;
	del_en(&data->enm);
	data->enm = NULL;
	find_all_enm(data);
	data->i = 0;
	data->player.coll = count_c(map, 'C');
	data->player.enemy = count_c(map, 'Y');
	data->player.moves = 0;
	data->player.score = 0;
	data->door_nb = 0;
	data->door_count = 0;
	data->heart = HEART;
	data->enemy_mv = 0;
	data->dir = 0;
	data->lose = 0;
	data->atk.x_final = 0;
	data->count_attack = NULL;
	data->show = 1;
}

void	set_up_all_window(t_data *data)
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
}

void	init_from_beggin(t_data *data)
{
	set_up_all_window(data);
	free_split(data->map);
	data->map = map_rese(data->file_map);
	init_struct2(data, data->map);
	data->count = data->courent;
	data->c_col = data->mv_coll;
	data->courent = data->left;
	data->skull_count = data->skull;
	put_header(data);
	init_imgs(data->map, data);
	put_heart(data);
}
