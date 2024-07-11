/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:17:15 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/23 14:49:00 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	ft_pos(int i, int j, int x, int y)
{
	if ((j == 0 && i == 0) || (j == 0 && i == x - 1))
	{
		ft_putchar('A');
	}
	else if ((j == y - 1 && i == 0) || (j == y - 1 && i == x - 1))
	{
		ft_putchar('C');
	}
	else if (j == 0 || j == y - 1 || i == 0 || i == x - 1)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

int	rush_02(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
	{
		return (1);
	}
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			ft_pos(i, j, x, y);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	return (0);
}
