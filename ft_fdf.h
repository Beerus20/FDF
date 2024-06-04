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


t_map	**ft_get_map(const char *file_name);

/*--------------------- PARAMS ---------------------*/
void	ft_show_map(t_map *map);
void	ft_show_coor(t_map *map);

#endif