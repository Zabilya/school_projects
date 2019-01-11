/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:43:36 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/23 10:43:37 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const	unsigned	char	*ps1;
	const	unsigned	char	*ps2;
	size_t						i;

	i = 0;
	ps1 = (const unsigned char *)s1;
	ps2 = (const unsigned char *)s2;
	while (i < n && *ps1 == *ps2)
	{
		ps1++;
		ps2++;
		i++;
	}
	if (i == n)
		return (0);
	return (*ps1 - *ps2);
}
