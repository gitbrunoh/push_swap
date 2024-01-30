/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunhenr <brunhenr@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:47:06 by brunhenr          #+#    #+#             */
/*   Updated: 2024/01/29 17:47:10 by brunhenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_n(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min_n(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
