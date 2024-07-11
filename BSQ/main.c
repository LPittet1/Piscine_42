/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:21:42 by lpittet           #+#    #+#             */
/*   Updated: 2024/07/10 08:56:25 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int ac, char **av)
{
	int			i;
	t_map		*map;
	t_param		param;
	char		*path;

	i = 1;
	if (ac == 1)
	{
		if (mini_main() == ERROR)
			map_error();
	}
	while (i < ac)
	{
		path = av[i];
		param = parse_param(path);
		map = parse_map(path);
		if (map_valid(map, param) == FALSE)
			map_error();
		else
			map = solve_and_print(map, param);
		i++;
		free_all(map);
	}
	exit (0);
}
