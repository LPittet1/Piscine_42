/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:28:00 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/27 14:16:04 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort(int argc, char **argv)
{
	int		i;
	char	*t;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			t = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = t;
			if (i != 1)
				i--;
		}
		else
			i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	len;

	i = 1;
	ft_sort(argc, argv);
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		write(1, argv[i], len);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
