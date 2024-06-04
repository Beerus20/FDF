#include "ft_fdf.h"

void	ft_show_map(t_map *map)
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
