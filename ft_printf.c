/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:12:53 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/20 15:29:52 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c, int *result)
{
	write(1, &c, 1);
	*result += 1;
}

void	ft_putstr(char *str, int *result)
{
	if (str == NULL)
		ft_putstr("(null)", result);
	else
	{
		while (*str)
		{
			ft_putchar(*str, result);
			str++;
		}
	}
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	ap;

	result = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (format[1] == 'c')
				ft_putchar(va_arg(ap, int), &result);
			if (format[1] == 's')
				ft_putstr(va_arg(ap, char *), &result);
			if (format[1] == 'd' || format[1] == 'i')
				ft_printnum(va_arg(ap, int), &result);
			if (format[1] == 'u')
				ft_print_unum(va_arg(ap, unsigned int), &result);
			if (format[1] == '%')
				ft_putchar('%', &result);
			format++;
		}
		else
			ft_putchar(*format, &result);
		format++;
	}
	va_end(ap);
	return (result);
}

#include <stdio.h>

int	main(void)
{
	int				count_p;
	int				count_ft;
	int				a;
	unsigned int	u;
	char			*s = NULL;

	ft_printf("-------%%c--------\n");
	printf("-------%%c--------\n");
	count_ft = ft_printf("ft_printf : %c%c%c\n", 'a', 'P', '\0');
	count_p = printf("   printf : %c%c%c\n", 'a', 'P', '\0');
	printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);

	ft_printf("-------%%s--------\n");
	printf("-------%%s--------\n");
	count_ft = ft_printf("ft_printf : %s %s\n", s, "lalalalala");
	count_p = printf("   printf : %s %s\n", s, "lalalalala");
	printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);

	ft_printf("-------%%d--------\n");
	printf("-------%%d--------\n");
	a = -2147483648;
	count_ft = ft_printf("ft_printf : %d %d %d\n", 0, a, 2147483647);
	count_p = printf("   printf : %d %d %d\n", 0, a, 2147483647);
	printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);

	ft_printf("-------%%i--------\n");
	printf("-------%%i--------\n");
	count_ft = ft_printf("ft_printf : %i %i %i\n", 0, a, 2147483647);
	count_p = printf("   printf : %i %i %i\n", 0, a, 2147483647);
	printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);

	ft_printf("-------%%u--------\n");
	printf("-------%%u--------\n");
	u = 4294967295;
	count_ft = ft_printf("ft_printf : %u %u\n", 0, u);
	count_p = printf("   printf : %u %u\n", 0, u);
	printf("count ft_printf : %d\n", count_ft);
	printf("count    printf : %d\n", count_p);
	
	return (0);
}

//a = sum_integers(6, 10, 20, 30, 40, 50, 60); 
//le premier arg indique le nombre d'arg qui suivent
/* int	sum_integers(int num, ...)
{
	int	result;
	va_list	ap;

	result = 0;
	va_start(ap, num);
	while (num > 0)
	{
		result += va_arg(ap, int);
		num--;
	}
	va_end(ap);
	return (result);
} */
	/* va_list
=>permet de déclarer une variable opaque au programmeur, à passer en paramètre
 aux autres macros va_start(), va_arg() and va_end().
Cette variable s'appelle traditionnellement ap (pour argument pointer), 
et a pour but de repérer le paramètre effectif courant.

	va_start(va_list ap, parmN)
=>doit être appelée avant toute utilisation de va_arg. 
La macro va_start a deux paramètres :
 la variable ap et le nom du dernier paramètre obligatoire de la fonction.

	va_arg(va_list ap, type)
=>délivre le paramètre effectif courant : le premier appel à 
va_arg délivre le premier paramètre,
puis chaque nouvel appel à va_arg délivre le paramètre suivant.
La macro va_arg admet deux paramètres : la variable ap et 
le type du paramètre courant

	va_end(va_list ap) 
=>doit être appelée après toutes les utilisations de va_arg. 
La macro va_end admet un seul paramètre : la variable ap.

	va_copy(va_list dest, va_list src)
=>This macro makes a copy of the variadic function arguments.
	*/