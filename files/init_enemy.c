/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:50:33 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_enemy_pos(t_en_pos *new, int dir, int i, int j)
{
	new->heart = ENEMY_HEART;
	new->x = j;
	new->y = i + 1;
	if (dir)
	{
		new->left = 1;
		new->right = 0;
		new->top = 1;
		new->down = 0;
	}
	else
	{
		new->left = 0;
		new->right = 1;
		new->top = 0;
		new->down = 1;
	}
	new->next = NULL;
}

void	init_enemy_pos2(t_data *data, t_en_pos *new, int dir)
{
	new->att = 0;
	new->mv = 0;
	if (dir)
	{
		new->courent = data->enemy_r.fly;
		new->cour = new->courent;
	}
	else
	{
		new->courent = data->enemy_l.fly;
		new->cour = new->courent;
	}
}

void	add_new_enemy(t_en_pos **enm, t_en_pos *new)
{
	t_en_pos	*tmp;

	tmp = *enm;
	if (!tmp)
		*enm = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	find_all_enm(t_data *data)
{
	int			i;
	int			j;
	int			dir;
	t_en_pos	*new;

	i = 0;
	dir = 0;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'Y')
			{
				new = (t_en_pos *)malloc(sizeof(t_en_pos));
				if (!new)
					exit(0);
				new->save = 0;
				init_enemy_pos(new, dir, i, j);
				init_enemy_pos2(data, new, dir);
				dir = !dir;
				add_new_enemy(&data->enm, new);
			}
		}
	}
}
