/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_row.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adosiak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 11:58:06 by adosiak           #+#    #+#             */
/*   Updated: 2017/05/04 12:47:49 by adosiak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	del_row(t_schema *a, FILE *fd, char *db_name)
{
	int		option;
	FILE	*ft;
	int		i;
	char	buff[SIZE * a->coloms + sizeof(int)];

	i = 0;
	ft = fopen("tmp.dat", "wb");
	printf("Enter the ID of the record you want to delete:\n");
	scanf("%i", &option);
	rewind(fd);
	fread(buff, sizeof(buff), 1, fd);
	fwrite(buff, sizeof(buff), 1, ft);
	while (fread(buff, SIZE * a->coloms, 1, fd) == 1)
	{
		if (i != option - 1)
			fwrite(buff, SIZE * a->coloms, 1, ft);
		i++;
	}
	fclose(fd);
	fclose(ft);
	remove(db_name);
	rename("tmp.dat", db_name);
	fd = fopen(db_name, "r+");
	printf("\nDONE!\n");
}
