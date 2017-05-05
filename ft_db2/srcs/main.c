/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 16:33:30 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/05 12:52:03 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(void)
{
	char		db_name[50]; 
	FILE		*fd;
	t_schema	a;
	int			option;
	int 		file_size;

	option = 42;
	printf("\nEnter the name of the DB:\n");
	scanf("%s", db_name);
	fd = fopen(db_name, "a+");
	fseek(fd, 0, SEEK_END);
	file_size = ftell(fd);
	if (!file_size)
	{
		printf("\n Create schema of new DB\n");
		a.names = 0;
		a.coloms = 0;
		get_schema(&a, fd);
		print_schema(&a);
	}

	printf("Which option do you want?\n");
	a = read_schema(fd);
	while (option != 0)
	{
		printf("\n-------------------\nChange schema:\n-------------------\n");
		printf("1: add column\n2: delete column\n");

		printf("\n-------------------\nView:\n-------------------\n");
		printf("3: view all\n4: search\n");

		printf("\n-------------------\nModify data:\n-------------------\n");
		printf("5: add new record\n6: modify record\n7: delete record\n");

		printf("\n-------------------\n8: Clear the screen\n0: exit\n");
		scanf("%i", &option);
		if (option == 3)
			view_all(fd, &a);
		else if (option == 2)
			del_column(&a, fd, db_name);
		else if (option == 5)
			add_row(&a, fd);
		else if (option == 1)
			add_columns(&a, fd, db_name);
		else if (option == 4)
			search(&a, fd);
		else if (option == 6)
			mod_row(&a, fd, db_name);
		else if (option == 7)
			del_row(&a, fd, db_name);
		else if (option == 8)
			clear_screen();
		printf("\n");
	}
	return (0);
}
