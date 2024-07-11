/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbey <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:21:56 by lpittet           #+#    #+#             */
/*   Updated: 2024/07/10 08:53:45 by jbarbey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_param
{
	int		lines;
	char	empty;
	char	obst;
	char	full;
}	t_param;

typedef struct s_map
{
	int		str_len;
	char	*str;
}	t_map;

typedef struct s_line
{
	int	start;
	int	end;
}	t_line;

typedef struct s_square
{
	int	line;
	int	index;
	int	size;
}	t_square;

// utils.c
int			ft_strlen(char *str);
char		*ft_strcat(char *s1, char *s2);
int			ft_atoi(char *str);
void		free_all(t_map *map);
t_map		*solve_and_print(t_map *map, t_param param);

// utils2.c
char		*ft_calloc(int n_items, int size_item);
char		*ft_realloc(char *old_ptr, int old_size, int new_size);
int			ft_count_file_lines(char *file_str);
char		*ft_strndup(char *src, int size);
void		map_error(void);

// read_stdin.c
int			line_len(char *str);
int			get_line_amount(char *buf, int ret, int line_amount);
int			print_nl(void);
char		*read_stdin(void);
int			mini_main(void);

// parse_param.c
char		*read_param(char *path);
t_param		gen_param(char *file_str, int end);
t_param		parse_param(char *path);

// parse_map.c
char		*read_map(char *path);
t_line		gen_index(char *file_str, int f_i);
t_map		*gen_map(char *file_str, int f_i);
t_map		*parse_map(char *path);

// is_map_valid.c
int			check_line_len(t_map *map, t_param params);
int			check_line_content(t_map *map, t_param params);
int			check_params_valid(t_param params);
int			map_valid(t_map *map, t_param param);

// print_answer.c
void		print_answer(t_param params, t_map *map);

// solver.c
int			is_safe_line(char *line, int size, int index, t_param param);
int			is_safe_col(t_map *map, t_square temp, t_param param);
t_square	solver(t_map *map, t_param param);
t_map		*fill_map(t_map *map, t_square square, t_param param);

# define TRUE 1
# define FALSE 0
# define ERROR 0

#endif