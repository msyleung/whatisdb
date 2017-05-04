/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 16:33:30 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/03 17:59:18 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_row(t_schema *a, FILE *fd)
{
	int buff_size;
	char buff[SIZE * a->coloms + 1];
	char tmp[SIZE + 1];
	int i;

	i = 0;
	fseek(fd, 0, SEEK_END);
	buff_size = a->coloms * SIZE;
	while (i < a->coloms)
	{
		printf("Enter the %s:\n", a->names[i]);
		scanf("%s", tmp);
		memcpy(&buff[i * (SIZE)], tmp, SIZE );
		i++;
	}
	//	buff[buff_size] = '\0';
	int write_return = fwrite(buff, buff_size, 1, fd);
//	printf("write_return=%i", write_return);
	//testing
/*	rewind(fd);
	char delete_me[SIZE * a->coloms + 1];
	fseek(fd, 4 + a->coloms * SIZE, SEEK_CUR);
	fread(delete_me, buff_size, 1, fd);
	i = 0;
	while (i < a->coloms)
	{
		printf("Result:%s\n", &delete_me[i * SIZE]);
		i++;
	}*/

//	view_all(&fd);

}

void copy_rows(t_schema *a, FILE *fd, int trash, FILE *ft)
{
	char buff[a->coloms * SIZE];
	int i = 0;
t_schema t;

	rewind(fd);
	printf("\nAAAAAAAAA\n");
	t = ft_read_schema(ft);
	ft_print_schema(&t);
	fseek(fd, 4 + trash * SIZE, SEEK_CUR);
	//	fseek(ft, 4 + a->coloms * SIZE, SEEK_CUR);
	while (fread(buff, trash * SIZE, 1, fd) == 1)
	{
		bzero(&buff[trash * SIZE], (a->coloms - trash) * SIZE);
		fseek(ft, 0, SEEK_END);
		fwrite(buff, a->coloms * SIZE, 1, ft);
	}
	//testing
/*	printf("\n------\n");
//	rewind(ft);
	char delete_me[SIZE * a->coloms + 1];
	fseek(ft, 0, SEEK_END);
	fseek(ft, -(a->coloms * SIZE), SEEK_CUR);
	fread(delete_me, SIZE * a->coloms, 1, ft);
	i = 0;
	ft_read_schema(ft);
	ft_print_schema(a);
//	printf("a->names[0]: %s | buff[0]: %s |\n", a->names[1], &buff[1]);
	while (i < a->coloms)
	{
		printf("Result_del: %s\n", &delete_me[i * SIZE]);
		i++;
	}*/
}


void	get_schema(FILE *fd, t_schema *a, char *db)
{
	FILE	*ft;
	char	b[SIZE];
	int		trash;
	int		i;

	i = 0;
	if (a->names == 0)
	{
		printf("\nEnter number of columns:\n");
		scanf("%i", &(a->coloms));
		a->names = (char **)malloc(sizeof(char *) * a->coloms);
		while (i < a->coloms)
		{
			a->names[i] = (char *)malloc(SIZE);
			printf("\nEnter name of the column #%i:\n", i + 1);
			scanf("%s", a->names[i]);
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
	else
	{
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
		ft_print_schema(a);
		copy_rows(a, fd, trash, ft);
		fclose(fd);
		fclose(ft);
		remove(db);
		rename("tmp.dat", db);
		fd = fopen(db, "a+");
	}
}



t_schema	ft_read_schema(FILE *fd)
{
	int			i;
	char		b[50];
	int			num;
	t_schema	a;

	rewind(fd);
	i = 0;
	fread(&num, sizeof(int), 1, fd); 
	a.coloms = num;
	a.names = (char **)malloc(sizeof(char *) * a.coloms);

	//printf("columns: %i\n", num);
	while (i < a.coloms)
	{	
		a.names[i] = (char *)malloc(SIZE);
		fread(a.names[i], SIZE, 1, fd);
		i++;
	}
	return (a);
}

void	ft_del_columns(FILE *fd)
{
	FILE *ft;
	char	d[50];

}

int		main(void)
{
	char		db_name[50]; 
	FILE		*fd;
	t_schema	a;
	int			option;


	printf("\nEnter the name of the DB:\n"); //or existing?
	scanf("%s", db_name);
	fd = fopen(db_name, "a+");
	printf("Which option do you want?\n");
	while (option != 0)
	{
		printf("\n1: create schema and add rows \n2: view all\n");
		printf("4: add new row\n5: add new columns\n6: search\n9: clear\n0: exit\n");
		scanf("%i", &option);
		if (option != 1)
			a = ft_read_schema(fd);
		if (option == 1)
		{
			a.names = 0;
			a.coloms = 0;
			get_schema(fd, &a, db_name);
			add_row(&a, fd);
		}
		else if (option == 2)
			view_all(fd, &a);
		else if (option == 3)
			ft_del_columns(fd);
		else if (option == 4)
			add_row(&a, fd);
		else if (option == 5)
			get_schema(fd, &a, db_name);
		else if (option == 6)
			search(&a, fd);
		else if (option == 9)
			clear_screen();
		printf("\n");
	}

/*	t_schema delete_me = ft_read_schema(fd);
	int i = 0;
	while (i < delete_me.coloms)
	{
		printf("%s\n", delete_me.names[i]);
		i++;
	}*/
	return (0);
}
