/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:27:21 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/25 14:27:22 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const	char	*begin;
	const	char	*str;
	int				l;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		l = (int)len;
		begin = haystack;
		str = needle;
		while (*haystack && *str && *haystack == *str && l--)
		{
			haystack++;
			str++;
		}
		if (l < 0)
			return (NULL);
		if (*str == '\0')
			return ((char *)begin);
		haystack = ++begin;
		len--;
	}
	return (NULL);
}
