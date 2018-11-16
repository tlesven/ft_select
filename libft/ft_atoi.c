/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlesven <tlesven@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 20:26:00 by tlesven           #+#    #+#             */
/*   Updated: 2013/12/08 20:27:04 by tlesven          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr(int neg, char *str)
{
	int		result;
	int		i;

	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		if (result != 0)
			result = result * 10;
		result = (str[i] - '0') + result;
		i++;
	}
	return (neg * result);
}

int			ft_atoi(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
			i++;
		if (str[i] == '-')
			return (ft_nbr(-1, str + i));
		if (str[i] == '+' || ft_isdigit(str[i]) == 1)
			return (ft_nbr(1, str + i));
		if (ft_isalpha(str[i]))
			return (0);
		i++;
	}
	return (0);
}
