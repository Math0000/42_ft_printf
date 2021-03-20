/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:14:50 by mmoreira          #+#    #+#             */
/*   Updated: 2021/03/19 18:01:46 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	unsigned int	cont;
	unsigned int	num;
	char			*temp;

	cont = 1;
	num = n;
	while (n >= 10 && cont++)
		n /= 10;
	if (!(temp = malloc((cont + 1) * sizeof(char))))
		return (NULL);
	*(temp + cont) = '\0';
	while (cont--)
	{
		*(temp + cont) = num % 10 + '0';
		num /= 10;
	}
	return (temp);
}
