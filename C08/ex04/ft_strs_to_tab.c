/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:03:44 by lpittet           #+#    #+#             */
/*   Updated: 2024/07/03 15:03:47 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

ft_strdup(char *str)
{
	int	len;
	int	i;
	char *dup;

	len = ft_strlen(str);
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*array;

	i = 0;
	array = malloc(sizeof(t_stock_str) * (ac + 1));
	if (array == NULL)
		return (NULL);
	while (i < ac)
	{
		array[i].size = ft_strlen(av[i]);
		array[i].str = av[i];
		array[i].copy = ft_strdup(av[i]);
		i++;
	}
	array[i].str = 0;
	array[i].copy = 0;
	return (array);
}
