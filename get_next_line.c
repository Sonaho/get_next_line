/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:36:40 by aalmela-          #+#    #+#             */
/*   Updated: 2022/02/09 12:56:57 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clear_buffer(char *buff_file)
{
	char	*ret;
	int		sizebuffer;
	int		sizeline;

	sizebuffer = ft_strlen(buff_file);
	if (ft_findchr(buff_file, '\n') > 0)
		sizeline = ft_findchr(buff_file, '\n') + 1;
	else
		sizeline = ft_findchr(buff_file, '\0');
	ret = ft_substr(buff_file, sizeline, sizebuffer - sizeline);
	free (buff_file);
	if (ft_strlen(ret) == 0)
		return (NULL);
	return (ret);
}

static char	*get_line_toreturn(char *buff_file)
{
	char	*ret;
	int		tmp;

	tmp = ft_findchr(buff_file, '\n') + 1;
	//printf("\ntmp \\n %d\n", tmp);
	if (tmp == 0)
	{	
		tmp = ft_findchr(buff_file, '\0');
	//	printf("\ntmp \\0 %d\n", tmp);
	}
	if (tmp > 0)
		ret = ft_substr(buff_file, 0, tmp);
	else
		return (NULL);
	return (ret);
}

static char	*read_next_line(char *b_file, int fd)
{
	char	*line;
	char	*tmp;
	int		numchars;

	line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	numchars = 1;
	while (numchars > 0 && (ft_findchr(b_file, '\n') < 0))
	{
		numchars = read(fd, line, BUFFER_SIZE);
		if (numchars == -1)
			break ;
		line[numchars] = '\0';
		tmp = ft_strjoin(b_file, line);
		free (b_file);
		b_file = tmp;
	}
	free (line);
	return (b_file);
}

char	*get_next_line(int fd)
{
	static char	*buff_file;
	char		*ret_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (buff_file == NULL)
	{
		buff_file = (char *)malloc(sizeof(char));
		if (!buff_file)
			return (NULL);
		buff_file[0] = 0;
	}
	buff_file = read_next_line(buff_file, fd);
	if (!buff_file)
		return (NULL);
	ret_line = get_line_toreturn(buff_file);
	if (!ret_line)
		return (NULL);
	buff_file = clear_buffer(buff_file);
	return (ret_line);
}
