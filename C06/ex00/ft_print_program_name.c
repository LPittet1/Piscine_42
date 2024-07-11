/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_programme_name.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:49:59 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/27 11:26:46 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char **argv)
{
	int	len;

	len = 0;
	while (argv[0][len])
		len++;
	if (argc > 0)
		write(1, argv[0], len);
	write(1, "\n", 1);
}
