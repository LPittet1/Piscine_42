/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:29:07 by lpittet           #+#    #+#             */
/*   Updated: 2024/07/02 14:50:57 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef int	t_bool;
# define EVEN(nbr) nbr % 2 == 0
# define TRUE 0
# define FALSE 1
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd numbers of arguments.\n"
# define SUCCESS 0

#endif
