/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:32:22 by sleung            #+#    #+#             */
/*   Updated: 2017/04/24 14:38:02 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_add_save(FILE *fd)
{
	t_data	a;
	int	we;

	printf("Enter First name:\n");
	we = scanf("%s", a.first_name);
//	printf("Here's your input: %i, %s", we, a.first_name);
	printf("Enter Last name:\n");
	we = scanf("%s", a.last_name);
	printf("%s", a.last_name);
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
	
	printf("First name: %s\n", a.first_name);
	printf("Last name: %s\n", a.last_name);
	printf("Year of birthday: %s\n", a.birthyear);
	printf("Phone namber: %s\n", a.phonenumber);
	printf("Current project: %s\n", a.curr_proj);
}

void	ft_view(FILE *fd)
{
	t_data a;
	char *option;
	char last_name[50];

	printf("Do you want to view all?\nEnter: Y\\N\n");
	scanf("%s", option);
//	printf("MY options:%c\n", option);


//	fread(&a, sizeof(a), 1, fd);
//	ft_view_one(a);

	if (option[0] == 'Y')
	{
		printf("***1***");
		while (fread(&a, sizeof(a), 1, fd))
			ft_view_one(a);

		printf("***2***");
		return ;
	}
	else
	{
		printf("Enter Last name of the student:\n");
		scanf("%s", last_name);
	}
		
		printf("***3***");
	while (fread(&a, sizeof(a), 1, fd))
	{

		printf("***4***");
		if (last_name == a.last_name)
		{
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
	printf("\n\tChose one of the options:\n\t 1: add/save\n\t 2: view\n\t 3: modify\n\t 4: delete\n\n");
	scanf("%d", &option);
	if (option == 1)
		ft_add_save(fd);
	else if (option == 2)
		ft_view(fd);
/*	else if (option == 3)
		ft*/


	return (0);

}
