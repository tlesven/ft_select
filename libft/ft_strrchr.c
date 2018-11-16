/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:35:51 by tlesven           #+#    #+#             */
/*   Updated: 2013/11/27 19:47:52 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int		i;
	int		j;

	cc = (char)c;
	if (cc == 0)
		return ((char *)(s + ft_strlen(s)));
	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			j = i;
		i++;
	}
	if (j != -1)
		return ((char *)(s + j));
	return (NULL);
}
