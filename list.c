/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 12:36:18 by tlesven           #+#    #+#             */
/*   Updated: 2014/01/07 16:31:59 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"
#include "libft.h"

t_list	*init_list(void)
{
	t_list		*l;

	l = (t_list *)malloc(sizeof(t_list));
	l->next = l;
	l->prev = l;
	l->argv = "Start";
	l->select = 0;
	l->rank = 0;
	return (l);
}

void	*add_node(char *argv, t_list *l)
{
	t_list		*node;
	static int	rank = 1;

	node = (t_list *)malloc(sizeof(t_list));
	l->prev->next = node;
	node->prev = l->prev;
	l->prev = node;
	node->next = l;
	node->argv = argv;
	node->select = 0;
	node->rank = rank;
	rank++;
	return (l);
}
