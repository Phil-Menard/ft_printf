/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:12:40 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/20 12:14:28 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	len_int(long int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n, int *result)
{
	char		*ptr;
	int			i;
	long int	x;

	x = (long int) n;
	i = len_int(x);
	if (x < 0)
	{
		ft_putchar('-', result);
		x *= -1;
	}
	ptr = malloc((len_int(x) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr[i--] = '\0';
	while (x > 9)
	{
		ptr[i--] = '0' + (x % 10);
		x /= 10;
	}
	ptr[i] = '0' + x;
	return (ptr);
}

void	ft_printnum(int nb, int *result)
{
	char		*arr;

	arr = ft_itoa(nb, result);
	while (*arr)
	{
		ft_putchar(*arr, result);
		arr++;
	}
}
