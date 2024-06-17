#include "ft_fdf.h"

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	ft_putpxl(double x, double y, t_color c, t_data *data)
{
	int	offset;

	if (x >= WIDTH || y >= HEIGHT || x <= 0 || y <= 0)
		return ;
	offset = ((data->ll * (int)(y)) + ((int)(x) * (data->bpp / 8)));
	*((unsigned int *)(offset + data->img_ptr)) = create_trgb(c);
}

t_color	ft_gradient(t_coor s, t_coor e, int dist)
{
	t_color		c;
	static int	i = 0;

	if (dist)
	{
		c.t = 255;
		c.r = (((dist - i) * s.c.r / dist)) + ((i * e.c.r / dist));
		c.g = (((dist - i) * s.c.g / dist)) + ((i * e.c.g / dist));
		c.b = (((dist - i) * s.c.b / dist)) + ((i * e.c.b / dist));
		if (i >= dist)
			i = 0;
		else
			i++;
		return (c);
	}
	return (e.c);
}

void	ft_plotlinelow(t_coor s, t_coor e, t_data *data)
{
	double	dx;
	double	dy;
	double	D;
	double	yi;

	dx = e.x - s.x;
	dy = e.y - s.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = (2 * dy) - dx;
	while (s.x++ < e.x)
	{
		ft_putpxl(s.x, s.y, ft_gradient(s, e, dx), data);
		if (D > 0)
		{
			s.y += yi;
			D += 2 * (dy - dx);
		}
		else
			D += 2 * dy;
	}
}

void	ft_plotlinehigh(t_coor s, t_coor e, t_data *data)
{
	double	dx;
	double	dy;
	double	D;
	double	xi;

	dx = e.x - s.x;
	dy = e.y - s.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	D = (2 * dx) - dy;
	while (s.y++ < e.y)
	{
		ft_putpxl(s.x, s.y, ft_gradient(s, e, dy), data);
		if (D > 0)
		{
			s.x += xi;
			D += 2 * (dx - dy);
		}
		else
			D += 2 * dx;
	}
}

void	ft_plotline(t_coor s, t_coor e, t_data *data)
{
	if (ft_abs(e.y - s.y) < ft_abs(e.x - s.x))
	{
		if (s.x > e.x)
			ft_plotlinelow(e, s, data);
		else
			ft_plotlinelow(s, e, data);
	}
	else
	{
		if (s.y > e.y)
			ft_plotlinehigh(e, s, data);
		else
			ft_plotlinehigh(s, e, data);
	}
}

void	ft_draw(int i, int j, t_map *map, t_data *data)
{
	t_coor	prev;
	t_coor	next;

	prev = ft_apply_modif(&map->cgravity, &map->coor[j][i], &map->modif);
	next = ft_apply_modif(&map->cgravity, &map->coor[j][i], &map->modif);
	if (i != 0)
		prev = ft_apply_modif(&map->cgravity, &map->coor[j][i - 1], &map->modif);
	ft_plotline(prev, next, data);
	prev = ft_apply_modif(&map->cgravity, &map->coor[j][i], &map->modif);
	next = ft_apply_modif(&map->cgravity, &map->coor[j][i], &map->modif);
	if (j != 0)
		prev = ft_apply_modif(&map->cgravity, &map->coor[j - 1][i], &map->modif);;
	ft_plotline(prev, next, data);
}

t_data	ft_init_data(t_window *w)
{
	t_data	data;

	mlx_destroy_image(w->mlx, w->data.img);
	data.img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	data.img_ptr = mlx_get_data_addr(data.img, &data.bpp, &data.ll, &data.e);
	return (data);
}

int	ft_draw_string(t_window *w, int y, char *name, char *value)
{
	mlx_string_put(w->mlx, w->win, WIDTH - 120, y, 0xFFFFFF, name);
	mlx_string_put(w->mlx, w->win, WIDTH - 50, y, 0xFF0000, value);
	free(value);
	return (20);
}

void	ft_draw_info(t_window *w)
{
	int	y;

	y = 20;
	y += ft_draw_string(w, y, "WIDTH   : ", ft_itoa(WIDTH));
	y += ft_draw_string(w, y, "HEIGHT  : ", ft_itoa(HEIGHT));
	y += ft_draw_string(w, y, "ZOOM    : ", ft_itoa(w->map->modif.zoom / ZOOM));
	y += ft_draw_string(w, y, "pos x   : ", ft_itoa(w->map->modif.gap.x));
	y += ft_draw_string(w, y, "pos y   : ", ft_itoa(w->map->modif.gap.y));
	y += ft_draw_string(w, y, "Teta x  : ", ft_itoa(w->map->modif.teta.x));
	y += ft_draw_string(w, y, "Teta y  : ", ft_itoa(w->map->modif.teta.y));
	y += ft_draw_string(w, y, "Teta z  : ", ft_itoa(w->map->modif.teta.z));

}

void	ft_draw_image(t_window *w)
{
	int		i;
	int		j;

	j = 0;
	w->data = ft_init_data(w);
	while (j < w->map->row)
	{
		i = 0;
		while (i < w->map->col)
		{
			ft_draw(i, j, w->map, &w->data);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(w->mlx, w->win, w->data.img, 0, 0);
	ft_draw_info(w);
}
