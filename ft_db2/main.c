/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 16:33:30 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/04 12:44:19 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(void)
{
	char		db_name[50]; 
	FILE		*fd;
	t_schema	a;
	int			option;

	printf("\nEnter the name of the DB:\n");
	scanf("%s", db_name);
	fd = fopen(db_name, "a+");
	printf("Which option do you want?\n");
	while (option != 0)
	{
		printf("\n1: create schema and add rows \n2: view all\n");
		printf("4: add new row\n5: add new columns\n6: search\n");
		printf("7: modify record\n8: delete record\n9: clear\n0: exit\n");

		scanf("%i", &option);
		if (option != 1)
			a = read_schema(fd);
		if (option == 1)
		{
			a.names = 0;
			a.coloms = 0;
			get_schema(&a, fd);
			add_row(&a, fd);
		}
		else if (option == 2)
			view_all(fd, &a);
		//		else if (option == 3)
		//			del_columns(fd);
		else if (option == 4)
			add_row(&a, fd);
		else if (option == 5)
			add_columns(&a, fd, db_name);
		else if (option == 6)
			search(&a, fd);
		else if (option == 7)
			mod_row(&a, fd, db_name);
		else if (option == 8)
			del_row(&a, fd, db_name);
		else if (option == 9)
			clear_screen();
		printf("\n");
	}
	return (0);
}
