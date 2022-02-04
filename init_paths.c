/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:27:02 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/04 11:16:54 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	*paths(t_data *data, char *fold, int i)
{
	char	path[100];
	int		j;
	int		index;

	index = -1;
	j = 0;
	while (fold[++index])
		path[j++] = fold[index];
	if (i > 9)
		path[j++] = i / 10 + 48;
	path[j++] = i % 10 + 48;
	path[j++] = '.';
	path[j++] = 'x';
	path[j++] = 'p';
	path[j++] = 'm';
	path[j++] = 0;
	return (pxpm(data, path));
}

t_stand	*path_to(t_data *data, char *fold, int imgs)
{
	int		i;
	t_stand	*head;

	head = NULL;
	i = 0;
	while (++i <= imgs)
		ft_so_lstadd_back(&head, ft_so_lstnew(paths(data, fold, i)));
	return (head);
}
