#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include "./printf/includes/ft_printf.h"
# include "./minilibx/mlx.h"

# define PI 3.1415926535897932385
# define DEG 5

# ifndef HEIGHT
#  define HEIGHT 800
# endif

# ifndef WIDTH
#  define WIDTH 1000
# endif

typedef struct s_teta
{
	int		x;
	int		y;
	int		z;
}	t_teta;

typedef struct s_coor
{
	double	x;
	double	y;
	double	z;
	int	c;
}	t_coor;

typedef struct s_map
{
	int		col;
	int		row;
	int		id_m;
	double		add;
	void	(*f_modif)(double *, double *);
	void	(*f_rotation)(double *, double *);
	t_coor	**coor;
	t_coor	cgravity;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*img_ptr;
	int		bpp;
	int		ll;
	int		e;
}				t_data;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_data	data;
}	t_window;

t_map	*ft_get_map(const char *file_name);
int		ft_abs(int value);

/*--------------------- PARAMS ---------------------*/
void	ft_show_map(t_map *map, int id);
void	ft_show_coor(t_map *map);
void	ft_show_element(t_map *map);

/*--------------------- ROTATION ---------------------*/
double	ft_linear_combinaison(double a, double b);
void	ft_rot_x_axes(double *y, double *z);
void	ft_rot_y_axes(double *x, double *z);
void	ft_rot_z_axes(double *x, double *y);

/*--------------------- MODIF ---------------------*/
void	ft_up_modif_func(t_map *map, int id_m, int add, void (*f_modif)(double *, double *));
void	ft_update_mapv(t_map *map, int i, int j);

/*--------------------- DRAW ---------------------*/
void	ft_putpxl(double x, double y, int c, t_data *data);
void	ft_plotline(t_coor s, t_coor e, t_data *data);
void	ft_draw_image(t_window *w);

/*--------------------- OPERATOR ---------------------*/
void	ft_op_add(double *a, double *b);
void	ft_op_sub(double *a, double *b);
void	ft_op_mul(double *a, double *b);
void	ft_op_div(double *a, double *b);
// void	ft_op_mod(double *a, double *b);

/*--------------------- FREE ---------------------*/
void	ft_free_map(t_map *map);

#endif