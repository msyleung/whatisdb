/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 15:25:35 by sleung            #+#    #+#             */
/*   Updated: 2017/04/27 16:09:49 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_error_security(char *msg)
{
	printf("%s", msg);
	return (0);
}

void	ft_error(int opt)
{
	printf("You entered: '%i' || Error: Invalid usage.\n", opt);
}
