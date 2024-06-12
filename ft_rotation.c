#include "ft_fdf.h"

double	ft_rad(double degree)
{
	return (degree * PI / 180);
}

double	ft_linear_combinaison(double a, double b)
{
	return (cos(ft_rad(DEG)) * a + sin(ft_rad(DEG)) * b);
}

void	ft_rot_x_axes(double *y, double *z)
{
	double	_y;
	double	_z;

	_y = *y;
	_z = *z;
	*y = ft_linear_combinaison(_y, -_z);
	*z = ft_linear_combinaison(_z, _y);
}

void	ft_rot_y_axes(double *x, double *z)
{
	double	_x;
	double	_z;

	_x = *x;
	_z = *z;
	*x = ft_linear_combinaison(_x, _z);
	*z = ft_linear_combinaison(_z, -_x);
}

void	ft_rot_z_axes(double *x, double *y)
{
	double	_x;
	double	_y;

	_x = *x;
	_y = *y;
	*x = ft_linear_combinaison(_x, -_y);
	*y = ft_linear_combinaison(_y, _x);
}
