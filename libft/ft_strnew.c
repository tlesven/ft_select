/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:27:18 by tlesven           #+#    #+#             */
/*   Updated: 2013/11/22 10:49:01 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(size * sizeof(str));
	if (str == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < size)
		{
			str[i] = '\0';
			i++;
		}
		return (str);
	}
}
