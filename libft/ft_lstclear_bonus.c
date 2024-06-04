/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:29:37 by ballain           #+#    #+#             */
/*   Updated: 2024/05/31 20:14:41 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*to_free;

	if (!(*lst))
		return ;
	tmp = *lst;
	to_free = NULL;
	while (tmp)
	{
		to_free = tmp;
		tmp = tmp->next;
		del(to_free->content);
		free(to_free);
	}
	*lst = NULL;
}
