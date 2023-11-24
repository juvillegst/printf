/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juvilleg <juvilleg@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:24:19 by juvilleg          #+#    #+#             */
/*   Updated: 2023/11/24 11:42:41 by juvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printunsg(unsigned int num)
{
	if (num > 9)
		ft_printunsg(num / 10);
	ft_printchar(num % 10 + '0');
}

int	ft_unsglen(unsigned int num)
{
	int	cont;

	cont = 0;
	ft_printunsg(num);
	if (num == 0)
		cont = 1;
	while (num != '\0')
	{
		num /= 10;
		cont++;
	}
	return (cont);
}
