/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:34:52 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/23 10:34:53 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const	unsigned	char	*sp;

	sp = (const unsigned char *)s;
	while (n--)
	{
		if (*sp == (unsigned char)c)
			return ((void *)sp);
		sp++;
	}
	return (NULL);
}
