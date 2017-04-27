/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:32:22 by sleung            #+#    #+#             */
/*   Updated: 2017/04/25 17:44:28 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_add_save(FILE *fd)
{
	t_data	a;

	fseek(fd, 0, SEEK_END);
	printf("Enter 50 characters of First Name:\n");
	scanf("%s", a.first_name);
	printf("Enter Last name:\n");
	scanf("%s", a.last_name);
	printf("Enter Year of birth:\n");
	scanf("%s", a.birthyear);
	printf("Enter Phone number:\n");
	scanf("%s", a.phonenumber);
	printf("Enter Current project:\n");
	scanf ("%s", a.curr_proj);

	fwrite(&a, sizeof(a), 1, fd);
}

void	ft_view_one(t_data a)
{
	printf("\n********************\n");
	printf("First name: %s\n", a.first_name);
	printf("Last name: %s\n", a.last_name);
	printf("Year of birthday: %s\n", a.birthyear);
	printf("Phone number: %s\n", a.phonenumber);
	printf("Current project: %s\n", a.curr_proj);
	printf("\n********************\n");
}

void	ft_view(FILE *fd)
{
	t_data a;
	int	found;
	char option[2];
	char last_name[50];

	printf("Do you want to view all?\nEnter: [Y/N]\n");
	scanf("%s", option);
	rewind(fd);
	if (option[0] == 'Y' || option[0] == 'y')
	{
		while (fread(&a, sizeof(a), 1, fd) == 1)
			ft_view_one(a);
	}
	else if (option[0] == 'N' || option[0] == 'n')
	{
		printf("Enter Last name of the student:\n");
		scanf("%s", last_name);
		//printf("Entered last name:%s\n", last_name);
		while (fread(&a, sizeof(a), 1, fd) == 1)
		{
			found = 0;
			if (strcmp(last_name, a.last_name) == 0)
			{
				ft_view_one(a);
				found = 1;
				break ;
			}
		}
		if (found == 0)
			printf ("There's no such student\n");
	}
}

void	ft_mod(FILE *fd)
{
	t_data a;
	int	found;
	char last_name[50];

	rewind(fd);
	printf("\nEnter Last name of the student to modify:\n");
	scanf("%s", last_name);

	while (fread(&a, sizeof(a), 1, fd) == 1)
	{
		found = 0;
		if (strcmp(last_name, a.last_name) == 0)
		{
			printf("\n\t%sData of the student you're modifying:%s\n",
					GREEN BOLD_ON, BOLD_OFF RESET);
			ft_view_one(a);
			fseek(fd, -sizeof(t_data), SEEK_CUR);
			found = 1;
			break ;
		}
	}
	if (found)
	{
		printf("%sEnter new  First Name:%s\n", BOLD_ON, BOLD_OFF RESET);
		scanf("%s", a.first_name);
		printf("Enter new Last name:\n");
		scanf("%s", a.last_name);
		printf("Enter new Year of birth:\n");
		scanf("%s", a.birthyear);
		printf("Enter new Phone number:\n");
		scanf("%s", a.phonenumber);
		printf("Enter new Current project:\n");
		scanf ("%s", a.curr_proj);

		fwrite(&a, sizeof(a), 1, fd);
	}

	if (found == 0)
		printf ("There's no such student\n");
}
int	main(void)
{
	int option;
	FILE *fd;

	fd = fopen("file.txt", "r+");
	option = 1;
	while (option)
	{
		printf("\n\t%sChoose one of the options:%s\n\t 1: add/save\n\t 2: view\n\t 3: modify\n\t 4: delete\n\t 0: exit\n\n", GREEN BOLD_ON, BOLD_OFF RESET);
		scanf("%d", &option);
		if (option == 1)
			ft_add_save(fd);
		else if (option == 2)
			ft_view(fd);
		else if (option == 3)
			ft_mod(fd);
		else if (option == 4)
			ft_del(fd);
		else if (option == 0)
			break ;
		else
			ft_error(option);
	}
	fclose(fd);
	return (0);
}
