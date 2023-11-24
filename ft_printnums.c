/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juvilleg <juvilleg@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:20:00 by juvilleg          #+#    #+#             */
/*   Updated: 2023/11/24 11:42:55 by juvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printnum(int num)
{
	if (num == -2147483648)
	{
		ft_printchar('-');
		ft_printchar('2');
		num = 147483648;
	}
	if (num < 0)
	{
		ft_printchar('-');
		num *= -1;
	}
	if (num > 9)
		ft_printnum(num / 10);
	ft_printchar(num % 10 + '0');
}

int	ft_numlen(int num)
{
	int	cont;

	ft_printnum(num);
	cont = 0;
	if (num <= 0)
		cont = 1;
	while (num != '\0')
	{
		num /= 10;
		cont++;
	}
	return (cont);
}
