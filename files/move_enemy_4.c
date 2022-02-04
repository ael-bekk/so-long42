/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:26:57 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 17:53:44 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	chang_top(t_en_pos *enemy)
{
	enemy->top = 1;
	enemy->down = 0;
}

void	chang_down(t_en_pos *enemy)
{
	enemy->top = 0;
	enemy->down = 1;
}

void	chang_left(t_data *data, t_en_pos *enemy)
{
	enemy->courent = data->enemy_r.fly;
	enemy->cour = enemy->courent;
	enemy->right = 0;
	enemy->left = 1;
}

void	chang_right(t_data *data, t_en_pos *enemy)
{
	enemy->courent = data->enemy_l.fly;
	enemy->cour = enemy->courent;
	enemy->right = 1;
	enemy->left = 0;
}
