/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:21:33 by ballain           #+#    #+#             */
/*   Updated: 2024/06/20 19:20:00 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_exit(t_window *w)
{
	ft_free_map(w->map);
	mlx_destroy_image(w->mlx, w->data.img);
	mlx_destroy_window(w->mlx, w->win);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
	exit(1);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
	{
		free(map->coor[i]);
		i++;
	}
	free(map->coor);
	free(map);
}

int	ft_close(int keycode, t_window *w)
{
	(void)keycode;
	ft_exit(w);
	return (0);
}
