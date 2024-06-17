/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballain <ballain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:21:05 by ballain           #+#    #+#             */
/*   Updated: 2024/06/17 23:21:06 by ballain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_op_add(double *a, double *b)
{
	*a += *b;
}

void	ft_op_sub(double *a, double *b)
{
	*a -= *b;
}

void	ft_op_mul(double *a, double *b)
{
	*a *= *b;
}

void	ft_op_div(double *a, double *b)
{
	*a /= *b;
}
