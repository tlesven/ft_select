/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 21:07:14 by tlesven           #+#    #+#             */
/*   Updated: 2014/01/12 20:47:22 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_select.h"
#include "libft.h"

static struct termios	g_term;

int						tputs_putchar(int c)
{
	write(3, &c, 1);
	return (1);
}

static void				init_term(void)
{
	char	buffer[2048];

	if (tgetent(buffer, getenv("TERM")) < 1)
		exit(0);
	tcgetattr(0, &g_term);
	g_term.c_lflag &= ~(ICANON | ECHO);
	g_term.c_cc[VMIN] = 1;
	g_term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &g_term);
	tputs(tgetstr("vi", NULL), 3, tputs_putchar);
	tputs(tgetstr("ti", NULL), 3, tputs_putchar);
	tputs(tgetstr("sc", NULL), 3, tputs_putchar);
}

void					restore_term(void)
{
	tputs(tgetstr("te", NULL), 3, tputs_putchar);
	tputs(tgetstr("ve", NULL), 3, tputs_putchar);
	g_term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, 0, &g_term);
}

static int				affiche_result(t_list *l)
{
	int		i;

	i = 0;
	l = l->next;
	while (l->rank != 0)
	{
		if (l->select == 1)
		{
			if (i > 0)
				ft_putchar(' ');
			ft_putstr(l->argv);
			i++;
		}
		l = l->next;
	}
	return (0);
}

int						main(int argc, char **argv)
{
	t_list	*l_argv;
	int		i[2] = {1, argc -1};

	open("/dev/tty", O_WRONLY);
	if (argc == 1)
		return (0);
	set_signal();
	init_term();
	l_argv = init_list();
	while (i[0] < argc)
	{
		add_node(argv[i[0]], l_argv);
		i[0]++;
	}
	i[0] = 1;
	i[0] = ft_select(l_argv, i);
	restore_term();
	if (i[0] == 1)
		affiche_result(l_argv);
	return (0);
}
