/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:02:11 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/01 15:26:39 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	*m;

	m = (size_t *)malloc(size);
	if (m == NULL)
		return (NULL);
	else
		ft_bzero(m, size);
	return ((void *)m);
}
