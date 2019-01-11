/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:29:42 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/26 10:29:42 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (!s || !f || !(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(str + i) = f(*(s + i));
		i++;
	}
	return (str);
}
