/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:26:05 by oel-mado          #+#    #+#             */
/*   Updated: 2024/11/09 13:09:57 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int nbr)
{
	int	i;

	i = 1;
	while (nbr >= 10 || nbr <= -10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static char	*ft_instr(int n)
{
	int		i;
	int		len;
	char	*nbr;

	i = 0;
	len = ft_intlen(n);
	if (n < 0)
		len++;
	nbr = ft_calloc(sizeof(char), len + 1);
	if (!nbr)
		return (NULL);
	if (n < 0)
	{
		nbr[0] = '-';
		n = -n;
	}
	while (i < len && nbr[len - i - 1] != '-')
	{
		nbr[len - i - 1] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	if (!n)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (ft_instr(n));
}
