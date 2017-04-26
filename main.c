/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:32:22 by sleung            #+#    #+#             */
/*   Updated: 2017/04/24 17:05:38 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_add_save(FILE *fd)
{
	t_data	a;

	fseek(fd, 0, SEEK_END);
	printf("Enter First name:\n");
	scanf("%s", a.first_name);
	printf("Here's your input: %s\n",a.first_name);
	printf("Enter Last name:\n");
	scanf("%s", a.last_name);
	printf("Enter Year of birth:\n");
	scanf("%s", a.birthyear);
	printf("Enter Phone number:\n");
	scanf("%s", a.phonenumber);
	printf("last_name: %s\n", a.last_name);
	printf("Enter Current project:\n");
	scanf ("%s", a.curr_proj);

	fwrite(&a, sizeof(a), 1, fd);
//	fflush(stdin);
}

void	ft_view_one(t_data a)
{
	printf("\n********************\n");
	printf("First name: %s\n", a.first_name);
	printf("Last name: %s\n", a.last_name);
	printf("Year of birthday: %s\n", a.birthyear);
	printf("Phone number: %s\n", a.phonenumber);
	printf("Current project: %s\n", a.curr_proj);
}

void	ft_view(FILE *fd)
{
	t_data a;
	char *option;
	char last_name[50];

	printf("Do you want to view all?\nEnter: [Y/N]\n");

	scanf("%s", option);
	printf("Before rewind\n");
	rewind(fd);
	printf("After rewind\n");
//	printf("MY options:%c\n", option);


	if (option[0] == 'Y')
	{
	//	printf("***1***");
		while (fread(&a, sizeof(a), 1, fd) == 1)
			ft_view_one(a);

	//	printf("***2***");
		return ;
	}
	else
	{
		printf("Enter Last name of the student:\n");
		scanf("%s", last_name);
	}
		printf("Entered last name:%s\n", last_name);
		
	//	printf("***3***");
	while (fread(&a, sizeof(a), 1, fd) == 1)
	{

//		printf("***4***");

		if (strcmp(last_name, a.last_name) == 0)
		{
			
/*			printf("\n********************\n");
	printf("First name: %s\n", a.first_name);
	printf("Last name: %s\n", a.last_name);
	printf("Year of birthday: %s\n", a.birthyear);
	printf("Phone number: %s\n", a.phonenumber);
	printf("Current project: %s\n", a.curr_proj);*/
	ft_view_one(a);
			return ;
		}
	}
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
		printf("\n\tChoose one of the options:\n\t 1: add/save\n\t 2: view\n\t 3: modify\n\t 4: delete\n\t 0: exit\n\n");
		scanf("%d", &option);
		if (option == 1)
			ft_add_save(fd);
		else if (option == 2)
			ft_view(fd);
		else if (option == 4)
			ft_del(fd);
		else if (option == 0)
			break ;
		else
			ft_error(option);
	}
	return (0);
}
