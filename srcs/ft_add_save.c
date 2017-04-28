/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 17:44:19 by sleung            #+#    #+#             */
/*   Updated: 2017/04/27 18:13:00 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_add_save(FILE *fd)
{
	t_data	a;

	fseek(fd, 0, SEEK_END);
	printf("%sEnter 50 characters of First Name:%s\n", BOLD_ON, RESET);
	scanf("%s", a.first_name);
	printf("%sEnter Last name:%s\n", BOLD_ON, RESET);
	scanf("%s", a.last_name);
	printf("%sEnter Year of birth:%s\n", BOLD_ON, RESET);
	scanf("%s", a.birthyear);
	printf("%sEnter Phone number:%s\n", BOLD_ON, RESET);
	scanf("%s", a.phonenumber);
	printf("%sEnter Current project:%s\n", BOLD_ON, RESET);
	scanf("%s", a.curr_proj);
	fwrite(&a, sizeof(a), 1, fd);
}
