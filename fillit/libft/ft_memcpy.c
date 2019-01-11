/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:00:19 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/22 13:00:20 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char				*dp;
	const	unsigned	char	*sp;

	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	while (n--)
		*dp++ = *sp++;
	return (dst);
}
