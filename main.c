/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:19:48 by aalmela-          #+#    #+#             */
/*   Updated: 2022/02/09 12:58:41 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char	*s;
	int		fd;
	int		i;

	fd = open("files/full.txt", O_RDONLY);
	i = 1;
	while (i)
	{
		printf("%s", s);
		s = get_next_line(fd);
		if (!s)
			break ;
	}
	close(fd);
	return (0);
}
