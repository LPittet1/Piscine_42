/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 08:31:50 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/30 08:37:16 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_input(int count, char *str)
{
	int	i;

	i = 0;
	if (count != 2)
		return (1);
	while (str[i])
		i++;
	if (i != 31)
		return (1);
	return (0);
}

int	check_input2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (('1' <= str[i] && str[i] <= '4') || (str[i] == ' '))
			i++;
		else
			return (1);
	}
	i = 0;
	while (str[i])
	{
		if (str[0] == ' ')
			return (1);
		if ((str[i] >= '1') && (str[i + 1]) && (str[i + 1] >= '1'))
			return (1);
		if (str[i] == ' ' && str[i + 1] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_input3(char *str, int i, int j)
{
	int	count;

	count = 0;
	while (i < j)
	{
		if (str[i] == '1')
			count++;
		i += 2;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	check_input4(char *str)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	j = 8;
	k = 16;
	l = 24;
	if (check_input3(str, i, j) == 1)
		return (1);
	if (check_input3(str, j, k) == 1)
		return (1);
	if (check_input3(str, k, l) == 1)
		return (1);
	if (check_input3(str, l, 32) == 1)
		return (1);
	return (0);
}
