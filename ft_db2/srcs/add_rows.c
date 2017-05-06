/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rows.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:03:47 by sleung            #+#    #+#             */
/*   Updated: 2017/05/05 17:29:43 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_row(t_schema *a, FILE *fd)
{
	int buff_size;
	char buff[SIZE * a->coloms + 1];
	char *tmp;
	int	write_return;
	int i;

	i = 0;
	fseek(fd, 0, SEEK_END);
	buff_size = a->coloms * SIZE;
	while (i < a->coloms)
	{
		printf("Enter the %s:\n", a->names[i]);
//		scanf("%s", tmp);
		tmp = (char *)malloc(SIZE);
		tmp = getline_yay();
		memcpy(&buff[i * (SIZE)], tmp, SIZE );
		free(tmp);
		i++;
	}
	write_return = fwrite(buff, buff_size, 1, fd);
}
