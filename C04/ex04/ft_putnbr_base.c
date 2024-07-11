/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:35:38 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/26 09:38:56 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	len;
	int	j;

	len = 0;
	j = 1;
	while (base[len])
	{
		if (base[len] == '-' || base[len] == '+')
			return (0);
		while (base[j])
		{
			if (base[len] == base[j])
				return (0);
			j++;
		}
		len++;
		j = len + 1;
	}	
	if (len <= 1)
		return (0);
	return (len);
}

void	ft_putnbr(long int nb, char *base, int len)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb, base, len);
	}
	else if (nb >= len)
	{
		ft_putnbr(nb / len, base, len);
		ft_putchar(base[nb % len]);
	}
	else if (nb < len)
		ft_putchar(base[nb % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = check_base(base);
	if (len != 0)
		ft_putnbr(nbr, base, len);
}
