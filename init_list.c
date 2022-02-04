/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 02:39:44 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/02/03 11:40:50 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	count_c(char **map, char o)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == o)
				c++;
	}
	return (c);
}

int	count_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

t_stand	*ft_so_lstnew(void *content)
{
	t_stand	*new;

	new = NULL;
	new = (t_stand *)malloc(sizeof(t_stand));
	if (!new)
		return (NULL);
	new->img = content;
	new->next = NULL;
	return (new);
}

t_stand	*ft_so_lstlast(t_stand *lst)
{
	if (!lst)
		return (lst);
	if (!lst->next)
		return (lst);
	return (ft_so_lstlast(lst->next));
}

void	ft_so_lstadd_back(t_stand **lst, t_stand *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_so_lstlast(*lst)->next = new;
}
