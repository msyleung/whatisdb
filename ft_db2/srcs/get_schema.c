/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_schema.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:10:33 by sleung            #+#    #+#             */
/*   Updated: 2017/05/05 18:46:40 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_schema(t_schema *a, FILE *fd)
{
	int		i;

	i = 0;
	if (a->names == 0)
	{
		printf("\n%sEnter number of columns:%s\n", B_ON, RES);
		scanf("%i", &(a->coloms));
		a->names = (char **)malloc(sizeof(char *) * a->coloms);
		while (i < a->coloms)
		{
			a->names[i] = (char *)malloc(SIZE);
			printf("\n%sEnter name of the column #%i:%s\n", B_ON, i + 1, RES);
			a->names[i] = memcpy(a->names[i], getline_yay(), SIZE);
			i++;
		}
		i = 0;
		fwrite(&(a->coloms), sizeof(int), 1, fd);
		while (i < a->coloms)
		{
			fseek(fd, 0, SEEK_END);
			fwrite(a->names[i], sizeof(char) * SIZE, 1, fd);
			i++;
		}
	}
}
