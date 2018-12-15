/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:00:16 by aljacque          #+#    #+#             */
/*   Updated: 2018/12/07 17:41:32 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_color(char *str, char *color)
{
	if (!str || !color)
		return ;
	if (!ft_strcmp(color, "black"))
		str = ft_strjoin("\033[0;30m", str);
	else if (!ft_strcmp(color, "red"))
		str = ft_strjoin("\033[0;31m", str);
	else if (!ft_strcmp(color, "green"))
		str = ft_strjoin("\033[0;32m", str);
	else if (!ft_strcmp(color, "yellow"))
		str = ft_strjoin("\033[0;33m", str);
	else if (!ft_strcmp(color, "blue"))
		str = ft_strjoin("\033[0;34m", str);
	else if (!ft_strcmp(color, "white"))
		str = ft_strjoin("\033[0;37m", str);
	else
		return ;
	ft_putstr(str);
	ft_putstr("\033[0m\n");
}
