/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 14:48:49 by tlesven           #+#    #+#             */
/*   Updated: 2013/11/28 14:36:40 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(*str));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == ',' || s[i] == '\t')
			i++;
		else
		{
			str[j] = s[i];
			j++;
			i++;
		}
	}
	str[j] = '\0';
	return (str);
}
