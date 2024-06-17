/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 08:42:41 by ballain           #+#    #+#             */
/*   Updated: 2024/04/03 10:54:06 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

char	*ft_strchr_gnl(char *str, int c);
int		ft_strlen_gnl(char *str);
int		ft_get_len_gnl(t_list *value);
char	*ft_alloc(char *s, int len);
void	ft_free(t_list *value);
char	*get_next_line(int fd);
#endif
