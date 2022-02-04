/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:05:45 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 11:16:54 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef files_H
# define files_H

# include <stdio.h>
# include "structers.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>

/////////////////   valid_map_1     ///////////////
void		test_all_maps_valid(char **maps, int ac);
void		valid_map(char *map);
void		valid(char **map, char *name);
//-----------------   valid_map_2     -----------------//
void		check_walls(char **map, char *name);
void		check_wall(char *wall, char *name);
void		check_char(char **map, char *name);
void		check_shape(char **map, char *name);
void		check_char_cond(char map, t_char *check, char *name);

/////////////////   free     ///////////////
void		free_split(char **s);
/////////////////   error     ///////////////
void		error_map(char *s, char *name);

/////////////////   init_struct     ///////////////
void		init_enemy_path(t_data *data);
void		init_images(t_data *data);
void		init_vars(t_data *data);
void		control(t_data *data, int type);

/////////////////   init_list     ///////////////
int			count_c(char **map, char o);
int			count_y(char **map);
t_stand		*ft_so_lstnew(void *content);
t_stand		*ft_so_lstlast(t_stand *lst);
void		ft_so_lstadd_back(t_stand **lst, t_stand *new);

/////////////////    moves      /////////////
int			need_to_exit(int y, int x, t_data *data);
void		up(t_data *data);
void		down(t_data *data);
void		left(t_data *data);
void		right(t_data *data);

//////////////////    display      /////////////
void		init_struct(t_data *data, char **map);
void		display_map(char **map, char *file_map);

//////////////////    header     ///////////////
void		put_heart(t_data *data);
void		put_score(t_data *data, int color);
void		put_moves(t_data *data, int color);
void		put_title(t_data *data);
void		put_header(t_data *data);

//////////////////    door_op_cl      /////////////
void		open_door(t_data *data);
void		close_door(t_data *data);
void		frem_door(t_data *data);

//////////////////    init_enemy     /////////////
void		find_all_enm(t_data *data);
void		init_enemy_pos(t_en_pos *new, int dir, int i, int j);
void		init_enemy_pos2(t_data *data, t_en_pos *new, int dir);
void		add_new_enemy(t_en_pos **enm, t_en_pos *new);

//////////////////    init_from_beggin      /////////////
char		**map_rese(char *map);
void		del_en(t_en_pos **enms);
void		init_struct2(t_data *data, char **map);
void		set_up_all_window(t_data *data);
void		init_from_beggin(t_data *data);

//////////////////    init_imag      /////////////
void		all_floor(char **map, t_data *data);
void		init_imgs_3(t_data *data, char **map, int i, int j);
void		init_imgs_2(t_data *data, char **map, int i, int j);
void		init_imgs(char **map, t_data *data);

//////////////////    attack      /////////////
void		attack_on_enemy(t_data *data);
void		freed(t_data *data, t_en_pos *tmp);
int			del_from_front(t_data *data, t_en_pos **enm, int y, int x);
void		delete_enemy(t_data *data, t_en_pos **enm, int y, int x);
void		attack_mv(t_data *data);

//////////////////    frames      /////////////
void		frame_player(t_data *data);
void		frame_collection(t_data *data);
void		frame_attack(t_data *data);
//-----------------   frames_2      ----------------//
void		frame_skull(t_data *data);
void		frame_death(t_data *data);
void		frame_enemy(t_data *data);
//////////////////    move_enemy_1      /////////////
void		mv_enemy_top_down(t_data *data, t_en_pos *enemy);
void		mv_enemy_left_right(t_data *data, t_en_pos *enemy);
int			player_near(t_data *data, t_en_pos *enm, int valid);
void		move_enemy(t_data *data);
//---------------   move_enemy_2     --------------//
void		en_top(t_data *data, t_en_pos *enemy);
void		en_down(t_data *data, t_en_pos *enemy);
void		en_right(t_data *data, t_en_pos *enemy);
void		en_left(t_data *data, t_en_pos *enemy);
int			attack_types(t_data *data, t_en_pos *enm, int dir);
//---------------   move_enemy_3     --------------//
void		animat(t_data *data);
void		enemy_rise_2(t_data *data, t_en_pos *enm);
void		enemy_rise_3(t_data *data, t_en_pos *enm);
void		enemy_rise(t_data *data);
void		past_char(t_data *data, char **map, int i, int j);
//---------------   move_enemy_4     --------------//
void		chang_top(t_en_pos *enemy);
void		chang_down(t_en_pos *enemy);
void		chang_left(t_data *data, t_en_pos *enemy);
void		chang_right(t_data *data, t_en_pos *enemy);

//////////////////    hooks      /////////////
int			key_hook(int keycode, t_data *data);
int			render_next_frame(t_data *data);
int			close_win(void);
int			releas_press(int keycode, t_data *data);
int			mous_click(int button, int x, int y, t_data *data);
//---------------   hooks_2     --------------//
void		str_pos_rest(t_data *data, int y);
void		setting_first_click(t_data *data);
void		setting_second_click(t_data *data, int y);

//////////////////    mlx_functions      /////////////
void		pimg(t_data *data, void *img, int x, int y);
void		*pxpm(t_data *data, char *path);
void		*mlxnw(t_data *data, char *title);

//////////////////    init_paths      /////////////
t_stand		*path_to(t_data *data, char *fold, int imgs);
void		*paths(t_data *data, char *fold, int i);

//////////////////    win_the_game      /////////////
void		win_the_game(t_data *data);
void		lose_the_game(t_data *data);

#endif
