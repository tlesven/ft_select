/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/06 21:13:18 by tlesven           #+#    #+#             */
/*   Updated: 2014/01/12 18:11:18 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# define ESCAPE 27
# define SPACE 32
# define UP 4283163
# define LEFT 4479771
# define RIGHT 4414235
# define DOWN 4348699
# define RETURN 10
# define DELETE 127
# define BACKSPACE 2117294875

typedef struct		s_list
{
	struct s_list	*prev;
	char			*argv;
	int				select;
	int				rank;
	struct s_list	*next;
}					t_list;

int					tputs_putchar(int c);
void				restore_term(void);

void				set_signal(void);

void				*add_node(char *argv, t_list *l);
t_list				*init_list(void);

int					ft_select(t_list *l, int i[2]);
int					ft_rezise(int i);

void				ft_up(int i[2]);
void				ft_down(int i[2]);
void				ft_space(int i[2], t_list *l);
void				ft_delete(int i[2], t_list *l);

#endif /*FT_SELECT_H*/
