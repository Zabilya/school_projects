/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:11:21 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/21 14:11:28 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*str;
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	while (src[counter])
		counter++;
	if (!(str = (char *)malloc(sizeof(char) * (counter + 1))))
		return (NULL);
	while (i < counter)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
