/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:16:55 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/29 13:21:02 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_comb2(char *str, int i)
{
	if ((str[i] == '1') && (str [i + 8] == '1'))
		return (1);
	if ((str[i] == '2') && (str[i + 8] == '4'))
		return (1);
	if ((str[i] == '3') && (str [i + 8] >= '3'))
		return (1);
	if ((str[i] == '4') && (str[i + 8] != '1'))
		return (1);
	if ((str[0] == '1' && str[16] != '1') || (str[0] != '1' && str[16] == '1'))
		return (1);
	if ((str[6] == '1' && str[24] != '1') || (str[6] != '1' && str[24] == '1'))
		return (1);
	if ((str[8] == '1' && str[22] != '1') || (str[8] != '1' && str[22] == '1'))
		return (1);
	if ((str[14] == '1' && str[30] != '1')
		|| (str[14] != '1' && str[30] == '1'))
		return (1);
	return (0);
}

int	check_comb(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 16;
	while (i <= 6)
	{
		if (check_comb2(str, i) == 1)
			return (1);
		if (check_comb2(str, j) == 1)
			return (1);
		i += 2;
		j += 2;
	}
	return (0);
}
