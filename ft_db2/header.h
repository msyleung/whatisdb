/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:58:55 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/03 18:08:30 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <assert.h>
# include <ctype.h>
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
# define GREEN	"\x1b[32m"
# define YELLOW	"\x1b[33m"
# define BLUE	"\x1b[34m"
# define MAGENTA	"\x1b[95m"
# define CYAN	"\x1b[36m"
# define WHITE	"\x1b[37m"
# define RESET	"\x1b[0m"
# define BOLD_ON	"\x1b[1m"
# define DENIED	0
# define ALLOWED 1

# define SIZE 50

typedef struct	s_schema
{
	int 		coloms;
	char		**names;
}				t_schema;

t_schema		ft_read_schema(FILE *fd);
void			ft_print_schema(t_schema *a);
void			view_all(FILE *fd, t_schema *a);
void			clear_screen(void);
void			search(t_schema *a, FILE *fd);
void			view_columns(t_schema *a);
#endif
