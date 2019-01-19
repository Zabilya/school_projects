/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:27:39 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/03 12:27:40 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_power(int num, int pow)
{
	int orig;

	orig = num;
	while (pow--)
		num = num * orig;
	return ((size_t)num);
}
