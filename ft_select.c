/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 15:41:31 by tlesven           #+#    #+#             */
/*   Updated: 2014/01/12 19:47:29 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/uio.h>
#include <unistd.h>
#include <termcap.h>
#include "libft.h"
#include "ft_select.h"

int				ft_rezise(int i)
{
	static int	rezise = 0;

	if (i == 1)
		rezise = 1;
	if (i == -1)
		rezise = 0;
	return (rezise);
}

static int		ft_toosmall(t_list *l)
{
	struct winsize	sz;

	ioctl(0, TIOCGWINSZ, &sz);
	if (l->prev->prev->rank > sz.ws_row)
			return (1);
	while (l->rank != 0)
	{
		if (ft_strlen(l->argv) > sz.ws_col)
			return (1);
		l = l->next;
	}
	return (0);
}



static void		affiche(t_list *l, int i)
{
	tputs(tgetstr("cl", NULL), 3, tputs_putchar);
	l = l->next;
	if (ft_toosmall(l))
		ft_putstr_fd("window is too small", 3);
	else
	{
		while (l->rank != 0)
		{
			if (l->select == 1)
				tputs(tgetstr("mr", NULL), 3, tputs_putchar);
			if (l->rank == i)
				tputs(tgetstr("us", NULL), 3, tputs_putchar);
			ft_putstr_fd(l->argv, 3);
			tputs(tgetstr("me", NULL), 3, tputs_putchar);
			tputs(tgetstr("do", NULL), 3, tputs_putchar);
			l = l->next;
		}
	}
	ft_rezise(-1);
}

int				ft_select(t_list *l, int i[2])
{
	char	buf[10];

	while (1)
	{
		affiche(l, i[0]);
		ft_bzero(buf, 5);
		read(0, buf, 10);
		if (*(unsigned int *)buf == RETURN)
			return (1);
		if (*(unsigned int *)buf == UP)
			ft_up(i);
		if (*(unsigned int *)buf == DOWN)
			ft_down(i);
		if (*(unsigned int *)buf == SPACE)
			ft_space(i, l);
		if (*(unsigned int *)buf == DELETE || *(unsigned int *)buf == BACKSPACE)
			ft_delete(i, l);
		if (*(unsigned int *)buf == ESCAPE || i[1] == 0)
			return (0);
	}
}
