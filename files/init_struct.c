/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:17:05 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_enemy_path(t_data *data)
{
	data->enemy_l.att1 = path_to(data, "enemy/l/at/1/", 8);
	data->enemy_l.att2 = path_to(data, "enemy/l/at/2/", 8);
	data->enemy_l.att3 = path_to(data, "enemy/l/at/3/", 6);
	data->enemy_l.prjct = path_to(data, "enemy/l/pro/", 8);
	data->enemy_l.fly = path_to(data, "enemy/l/fly/", 8);
	data->enemy_l.hit = path_to(data, "enemy/l/hit/", 4);
	data->enemy_l.dht = path_to(data, "enemy/l/dht/", 4);
	data->enemy_r.att1 = path_to(data, "enemy/r/at/1/", 8);
	data->enemy_r.att2 = path_to(data, "enemy/r/at/2/", 8);
	data->enemy_r.att3 = path_to(data, "enemy/r/at/3/", 6);
	data->enemy_r.prjct = path_to(data, "enemy/r/pro/", 8);
	data->enemy_r.fly = path_to(data, "enemy/r/fly/", 8);
	data->enemy_r.hit = path_to(data, "enemy/r/hit/", 4);
	data->enemy_r.dht = path_to(data, "enemy/r/dht/", 4);
}

void	init_images(t_data *data)
{
	init_enemy_path(data);
	data->left = path_to(data, "mv/pr/", 12);
	data->right = path_to(data, "mv/pl/", 12);
	data->run_r = path_to(data, "mv/rl/", 8);
	data->run_l = path_to(data, "mv/rr/", 8);
	data->atk.attack = path_to(data, "attack/", 8);
	data->mv_coll = path_to(data, "mv/cl/", 30);
	data->skull = path_to(data, "mv/sk/", 8);
	data->img_door = pxpm(data, "mv/dr/1.xpm");
	data->img_coll = pxpm(data, "mv/cl/1.xpm");
	data->img_floor = pxpm(data, "characters/floor.xpm");
	data->img_wall2 = pxpm(data, "characters/wall2.xpm");
	data->img_wall = pxpm(data, "characters/wall.xpm");
	data->bg = pxpm(data, "characters/bg.xpm");
	data->start = pxpm(data, "icons/start.xpm");
	data->pause = pxpm(data, "icons/pause.xpm");
	data->restart = pxpm(data, "icons/restart.xpm");
	data->set = pxpm(data, "icons/setting.xpm");
	data->flech = pxpm(data, "icons/flech.xpm");
	data->asdw = pxpm(data, "icons/asdw.xpm");
	data->game_over = pxpm(data, "icons/g_over.xpm");
	data->game_win = pxpm(data, "icons/win.xpm");
}

void	init_vars(t_data *data)
{
	data->i = 0;
	data->player.moves = 0;
	data->player.score = 0;
	data->door_nb = 0;
	data->door_count = 0;
	data->enemy_mv = 0;
	data->dir = 0;
	data->lose = 0;
	data->win_game = 0;
	data->atk.x_final = 0;
	data->show = 1;
	data->seting = 0;
	data->enm = NULL;
	data->heart = HEART;
	data->count_attack = NULL;
	data->death.img = NULL;
	data->courent = data->left;
	data->count = data->courent;
	data->c_col = data->mv_coll;
}

void	control(t_data *data, int type)
{
	if (type == 1)
	{
		data->ctl.up = UP1;
		data->ctl.down = DOWN1;
		data->ctl.left = LEFT1;
		data->ctl.right = RIGHT1;
	}
	else
	{
		data->ctl.up = UP2;
		data->ctl.down = DOWN2;
		data->ctl.left = LEFT2;
		data->ctl.right = RIGHT2;
	}
}
