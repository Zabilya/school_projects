/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschuste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:19:58 by cschuste          #+#    #+#             */
/*   Updated: 2018/11/22 11:19:59 by cschuste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int num;
	int minus;
	int counter;

	counter = 0;
	num = 0;
	minus = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' && *str++)
		minus = -1;
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str++ - '0';
		counter++;
	}
	if (counter >= 20 && minus == 1)
		return (-1);
	else if (counter >= 20 && minus == -1)
		return (0);
	return (num * minus);
}
