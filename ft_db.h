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

#ifndef
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

struct	s_data
{
	char	*first_name;
	char	*last_name;
	int		birthyear;
	int		phonenumber;
	char	*curr_proj;
}		t_data;

#endif
