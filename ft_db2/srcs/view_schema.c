/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_schema.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:15:55 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/05 18:07:33 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_schema(t_schema *a)
{
	int i;
	int len;
	int j;
	int space;

	i = 0;
	printf("\n| %s#%s ", B_ON, RES);
	while (i < a->coloms)
	{
		j = 0;
		len = strlen(a->names[i]);
		space = (SIZE / 2.5 - len) / 2;
		printf("|");
		while (j++ < space)
			printf(" ");
		printf("%s%s%s", B_ON, a->names[i], RES);
		while (space-- >= 0)
			printf(" ");
		printf("|");
		i++;
	}
	printf("\n");
	while (space++ <= (SIZE / 2.5 + 3) * a->coloms)
		printf("-");
	printf("\n");
}

void	view_one(t_schema *a, char *str, int num)
{
	int		i;
	int		j;
	int		len;
	char	c;

	i = 0;
	c = (num < 10) ? '0' : '\0';
	printf("|%c%i", c, num);
	while (i < a->coloms)
	{
		j = 0;
		printf("| %s", &str[i * SIZE]);
		len = strlen(&str[i * SIZE]);
		while (j++ < (SIZE / 2.5 - len - 1))
			printf(" ");
		printf("|");
		i++;
	}
	printf("\n");
}

void	view_all(FILE *fd, t_schema *a)
{
	int			read;
	int			i;
	char		buff[SIZE * a->coloms];

	i = 0;
	rewind(fd);
	print_schema(a);
	fseek(fd, a->coloms * SIZE + sizeof(int), SEEK_CUR);
	while ((read = fread(buff, SIZE * a->coloms, 1, fd)) == 1)
	{
		view_one(a, buff, i + 1);
		i++;
	}
}

void	help_search(t_schema *a, int *option)
{
	printf("%s\nChoose the key you want to search by:%s\n", B_ON, RES);
	view_columns(a);
	scanf("%i", option);
	(*option)--;
	printf("%s\nEnter the %s:%s\n", B_ON, a->names[*option], RES);
}

void	search(t_schema *a, FILE *fd)
{
	int		i;
	int		option;
	int		count;
	char	buff[SIZE * a->coloms];
	char	search[SIZE];

	count = 0;
	help_search(a, &option);
	scanf("%s", search);
	rewind(fd);
	fseek(fd, sizeof(int) + SIZE * a->coloms, SEEK_CUR);
	i = 0;
	while (fread(buff, SIZE * a->coloms, 1, fd) == 1)
	{
		count++;
		if (strcmp(&buff[SIZE * option], search) == 0)
		{
			i++;
			if (i == 1)
				print_schema(a);
			view_one(a, buff, count);
		}
	}
	if (i == 0)
		printf("\n %s'%s' not found%s\n", B_ON, search, RES);
}
