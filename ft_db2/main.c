/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 16:33:30 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/02 18:59:39 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_row(t_schema *a, FILE fd)
{
	int buff_size;
	char buff[SIZE * a->coloms + 1];
	char tmp[SIZE + 1];
	char delete_me[SIZE * a->coloms + 1];
	int i;

	i = 0;
	buff_size = a->coloms * SIZE;
	while (i < a->coloms)
	{
		printf("Enter the %s:\n", a->names[i]);
		scanf("%s", tmp);
		memcpy(&buff[i * (SIZE)], tmp, 50 );
		i++;
	}
//	buff[buff_size] = '\0';
fwrite(buff, buff_size, 1, &fd);

	//testing
/*fread(delete_me, buff_size, 1, &fd);
i = 0;
while (i < a->coloms)
	{
		printf("Result:%s\n", &buff[i * SIZE]);
		i++;
	}
*/
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
		printf("\nEnter number of coloms:\n");
		scanf("%i", &(a->coloms));
		a->names = (char **)malloc(sizeof(char *) * a->coloms);
		while (i < a->coloms)
		{
			a->names[i] = (char *)malloc(50);
			printf("\nEnter name of the colom #%i:\n", i + 1);
			scanf("%s", a->names[i]);
			i++;
		}
		i = 0;
		//	fwrite(a, sizeof(char) * SIZE * a->coloms + 4 + sizeof(char *), 1, fd);
		fwrite(&(a->coloms), sizeof(int), 1, fd);
		while (i < a->coloms)
		{
			fseek(fd, 0, SEEK_END);
			//		fwrite(a, sizeof(char) * SIZE * a->coloms + 4, 1, fd);
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
		a->names = (char **)realloc(a->names, i + a->coloms);
		a->coloms = i + a->coloms;
		while (i < a->coloms)
		{
			a->names[i] = (char *)malloc(50);
			printf("\nEnter name of the colom #%i:\n", i + 1);
			scanf("%s", a->names[i]);
			i++;
		}
		i = trash;
		rewind(fd);
		fwrite(&(a->coloms), sizeof(int), 1, ft);
		fread(&trash, sizeof(int), 1, fd);
		while (fread(&b, sizeof(char) * SIZE, 1, fd) == 1)
			fwrite(&b, sizeof(char) * SIZE, 1, ft);
		while (i < a->coloms)
		{
			fseek(ft, 0, SEEK_END);
			fwrite(a->names[i], sizeof(char) * SIZE, 1, ft);
			i++;
		}
		fclose(fd);
		fclose(ft);
		remove(db);
		rename("tmp.dat", db);
		fd = fopen(db, "a+");
	}
}

void	ft_read_file(FILE *fd)
{
	int			i;
	char	b[50];
	int		num;

	rewind(fd);
	i = 0;
	fread(&num, sizeof(int), 1, fd);
	printf("columns: %i\n", num);
	while (fread(&b, sizeof(char) * SIZE, 1, fd) == 1)
	{
		printf("| %s | ", b);
	}
	printf("\n");
}

void	ft_del_columns(FILE *fd)
{
	FILE *ft;
	char	d[50];

}

void	clear_screen(void)
{
	int	n;

	n = -1;
	while (++n < 10)
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void	init_schema(t_schema *a, int first, FILE *fd)
{
	int	i;

	i = -1;
	if (first == 0)
	{
		fread(&a->coloms, sizeof(int), 1, fd);
		a->names = (char **)malloc(sizeof(char *) * a->coloms);
		while (++i < a->coloms)
			a->names[i] = (char *)malloc(SIZE);
		i = 0;
		while (fread(a->names[i], sizeof(char) * SIZE, 1, fd) == 1)
			printf("| %s | ", a->names[i++]);
		printf("\n\n");
	}
	else
	{
		a->coloms = 0;
		a->names = 0;
	}
}

int		main(void)
{
	char		db_name[50]; 
	FILE		*fd;
	t_schema	a;
	int			option;
	int			first;

	first = 0;
	printf("\nEnter the name of the Database or create new:\n");
	scanf("%s", db_name);
	if (!(fd = fopen(db_name, "r+")))
	{
		fd = fopen(db_name, "a+");
		first = 2;
	}
	init_schema(&a, first, fd);
	printf("Which option do you want?\n");
	while (option != 0)
	{
		if (first == 1 && option != 2)
			ft_read_file(fd);
		first = 1;
		printf("\n1: add\n2: read\n9: clear\n0: exit\n");
		scanf("%i", &option);
		if (option == 1)
		{
			get_schema(fd, &a, db_name);
//			add_row(&a, *fd);
		}
		else if (option == 2)
			ft_read_file(fd);
		else if (option == 3)
			ft_del_columns(fd);
		else if (option == 9)
			clear_screen();
		printf("\n");
	}
	return (0);
}
