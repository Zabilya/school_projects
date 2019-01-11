/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:15:10 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/22 13:15:12 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned			char			*dp;
	const	unsigned	char			*sp;

	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	if (n == 0 || dst == src)
		return (NULL);
	while (n--)
	{
		*dp = *sp;
		if (*sp == (unsigned char)c)
			return (dp + 1);
		dp++;
		sp++;
	}
	return (NULL);
}
