/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:38:29 by coremart          #+#    #+#             */
/*   Updated: 2018/12/08 13:35:32 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# define BUFF_SIZE 5

typedef struct	s_fd
{
	char		*content;
	int			fd;
	struct s_fd	*next;
}				t_fd;

typedef struct	s_piece
{
	char	piece[4][4];
}				t_piece;

char			**ft_tab_dup(const char **tab, size_t size);
int				get_next_line(const int fd, char **line);
size_t			ft_next_sqrt(size_t nb);
size_t			ft_tab_size(t_piece *tab);
t_piece			*ft_check_error(int fd);
t_piece			*ft_convers(t_piece *tab);
t_piece			*ft_shift_pieces(t_piece *tab);
void			ft_check_pieces(t_piece *tab, int fd);
void			ft_fillit(t_piece *tab, int fd);
void			ft_free_tab(char **tab, size_t size);
void			ft_print_error(int fd, int num);
void			ft_print_res(const char **tab, size_t size);
void			**ft_2dim_alloc(size_t x, size_t y);
void			ft_init_tab(char **tab, size_t x_len, size_t y_len);

#endif
