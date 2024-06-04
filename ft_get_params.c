#include "ft_fdf.h"

int	ft_get_nbcol(char *line)
{
	int	r_value;

	r_value = 0;
	while (*line)
	{
		while (!ft_isdigit(*line) && *line)
			line++;
		if (ft_isdigit(*line))
			r_value++;
		while (*line != ' ' && *line)
			line++;
	}
	return (r_value);
}

int	ft_z_value(char *line)
{
	int	sign;
	int	r_value;

	sign = 1;
	r_value = 0;
	while (*line && *line != ' ')
	{
		if (*line == '-')
		{
			sign = -1;
			line++;
		}
		r_value = (*line - '0') + (r_value * 10);
		line++;
	}
	return (r_value * sign);
}

t_coor	*ft_get_colvalue(char *line, int nb_col, int y)
{
	t_coor	*r_value;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	r_value = (t_coor *)malloc(sizeof(t_coor) * nb_col);
	if (!r_value)
		exit(1);
	while (i < nb_col)
	{
		r_value[i].c = i;
		r_value[i].y = y;
		r_value[i].z = ft_z_value(line);
		while (*(line++) != ' ' && *line)
			;
		i++;
	}
	i = 0;
	while (i < nb_col)
	{
		ft_printf("%d ", r_value[i].z);
		i++;
	}
	ft_printf("\n");
	return (r_value);
}

t_map	*ft_get_coor(t_list *lines)
{
	t_map	*map;
	int		col;
	int		row;
	int		i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit(1);
	map->row = ft_lstsize(lines);
	map->col = ft_get_nbcol(lines->content);
	map->coor = (t_coor **)malloc(sizeof(t_coor *) * map->row);
	if (!map->coor)
		exit(1);
	while (i < map->row)
	{
		map->coor[i] = ft_get_colvalue(lines->content, map->col, i);
		lines = lines->next;
		i++;
	}
	return (map);
}

void	ft_show(void *content)
{
	ft_printf("%s", (char *)content);
}

t_map	**ft_get_map(const char *file_name)
{
	t_map	*r_value;
	t_list	*lines;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit(1);
	lines = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&lines, ft_lstnew(line));
		line = get_next_line(fd);
	}
	r_value = ft_get_coor(lines);
	ft_lstiter(lines, ft_show);
	// ft_show_map(r_value);
	// ft_show_coor(r_value);
	close(fd);
	return (NULL);
}
