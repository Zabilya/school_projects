/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:15:32 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/23 20:15:33 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const	char	*begin;
	const	char	*str;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		begin = haystack;
		str = needle;
		while (*haystack && *str && *haystack == *str)
		{
			haystack++;
			str++;
		}
		if (*str == '\0')
			return ((char *)begin);
		haystack = ++begin;
	}
	return (NULL);
}
