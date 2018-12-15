/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dim_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:58:42 by coremart          #+#    #+#             */
/*   Updated: 2018/12/08 13:38:38 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

void	**ft_2dim_alloc(size_t x, size_t y)
{
	size_t			i;
	unsigned char	**res;

	i = 0;
	if (!(res = (unsigned char **)malloc(sizeof(unsigned char*) * x)))
		return (NULL);
	while (i < y)
	{
		if (!(res[i] = (unsigned char*)malloc(y)))
			return (NULL);
		i++;
	}
	return ((void**)res);
}
