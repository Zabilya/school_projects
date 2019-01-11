/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:38:23 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/23 18:38:24 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_l;
	size_t src_l;
	size_t i;

	dst_l = ft_strlen(dst);
	i = dst_l;
	src_l = ft_strlen(src);
	if (size <= dst_l)
		return (src_l + size);
	else if (size > dst_l)
	{
		while (i < size - 1)
			dst[i++] = *src++;
		dst[i] = '\0';
	}
	return (dst_l + src_l);
}
