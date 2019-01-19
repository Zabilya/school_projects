/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:01:38 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/23 20:01:39 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)(s + i));
	while (i--)
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
	return (NULL);
}
