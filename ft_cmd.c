/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 19:26:44 by tlesven           #+#    #+#             */
/*   Updated: 2014/01/08 16:50:03 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdlib.h>

void	ft_up(int i[2])
{
	i[0]--;
	if (i[0] == 0)
		i[0] = i[1];
}

void	ft_down(int i[2])
{
	i[0]++;
	if (i[0] > i[1])
		i[0] = 1;
}

void	ft_space(int i[2], t_list *l)
{
	t_list	*tmp;

	tmp = l->next;
	while (tmp != l)
	{
		if (tmp->rank == i[0])
		{
			if (tmp->select == 0)
				tmp->select = 1;
			else
				tmp->select = 0;
			break ;
		}
		tmp = tmp->next;
	}
	i[0]++;
	if (i[0] > i[1])
		i[0] = 1;
}

void	ft_delete(int i[2], t_list *l)
{
	t_list	*tmp;
	int		j;

	j = 0;
	tmp = l->next;
	while (tmp != l)
	{
		if (i[0] == 0)
			tmp->rank--;
		else if (tmp->rank == i[0])
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			j = i[0];
			i[0] = 0;
		}
		tmp = tmp->next;
	}
	i[1]--;
	if (j == i[1] + 1)
		j--;
	i[0] = j;
}
