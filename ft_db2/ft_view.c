/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 11:15:55 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/03 12:02:19 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_schema(t_schema *a)
{
	int i;
	int len;
	int j;
	int space;

	i = 0;
	while (i < a->coloms)
	{
		j = 0;
		len = strlen(a->names[i]);
		space = (SIZE / 2 - len) / 2;
		printf("|");
		while (j++ < space)
			printf(" ");
		printf("%s", a->names[i]);
		while (space-- >= 0)
			printf(" ");
		printf("|");
		i++;
	}
	printf("\n");
	i = 0;
	while (i++ <= (SIZE / 2 + 3) * a->coloms )
		printf("-");
	printf("\n");
}


void	view_one(t_schema *a, char *str)
{
	int i;
	int j;
	int len;

	i = 0;
	while (i < a->coloms)
	{
		j = 0;
		printf("| %s", &str[i * SIZE]);
		len = strlen(&str[i * SIZE]);
		while (j++ < SIZE / 2 - len)
			printf(" ");
		printf("|");
		i++;
	}
	printf("\n");
}

void	view_all(FILE *fd)
{
	t_schema a;
	int read;

	a = ft_read_schema(fd);
	int i = 0;
	rewind(fd);
	ft_print_schema(&a);

	char buff[SIZE * a.coloms];
	fseek(fd, a.coloms * SIZE + sizeof(int), SEEK_CUR);
//	printf("fread=%zu\n", fread(buff, SIZE * a.coloms, 1, fd) );
	while ((read = fread(buff, SIZE * a.coloms, 1, fd)) == 1)
	{
	//	printf("\n!!!!read=%i\n", read);
		view_one(&a, buff);
	}
//	printf("read=%i\n", i);
//	printf("buf=%s\n", buff);
}
