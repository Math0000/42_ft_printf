/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numdigt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:17:57 by mmoreira          #+#    #+#             */
/*   Updated: 2021/03/19 18:02:01 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_numdigt(int unsigned base, int n)
{
	unsigned int	cont;
	unsigned int	num;

	if (n < 0)
	{
		num = -n;
		cont = 2;
	}
	else
	{
		num = n;
		cont = 1;
	}
	while (num >= base && cont++)
		num /= base;
	return (cont);
}
