/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:14:05 by jbarbey           #+#    #+#             */
/*   Updated: 2024/07/10 08:53:58 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	get_line_amount(char *buf, int ret, int line_amount)
{
	char	*temp;

	if (line_amount == -1)
	{
		if (line_len(buf) < 4)
			return (-1);
		temp = ft_strndup(buf, line_len(buf) - 3);
		line_amount = ft_atoi(temp);
	}
	else if (line_amount > 0 && buf[ret - 1] == '\n')
		line_amount--;
	return (line_amount);
}

int	print_nl(void)
{
	write(1, "\n", 1);
	return (1);
}

char	*read_stdin(void)
{
	char	buf[500];
	char	*str;
	int		str_len;
	int		ret;
	int		line_amount;

	str = ft_calloc(1, sizeof(char));
	str_len = 0;
	ret = 0;
	line_amount = -1;
	while (1)
	{
		ret = read(0, buf, 499);
		buf[ret] = '\0';
		str = ft_realloc(str, str_len, str_len + ret + 1);
		ft_strcat(str, buf);
		str_len += ret;
		line_amount = get_line_amount(buf, ret, line_amount);
		if (line_amount == -1)
			return (NULL);
		if (line_amount == 0 && print_nl())
			break ;
	}
	return (str);
}

int	mini_main(void)
{
	char		*path;
	t_param		param;
	t_map		*map;
	t_square	square;

	path = read_stdin();
	if (path == NULL)
		return (ERROR);
	param = gen_param(path, line_len(path) - 1);
	map = gen_map(path, line_len(path) + 1);
	if (map_valid(map, param) == FALSE)
		return (ERROR);
	else
	{
		square = solver(map, param);
		map = fill_map(map, square, param);
		print_answer(param, map);
	}
	free_all(map);
	return (1);
}
