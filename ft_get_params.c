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

static int	ft_inc(int value)
{
	int	move;

	move = 0;
	if (value <= 0)
	{
		move++;
		value *= -1;
	}
	while (value)
	{
		value /= 10;
		move++;
	}
	return (move);
}

t_coor	*ft_get_colvalue(char *line, int nb_col, int y)
{
	t_coor	*r_value;
	int		i;
	int		k;

	i = 0;
	k = 0;
	r_value = (t_coor *)malloc(sizeof(t_coor) * nb_col);
	if (!r_value)
		exit(1);
	while (i < nb_col)
	{
		r_value[i].x = i;
		r_value[i].y = y;
		r_value[i].z = ft_atoi(line);
		if (r_value[i].z > 0)
			r_value[i].c = 0x00F450;
		else if (r_value[i].z < 0)
			r_value[i].c = 0x0050F4;
		else
			r_value[i].c = 0xFFFFFF;
		k = ft_inc(r_value[i].z);
		line += k;
		while (*line == ' ')
			line++;
		i++;
	}
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

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->row)
	{
		free(map->coor[i]);
		i++;
	}
	free(map->coor);
	free(map);
}

t_map	*ft_get_map(const char *file_name)
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
	close(fd);
	ft_lstclear(&lines, free);
	r_value->modif.teta.x = 0;
	r_value->modif.teta.y = 0;
	r_value->modif.teta.z = 0;
	return (r_value);
}
