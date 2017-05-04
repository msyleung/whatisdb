/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_row.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:20:04 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/04 15:51:58 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mod_options(t_schema *a, FILE *fd, char *buff, int num)
{
	int		option;
	char	tmp[SIZE + 1];

	option = 1;
	print_schema(a);
	view_one(a, buff, num);
	printf("Enter the number of the colunm you want to modify:\n");
	view_columns(a);
	fseek(fd, -(SIZE * a->coloms), SEEK_CUR);
	printf("0: Back\n");
	scanf("%i", &option);
	if (option)
	{
		printf("Enter the %s:\n", a->names[option - 1]);
		scanf("%s", &buff[(option - 1) * SIZE]);
		fwrite(buff, SIZE * a->coloms, 1, fd);
	}
}

void	mod_row(t_schema *a, FILE *fd, char *db_name)
{
	int		option;
	int		i;
	int		flag;
	char	buff[SIZE * a->coloms];

	i = 0;
	flag = 0;
	printf("Enter the ID of the field you want to modify:\n");
	scanf("%i", &option);
	fclose(fd);
	fd = fopen(db_name, "r+");
	fseek(fd, sizeof(int) + SIZE * a->coloms, SEEK_CUR);
	while (fread(buff, SIZE * a->coloms, 1, fd) == 1)
	{
		if (i == option - 1)
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 1)
		mod_options(a, fd, buff, option);
	else
		printf("There's no such ID\n");
}
