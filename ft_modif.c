#include "ft_fdf.h"

void	ft_update_modif(t_modif *modif, int id, char axe, void (*action))
{
	modif->action = action;
}

// void	ft_rotate_map(t_map *map, int i, int j)
// {
// 	if (axe == 'x')
// 	{
// 		map->coor[j][i].y -= map->cgravity.y;
// 		map->coor[j][i].z -= map->cgravity.z;
// 		map->f_modif(&map->coor[j][i].y, &map->coor[j][i].z);
// 		map->coor[j][i].y += map->cgravity.y;
// 		map->coor[j][i].z += map->cgravity.z;
// 	}
// 	if (axe == 'y')
// 	{
// 		map->coor[j][i].x -= map->cgravity.x;
// 		map->coor[j][i].z -= map->cgravity.z;
// 		map->f_modif(&map->coor[j][i].x, &map->coor[j][i].z);
// 		map->coor[j][i].x += map->cgravity.x;
// 		map->coor[j][i].z += map->cgravity.z;
// 	}
// 	if (axe == 'z')
// 	{
// 		map->coor[j][i].x -= map->cgravity.x;
// 		map->coor[j][i].y -= map->cgravity.y;
// 		map->f_modif(&map->coor[j][i].x, &map->coor[j][i].y);
// 		map->coor[j][i].x += map->cgravity.x;
// 		map->coor[j][i].y += map->cgravity.y;
// 	}
// }

t_coor	ft_apply_modif(t_coor *cg, t_coor *e, t_modif *modif)
{
	t_coor r_value;

	r_value.x = e->x;
	r_value.y = e->y;
	r_value.z = e->z;
	r_value.x *= modif->zoom;
	r_value.y *= modif->zoom;
	r_value.z *= modif->zoom;
	ft_op_add(&r_value.x, &modif->gap.x);
	ft_op_add(&r_value.y, &modif->gap.y);
	ft_op_add(&r_value.z, &modif->gap.z);
	ft_rot_x_axes(cg, &r_value.y, &r_value.z, modif->teta.x);
	ft_rot_x_axes(cg, &r_value.x, &r_value.z, modif->teta.y);
	ft_rot_x_axes(cg, &r_value.x, &r_value.y, modif->teta.z);
	return (r_value);
}
