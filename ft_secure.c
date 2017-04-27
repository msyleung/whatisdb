/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:11:05 by sleung            #+#    #+#             */
/*   Updated: 2017/04/27 12:38:12 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int	ft_secure(void)
{
	t_pass	p;
	char	u_input[50];
	char	p_input[50];
	int		authorized;

	p.username = "Root";
	p.password = "Root";
	printf("\n\t%s======== Unauthorized Access =======%s\n", RED BOLD_ON, RESET BOLD_OFF);
	printf("\n\tEnter Username:\n\t");
	scanf("%s", u_input);
	printf("\tEnter Password:\n\t");
	scanf("%s", p_input);
	authorized = DENIED;
	if (strcmp(u_input, p.username) != 0)
		printf("\tUser not found\n");
	else if ((strcmp(u_input, p.username) == 0) && (strcmp(p.password, p_input) != 0))
		printf("\tIncorrect Password!\n");
	else if ((strcmp(u_input, p.username) == 0) && (strcmp(p.password, p_input) == 0))
	{
		authorized = ALLOWED;
		printf("\n\t%s======= Access Granted =======%s\n", GREEN BOLD_ON, RESET BOLD_OFF);
	}
	return (authorized);
}
