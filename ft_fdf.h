#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include "./printf/includes/ft_printf.h"
# include "./minilibx/mlx.h"

# ifndef HEIGHT
#  define HEIGHT 800
# endif

# ifndef WIDTH
#  define WIDTH 1000
# endif

typedef struct s_coor
{
	int	x;
	int	y;
	int	z;
	int	c;
}	t_coor;

typedef struct s_map
{
	int		col;
	int		row;
	t_coor	**coor;
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
void	ft_show_map(t_map *map);
void	ft_show_coor(t_map *map);
void	ft_show_element(t_map *map);

/*--------------------- DRAW ---------------------*/
void	ft_putpxl(int x, int y, int c, t_data *data);
void	ft_plotline(t_coor s, t_coor e, t_data *data);
void	ft_draw_image(t_window *w);

/*--------------------- OPERATOR ---------------------*/
int		ft_op_add(int a, int b);
int		ft_op_sub(int a, int b);
int		ft_op_mul(int a, int b);
int		ft_op_div(int a, int b);
int		ft_op_mod(int a, int b);

/*--------------------- FREE ---------------------*/
void	ft_free_map(t_map *map);

#endif