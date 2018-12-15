/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:52:53 by aljacque          #+#    #+#             */
/*   Updated: 2018/11/26 16:28:05 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_next(int fd, char **str, char **line)
{
	char	*tmp;

	if (str[fd][ft_strclen(str[fd], '\n')] == '\n')
	{
		if (!(*line = ft_strsub(str[fd], 0, ft_strclen(str[fd], '\n'))))
			return (0);
		tmp = str[fd];
		if (!(str[fd] = ft_strsub(tmp, ft_strclen(str[fd], '\n') + 1,
		ft_strlen(str[fd]))))
			return (0);
		ft_strdel(&tmp);
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][ft_strclen(str[fd], '\n')] == '\0')
	{
		if (!(*line = ft_strdup(str[fd])))
			return (0);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			rd;
	static char	*str[FD_NBR];
	char		*tmp;
	char		buf[BUFF_SIZE + 1];

	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if (str[fd] == NULL)
			if (!(str[fd] = ft_strnew(0)))
				return (0);
		tmp = str[fd];
		if (!(str[fd] = ft_strjoin(tmp, buf)))
			return (0);
		ft_strdel(&tmp);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (rd < 0)
		return (-1);
	else if ((str[fd] == NULL || str[fd][0] == '\0') && rd == 0)
		return (0);
	return (ft_next(fd, str, line));
}
