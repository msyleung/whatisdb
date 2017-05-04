/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_columns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:43:30 by sleung            #+#    #+#             */
/*   Updated: 2017/05/03 17:40:43 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	add_cols_help(t_schema *a, int trash, FILE *fd, FILE *ft)
{
	int	i;

	i = trash;
	rewind(fd);
	fwrite(&(a->coloms), sizeof(int), 1, ft);
	fread(&trash, sizeof(int), 1, fd);
	i = 0;
	while (i < a->coloms)
	{
		fseek(ft, 0, SEEK_END);
		fwrite(a->names[i], sizeof(char) * SIZE, 1, ft);
		i++;
	}
	print_schema(a);
	copy_rows(a, fd, trash, ft);
	fclose(fd);
	fclose(ft);
}

void		add_columns(t_schema *a, FILE *fd, char *db)
{
	FILE	*ft;
	int		i;
	int		trash;

	ft = fopen("tmp.dat", "a+");
	i = a->coloms;
	trash = i;
	printf("Enter number of new columns?\n");
	scanf("%i", &(a->coloms));
	printf("Total columns: %i\n", i + a->coloms);
	a->names = (char **)realloc(a->names, (i + a->coloms) * sizeof(char *));
	a->coloms = i + a->coloms;
	printf("columns=%i\n", a->coloms);
	while (i < a->coloms)
	{
		a->names[i] = (char *)malloc(SIZE);
		printf("\nEnter name of the colom #%i:\n", i + 1);
		scanf("%s", a->names[i]);
		i++;
	}
	add_cols_help(a, trash, fd, ft);
	remove(db);
	rename("tmp.dat", db);
	fd = fopen(db, "a+");
}
