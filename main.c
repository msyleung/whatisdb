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
	printf("Here's your input: %i, %s", we, a.first_name);
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

/*void	ft_view(FILE *fd)
{*/




int	main(void)
{
	int option;
	FILE *fd;

	fd = fopen("file.txt", "r+");
	printf("\n\tChose one of the options:\n\t 1: add/save\n\t 2: view\n\t 3: modify\n\t 4: delete\n\n");
	scanf("%d", &option);
	if (option == 1)
		ft_add_save(fd);
/*	else if (option == 2)
		ft_view();
	else if (option == 3)
		ft*/


	return (0);

}
