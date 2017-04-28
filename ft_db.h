/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:06:11 by sleung            #+#    #+#             */
/*   Updated: 2017/04/27 16:09:12 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

# define RED	"\x1b[31m"
# define GREEN	"\x1b[32m"
# define YELLOW	"\x1b[33m"
# define BLUE	"\x1b[34m"
# define MAGENTA	"\x1b[95m"
# define CYAN	"\x1b[36m"
# define WHITE	"\x1b[37m"
# define RESET	"\x1b[0m"
# define BOLD_ON	"\x1b[1m"
# define BOLD_OFF	"\x1b[21m"
# define DENIED	0
# define ALLOWED 1

typedef struct s_pass
{
	char	*username;
	char	*password;
}				t_pass;

typedef struct	s_data
{
	char	first_name[50];
	char	last_name[50];
	char	birthyear[5];
	char	phonenumber[10];
	char	curr_proj[50];
}		t_data;

int			main(void);
void		ft_welcome_msg(void);
void		ft_add_save(FILE *fd);
void		ft_view(FILE *fd);
void		ft_view_one(t_data a);
void		ft_del(FILE *fd);
void		ft_error(int opt);
int			ft_error_security(char *msg);
int			ft_secure(void);
void		ft_mod(FILE *fd);
char		*ft_option(int option);


#endif
