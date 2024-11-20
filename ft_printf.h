#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
size_t	len_int(long int n);
char	*ft_itoa(int n, int *result);
void	ft_printnum(int nb, int *result);
void	ft_putchar(int c, int *result);

#endif