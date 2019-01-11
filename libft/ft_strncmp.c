/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:05:39 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/25 15:05:39 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s1 && *s2 && n--)
	{
		s1++;
		s2++;
	}
	if (n > 0)
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
	return (0);
}
