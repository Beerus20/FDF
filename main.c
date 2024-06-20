/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:03:38 by ballain           #+#    #+#             */
/*   Updated: 2024/06/20 19:40:35 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_arg_error(int argc)
{
	if (argc >= 3 || argc == 1)
	{
		ft_printf("\033[0;31mARG ERROR ...\033[0;0m\n");
		exit(0);
	}
}

int	main(int argc, const char **argv)
{
	t_window	w;

	ft_arg_error(argc);
	w.map = ft_get_map(argv[1]);
	w.mlx = mlx_init();
	w.a_mouse = 0;
	if (!w.mlx)
		ft_exit(&w);
	w.win = mlx_new_window(w.mlx, WIDTH, HEIGHT, "FDF ---");
	if (!w.win)
		ft_exit(&w);
	w.data.img = mlx_new_image(w.mlx, WIDTH, HEIGHT);
	w.data.img_ptr = mlx_get_data_addr(\
						w.data.img, &w.data.bpp, &w.data.ll, &w.data.e);
	mlx_hook(w.win, 17, 1L << 0, ft_close, &w);
	mlx_hook(w.win, 2, 1L << 0, ft_key_event, &w);
	mlx_hook(w.win, 6, 1L << 6, ft_mouse_event, &w);
	mlx_hook(w.win, 4, 1L << 2, ft_scroll_wheel, &w);
	ft_update_cgravity(w.map);
	ft_draw_image(&w);
	mlx_loop(w.mlx);
	ft_exit(&w);
	return (0);
}
