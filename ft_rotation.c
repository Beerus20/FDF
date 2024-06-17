/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:23:07 by ballain           #+#    #+#             */
/*   Updated: 2024/06/17 23:23:08 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

double	ft_rad(double degree)
{
	return (degree * PI / 180);
}

double	ft_linear_combinaison(double a, double b, int teta)
{
	return (cos(ft_rad(teta)) * a + sin(ft_rad(teta)) * b);
}

void	ft_rot_x_axes(t_coor *cg, double *y, double *z, int teta)
{
	double	_y;
	double	_z;

	_y = *y;
	_z = *z;
	_y -= cg->y;
	_z -= cg->z;
	*y = ft_linear_combinaison(_y, -_z, teta);
	*z = ft_linear_combinaison(_z, _y, teta);
	*y += cg->y;
	*z += cg->z;
}

void	ft_rot_y_axes(t_coor *cg, double *x, double *z, int teta)
{
	double	_x;
	double	_z;

	_x = *x;
	_z = *z;
	_x -= cg->x;
	_z -= cg->z;
	*x = ft_linear_combinaison(_x, _z, teta);
	*z = ft_linear_combinaison(_z, -_x, teta);
	*x += cg->x;
	*z += cg->z;
}

void	ft_rot_z_axes(t_coor *cg, double *x, double *y, int teta)
{
	double	_x;
	double	_y;

	_x = *x;
	_y = *y;
	_x -= cg->x;
	_y -= cg->y;
	*x = ft_linear_combinaison(_x, -_y, teta);
	*y = ft_linear_combinaison(_y, _x, teta);
	*x += cg->x;
	*y += cg->y;
}
