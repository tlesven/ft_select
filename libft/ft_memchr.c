/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:03:56 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/01 15:27:55 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sub;
	unsigned int	i;
	unsigned char	cc;

	cc = c;
	sub = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (sub[i] == cc)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
