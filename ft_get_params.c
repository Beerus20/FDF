/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:42:29 by ballain           #+#    #+#             */
/*   Updated: 2024/06/20 19:36:47 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_get_nbcol(char *line)
{
	int	r_value;

	r_value = 0;
	while (*line)
	{
		while (ft_isspace(*line) && *line)
			line++;
		if (!(*line))
			break ;
		r_value++;
		while (!ft_isspace(*line) && *line)
			line++;
	}
	return (r_value);
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

t_map	*ft_get_map(const char *file_name)
{
	t_map	*r_value;
	t_list	*lines;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit(0);
	lines = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&lines, ft_lstnew(line));
		line = get_next_line(fd);
	}
	if (ft_init_map_error(lines))
		exit(0);
	r_value = ft_get_coor(lines);
	close(fd);
	ft_lstclear(&lines, free);
	ft_init_modif(r_value, r_value->col, r_value->row);
	return (r_value);
}
