/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:16:06 by aljacque          #+#    #+#             */
/*   Updated: 2018/11/16 14:52:49 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnset(char *str, int c, size_t n)
{
	size_t i;

	i = 0;
	if (!str || !c)
		return (0);
	while (str[i] && i < n)
	{
		str[i] = (char)c;
		i++;
	}
	return (str);
}
