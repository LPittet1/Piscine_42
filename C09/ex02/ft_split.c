/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:58:07 by lpittet           #+#    #+#             */
/*   Updated: 2024/07/11 15:07:02 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str, int j, int i)
{
	int		len;
	int		a;
	char	*dup;

	a = 0;
	len = (i - j) + 1;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (j < i)
	{
		dup[a] = str[j];
		j++;
		a++;
	}
	dup[a] = '\0';
	return (dup);
}

int	in_charset(char a, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (a == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	split = (char **)malloc(sizeof(char *) * ft_strlen(str));
	if (split == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && in_charset(str[i], charset) == 1)
			i++;
		j = i;
		while (str[i] && in_charset(str[i], charset) == 0)
			i++;
		if (j < i)
		{
			split[k] = ft_strdup(str, j, i);
			k++;
		}
			
	}
	split[k] = 0;
	return (split);
}
#include<stdio.h>
int main()
{
	int i = 0;
	char *str = "bachbjla ajl";
	char *sep = "a";
	char **tab;
	tab = ft_split(str, sep);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free(tab);
}
