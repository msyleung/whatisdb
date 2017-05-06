/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_column.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 13:11:12 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/05 17:20:21 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	del_copy_rows(FILE *fd, FILE *ft, t_schema *a, int opt)
{
	int		i;
	int		j;
	char	buff_fd[SIZE * (a->coloms + 1)];
	char	buff_ft[SIZE * a->coloms];

	rewind(fd);
	fseek(fd, sizeof(int) + SIZE * (a->coloms + 1), SEEK_CUR);
	while (fread(buff_fd, sizeof(buff_fd), 1, fd) == 1)
	{
		j = 0;
		i = 0;
	//	printf("HERE!\n");
		while (i < a->coloms + 1)
		{
			if (i != opt - 1)
			{
				memcpy(&buff_ft[j * SIZE], &buff_fd[i * SIZE], SIZE);
				j++;
			}
			i++;
		}
		fseek(ft, 0, SEEK_END);
		fwrite(buff_ft, sizeof(buff_ft), 1, ft);
	}
}

void	del_column(t_schema *a, FILE *fd, char *db)
{
	int		opt;
	int		i;
	FILE	*ft;

	i = 0;
	ft = fopen("tmp.dat", "a+");
	printf("Choose the number of the colunm you want to delete:\n");
	view_columns(a);
	scanf("%i", &opt);
	if (opt == 0)
		return ;
	a->coloms--;
	fwrite(&a->coloms, sizeof(int), 1, ft);
	while (i < a->coloms + 1)
	{
		fseek(ft, 0, SEEK_END);
		if (i != (opt - 1))
			fwrite(a->names[i], SIZE, 1, ft);
		i++;
	}
	del_copy_rows(fd, ft, a, opt);
	*a = read_schema(ft);
	fclose(fd);
	fclose(ft);
	remove(db);
	rename("tmp.dat", db);
	fd = fopen(db, "r+");
}
