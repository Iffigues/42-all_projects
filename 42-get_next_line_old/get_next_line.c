/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:01:42 by aljacque          #+#    #+#             */
/*   Updated: 2018/11/20 18:33:17 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int		get_next_line(const int fd, char **line)
{
	static char		*str[256];
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				rd;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	if (!(str[fd]) && (str[fd] = ft_strnew(1)) == NULL)
		return (-1);
	while (!(ft_strchr(str[fd], '\n')) && (rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if (ft_strlen(str[fd]) == 0)
		return (0);
	*line = ft_strsub(str[fd], 0, ft_strclen(str[fd], '\n'));
	tmp = str[fd];
	str[fd] = ft_strsub(tmp, ft_strclen(str[fd], '\n') + 1,
	ft_strlen(&str[fd][ft_strclen(str[fd], '\n')]));
	ft_strdel(&tmp);
	return (1);
}
