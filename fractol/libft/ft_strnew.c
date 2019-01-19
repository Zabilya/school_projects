/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:54:22 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/26 09:54:22 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	max;

	max = -1;
	if (size == max)
		return (NULL);
	if (!(str = (char *)(malloc(sizeof(char) * (size + 1)))))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
