/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 08:38:05 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/30 14:04:25 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*fill_tab_col(char *str, char *tab, int i, int j)
{
	while (i <= 6)
	{
		if (str[i] == '1')
		{
			tab[j] = '4';
			if (str[i + 8] == '4')
			{
				tab[j + 4] = '3';
				tab[j + 8] = '2';
				tab[j + 12] = '1';
			}
		}
		if (str[i] == '4')
		{
			tab[j] = '1';
			tab[j + 4] = '2';
			tab[j + 8] = '3';
			tab[j + 12] = '4';
		}
		i += 2;
		j++;
	}
	return (tab);
}

char	*fill_tab_row(char *str, char *tab, int i, int j)
{
	while (i <= 22)
	{
		if (str[i] == '1')
		{
			tab[j] = '4';
			if (str[i + 8] == '4')
			{
				tab[j + 1] = '3';
				tab[j + 2] = '2';
				tab[j + 3] = '1';
			}
		}
		if (str[i] == '4')
		{
			tab[j] = '1';
			tab[j + 1] = '2';
			tab[j + 2] = '3';
			tab[j + 3] = '4';
		}
		i += 2;
		j += 4;
	}
	return (tab);
}

char	*fill_tab_rest(char *str, char *tab, int i, int j)
{
	while (i <= 14)
	{
		if (str[i] == '1')
			tab[j] = '4';
		i += 2;
		j++;
	}
	i = 24;
	j = 3;
	while (i <= 30)
	{
		if (str[i] == '1')
			tab[j] = '4';
		i += 2;
		j += 4;
	}
	return (tab);
}

char	*fill_tab_col1(char *str, char *tab, int i, int j)
{
	while (i <= 6)
	{
		if (str[i] == '1' && str[i + 8] == '2')
			tab[j + 12] = '3';
		if (str[i] == '2' && str[i + 8] == '3')
			tab[j + 4] = '4';
		if (str[i] == '3' && str[i + 8] == '2')
			tab[j + 8] = '4';
		if (str[i] == '2' && str[i + 8] == '1')
			tab[j] = '3';
		i += 2;
		j++;
	}
	return (tab);
}

char	*fill_tab_row1(char *str, char *tab, int i, int j)
{
	while (i <= 22)
	{
		if (str[i] == '1' && str[i + 8] == '2')
			tab[j + 3] = '3';
		if (str[i] == '2' && str[i + 8] == '3')
			tab[j + 1] = '4';
		if (str[i] == '3' && str[i + 8] == '2')
			tab[j + 2] = '4';
		if (str[i] == '2' && str[i + 8] == '1')
			tab[j] = '3';
		i += 2;
		j += 4;
	}
	return (tab);
}
