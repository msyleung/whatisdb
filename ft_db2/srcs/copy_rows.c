/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_rows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:04:50 by sleung            #+#    #+#             */
/*   Updated: 2017/05/05 12:52:57 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void copy_rows(t_schema *a, FILE *fd, int trash, FILE *ft)
{
	char buff[a->coloms * SIZE];
//	t_schema t;

	rewind(fd);
	fseek(fd, 4 + trash * SIZE, SEEK_CUR);
	while (fread(buff, trash * SIZE, 1, fd) == 1)
	{
		bzero(&buff[trash * SIZE], (a->coloms - trash) * SIZE);
		fseek(ft, 0, SEEK_END);
		fwrite(buff, a->coloms * SIZE, 1, ft);
	}
}
