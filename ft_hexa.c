/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:54:09 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/20 16:43:21 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itohex(unsigned int x, int loworup)
{
	size_t	i;
	char	*ptr;
	int		temp;

	i = 0;
	ptr = malloc((len_int(x) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (x == 0)
		ptr[i++] = '0';
	while (x != 0)
	{
		temp = x % 16;
		if (temp < 10)
			ptr[i++] = 48 + temp;
		else
			ptr[i++] = loworup + temp;
		x /= 16;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_puthexlow(unsigned int x, int *result)
{
	char	*arr;
	char	*p;
	int		i;

	arr = ft_itohex(x, 87);
	p = arr;
	if (arr != NULL)
	{
		i = ft_strlen(arr) - 1;
		while (i >= 0)
		{
			ft_putchar(arr[i], result);
			i--;
		}
		free(p);
	}
}

void	ft_puthexup(unsigned int x, int *result)
{
	char	*arr;
	char	*p;
	int		i;

	arr = ft_itohex(x, 55);
	p = arr;
	if (arr != NULL)
	{
		i = ft_strlen(arr) - 1;
		while (i >= 0)
		{
			ft_putchar(arr[i], result);
			i--;
		}
		free(p);
	}
}