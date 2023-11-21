/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juvilleg <juvilleg@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:58:43 by juvilleg          #+#    #+#             */
/*   Updated: 2023/11/21 17:47:10 by juvilleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_numlen(int num);
int	ft_unsglen(unsigned int num);
int	ft_hexalen(unsigned int num, char c);
int	ft_hexaplen(uintptr_t num);
#endif
