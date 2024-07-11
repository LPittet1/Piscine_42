/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:57:35 by lpittet           #+#    #+#             */
/*   Updated: 2024/07/09 14:42:10 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_line_len(t_map *map, t_param param)
{
	int	i;

	i = 0;
	if (param.lines == 0 || map[i].str_len == 0)
		return (FALSE);
	while (i < param.lines - 1)
	{
		if (map[i].str_len != map[i + 1].str_len)
			return (FALSE);
		i++;
	}
	if (map[i + 1].str_len)
		return (FALSE);
	return (TRUE);
}

int	check_line_content(t_map *map, t_param param)
{
	int	i;
	int	j;

	j = 0;
	while (j < param.lines)
	{
		i = 0;
		while (map[j].str[i])
		{		
			if (map[j].str[i] != param.empty && map[j].str[i] != param.obst)
				return (FALSE);
			i++;
		}
		j++;
	}
	return (TRUE);
}

int	check_params_valid(t_param param)
{
	if ((param.empty == param.full)
		|| (param.empty == param.obst)
		|| (param.full == param.obst))
		return (FALSE);
	if ((param.empty < ' ' || '~' < param.empty)
		|| (param.full < ' ' || '~' < param.full)
		|| (param.obst < ' ' || '~' < param.obst))
		return (FALSE);
	return (TRUE);
}

int	map_valid(t_map *map, t_param param)
{
	if ((check_params_valid(param) == FALSE)
		|| (check_line_len(map, param) == FALSE)
		|| (check_line_content(map, param) == FALSE))
		return (FALSE);
	return (TRUE);
}
