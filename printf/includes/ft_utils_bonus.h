/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:16:24 by ballain           #+#    #+#             */
/*   Updated: 2024/06/03 18:42:25 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_BONUS_H
# define FT_UTILS_BONUS_H

# include "../../libft/libft.h"

int		ft_add_blank(char *text, char c, int e);
int		ft_unblen(unsigned long nb, int base);
int		ft_put_nb(char *text, unsigned long nb, int prec, char *base);
void	ft_manage_precision(int flags[7], int sup);
#endif