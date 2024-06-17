/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plotline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:17:13 by ballain           #+#    #+#             */
/*   Updated: 2024/06/17 23:17:13 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_putpxl(double x, double y, t_color c, t_data *data)
{
	int	offset;

	if (x >= WIDTH || y >= HEIGHT || x <= 0 || y <= 0)
		return ;
	offset = ((data->ll * (int)y) + ((int)x * (data->bpp / 8)));
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
	double	d;
	double	yi;

	dx = e.x - s.x;
	dy = e.y - s.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = (2 * dy) - dx;
	while (s.x++ < e.x)
	{
		ft_putpxl(s.x, s.y, ft_gradient(s, e, dx), data);
		if (d > 0)
		{
			s.y += yi;
			d += 2 * (dy - dx);
		}
		else
			d += 2 * dy;
	}
}

void	ft_plotlinehigh(t_coor s, t_coor e, t_data *data)
{
	double	dx;
	double	dy;
	double	d;
	double	xi;

	dx = e.x - s.x;
	dy = e.y - s.y;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	d = (2 * dx) - dy;
	while (s.y++ < e.y)
	{
		ft_putpxl(s.x, s.y, ft_gradient(s, e, dy), data);
		if (d > 0)
		{
			s.x += xi;
			d += 2 * (dx - dy);
		}
		else
			d += 2 * dx;
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
