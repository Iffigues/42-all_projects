/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:07:48 by coremart          #+#    #+#             */
/*   Updated: 2018/12/08 19:25:27 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/fillit.h"
#include <stdlib.h>

static char	**ft_free_n_return(char **tab, size_t size)
{
	ft_free_tab(tab, size);
	return (NULL);
}

static char	**fill_w(char pc[4][4], const char **tab, size_t size, size_t pos)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**res;

	i = pos / size;
	j = pos % size;
	k = -1;
	l = -1;
	if (!(res = ft_tab_dup(tab, size)))
		return (NULL);
	while (++k < 4)
	{
		while (++l < 4)
			if (pc[k][l] != '.')
			{
				if (i + k >= (int)size || j + l >= (int)size
						|| res[i + k][j + l])
					return (ft_free_n_return(res, size));
				res[i + k][j + l] = pc[k][l];
			}
		l = -1;
	}
	return (res);
}

static int	is_fill(t_piece *tab, const char **res, size_t size, size_t pos)
{
	const char	**new_res;
	size_t		last_pos;

	last_pos = size * size - 3;
	if (!tab->piece[0][0])
	{
		ft_print_res(res, size);
		return (1);
	}
	new_res = (const char**)fill_w(tab->piece, res, size, pos);
	while (!new_res && pos < last_pos)
		new_res = (const char**)fill_w(tab->piece, res, size, ++pos);
	if (pos == last_pos)
		return (0);
	if (is_fill(tab + 1, new_res, size, 0) || is_fill(tab, res, size, pos + 1))
	{
		ft_free_tab((char**)new_res, size);
		return (1);
	}
	ft_free_tab((char**)new_res, size);
	return (0);
}

void		ft_fillit(t_piece *tab, int fd)
{
	size_t	size;
	size_t	i;
	size_t	res_size;
	char	**res;

	size = ft_tab_size(tab);
	res_size = ft_next_sqrt(size * 4);
	i = 0;
	while (1)
	{
		if (!(res = (char **)ft_2dim_alloc(res_size, res_size)))
			ft_print_error(fd, -1);
		ft_init_tab(res, res_size, res_size);
		if (is_fill(tab, (const char **)res, res_size, 0))
			break ;
		ft_free_tab(res, res_size);
		res_size++;
	}
	ft_free_tab(res, res_size);
	free(tab);
}
