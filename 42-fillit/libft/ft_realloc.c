/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:30:22 by coremart          #+#    #+#             */
/*   Updated: 2018/12/05 15:53:37 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include <stdio.h>

void	*ft_realloc(void *ptr, size_t cur_size, size_t new_size)
{
	unsigned char	*res;
	unsigned char	*ptr_tmp;
	size_t			i;

	i = 0;
	ptr_tmp = (unsigned char*)ptr;
	if (!(res = (unsigned char*)malloc(new_size)))
		return (NULL);
	while (i < cur_size)
	{
		res[i] = ptr_tmp[i];
		i++;
	}
	free(ptr);
	return ((void*)res);
}
