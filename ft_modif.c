#include "ft_fdf.h"

void	ft_up_modif_func(t_map *map, int id_m, int add, void (*f_modif)(int *, int))
{
	map->id_m = id_m;
	map->f_modif = f_modif;
	map->add = add;
}

void	ft_update_mapv(t_map *map, int i, int j)
{
	if (map->id_m == 0)
		map->f_modif(&map->coor[j][i].x, map->add);
	else if (map->id_m == 1)
		map->f_modif(&map->coor[j][i].y,map->add);
	else if (map->id_m == 2)
		map->f_modif(&map->coor[j][i].z,map->add);
	else
	{
		map->f_modif(&map->coor[j][i].x,map->add);
		map->f_modif(&map->coor[j][i].y,map->add);
		map->f_modif(&map->coor[j][i].z,map->add);
	}
}