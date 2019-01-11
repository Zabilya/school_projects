/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:23:59 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/26 12:24:00 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	check_start(char const *s, int *start, int *end, int *j)
{
	int i;

	i = 0;
	*j = 0;
	*start = 0;
	*end = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static	int	check_end(char const *s, int end)
{
	while (s[end])
		++end;
	--end;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	end++;
	return (end);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	start = check_start(s, &start, &end, &i);
	if (start == (int)ft_strlen(s))
	{
		str = (char *)malloc(1);
		*str = '\0';
		return (str);
	}
	end = check_end(s, end);
	if (!(str = (char *)(malloc(sizeof(char) * (end - start + 1)))))
		return (NULL);
	while ((end - start))
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
