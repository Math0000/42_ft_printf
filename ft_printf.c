/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:01:37 by mmoreira          #+#    #+#             */
/*   Updated: 2021/03/19 18:06:28 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, str);
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '%')
			j += ft_check_flags(str, args, &i);
		else
		{
			ft_putchar_fd(*(str + i), 1);
			j++;
		}
		i++;
	}
	va_end(args);
	return (j);
}
