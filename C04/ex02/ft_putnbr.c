/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:14:27 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/26 09:27:36 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	t;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
		ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		t = nb % 10;
		nb = nb / 10;
		ft_putnbr(nb);
		ft_putchar(t + 48);
	}
	else if (nb < 10)
	{
		ft_putchar(nb + 48);
	}
}
