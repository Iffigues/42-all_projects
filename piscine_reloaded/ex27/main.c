/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:03:44 by aljacque          #+#    #+#             */
/*   Updated: 2018/11/06 17:06:41 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		size;
	char	buf[4097];

	if (ac < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	else if (ac > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	size = read(fd, buf, 4096);
	buf[size] = 0;
	ft_putstr(buf);
	return (0);
}
