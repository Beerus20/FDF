#include "ft_fdf.h"

void	ft_up_modif_func(t_map *map, int id_m, int add, void (*f_modif)(float *, float *))
{
	map->id_m = id_m;
	map->f_modif = f_modif;
	map->add = add;
}

void	ft_ajust_value(t_map *map, int i, int j, char axe)
{
	if (axe == 'x')
	{
		map->coor[j][i].y -= map->cgravity.y;
		map->coor[j][i].z -= map->cgravity.z;
		map->f_modif(&map->coor[j][i].y, &map->coor[j][i].z);
		map->coor[j][i].y += map->cgravity.y;
		map->coor[j][i].z += map->cgravity.z;
	}
	if (axe == 'y')
	{
		map->coor[j][i].x -= map->cgravity.x;
		map->coor[j][i].z -= map->cgravity.z;
		map->f_modif(&map->coor[j][i].x, &map->coor[j][i].z);
		map->coor[j][i].x += map->cgravity.x;
		map->coor[j][i].z += map->cgravity.z;
	}
	if (axe == 'z')
	{
		map->coor[j][i].x -= map->cgravity.x;
		map->coor[j][i].y -= map->cgravity.y;
		map->f_modif(&map->coor[j][i].x, &map->coor[j][i].y);
		map->coor[j][i].x += map->cgravity.x;
		map->coor[j][i].y += map->cgravity.y;
	}
}

void	ft_update_mapv(t_map *map, int i, int j)
{
	if (map->id_m == 0)
		map->f_modif(&map->coor[j][i].x, &map->add);
	else if (map->id_m == 1)
		map->f_modif(&map->coor[j][i].y, &map->add);
	else if (map->id_m == 2)
		map->f_modif(&map->coor[j][i].z, &map->add);
	else if (map->id_m == 3)
	{
		map->f_modif(&map->coor[j][i].x, &map->add);
		map->f_modif(&map->coor[j][i].y, &map->add);
		map->f_modif(&map->coor[j][i].z, &map->add);
	}
	else if (map->id_m == 4)
		ft_ajust_value(map, i, j, 'x');
	else if (map->id_m == 5)
		ft_ajust_value(map, i, j, 'y');
	else
		ft_ajust_value(map, i, j, 'z');
}
