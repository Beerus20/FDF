#include "ft_fdf.h"

static int	ft_isspace(const int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_get_nbcol(char *line)
{
	int	r_value;

	r_value = 0;
	while (ft_isspace(*line))
		line++;
	while (*line)
	{
		while (!ft_isspace(*line) && *line)
			line++;
		if (ft_isspace(*line))
			r_value++;
		while (ft_isspace(*line))
			line++;
	}
	return (r_value);
}

int	ft_pow(int value, int n)
{
	int	r_value;

	r_value = 1;
	while (n > 0)
	{
		if (n % 2 == 1)
			r_value *= value;
		value *= value;
		n /= 2;
	}
	return (r_value);
}

int	ft_ctoi(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - '7');
	if (c >= 'a' && c <= 'f')
		return (c - 'W');
	return (0);
}

int	ft_htoic(char *line)
{
	int		i;
	int		r_value;
	char	*tmp;

	i = 6;
	r_value = 0;
	tmp = line;
	// while (!ft_isspace(*tmp) && *tmp && i++)
	// 	tmp++;
	while (i-- >= 0 && !ft_isspace(*line))
	{
		r_value += ft_ctoi(*line) * ft_pow(16, i);
		line++;
	}
	return (r_value);
}

static int	ft_get_color(t_coor *coor, char *line)
{
	int	color;
	int	r_value;

	coor->c.t = 0;
	r_value = 1;
	if (*line == 'x')
	{
		line++;
		color = ft_htoic(line);
		coor->c.t = ft_get_t(color);
		coor->c.r = ft_get_r(color);
		coor->c.g = ft_get_g(color);
		coor->c.b = ft_get_b(color);
		while (!ft_isspace(*line))
		{
			r_value++;
			line++;
		}
		return (r_value);
	}
	else if (ft_isspace(*line))
	{
		coor->c.r = 0;
		coor->c.g = 0;
		coor->c.b = 0;
		if (coor->z > 0)
			coor->c.g	= 255;
		else if (coor->z < 0)
			coor->c.r	= 255;
		else
		{
			coor->c.r = 255;
			coor->c.g = 255;
			coor->c.b = 255;
		}
	}
	return (0);
}

int	ft_get_zc(t_coor *coor, char *line)
{
	int	r_count;

	r_count = 0;
	while (ft_isspace(*line) && *line)
	{
		r_count++;
		line++;
	}
	coor->z = ft_atoi(line);
	while (!ft_isspace(*line) && *line != 'x' && *line)
	{
		r_count++;
		line++;
	}
	r_count += ft_get_color(coor, line);
	return (r_count);
}

t_coor	*ft_get_colvalue(char *line, int nb_col, int y)
{
	t_coor	*r_value;
	int		i;
	int		j;

	i = 0;
	r_value = (t_coor *)malloc(sizeof(t_coor) * nb_col);
	if (!r_value)
		exit(1);
	while (i < nb_col)
	{
		r_value[i].x = i;
		r_value[i].y = y;
		line += ft_get_zc(&r_value[i], line);
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
