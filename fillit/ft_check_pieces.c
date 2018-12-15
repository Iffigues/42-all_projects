/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:09:32 by aljacque          #+#    #+#             */
/*   Updated: 2018/12/08 19:25:44 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

static int	ft_check_link(char tab[4][4], int j, int i)
{
	int link;

	link = 0;
	if (j != 0)
		if (tab[j - 1][i] == '#')
			link++;
	if (j != 3)
		if (tab[j + 1][i] == '#')
			link++;
	if (i != 0)
		if (tab[j][i - 1] == '#')
			link++;
	if (i != 3)
		if (tab[j][i + 1] == '#')
			link++;
	return (link);
}

static int	ft_count_elem(char tab[4][4])
{
	int i;
	int j;
	int elem;

	i = 0;
	j = -1;
	elem = 0;
	while (++j < 4)
	{
		while (i < 4)
			if (tab[j][i++] == '#')
				elem++;
		i = 0;
	}
	if (elem == 4)
		return (1);
	return (0);
}

static int	ft_check_piece(char tab[4][4])
{
	int i;
	int j;
	int link;

	i = -1;
	j = -1;
	link = 0;
	while (++j < 4)
	{
		while (++i < 4)
			if (tab[j][i] == '#')
				link = link + ft_check_link(tab, j, i);
		i = -1;
	}
	if (link == 6 || link == 8)
		return (1);
	return (0);
}

void		ft_check_pieces(t_piece *tab, int fd)
{
	int i;

	i = -1;
	while (tab[++i].piece[0][0])
	{
		if (!(ft_check_piece(tab[i].piece)))
			ft_print_error(fd, 1);
		if (!(ft_count_elem(tab[i].piece)))
			ft_print_error(fd, 1);
	}
}
