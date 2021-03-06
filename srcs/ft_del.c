/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:40:34 by sleung            #+#    #+#             */
/*   Updated: 2017/04/27 17:40:39 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static void	ft_del_get_input(t_data *to_del)
{
	t_data	x;

	printf("Enter LAST NAME of student to delete\n");
	scanf("%s", x.last_name);
	printf("Enter the PHONE NUMBER of student to delete\n");
	scanf("%s", x.phonenumber);
	*to_del = x;
}

void		ft_del(FILE *fp)
{
	FILE	*ft;
	t_data	d;
	t_data	to_del;
	char	yes;

	yes = 'Y';
	while (yes == 'Y' || yes == 'y')
	{
		ft_del_get_input(&to_del);
		ft = fopen("tmp.dat", "wb");
		rewind(fp);
		while (fread(&d, sizeof(d), 1, fp) == 1)
		{
			if ((strcmp(d.last_name, to_del.last_name) != 0) ||
					(strcmp(d.phonenumber, to_del.phonenumber) != 0))
				fwrite(&d, sizeof(d), 1, ft);
		}
		fclose(fp);
		fclose(ft);
		remove("file.txt");
		rename("tmp.dat", "file.txt");
		fp = fopen("file.txt", "rb+");
		printf("\nDelete another record? [Y/N]\n");
		scanf("%s", &yes);
	}
}
