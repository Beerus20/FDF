#include "ft_fdf.h"

void	ft_show_map(t_map *map, int id)
{
	int	i;
	int	j;
	int	z;

	j = 0;
	i = 0;
	ft_printf("COOR	: row [%d] - col [%d]\n%6s", map->row, map->col, "");
	while (i < map->col)
	{
		ft_printf("%3d", i);
		i++;
	}
	i = 0;
	ft_printf("\n%6s", "");
	while (i < map->col)
	{
		ft_printf("---");
		i++;
	}
	ft_printf("\n");
	while (j < map->row)
	{
		i = 0;
		ft_printf(" %3d |", j);
		while (i < map->col)
		{
			if (id == 0)
				z = map->coor[j][i].z;
			if (id == 1)
				z = map->coor[j][i].x;
			if (id == 2)
				z = map->coor[j][i].y;
			if (map->coor[j][i].z > 0)
				ft_printf("\033[0;32m%3d\033[0;0m", z);
			else if (z < 0)
				ft_printf("\033[0;31m%3d\033[0;0m", z);
			else
				ft_printf("%3d", z);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}

void	ft_show_element(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	z;

	j = 0;
	ft_printf("COOR	: row [%d] - col [%d]\n", map->row, map->col);
	while (j < map->row)
	{
		i = 0;
		while (i < map->col)
		{
			x = map->coor[j][i].x;
			y = map->coor[j][i].y;
			z = map->coor[j][i].z;
			ft_printf("element	: [%3d] [%3d] [%3d]\n", x, y, z);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}

void	ft_show_coor(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->row)
	{
		i = 0;
		while (i < map->col)
		{
			if (map->coor[j][i].z > 0)
				ft_printf("\033[0;32m%3d\033[0;0m ", map->coor[j][i].z);
			else if (map->coor[j][i].z < 0)
				ft_printf("\033[0;31m%3d\033[0;0m ", map->coor[j][i].z);
			else
				ft_printf("%3d ", map->coor[j][i].z);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}
