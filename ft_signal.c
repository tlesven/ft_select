/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 14:43:33 by tlesven           #+#    #+#             */
/*   Updated: 2014/01/12 20:09:08 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "ft_select.h"

static void		interrupt_prog(int signum)
{
	restore_term();
	exit(signum);
}

static void		resize_window(int signum)
{
	signum = 0;
	ft_rezise(1);
}

void			set_signal(void)
{
	signal(SIGINT, interrupt_prog);
	signal(SIGTTIN, interrupt_prog);
	signal(SIGTTOU, interrupt_prog);
	signal(SIGTSTP, interrupt_prog);
	signal(SIGWINCH, resize_window);
}
