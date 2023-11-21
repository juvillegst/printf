/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juvilleg <juvilleg@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:16:21 by juvilleg          #+#    #+#             */
/*   Updated: 2023/11/21 17:47:34 by juvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexapchar(uintptr_t num)
{
	if (num == 10)
		ft_printchar('a');
	else if (num == 11)
		ft_printchar('b');
	else if (num == 12)
		ft_printchar('c');
	else if (num == 13)
		ft_printchar('d');
	else if (num == 14)
		ft_printchar('e');
	else if (num == 15)
		ft_printchar('f');
}

void	ft_printhexap(uintptr_t num)
{
	int	res;
	int	quot;

	quot = num / 16;
	res = num - (16 * quot);
	if (num > 15)
		ft_printhexap(num / 16);
	if (res >= 10 && res <= 15)
		ft_printhexapchar(res);
	else
		ft_printchar(res + '0');
}

int	ft_hexaplen(uintptr_t num)
{
	int	cont;

	cont = 3;
	ft_printchar('0');
	ft_printchar('x');
	if (num == 0)
		ft_printchar('0');
	else
		ft_printhexap(num);
	while (num > 15)
	{
		num /= 16;
		cont++;
	}
	return (cont);
}
