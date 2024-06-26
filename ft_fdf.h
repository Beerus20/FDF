#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include "./printf/includes/ft_printf.h"
# include "./minilibx-linux/mlx.h"

# define PI 3.1415926535897932385
# define DEG 5
# define GAP 5
# define ZOOM 2

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# ifndef WIDTH
#  define WIDTH 1800
# endif

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_gap
{
	double	x;
	double	y;
	double	z;
}	t_gap;

typedef struct s_coor
{
	double	x;
	double	y;
	double	z;
	t_color	c;
}	t_coor;

typedef struct s_modif
{
	int		zoom;
	t_gap	gap;
	t_gap	teta;
}	t_modif;

typedef struct s_map
{
	int		col;
	int		row;
	t_coor	**coor;
	t_coor	cgravity;
	t_modif	modif;
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
	int		a_mouse;
}	t_window;


/*--------------------- INIT ---------------------*/
int		ft_init_map_error(t_list *lines);
void	ft_init_modif(t_map *map, int col, int row);
t_color	ft_init_color(int color);

/*--------------------- FUNCTIONS SUP ---------------------*/
void	ft_update_cgravity(t_map *map);
int		ft_mouse_event(int x, int y, t_window *w);
int		ft_scroll_wheel(int button_id, int x, int y, t_window *w);

/*--------------------- PARAMS ---------------------*/
int		ft_get_nbcol(char *line);
t_map	*ft_get_map(const char *file_name);

/*--------------------- UTILS ---------------------*/
int		ft_abs(int value);
int		ft_pow(int value, int n);
int		ft_ctoi(char c);
int		ft_htoic(char *line);
int		ft_get_color(t_coor *coor, char *line);

/*--------------------- EVENT ---------------------*/
void	ft_move_map(int keycode, t_map *map);
void	ft_zoom_map(int keycode, t_map *map);
void	ft_rotate_map(int keycode, t_map *map);
int		ft_key_event(int keycode, t_window *w);

/*--------------------- COLOR ---------------------*/
int		ft_get_t(int trgb);
int		ft_get_r(int trgb);
int		ft_get_g(int trgb);
int		ft_get_b(int trgb);
int		create_trgb(t_color c);

/*--------------------- SHOW ---------------------*/
void	ft_show_map(t_map *map, int id);
void	ft_show_coor(t_map *map);
void	ft_show_element(t_map *map);

/*--------------------- PLOTLINE ---------------------*/
void	ft_putpxl(double x, double y, t_color c, t_data *data);
t_color	ft_gradient(t_coor s, t_coor e, int dist);
void	ft_plotlinelow(t_coor s, t_coor e, t_data *data);
void	ft_plotlinehigh(t_coor s, t_coor e, t_data *data);

/*--------------------- ROTATION ---------------------*/
double	ft_linear_combinaison(double a, double b, int teta);
void	ft_rot_x_axes(t_coor *cg, double *y, double *z, int teta);
void	ft_rot_y_axes(t_coor *cg, double *x, double *z, int teta);
void	ft_rot_z_axes(t_coor *cg, double *x, double *y, int teta);

/*--------------------- MODIF ---------------------*/
t_coor	ft_apply_modif(t_coor *cg, t_coor *e, t_modif *modif);

/*--------------------- DRAW ---------------------*/
void	ft_putpxl(double x, double y, t_color c, t_data *data);
void	ft_plotline(t_coor s, t_coor e, t_data *data);
void	ft_draw_image(t_window *w);

/*--------------------- OPERATOR ---------------------*/
void	ft_op_add(double *a, double *b);
void	ft_op_sub(double *a, double *b);
void	ft_op_mul(double *a, double *b);
void	ft_op_div(double *a, double *b);

/*--------------------- FREE ---------------------*/
void	ft_exit(t_window *w);
void	ft_free_map(t_map *map);
int		ft_close(int keycode, t_window *w);
#endif
