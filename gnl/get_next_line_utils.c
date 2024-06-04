/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 21:03:36 by ballain           #+#    #+#             */
/*   Updated: 2024/05/31 22:56:44 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_getlen(t_list *value)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (!ft_strchr((const char *)value->content, '\n') && value->next)
	{
		len += ft_strlen(value->content);
		value = value->next;
	}
	if (ft_strchr((const char *)value->content, '\n'))
	{
		while (value->content[i++] != '\n')
			;
		len += i;
	}
	else
		len += ft_strlen(value->content);
	return (len);
}

char	*ft_alloc(char *s, int len)
{
	char	*r_value;
	int		i;

	i = 0;
	if (s)
		len = ft_strlen(s);
	r_value = (char *)malloc(sizeof(char) * (len + 1));
	if (!r_value)
		return (0);
	if (s)
	{
		while (i < len)
		{
			r_value[i] = s[i];
			i++;
		}
	}
	else
	{
		while (i < len)
			r_value[i++] = 0;
	}
	r_value[i] = '\0';
	return (r_value);
}

void	ft_free(t_list *value)
{
	t_list	*to_free;

	to_free = NULL;
	while (value)
	{
		to_free = value;
		value = value->next;
		free(to_free->content);
		free(to_free);
	}
}
