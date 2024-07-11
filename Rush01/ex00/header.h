/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:59:24 by lpittet           #+#    #+#             */
/*   Updated: 2024/06/30 14:08:40 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

void	print_tab(char *tab);
int		test_args(int i, char *str);
char	*fill_tab_col(char *str, char *tab, int i, int j);
char	*fill_tab_row(char *str, char *tab, int i, int j);
char	*fill_tab_rest(char *str, char *tab, int i, int j);
char	*fill_tab_col1(char *str, char *tab, int i, int j);
char	*fill_tab_row1(char *str, char *tab, int i, int j);
char	*create_tab(char *str);
int		check_input(int count, char *str);
int		check_input2(char *str);
int		check_input3(char *str, int i, int j);
int		check_input4(char *str);
int		check_comb2(char *str, int i);
int		check_comb(char *str);
int		ft_strcmp(char *s1, char *s2);
int		is_free(char *tab);
int		num_is_ok_row(char *tab, int i, int num);
int		num_is_ok_col(char *tab, int i, int num);
char	*solve(char *tab);

#endif
