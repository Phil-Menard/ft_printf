/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:14:38 by pmenard           #+#    #+#             */
/*   Updated: 2024/11/20 16:42:46 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
size_t	len_int(unsigned int n);
char	*ft_itoa(unsigned int n);
void	ft_printnum(int nb, int *result);
void	ft_putchar(int c, int *result);
void	ft_print_unum(unsigned int nb, int *result);
char	*ft_itohex(unsigned int x, int loworup);
void	ft_puthexlow(unsigned int x, int *result);
void	ft_puthexup(unsigned int x, int *result);

#endif