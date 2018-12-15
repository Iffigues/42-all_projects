/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:39:16 by aljacque          #+#    #+#             */
/*   Updated: 2018/12/06 17:47:46 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

t_piece	*ft_convers(t_piece *tab)
{
	int i;
	int j;
	int k;

	i = -1;
	j = -1;
	k = -1;
	while (tab[++i].piece[0][0])
	{
		while (++j < 4)
		{
			while (++k < 4)
				if (tab[i].piece[j][k] == '#')
					tab[i].piece[j][k] = 'A' + i;
			k = -1;
		}
		j = -1;
	}
	return (tab);
}
