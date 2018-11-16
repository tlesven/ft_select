/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 15:48:54 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/02 15:49:05 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*sub1;
	const char		*sub2;

	sub1 = s1;
	sub2 = s2;
	i = 0;
	while (i < n)
	{
		sub1[i] = sub2[i];
		i++;
	}
	return (s1);
}
