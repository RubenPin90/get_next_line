/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:56:21 by rpinchas          #+#    #+#             */
/*   Updated: 2022/12/02 11:26:59 by rpinchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*tschuessibaba(char **c)
{
	if (*c == NULL)
		return (NULL);
	free(*c);
	*c = NULL;
	return (NULL);
}

char	*save_new_line(char **line)
{
	char	*rest;
	char	*print;
	char	*ptr2;
	char	*tmp;
	int		l_len;

	if (!ft_strchr(*line, '\n'))
		ptr2 = "";
	else
		ptr2 = ft_strchr(*line, '\n') + 1;
	l_len = ft_strlen(*line) - (ft_strlen(ptr2) + 1) + 1;
	rest = (char *) ft_calloc(sizeof(char), (ft_strlen(ptr2) + 1));
	if (!rest)
		return (0);
	ft_strlcpy(rest, ptr2, (ft_strlen(ptr2) + 1));
	print = (char *) ft_calloc(sizeof(char), l_len + 1);
	if (!print)
		return (0);
	ft_strlcpy(print, *line, l_len + 1);
	tmp = *line;
	*line = rest;
	free(tmp);
	return (print);
}

char	*read_line(int fd, char *save)
{
	char	*buf;
	char	*tmp;
	int		rd;

	if (save == NULL)
	{
		save = (char *) ft_calloc(sizeof(char), 1);
		if (!save)
			return (NULL);
	}
	rd = 1;
	while (!ft_strchr(save, '\n') && (rd > 0))
	{
		buf = (char *) ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (tschuessibaba(&save));
		tmp = save;
		save = ft_strjoin(tmp, buf);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[10000];
	char		*print;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (tschuessibaba(&save[fd]));
	save[fd] = read_line(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	if (save[fd][0] == '\0')
		return (tschuessibaba(&save[fd]));
	print = save_new_line(&save[fd]);
	if (!ft_strchr(print, '\n') && save[fd][0] == '\0')
	{
		free(save[fd]);
		save[fd] = NULL;
	}
	return (print);
}
