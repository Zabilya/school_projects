/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:39:25 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/21 11:39:29 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int a)
{
	if (a >= 97 && a <= 122)
		return (a - 32);
	else
		return (a);
}
