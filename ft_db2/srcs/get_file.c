/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 13:27:26 by sleung            #+#    #+#             */
/*   Updated: 2017/05/05 15:53:36 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	get_file_help(char *filename, int *yes)
{
	DIR				*imanidiot;

	if (filename[0] != '.' && strcmp(filename, "Makefile") != 0
			&& strcmp(filename, "whatisdb") != 0
			&& strcmp(filename, "author") != 0)
	{
		if ((imanidiot = opendir(filename)) != NULL)
			closedir(imanidiot);
		else
		{
			printf("| %s ", filename);
			*yes = 1;
		}
	}
}

void		get_file(void)
{
	DIR				*mydir;
	struct dirent	*myfile;
	int				yes;

	yes = 0;
	mydir = opendir(".");
	printf("%s\nCurrent databases available:%s\n", B_ON, RES);
	while ((myfile = readdir(mydir)) != NULL)
	{
		get_file_help(myfile->d_name, &yes);
	}
	if (yes)
		printf("|\n");
	closedir(mydir);
}
