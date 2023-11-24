/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juvilleg <juvilleg@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 13:34:36 by juvilleg          #+#    #+#             */
/*   Updated: 2023/11/24 11:33:04 by juvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	int	cont;

	cont = 0;
	write(1, &c, 1);
	cont++;
	return (cont);
}

int	ft_printstr(char const *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		i = 6;
		return (i);
	}
	while (str[i] != '\0')
	{
		ft_printchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_format(char c, va_list arg, int cont)
{
	if (c == '%')
		cont += ft_printchar('%');
	else if (c == 'c')
		cont += ft_printchar(va_arg(arg, int));
	else if (c == 's')
		cont += ft_printstr(va_arg(arg, char const *));
	else if (c == 'p')
		cont += ft_hexaplen(va_arg(arg, uintptr_t));
	else if (c == 'd' || c == 'i')
		cont += ft_numlen(va_arg(arg, int));
	else if (c == 'u')
		cont += ft_unsglen(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		cont += ft_hexalen(va_arg(arg, unsigned int), c);
	return (cont);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		cont;
	va_list	arg;

	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	cont = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			cont = ft_format(str[i + 1], arg, cont);
			i++;
		}
		else
			cont += ft_printchar(str[i]);
		i++;
	}
	va_end(arg);
	return (cont);
}
