#include "ft_fdf.h"

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	ft_init_coor(t_coor *coor, int x, int y, int z)
{
	coor->x = x;
	coor->y = y;
	coor->z = z;
	coor->c = 0;
}

void	ft_putpxl(double x, double y, int c, t_data *data)
{
	int	offset;

	if (x >= WIDTH || y >= HEIGHT)
		return ;
	offset = ((data->ll * floor(y)) + (floor(x) * (data->bpp / 8)));
	*((unsigned int *)(offset + data->img_ptr)) = c;
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
		ft_putpxl(s.x, s.y, e.c, data);
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
		ft_putpxl(s.x, s.y, e.c, data);
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

t_data	ft_init_data(void *mlx)
{
	t_data	data;

	data.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	data.img_ptr = mlx_get_data_addr(data.img, &data.bpp, &data.ll, &data.e);
	return (data);
}

void	ft_draw_image(t_window *w)
{
	int		i;
	int		j;

	j = 0;
	w->data = ft_init_data(w->mlx);
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
}
