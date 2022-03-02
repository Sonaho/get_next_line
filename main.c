/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:19:48 by aalmela-          #+#    #+#             */
/*   Updated: 2022/02/15 11:51:13 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*s;
	int		fd;
	int		i;

	fd = open("files/multiple_nl.txt", O_RDONLY);
	i = 0;
	while (i < 13)
	{
		s = get_next_line(fd);
		printf("%s", s);
		i ++;
	}
	close(fd);
	return (0);
}
