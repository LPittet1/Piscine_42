/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:06:16 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/30 14:06:53 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	is_free(char *tab)
{
	int	i;

	i = 0;
	while (tab[i] != '0' && i <= 15)
		i++;
	return (i);
}

int	num_is_ok_row(char *tab, int i, int num)
{
	int	j;

	j = 0;
	while (j <= 15)
	{
		if (j / 4 == i / 4)
		{
			if (tab[j] == num + '0')
				return (1);
		}
		j++;
	}
	return (0);
}

int	num_is_ok_col(char *tab, int i, int num)
{
	int	j;

	j = 0;
	while (j <= 15)
	{
		if (j % 4 == i % 4)
		{
			if (tab[j] == num + '0')
				return (1);
		}
		j++;
	}
	return (0);
}

char	*solve(char *tab)
{
	int	num;
	int	i;

	i = is_free(tab);
	if (i == 16)
		return (tab);
	num = 1;
	while (num <= 4)
	{
		if ((num_is_ok_row(tab, is_free(tab), num) == 0)
			&& (num_is_ok_col(tab, is_free(tab), num) == 0))
		{
			tab[i] = num + '0';
			if (ft_strcmp(solve(tab), "Error") != 0)
				return (tab);
			tab[i] = '0';
		}
		num++;
	}
	write(1, "Error\n", 6);
	return ("Error");
}
