/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:41:52 by jbarbey           #+#    #+#             */
/*   Updated: 2024/07/08 20:39:46 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_calloc(int n_items, int size_item)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = malloc(n_items * size_item);
	if (ptr == ERROR)
		return (ERROR);
	while (i < n_items * size_item)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_realloc(char *old_ptr, int old_size, int new_size)
{
	int		i;
	char	*new_ptr;

	i = 0;
	new_ptr = ft_calloc(new_size, sizeof(char));
	if (new_ptr == ERROR)
		return (ERROR);
	while (i < old_size)
	{
		new_ptr[i] = old_ptr[i];
		i++;
	}
	free(old_ptr);
	return (new_ptr);
}

int	ft_count_file_lines(char *file_str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (file_str[i])
	{
		if (file_str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	*ft_strndup(char *src, int size)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (size + 1));
	if (dest == ERROR)
		return (ERROR);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	map_error(void)
{
	write(2, "map error\n", 10);
}
