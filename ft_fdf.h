#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include "./printf/includes/ft_printf.h"

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

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

t_map	*ft_get_map(const char *file_name);

/*--------------------- PARAMS ---------------------*/
void	ft_show_map(t_map *map);
void	ft_show_coor(t_map *map);
void	ft_show_element(t_map *map);

/*--------------------- DRAW ---------------------*/
void	ft_putpxl(int x, int y, int c, t_data *data);
// void	ft_plotline(t_coor s, t_coor e, t_data *data);
void	ft_draw_map(t_map *map, t_data *data);

/*--------------------- FREE ---------------------*/
void	ft_free_map(t_map *map);

#endif