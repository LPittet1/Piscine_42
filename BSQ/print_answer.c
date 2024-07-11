/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:25:37 by lpittet           #+#    #+#             */
/*   Updated: 2024/07/09 14:27:05 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_answer(t_param params, t_map *map)
{
	int	i;

	i = 0;
	while (i < params.lines)
	{
		write(1, map[i].str, map[i].str_len);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}
