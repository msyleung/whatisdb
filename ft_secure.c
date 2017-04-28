/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_secure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 12:11:05 by sleung            #+#    #+#             */
/*   Updated: 2017/04/27 18:29:31 by adosiak          ###   ########.fr       */
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
	authorized = DENIED;
	printf("\n\t\t%s%sUnauthorized Access%s\n", RED, BOLD_ON, RESET);
	printf("\n\tUsername: ");
	scanf("%s", u_input);
	if (strcmp(u_input, p.username) != 0)
		return (ft_error_security("\tUser not found\n"));
	printf("\tPassword: ");
	scanf("%s", p_input);
	if (strcmp(p.password, p_input) != 0)
		return (ft_error_security("\tIncorrect Password!\n"));
	else if ((strcmp(u_input, p.username) == 0)
			&& (strcmp(p.password, p_input) == 0))
	{
		authorized = ALLOWED;
		printf("\n\t\t%s%sAccess Granted%s\n", GREEN, BOLD_ON, RESET);
	}
	return (authorized);
}
