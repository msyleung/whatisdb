/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:03:40 by sleung            #+#    #+#             */
/*   Updated: 2017/05/03 17:25:04 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clear_screen(void)
{
	int	n;

	n = -1;
	while (++n < 10)
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
