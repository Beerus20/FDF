#include "ft_fdf.h"

t_coor	ft_apply_modif(t_coor *cg, t_coor *e, t_modif *modif)
{
	t_coor r_value;

	r_value.x = e->x;
	r_value.y = e->y;
	r_value.z = e->z;
	r_value.c = e->c;
	r_value.x *= modif->zoom;
	r_value.y *= modif->zoom;
	r_value.z *= modif->zoom;
	ft_op_add(&r_value.x, &modif->gap.x);
	ft_op_add(&r_value.y, &modif->gap.y);
	ft_op_mul(&r_value.z, &modif->gap.z);
	ft_rot_x_axes(cg, &r_value.y, &r_value.z, modif->teta.x);
	ft_rot_y_axes(cg, &r_value.x, &r_value.z, modif->teta.y);
	ft_rot_z_axes(cg, &r_value.x, &r_value.y, modif->teta.z);
	return (r_value);
}
