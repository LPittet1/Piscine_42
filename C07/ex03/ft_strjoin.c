/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:47:59 by lpittet           #+#    #+#             */
/*   Updated: 2024/07/02 10:08:13 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

int	totlen(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	len += (size - 1) * ft_strlen(sep);
	return (len);
}

char	*catstr(int size, char **strs, char *sep, char *join)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcat(join, strs[i]);
		if (i < size - 1)
			ft_strcat(join, sep);
		i++;
	}
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	int		len;
	int		i;

	len = 0;
	if (size == 0)
	{
		join = malloc(sizeof(char));
		join[0] = '\0';
		return (join);
	}
	len = totlen(size, strs, sep);
	join = malloc(sizeof(char) * (len + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	join[0] = '\0';
	join = catstr(size, strs, sep, join);
	return (join);
}
