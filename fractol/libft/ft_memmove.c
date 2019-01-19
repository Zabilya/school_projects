/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 09:38:49 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/23 09:38:52 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned	char			*dp;
	const	unsigned	char	*sp;

	dp = (unsigned char *)dst;
	sp = (unsigned char *)src;
	if (sp < dp)
		while (len--)
			dp[len] = sp[len];
	else
		while (len--)
			*dp++ = *sp++;
	return (dst);
}
