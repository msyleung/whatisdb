/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:32:22 by sleung            #+#    #+#             */
/*   Updated: 2017/04/27 16:21:18 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_add_save(FILE *fd)
{
	t_data	a;

	fseek(fd, 0, SEEK_END);
	printf("%sEnter 50 characters of First Name:%s\n", BOLD_ON, BOLD_OFF RESET);
	scanf("%s", a.first_name);
	printf("%sEnter Last name:%s\n", BOLD_ON, BOLD_OFF RESET);
	scanf("%s", a.last_name);
	printf("%sEnter Year of birth:%s\n", BOLD_ON, BOLD_OFF RESET);
	scanf("%s", a.birthyear);
	printf("%sEnter Phone number:%s\n", BOLD_ON, BOLD_OFF RESET);
	scanf("%s", a.phonenumber);
	printf("%sEnter Current project:%s\n", BOLD_ON, BOLD_OFF RESET);
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

char	*ft_search_option(int opt)
{
	if (opt == 1)
		return ("First Name");
	else if (opt == 2)
		return ("Last Name");
	else
		return ("Current Project");
}

void	ft_search_io(FILE *fd)
{
	t_data	a;
	int		found;
	int		opt;
	char	input[50];

	found = 0;
	opt = 4;
	while (opt != 1 && opt != 2 && opt != 3)
	{
		printf("\n\t%sHow do you want to look up the student?%s\n\t", CYAN BOLD_ON, RESET BOLD_OFF);
		printf("%sEnter a number:%s\n\t1: First Name\n\t2: Last Name\n\t3: Current Project\n\t0: (exit)\n", CYAN, RESET);
		scanf("%i", &opt);
		if (opt == 0)
			return ;
	}
	printf("\tEnter %s:\n", ft_search_option(opt));
	scanf("%s", input);
	while (fread(&a, sizeof(a), 1, fd) == 1)
	{
		if (((strcmp(input, a.first_name) == 0) && opt == 1) ||
				((strcmp(input, a.last_name) == 0) && opt == 2) ||
				((strcmp(input, a.curr_proj) == 0) && opt == 3))
		{
			ft_view_one(a);
			found = 1;
		}
	}
	if (found == 0)
		printf("%s\tThere's no such student\n%s", RED, RESET);
}

void	ft_view(FILE *fd)
{
	t_data a;
	char option[2];

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
		ft_search_io(fd);
}

int		main(void)
{
	int option;
	int	authorized;
	FILE *fd;

	ft_welcome_msg();
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
