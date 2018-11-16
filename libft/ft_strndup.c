/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 21:59:45 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/03 22:22:29 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char			*scopy;
	unsigned int	i;

	scopy = (char*)malloc(sizeof(*scopy) * n + 1);
	i = 0;
	while (i < n)
	{
		scopy[i] = s1[i];
		i++;
	}
	scopy[i] = '\0';
	return (scopy);
}
