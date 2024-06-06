/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:45:38 by ballain           #+#    #+#             */
/*   Updated: 2024/06/06 13:03:03 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_alloc_rvalue(char const *s, char c, int *nbw)
{
	int		i;
	int		can_countword;
	char	**r_value;

	i = 0;
	can_countword = 1;
	r_value = NULL;
	while (s[i] != '\0')
	{
		if (s[i] != c && can_countword)
		{
			can_countword = 0;
			*nbw += 1;
		}
		if (s[i] == c)
			can_countword = 1;
		i++;
	}
	*nbw += 1;
	r_value = (char **)malloc(sizeof(char *) * (*nbw));
	if (!r_value)
		return (0);
	return (r_value);
}

int	ft_iandl(const char *s, char c, int *i, int *len)
{
	int	tmp;

	tmp = 0;
	while (s[*i] == c)
		*i += 1;
	tmp = *i;
	while (s[*i] != c)
	{
		if (s[*i] == '\0')
			break ;
		*i += 1;
		*len += 1;
	}
	return (tmp);
}

int	ft_fill_content(char **r_value, char const *s, char c)
{
	int	i;
	int	id;
	int	tmp;
	int	len;

	i = 0;
	id = 0;
	tmp = 0;
	len = 0;
	while (s[i] != '\0')
	{
		len = 0;
		tmp = ft_iandl(s, c, &i, &len);
		if (len != 0)
		{
			r_value[id] = ft_substr(s, tmp, len);
			if (!r_value[id])
				return (0);
			id++;
		}
	}
	r_value[id] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		nbw;
	char	**r_value;

	nbw = 0;
	r_value = ft_alloc_rvalue(s, c, &nbw);
	if (!r_value)
		return (0);
	if (nbw == 0)
	{
		r_value[0] = NULL;
		return (r_value);
	}
	ft_fill_content(r_value, s, c);
	return (r_value);
}
