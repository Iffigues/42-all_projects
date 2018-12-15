/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:03 by coremart          #+#    #+#             */
/*   Updated: 2018/12/08 19:23:27 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		fd;
	t_piece	*tab;

	if (ac != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_print_error(fd, 2);
	tab = ft_check_error(fd);
	ft_check_pieces(tab, fd);
	ft_shift_pieces(tab);
	ft_convers(tab);
	ft_fillit(tab, fd);
	return (0);
}
