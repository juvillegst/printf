/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juvilleg <juvilleg@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:20:43 by juvilleg          #+#    #+#             */
/*   Updated: 2023/11/21 18:01:59 by juvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhexachar(unsigned int num, int cap)
{
	if (num == 10)
		ft_printchar('a' - cap);
	else if (num == 11)
		ft_printchar('b' - cap);
	else if (num == 12)
		ft_printchar('c' - cap);
	else if (num == 13)
		ft_printchar('d' - cap);
	else if (num == 14)
		ft_printchar('e' - cap);
	else if (num == 15)
		ft_printchar('f' - cap);
}

void	ft_printhexa(unsigned int num, int cap)
{
	int	res;
	int	quot;

	quot = num / 16;
	res = num - (16 * quot);
	if (num > 15)
		ft_printhexa(num / 16, cap);
	if (res >= 10 && res <= 15)
		ft_printhexachar(res, cap);
	else
		ft_printchar(res + '0');
}

int	ft_hexalen(unsigned int num, char c)
{
	int	cont;
	int	cap;

	cap = 0;
	cont = 1;
	if (c == 'x')
		ft_printhexa(num, cap);
	if (c == 'X')
	{
		cap = 32;
		ft_printhexa(num, cap);
	}
	while (num > 15)
	{
		num /= 16;
		cont++;
	}
	return (cont);
}
