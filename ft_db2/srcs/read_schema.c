/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_schema.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:22:04 by sleung            #+#    #+#             */
/*   Updated: 2017/05/05 18:39:16 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_schema	read_schema(FILE *fd)
{
	int			i;
	int			num;
	t_schema	a;

	rewind(fd);
	i = 0;
	fread(&num, sizeof(int), 1, fd);
	a.coloms = num;
	a.names = (char **)malloc(sizeof(char *) * a.coloms);
	while (i < a.coloms)
	{
		a.names[i] = (char *)malloc(SIZE);
		fread(a.names[i], SIZE, 1, fd);
		i++;
	}
	return (a);
}
