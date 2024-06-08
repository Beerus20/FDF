#include "ft_fdf.h"

float	ft_rad(int degree)
{
	return (degree * PI / 180);
}

int	ft_linear_combinaison(float a, float b)
{
	int	deg;

	deg = 30;
	return floor(cos(ft_rad(deg)) * a + sin(ft_rad(deg)) * b);
}

void	ft_rot_x_axes(float *y, float *z)
{
	int	_y;
	int	_z;

	_y = *y;
	_z = *z;
	*y = ft_linear_combinaison(_y, -_z);
	*z = ft_linear_combinaison(_z, _y);
}

void	ft_rot_y_axes(float *x, float *z)
{
	int	_x;
	int	_z;

	_x = *x;
	_z = *z;
	*x = ft_linear_combinaison(_x, _z);
	*z = ft_linear_combinaison(_z, -_x);
}

void	ft_rot_z_axes(float *x, float *y)
{
	int	_x;
	int	_y;

	_x = *x;
	_y = *y;
	*x = ft_linear_combinaison(_x, -_y);
	*y = ft_linear_combinaison(_y, _x);
}
