/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:06:11 by sleung            #+#    #+#             */
/*   Updated: 2017/04/24 14:20:12 by sleung           ###   ########.fr       */
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

typedef struct	s_data
{
	char	first_name[50];
	char	last_name[50];
	char	birthyear[5];
	char	phonenumber[10];
	char	curr_proj[50];

}		t_data;

int			main(void);
void		ft_add_save(FILE *fd);
void		ft_view(FILE *fd);
void		ft_del(FILE *fd);
void		ft_error(int opt);


#endif
