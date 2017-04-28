/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 14:32:22 by sleung            #+#    #+#             */
/*   Updated: 2017/04/27 17:53:18 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static void	print_menu_options(int option, FILE *fd)
{
	while (option != 0)
	{
		printf("\n\t%s%sChoose one of", CYAN, BOLD_ON);
		printf("the options:%s%s\n\t", BOLD_OFF, RESET);
		printf("1: add/save\n\t2: view\n\t3: modify\n\t");
		printf("4: delete\n\t0: exit\n\n");
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
}

int			main(void)
{
	int		authorized;
	FILE	*fd;

	ft_welcome_msg();
	if (!(authorized = ft_secure()))
		return (0);
	fd = fopen("file.txt", "r+");
	print_menu_options(1, fd);
	fclose(fd);
	return (0);
}
