/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:25:57 by tlesven           #+#    #+#             */
/*   Updated: 2013/11/25 15:20:45 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		tmp;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)(s1));
	while (s1[i] != '\0' && i < n)
	{
		tmp = i;
		j = 0;
		while (s1[tmp] == s2[j] && s2[j] && tmp < n)
		{
			tmp++;
			j++;
			if (s2[j] == '\0')
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
