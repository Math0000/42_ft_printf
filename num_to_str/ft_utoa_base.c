/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoreira <mmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:44:47 by mmoreira          #+#    #+#             */
/*   Updated: 2021/03/19 18:01:43 by mmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	check_base(char *base)
{
	char	vetor[ft_strlen(base) + 1];
	int		i;
	int		j;

	if (!(base) || ft_strlen(base) == 1)
		return (0);
	i = 0;
	while (*(base + i++) != '\0')
		if (*(base + i - 1) || *(base + i - 1) == '+')
			return (0);
	i = 0;
	*(vetor + i) = '\0';
	while (*(base + i) != '\0')
	{
		j = 0;
		while (*(vetor + j++) != '\0')
			if (*(base + i) == *(vetor + j - 1))
				return (0);
		*(vetor + j) = *(base + i);
		*(vetor + j + 1) = '\0';
		i++;
	}
	return (1);
}

static void	make_str(unsigned int n, char *base, unsigned int pot, char **temp)
{
	unsigned int	num;
	unsigned int	cont;

	cont = 0;
	num = n;
	while (pot > 0)
	{
		*(*temp + cont) = base[num / pot];
		num = num % pot;
		pot /= (unsigned int)ft_strlen(base);
		cont++;
	}
}

char		*ft_utoa_base(unsigned int n, char *base)
{
	unsigned int	cont;
	unsigned int	num;
	unsigned int	pot;
	char			*temp;

	if (check_base(base))
		return (NULL);
	num = n;
	cont = 1;
	while (num >= (unsigned int)ft_strlen(base) && cont++)
		num /= (unsigned int)ft_strlen(base);
	if (!(temp = malloc((cont + 1) * sizeof(char))))
		return (NULL);
	*(temp + cont) = '\0';
	pot = 1;
	while (--cont)
		pot *= (unsigned int)ft_strlen(base);
	make_str(n, base, pot, &temp);
	return (temp);
}
