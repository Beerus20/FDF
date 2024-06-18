/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:21:48 by ballain           #+#    #+#             */
/*   Updated: 2024/06/18 13:08:38 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
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

	i = 0;
	r_value = 0;
	tmp = line;
	while (!ft_isspace(*tmp) && *tmp)
	{
		tmp++;
		i++;
	}
	while (i-- >= 0 && !ft_isspace(*line))
	{
		r_value += ft_ctoi(*line) * ft_pow(16, i);
		line++;
	}
	return (r_value);
}

int	ft_get_color(t_coor *coor, char *line)
{
	int	color;
	int	r_value;

	r_value = 1;
	color = ft_htoic("FFFFFF");
	if (*line == 'x')
	{
		line++;
		color = ft_htoic(line);
		coor->c = ft_init_color(color);
		while (!ft_isspace(*(line++)))
			r_value++;
		return (r_value);
	}
	else if (ft_isspace(*line) || !(*line))
	{
		if (coor->z > 0)
			color = ft_htoic("00FF00");
		if (coor->z < 0)
			color = ft_htoic("0000FF");
		coor->c = ft_init_color(color);
	}
	return (0);
}
