/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:37:31 by cschuste          #+#    #+#             */
/*   Updated: 2018/12/03 12:37:40 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_rev(int *a, int *b)
{
	int buff;

	if (*a < *b)
	{
		buff = *a;
		*a = *b;
		*b = buff;
	}
}
