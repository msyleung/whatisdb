/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 16:33:30 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/02 15:46:28 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_schema(FILE *fd, t_schema *a)
{
//	FILE	*ft;
	int i;

	i = 0;
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
//	ft = fopen("tmp.dat", "wb");
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

int		main(void)
{
	char		db_name[50]; 
	FILE		*fd;
	t_schema	a;
	int			option;

	printf("\nEnter the name of the new DB:\n"); //or existing?
	scanf("%s", db_name);
	fd = fopen(db_name, "a+");
	printf("Which option do you want?\n");
	while (option != 0)
	{
		printf("\n1: add\n2: read\n9: clear\n0: exit\n");
		scanf("%i", &option);
		if (option == 1)
			get_schema(fd, &a);
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
