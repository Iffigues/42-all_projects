/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:09:57 by coremart          #+#    #+#             */
/*   Updated: 2018/12/07 17:36:33 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include <unistd.h>

void	ft_print_res(const char **tab, size_t size)
{
	size_t	i;
	size_t	j;
	char	point;

	i = 0;
	j = 0;
	point = '.';
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i][j])
				write(1, &tab[i][j], 1);
			else
				write(1, &point, 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}
