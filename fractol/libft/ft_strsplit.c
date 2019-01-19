/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:36:06 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/26 13:36:06 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		c_w(char const *s, char c)
{
	int words;

	words = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			++words;
		s++;
	}
	return (words);
}

static	int		count_letters(char const *s, char c, int i)
{
	int word;
	int counter;

	counter = 0;
	word = 0;
	while (word < i)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			word++;
		s++;
	}
	while (*s == c)
		s++;
	while (*s != c && *s != '\0')
	{
		counter++;
		s++;
	}
	return (counter);
}

static	char	**valid_mall(char **arr, int i)
{
	while (--i)
		free(arr[i]);
	arr[i] = NULL;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		words;
	int		i;
	int		buff;
	int		j;

	if (!s || !c || !(arr = (char **)malloc(sizeof(char *) * (c_w(s, c) + 1))))
		return (NULL);
	words = c_w(s, c);
	i = 0;
	buff = 0;
	while (words > i)
	{
		if (!(arr[i] = (char *)malloc(count_letters(s, c, i) + 1)))
			return (valid_mall(arr, i));
		j = 0;
		while (s[buff] == c)
			buff++;
		while (s[buff] != c && s[buff] != '\0')
			arr[i][j++] = s[buff++];
		arr[i++][j] = '\0';
	}
	arr[i] = 0;
	return (arr);
}
