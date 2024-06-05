#include "ft_fdf.h"

static int	ft_abs(int value)
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

void	ft_putpxl(int x, int y, int c, t_data *data)
{
	int	offset;

	offset = (data->line_length * y) + (x * (data->bits_per_pixel / 8));
	*((unsigned int *)(offset + data->addr)) = 0xFFFFFF;
}

void	ft_plotlinelow(t_coor s, t_coor e, t_data *data)
{
	int	dx;
	int	dy;
	int	D;
	int	yi;

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
		ft_putpxl(s.x, s.y, 0xFFFFFF, data);
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
	int	dx;
	int	dy;
	int	D;
	int	xi;

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
		ft_putpxl(s.x, s.y, 0xFFFFFF, data);
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

	prev = map->coor[j][i];
	if (map->coor[j][i].x != 0)
		prev = map->coor[j][i - 1];
	ft_plotline(prev, map->coor[j][i], data);
	prev = map->coor[j][i];
	if (map->coor[j][i].y != 0)
		prev = map->coor[j - 1][i];
	ft_plotline(prev, map->coor[j][i], data);
}

void	ft_draw_map(t_map *map, t_data *data)
{
	t_coor	prev;
	t_coor	next;
	int		i;
	int		j;

	j = 0;
	prev.x = 0;
	prev.y = 0;
	while (j < map->row - 1)
	{
		i = 0;
		while (i < map->col)
		{
			ft_draw(i, j, map, data);
			i++;
		}
		j++;
	}
}
