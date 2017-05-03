/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 16:33:30 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/03 11:17:09 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_row(t_schema *a, FILE *fd)
{
	int buff_size;
	char buff[SIZE * a->coloms + 1];
	char tmp[SIZE + 1];
	char delete_me[SIZE * a->coloms + 1];
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


void	get_schema(FILE *fd, t_schema *a)
{
//	FILE	*ft;
	int i;

	i = 0;
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
//	ft = fopen("tmp.dat", "wb");
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

void	clear_screen(void)
{
	int	n;

	n = -1;
	while (++n < 10)
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
		printf("\n1: create schema and add rows \n2: view all\n4: add new row\n9: clear\n0: exit\n");
		scanf("%i", &option);
		if (option == 1)
		{
			get_schema(fd, &a);
			add_row(&a, fd);
		}
		else if (option == 2)
			view_all(fd);
		else if (option == 3)
			ft_del_columns(fd);
		else if (option == 4)
		{
			a = ft_read_schema(fd);
		/*	printf("\nSCHEMA:\n");
			printf("int=%ii\n", a.coloms);
			printf("col_1:%s\n", a.names[0]);
			printf("col_2:%s\n", a.names[1]);*/
			add_row(&a, fd);
		}
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
