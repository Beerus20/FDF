/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:09:22 by ballain           #+#    #+#             */
/*   Updated: 2024/05/31 20:18:39 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*r_value;

	r_value = (t_list *)malloc(sizeof(t_list));
	if (!r_value)
		return (0);
	if (!content)
		r_value->content = NULL;
	else
		r_value->content = content;
	r_value->next = NULL;
	return (r_value);
}
