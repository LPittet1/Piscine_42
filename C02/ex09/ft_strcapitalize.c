/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitaize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:58:25 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/24 09:59:55 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alphanum(char str)
{
	if ('a' <= str && str <= 'z')
	{
		return (1);
	}
	if ('A' <= str && str <= 'Z')
	{
		return (2);
	}
	if ('0' <= str && str <= '9')
	{
		return (3);
	}
	else if (' ' <= str)
	{
		return (0);
	}
	return (10);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 || ft_char_is_alphanum(str[i - 1]) == 0)
			&& (ft_char_is_alphanum(str[i]) == 1))
		{
			str[i] -= 32;
		}
		if (((ft_char_is_alphanum(str[i - 1]) == 1)
				|| (ft_char_is_alphanum(str[i - 1]) == 2)
				|| (ft_char_is_alphanum(str[i - 1]) == 3))
			&& (ft_char_is_alphanum(str[i]) == 2))
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}
