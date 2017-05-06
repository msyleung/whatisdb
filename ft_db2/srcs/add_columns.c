/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_columns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 16:43:30 by sleung            #+#    #+#             */
/*   Updated: 2017/05/05 17:44:04 by sleung           ###   ########.fr       */
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
	copy_rows(a, fd, trash, ft);
	view_all(ft, a);
	fclose(fd);
	fclose(ft);
}

char	*getline_yay(void)
{
	char	*str;
	size_t	size;

	size = 0;
	str = (char *)malloc(sizeof(char) * SIZE + 1);
	memset(str, '\0', SIZE + 1);
	str[0] = '\n';
	while (str[0] == '\n')
		getline(&str, &size, stdin);
	str[strlen(str) - 1] = '\0';
	if (strlen(str) > 50)
	{
		printf("%sInput too long [< 50 chars] Try again:%s\n", B_ON, RES);
		free(str);
		str = NULL;
		return (getline_yay());
	}
	return (str);
}

void		add_columns(t_schema *a, FILE *fd, char *db)
{
	FILE	*ft;
	int		i;
	int		trash;

	ft = fopen("tmp.dat", "a+");
	i = a->coloms;
	trash = i;
	printf("%sEnter number of new columns?%s\n", B_ON, RES);
	scanf("%i", &(a->coloms));
	a->names = (char **)realloc(a->names, (i + a->coloms) * sizeof(char *));
	a->coloms = i + a->coloms;
	while (i < a->coloms)
	{
		a->names[i] = (char *)malloc(SIZE);
		printf("\n%sEnter name of the column #%i:%s\n", B_ON, i + 1, RES);
//		scanf("%s", a->names[i]);
		a->names[i] = memcpy(a->names[i], getline_yay(), SIZE);
//		printf("a->names[i]: [%s]\n", a->names[i]);
		i++;
	}
	add_cols_help(a, trash, fd, ft);
	remove(db);
	rename("tmp.dat", db);
	fd = fopen(db, "a+");
}
