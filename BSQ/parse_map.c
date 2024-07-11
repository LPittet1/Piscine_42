/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:21:40 by jbarbey           #+#    #+#             */
/*   Updated: 2024/07/09 14:21:52 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*read_map(char *path)
{
	int		fd;
	int		b_read;
	char	buf[100];
	int		file_len;
	char	*file_str;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	b_read = read(fd, buf, 99);
	file_str = ft_calloc(1, sizeof(char));
	file_len = 0;
	while (b_read > 0)
	{
		buf[b_read] = '\0';
		file_str = ft_realloc(file_str, file_len, file_len + b_read + 1);
		ft_strcat(file_str, buf);
		file_len += b_read;
		b_read = read(fd, buf, 99);
	}
	close(fd);
	return (file_str);
}

t_line	gen_index(char *file_str, int f_i)
{
	t_line	index;

	index.start = f_i;
	while (file_str[f_i] >= 32 && file_str[f_i] < 127)
		f_i++;
	index.end = f_i - 1;
	return (index);
}

t_map	*gen_map(char *file_str, int f_i)
{
	t_map	*map;
	t_line	index;
	int		map_i;

	map_i = 0;
	map = malloc(sizeof(t_map) * (ft_count_file_lines(file_str) + 1));
	while (file_str[f_i] != '\0')
	{
		index = gen_index(file_str, f_i);
		f_i = index.end + 1;
		map[map_i].str_len = index.end - index.start + 1;
		map[map_i].str = ft_strndup(file_str + index.start,
				index.end - index.start + 1);
		map_i++;
		f_i++;
	}
	map[map_i].str = "\0";
	map[map_i].str_len = 0;
	return (map);
}

t_map	*parse_map(char *path)
{
	t_map	*map;
	char	*file_str;
	int		f_i;

	file_str = read_map(path);
	f_i = 0;
	while (file_str[f_i] != '\n')
		f_i++;
	map = gen_map(file_str, f_i + 1);
	free(file_str);
	return (map);
}
