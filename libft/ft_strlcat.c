/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:05:55 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/08 20:31:02 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	j;

	if ((size < ft_strlen(dst)) && (size >= ft_strlen(src)))
	{
		len = ft_strlen(src) + size;
	}
	else if (size < ft_strlen(src) && (size < ft_strlen(dst)))
	{
		len = ft_strlen(src) + size;
	}
	else
		len = ft_strlen(dst) + ft_strlen(src);
	if (size > ft_strlen(dst))
	{
		i = ft_strlen(dst);
		j = 0;
		while (i < size - 1)
		{
			dst[i++] = src[j++];
		}
		dst[size] = '\0';
	}
	return (len);
}
