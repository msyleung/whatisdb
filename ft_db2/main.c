/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 16:33:30 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/02 13:22:27 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void	get_schema(FILE fd, t_schema *a)
{
	char coloms[3];
	int i;

	i = 0;

	printf("\n\tEnter number of coloms:\n");
	scanf("%s",coloms);

	a->coloms = atoi(coloms);
	a->names = (char **)malloc(sizeof(char *) * a->coloms);
	a->types= (int *)malloc(sizeof(int) * a->coloms);

	while (i < a->coloms)
	{

		a->names[i] = (char *)malloc(50);
		printf("\nEnter name of the colom #%i:\n", i + 1);
		scanf("%s", a->names[i]);

		printf("\nEnter type of the colom #%i:\n", i + 1);
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
	fd = fopen(db_name, "a");
	get_schema(*fd, &a);
	while (i < a.coloms)
	{
		printf("%s\n", a.names[i]);
		i++;
	}
	return (0);
}

	


