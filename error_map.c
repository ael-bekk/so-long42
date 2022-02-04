/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:50:49 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/03 14:39:15 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	error_map(char *s, char *name)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("============> [", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("] : ", 2);
	ft_putstr_fd(s, 2);
	exit(1);
}
