/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:27:26 by sleung            #+#    #+#             */
/*   Updated: 2017/05/05 15:25:40 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_file(void)
{
	DIR				*imanidiot;
	DIR				*mydir;
	struct dirent	*myfile;
	int				yes;

	yes = 0;
	mydir = opendir(".");
	printf("Current databases available:\n");
	while ((myfile = readdir(mydir)) != NULL)
	{
		if (myfile->d_name[0] != '.' && strcmp(myfile->d_name, "Makefile") != 0
				&& strcmp(myfile->d_name, "whatisdb") != 0
				&& strcmp(myfile->d_name, "author") != 0)
		{
			if ((imanidiot = opendir(myfile->d_name)) != NULL)
				closedir(imanidiot);
			else
			{
				printf("| %s ", myfile->d_name);
				yes = 1;
			}
		}
	}
	if (yes)
		printf("|\n");
	closedir(mydir);
}
