/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:27:00 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/02 15:58:52 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] != s2[i])
			break ;
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	if (i == n)
		i--;
	if ((s1[i] - s2[i]) > 0)
		return (1);
	if ((s1[i] - s2[i]) < 0)
		return (-1);
	return (0);
}
