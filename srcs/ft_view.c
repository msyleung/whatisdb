/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:44:58 by sleung            #+#    #+#             */
/*   Updated: 2017/04/27 18:29:50 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void		ft_view_one(t_data a)
{
	printf("\n********************\n");
	printf("First name: %s\n", a.first_name);
	printf("Last name: %s\n", a.last_name);
	printf("Year of birthday: %s\n", a.birthyear);
	printf("Phone number: %s\n", a.phonenumber);
	printf("Current project: %s", a.curr_proj);
	printf("\n********************\n");
}

static int	ft_search_opt(int opt)
{
	while (opt != 1 && opt != 2 && opt != 3 && opt != 0)
	{
		printf("\n\t%s%sHow do you want to look up", CYAN, BOLD_ON);
		printf("the student?%s\n\t", RESET);
		printf("%sEnter a number:%s\n\t", CYAN, RESET);
		printf("1: First Name\n\t2: Last Name");
		printf("\n\t3: Current Project\n\t0: (exit)\n");
		scanf("%i", &opt);
	}
	return (opt);
}

void		ft_search_io(FILE *fd)
{
	t_data	a;
	int		found;
	int		opt;
	char	input[50];

	found = 0;
	if (!(opt = ft_search_opt(4)))
		return ;
	printf("\tEnter %s:\n", opt != 3 ? ft_option(opt) : "Current Project");
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

void		ft_view(FILE *fd)
{
	t_data	a;
	char	option[2];

	printf("%sDo you want to view all?\nEnter: [Y/N]%s\n", BOLD_ON, RESET);
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
