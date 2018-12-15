/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:35:39 by aljacque          #+#    #+#             */
/*   Updated: 2018/12/07 17:44:03 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

static int		ft_check_move_top(char tab[4][4])
{
	int i;

	i = 0;
	while (i < 4 && tab[0][i] != '#')
		i++;
	if (i == 4)
		return (1);
	return (0);
}

static int		ft_check_move_left(char tab[4][4])
{
	int i;

	i = 0;
	while (i < 4 && tab[i][0] != '#')
		i++;
	if (i == 4)
		return (1);
	return (0);
}

static void		ft_move_top(char tab[4][4])
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (j < 4)
	{
		while (++i < 3)
			tab[i][j] = tab[i + 1][j];
		tab[i][j] = '.';
		j++;
		i = -1;
	}
}

static void		ft_move_left(char tab[4][4])
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (i < 4)
	{
		while (++j < 3)
			tab[i][j] = tab[i][j + 1];
		tab[i][j] = '.';
		i++;
		j = -1;
	}
}

t_piece			*ft_shift_pieces(t_piece *tab)
{
	int i;

	i = -1;
	while (tab[++i].piece[0][0])
	{
		while (ft_check_move_top(tab[i].piece))
			ft_move_top(tab[i].piece);
		while (ft_check_move_left(tab[i].piece))
			ft_move_left(tab[i].piece);
	}
	return (tab);
}
