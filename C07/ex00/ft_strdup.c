/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:42:30 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/28 13:17:56 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*dup;

	len = 0;
	while (src[len])
		len++;
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	len = 0;
	while (src[len])
	{
		dup[len] = src[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}
