/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rows.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:03:47 by sleung            #+#    #+#             */
/*   Updated: 2017/05/03 17:04:37 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_row(t_schema *a, FILE *fd)
{
	int buff_size;
	char buff[SIZE * a->coloms + 1];
	char tmp[SIZE + 1];
	int i;

	i = 0;
	fseek(fd, 0, SEEK_END);
	buff_size = a->coloms * SIZE;
	while (i < a->coloms)
	{
		printf("Enter the %s:\n", a->names[i]);
		scanf("%s", tmp);
		memcpy(&buff[i * (SIZE)], tmp, SIZE );
		i++;
	}
	//	buff[buff_size] = '\0';
	int write_return = fwrite(buff, buff_size, 1, fd);
	//	printf("write_return=%i", write_return);
	//testing
	/*	rewind(fd);
	//				char delete_me[SIZE * a->coloms + 1];
	//					fseek(fd, 4 + a->coloms * SIZE, SEEK_CUR);
	//						fread(delete_me, buff_size, 1, fd);
	//							i = 0;
	//								while (i < a->coloms)
	//									{
	//											printf("Result:%s\n", &delete_me[i * SIZE]);
	//													i++;
	//														}*/
	//
	//														//	view_all(&fd);
}
