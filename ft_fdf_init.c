/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:42:48 by ballain           #+#    #+#             */
/*   Updated: 2024/06/18 11:21:34 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_init_modif(t_map *map, int col, int row)
{
	map->modif.teta.x = 55;
	map->modif.teta.y = 35;
	map->modif.teta.z = -20;
	map->modif.gap.x = (WIDTH / 2) - (col / 2);
	map->modif.gap.y = (HEIGHT / 2) - (row / 2);
	map->modif.gap.z = 1;
	map->modif.zoom = 1;
}

t_color	ft_init_color(int color)
{
	t_color	r_color;

	r_color.t = ft_get_t(color);
	r_color.r = ft_get_r(color);
	r_color.g = ft_get_g(color);
	r_color.b = ft_get_b(color);
	return (r_color);
}

void	ft_delete(void *value)
{
	free(value);
}

void	ft_map_col_error(t_list *lines, int error[2])
{
	t_list	*tmp;
	int		nb_col;
	int		nb_tmp;
	int		i;

	error[0] = 0;
	error[1] = 0;
	tmp = lines;
	nb_tmp = 0;
	nb_col = ft_get_nbcol(tmp->content);
	while (tmp)
	{
		nb_tmp = ft_get_nbcol(tmp->content);
		if (nb_col != nb_tmp)
		{
			error[1] = nb_col - nb_tmp;
			break ;
		}
		error[0]++;
		tmp = tmp->next;
	}
}

int	ft_init_map_error(t_list *lines)
{
	int		error[2];

	if (!lines)
	{
		ft_printf("\
			\033[0;31mERROR	: \033[0;0m\033[0;32m[EMPTY MAP]\033[0;0m\n");
		return (1);
	}
	else
	{
		ft_map_col_error(lines, error);
		if (error[1])
		{
			ft_printf("\033[0;31mERROR	: \
				\033[0;0m[\033[0;32mat line (%d)\033[0;0m]\n", error[0] + 1);
			ft_printf("-- TYPE	: [\033[0;32mdifferent nb column\033[0;0m]\n");
			ft_printf("-- DIFF	: [\033[0;32m%d\033[0;0m]\n", error[1]);
			ft_lstclear(&lines, ft_delete);
			return (1);
		}
	}
	return (0);
}
