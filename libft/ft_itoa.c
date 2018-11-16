/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 14:38:35 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/17 02:30:46 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_itoarev(char *s)
{
	char	*str;
	int		i;
	int		len;
	int		j;

	len = ft_strlen(s) - 1;
	str = (char *)malloc(sizeof(*str) * len + 2);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s[0] == '-')
	{
		i++;
		str[j++] = '-';
	}
	while (len >= i)
	{
		str[j] = s[len];
		len--;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	tmp[20];
	int		i;

	i = 0;
	while (n != 0)
	{
		if (n < 0)
		{
			n = n * -1;
			tmp[i] = '-';
		}
		else
		{
			tmp[i] = (n % 10) + '0';
			n = n / 10;
		}
		i++;
	}
	tmp[i] = '\0';
	return (ft_itoarev(tmp));
}
