#include "ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
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
				ft_putchar(va_arg(ap, int));
			if (format[1] == 's')
				ft_putstr(va_arg(ap, char *));
			if(format[1] == '%')
				ft_putchar('%');
			format++;
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (result);
}

#include <stdio.h>

int	main(void)
{
	char	a;
	char	b;
	char	str[] = "hello";

	a = 'f';
	b = 'u';
	//a = sum_integers(6, 10, 20, 30, 40, 50, 60); //le premier arg indique le nombre d'arg qui suivent
	ft_printf("%c%c%%%s\n", a, b, str);
	printf("%c%c%%%s\n", a, b, str);

	return (0);
}

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
=>doit être appelée avant toute utilisation de va_arg. La macro va_start a deux paramètres :
 la variable ap et le nom du dernier paramètre obligatoire de la fonction.

	va_arg(va_list ap, type)
=>délivre le paramètre effectif courant : le premier appel à va_arg délivre le premier paramètre,
puis chaque nouvel appel à va_arg délivre le paramètre suivant.
La macro va_arg admet deux paramètres : la variable ap et le type du paramètre courant

	va_end(va_list ap) 
=>doit être appelée après toutes les utilisations de va_arg. 
La macro va_end admet un seul paramètre : la variable ap.

	va_copy(va_list dest, va_list src)
=>This macro makes a copy of the variadic function arguments.
	*/