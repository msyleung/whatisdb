/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:32:22 by sleung            #+#    #+#             */
/*   Updated: 2017/04/27 12:36:13 by sleung           ###   ########.fr       */
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
	printf("Current project: %s", a.curr_proj);
	printf("\n********************\n");
}

void	ft_view(FILE *fd)
{
	t_data a;
	int	found;
	char option[2];
	char last_name[50];

	printf("%sDo you want to view all?\nEnter: [Y/N]%s\n",
					BOLD_ON, BOLD_OFF RESET);
	scanf("%s", option);
	rewind(fd);
	if (option[0] == 'Y' || option[0] == 'y')
	{
		while (fread(&a, sizeof(a), 1, fd) == 1)
			ft_view_one(a);
	}
	else if (option[0] == 'N' || option[0] == 'n')
	{
		printf("%sEnter Last name of the student:%s\n",
					BOLD_ON, BOLD_OFF RESET);
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

void	ft_mod_option(t_data *a, FILE *fd, int option)
{			
	if (option == 1)
		scanf("%s", a->first_name);
	else if (option == 2)
		scanf("%s", a->last_name);
	else if (option == 3)
		scanf("%s", a->birthyear);
	else if (option == 4)
		scanf("%s", a->phonenumber);
	else if (option == 5)
		scanf("%s", a->curr_proj);
	else 
		fwrite(a, sizeof(*a), 1, fd);
}

char *ft_option(int option)
{
	if (option == 1)
		return ("First name");
	else if (option == 2)
		return ("Last name");
	else if (option == 3)
		return ("Year of birth");
	else if (option == 4)
		return ("Phone number");
	else if (option == 5)
		return ("Current project");
//	else if (option == 0)
	//	return ("Saved");
	return ("option");
}
void	ft_mod(FILE *fd)
{
	t_data a;
	int option;
	int	found;
	char last_name[50];

	rewind(fd);
	printf("\n%sEnter Last name of the student to modify:%s\n",
					BOLD_ON, BOLD_OFF RESET);
	scanf("%s", last_name);

	while (fread(&a, sizeof(a), 1, fd) == 1)
	{
		found = 0;
		if (strcmp(last_name, a.last_name) == 0)
		{
			printf("\n\t%sData of the student you're modifying:%s\n",
					BOLD_ON, BOLD_OFF RESET);
			ft_view_one(a);
			fseek(fd, -sizeof(t_data), SEEK_CUR);
			found = 1;
			break ;
		}
	}
	if (found)
	{		
		option = 1;
		while (option)
		{
			printf("\n\t%sChoose a field to modify:%s\n\t 1: First name\n\t 2: Last name\n\t 3: Year of birth\n\t 4: Phone number\n\t 5: Current_project\n\t 0: Done\n\n", CYAN BOLD_ON, BOLD_OFF RESET);
			scanf("%d", &option);
			printf("\n%sEnter new %s:%s\n",BOLD_ON, ft_option(option), BOLD_OFF RESET);
			if (option < 0 || option > 5)
				continue ;
			ft_mod_option(&a, fd, option);
		}
	}
	if (found == 0)
		printf ("There's no such student\n");
}

int		main(void)
{
	int option;
	int	authorized;
	FILE *fd;

	if (!(authorized = ft_secure()))
		return (0);
	fd = fopen("file.txt", "r+");
	option = 1;
	while (option)
	{
		printf("\n\t%sChoose one of the options:%s\n\t 1: add/save\n\t 2: view\n\t 3: modify\n\t 4: delete\n\t 0: exit\n\n", CYAN BOLD_ON, BOLD_OFF RESET);
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
