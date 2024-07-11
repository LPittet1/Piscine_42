/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 08:42:04 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/30 14:05:48 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_tab(char *tab)
{
	int	i;

	i = 0;
	while (i <= 15)
	{
		write(1, &tab[i], 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}	
}

int	test_args(int i, char *str)
{
	if ((check_input(i, str) == 1) || (check_input2(str) == 1)
		|| (check_input4(str) == 1))
	{
		return (1);
	}
	if (check_comb(str) == 1)
	{
		return (1);
	}
	return (0);
}

char	*create_tab(char *str)
{
	char	*tab;
	char	*str2;
	int		i;

	i = 0;
	str2 = str;
	tab = malloc(16 * sizeof(char));
	while (i <= 15)
	{
		tab[i] = '0';
		i++;
	}
	tab = fill_tab_col(str2, tab, 0, 0);
	tab = fill_tab_row(str2, tab, 16, 0);
	tab = fill_tab_rest(str2, tab, 8, 12);
	tab = fill_tab_col1(str2, tab, 0, 0);
	tab = fill_tab_row1(str2, tab, 16, 0);
	tab = solve(tab);
	return (tab);
}

int	main(int argc, char **argv)
{
	char	*tab;
	int		i;

	i = 0;
	if (test_args(argc, argv[1]) == 1)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	tab = create_tab(argv[1]);
	if (ft_strcmp(tab, "Error") == 0)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	else
		print_tab(tab);
	free(tab);
	return (0);
}
