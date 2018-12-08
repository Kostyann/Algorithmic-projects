/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmerkulo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:09:13 by kmerkulo          #+#    #+#             */
/*   Updated: 2018/11/07 13:09:16 by kmerkulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	ac = 1;
	int i = 0;
	int j = 0;
//
//		int fd = open(av[1], O_RDONLY);
//		int fd1 = open(av[2], O_RDONLY);
		char *line1;
		char *line2;
	//	char *line3;
	//	char *line4;
	//	char *line5;
	//	char *line6;
	//	char *line7;
int fd = 1;

	(get_next_line(fd, &line1));
	write(fd, "abc\n", 4);
	printf("LINE__%s\n", line1);
//    (get_next_line(fd, &line2));
//    printf("LINE____%s\n", line2);
//    (get_next_line(fd, &line3));
//    printf("LINE____%s\n", line3);
//    (get_next_line(fd, &line4));
//    printf("LINE____%s\n", line4);
//    (get_next_line(fd, &line5));
//    printf("LINE____%s\n", line5);
//    (get_next_line(fd, &line6));
//    printf("LINE____%s\n", line6);
//    (get_next_line(fd, &line7));
//    printf("LINE____%s\n", line7);
//
//    while ((i = get_next_line(0, &line1)) > 0)
//	{
//    	printf("%s\n", line1);
//	}

//	printf("%d\n", i);
//	get_next_line(fd, &line1);
//	printf("%s\n", line1);
	return (0);
}
