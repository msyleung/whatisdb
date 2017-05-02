/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 16:33:30 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/02 15:47:59 by adosiak          ###   ########.fr       */
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



void	get_schema(FILE fd, t_schema *a)
{
	char coloms[3];
	int i;

	i = 0;
	printf("\n\tEnter number of coloms:\n");
	scanf("%s",coloms);
	a->coloms = atoi(coloms);
	a->names = (char **)malloc(sizeof(char *) * a->coloms);
	while (i < a->coloms)
	{
		a->names[i] = (char *)malloc(50);
		printf("\nEnter name of the colom #%i:\n", i + 1);
		scanf("%s", a->names[i]);
		i++;
	}
}

int		main(void)
{
	char db_name[50]; 
	FILE *fd;
	t_schema a;
	int i = 0;

	printf("\n\tEnter the name of the new DB:\n");
	scanf("%s", db_name);
	fd = fopen(db_name, "a+");
	get_schema(*fd, &a);
/*	while (i < a.coloms)
	{
		printf("%s\n", a.names[i]);
		i++;
	}*/
	add_row(&a, *fd);
	return (0);
}
