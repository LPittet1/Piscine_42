/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:53:22 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/24 13:46:32 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '\0')
		return (to_find);
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			i++;
			j++;
		}
		else
		{
			j = 0;
			i++;
		}
		if (to_find[j] == '\0')
			return (&str[i - j]);
	}
	return (NULL);
}
