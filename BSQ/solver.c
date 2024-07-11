/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:44:33 by lpittet           #+#    #+#             */
/*   Updated: 2024/07/10 08:55:50 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	is_safe_line(char *line, int size, int index, t_param param)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (line[index + i] == param.obst)
			return (i + 1);
		i++;
	}
	return (0);
}

int	is_safe_col(t_map *map, t_square temp, t_param param)
{
	int	i;
	int	safe_line;

	i = 0;
	while (i < temp.size)
	{
		safe_line = is_safe_line(
				map[i + temp.line].str, temp.size, temp.index, param);
		if (safe_line != 0)
			return (safe_line);
		i++;
	}
	return (0);
}

t_square	solver(t_map *map, t_param param)
{
	t_square	temp;
	t_square	square;

	temp.size = 1;
	square.size = 0;
	temp.line = 0;
	while (temp.line < param.lines - (temp.size - 1))
	{
		temp.index = 0;
		while (temp.index < map[temp.line].str_len - (temp.size - 1)
			&& temp.line < param.lines - (temp.size - 1))
		{
			if (is_safe_col(map, temp, param))
				temp.index += is_safe_col(map, temp, param);
			else
			{
				square = temp;
				temp.size++;
			}
		}
		temp.line++;
	}
	return (square);
}

t_map	*fill_map(t_map *map, t_square square, t_param param)
{
	int	l;
	int	c;

	l = 0;
	if (square.size == 0)
		return (map);
	while (l < square.size)
	{
		c = 0;
		while (c < square.size)
		{
			map[square.line + l].str[square.index + c] = param.full;
			c++;
		}
		l++;
	}
	return (map);
}
