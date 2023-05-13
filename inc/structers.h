/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:38:30 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 11:13:56 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTERS_H
# define STRUCTERS_H

# define LEFT1  0
# define LEFT2  123
# define RIGHT1 2
# define RIGHT2 124
# define UP1    13
# define UP2    126
# define DOWN1  1
# define DOWN2  125
# define ESC    53
# define ESP    49
# define ENTRE  36
# define ENEMY_HEART 1
# define HEART  10
# define TIME_FRAME_1 3
# define TIME_FRAME_2 1
# define TIME_FRAME_3 5
# include <mlx.h>

typedef struct s_map
{
	int	x;
	int	y;
	int	coll;
	int	moves;
	int	score;
	int	enemy;
}	t_map;

typedef struct s_char
{
	int	p;
	int	e;
	int	c;
}	t_char;

typedef struct s_stand
{
	void			*img;
	struct s_stand	*next;
}	t_stand;

typedef struct s_en_pos
{
	t_stand			*cour;
	t_stand			*courent;
	int				dir;
	int				att;
	int				mv;
	int				heart;
	int				save;
	int				x;
	int				y;
	int				left;
	int				right;
	int				top;
	int				down;
	struct s_en_pos	*next;
}	t_en_pos;

typedef struct s_attack
{
	int		dir;
	int		x;
	int		y;
	int		x_final;
	t_stand	*attack;
}	t_attack;

typedef struct s_enemy_all_mvs
{
	t_stand		*att1;
	t_stand		*att2;
	t_stand		*att3;
	t_stand		*prjct;
	t_stand		*fly;
	t_stand		*hit;
	t_stand		*dht;
}	t_enemy_all_mvs;

typedef struct s_death
{
	int		x;
	int		y;
	t_stand	*img;
}	t_death;

typedef struct s_control
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_control;

typedef struct s_test {
	int				win_game;
	int				seting;
	int				show;
	int				width;
	int				height;
	int				img_width;
	int				img_height;
	int				i;
	int				door_nb;
	int				door_count;
	int				heart;
	int				enemy_mv;
	int				dir;
	int				lose;
	void			*file_map;
	void			*img_floor;
	void			*img_backg;
	void			*img_wall;
	void			*img_wall2;
	void			*img_door;
	void			*img_coll;
	void			*game_over;
	void			*game_win;
	void			*bg;
	void			*pause;
	void			*start;
	void			*restart;
	void			*flech;
	void			*asdw;
	void			*set;
	void			*mlx;
	void			*win;
	char			**map;
	t_control		ctl;
	t_stand			*left;
	t_stand			*right;
	t_stand			*run_l;
	t_stand			*run_r;
	t_stand			*courent;
	t_stand			*count;
	t_stand			*mv_coll;
	t_stand			*c_col;
	t_stand			*skull;
	t_stand			*skull_count;
	t_attack		atk;
	t_stand			*count_attack;
	t_death			death;
	t_en_pos		*enm;
	t_enemy_all_mvs	enemy_l;
	t_enemy_all_mvs	enemy_r;
	t_map			player;
}	t_data;

//enm   == enemies
//c_col == count_coll
//atk   == attack

#endif
