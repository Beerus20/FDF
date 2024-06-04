/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:22:30 by ballain           #+#    #+#             */
/*   Updated: 2024/05/31 19:46:47 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;

	str = (char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n-- > 0)
		*str++ = *(char *)src++;
	return (dest);
}
