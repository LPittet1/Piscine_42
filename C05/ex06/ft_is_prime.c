/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:25:34 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/26 17:23:47 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	f_sqrt(int nb)
{
	int	i;

	i = 0;
	while (nb > i * i)
		i++;
	return (i);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	max;

	i = 2;
	max = f_sqrt(nb);
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	while (i <= max)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}
