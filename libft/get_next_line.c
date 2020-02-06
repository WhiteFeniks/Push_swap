/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 21:26:41 by umoff             #+#    #+#             */
/*   Updated: 2020/02/03 21:26:43 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_new_line(char **buffer, char **line, int fd, int read_bytes)
{
	char	*tmp;
	int		len;

	len = 0;
	while (buffer[fd][len] != '\n' && buffer[fd][len])
		len++;
	if (buffer[fd][len] == '\n')
	{
		*line = ft_strsub(buffer[fd], 0, len);
		tmp = ft_strdup(buffer[fd] + len + 1);
		free(buffer[fd]);
		buffer[fd] = tmp;
		if (buffer[fd][0] == '\0')
			ft_strdel(&buffer[fd]);
	}
	else if (buffer[fd][len] == '\0')
	{
		if (read_bytes == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(buffer[fd]);
		ft_strdel(&buffer[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char *buffer[FD_MAX];
	char		s[BUFF_SIZE + 1];
	char		*tmp;
	int			read_bytes;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((read_bytes = read(fd, s, BUFF_SIZE)) > 0)
	{
		s[read_bytes] = '\0';
		if (buffer[fd] == NULL)
			buffer[fd] = ft_strnew(1);
		tmp = ft_strjoin(buffer[fd], s);
		free(buffer[fd]);
		buffer[fd] = tmp;
		if (ft_strchr(s, '\n'))
			break ;
	}
	if (read_bytes < 0)
		return (-1);
	else if (read_bytes == 0 && (buffer[fd] == NULL || buffer[fd][0] == '\0'))
		return (0);
	return (ft_new_line(buffer, line, fd, read_bytes));
}
