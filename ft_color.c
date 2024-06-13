#include "ft_fdf.h"

int	ft_get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	ft_get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	ft_get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	ft_get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	create_trgb(t_color c)
{
	return (c.t << 24 | c.r << 16 | c.g << 8 | c.b);
}