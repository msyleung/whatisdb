/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:58:55 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/05 17:22:06 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <assert.h>
# include <ctype.h>
# include <dirent.h>
# include <errno.h>
# include <float.h>
# include <limits.h>
# include <locale.h>
# include <math.h>
# include <signal.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# define RED	"\x1b[31m"
# define GRE	"\x1b[32m"
# define YEL	"\x1b[33m"
# define BLUE	"\x1b[34m"
# define MAG	"\x1b[95m"
# define CYA	"\x1b[36m"
# define WHI	"\x1b[37m"
# define RES	"\x1b[0m"
# define B_ON	"\x1b[1m"
# define DENIED	0
# define ALLOWED 1

# define SIZE 50

typedef struct	s_schema
{
	int			coloms;
	char		**names;
}				t_schema;

void			get_schema(t_schema *a, FILE *fd);
t_schema		read_schema(FILE *fd);
void			add_row(t_schema *a, FILE *fd);
void			add_columns(t_schema *a, FILE *fd, char *db);
void			copy_rows(t_schema *a, FILE *fd, int trash, FILE *ft);
void			print_schema(t_schema *a);
void			view_one(t_schema *a, char *str, int i);
void			view_all(FILE *fd, t_schema *a);
void			clear_screen(void);
void			search(t_schema *a, FILE *fd);
void			view_columns(t_schema *a);
void			mod_row(t_schema *a, FILE *fd, char *db_name);
void			del_row(t_schema *a, FILE *fd, char *db_name);
void			del_column(t_schema *a, FILE *fd, char *db_name);
void			get_file(void);
char			*getline_yay(void);
#endif
