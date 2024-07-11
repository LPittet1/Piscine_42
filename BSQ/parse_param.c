/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:51:57 by jbarbey           #+#    #+#             */
/*   Updated: 2024/07/10 07:26:52 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*read_param(char *path)
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

t_param	gen_param(char *file_str, int end)
{
	t_param	param;
	char	*temp;

	if (end < 3)
	{
		param.lines = 0;
		return (param);
	}
	param.full = file_str[end];
	param.obst = file_str[end - 1];
	param.empty = file_str[end - 2];
	temp = ft_strndup(file_str, end - 2);
	param.lines = ft_atoi(temp);
	free(temp);
	return (param);
}

t_param	parse_param(char *path)
{
	t_param	param;
	char	*file_str;
	int		f_i;

	file_str = read_param(path);
	f_i = 0;
	while (file_str[f_i] != '\n')
		f_i++;
	param = gen_param(file_str, f_i - 1);
	free(file_str);
	return (param);
}
