/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:28:46 by chmadran          #+#    #+#             */
/*   Updated: 2023/04/24 13:42:02 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_itoa_base(unsigned long n, char *base);
char	*ft_itoa(int n);
char	*ft_utoa_base(unsigned int n, char *base);
char	*ft_utoa(unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_identify(const char *format, int pos, va_list ap);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putstr_p(char *str);
int		ft_strlen(char *str);
int		ft_putnbr(int nbr);
int		ft_putnbr_unsigned_int(unsigned int nbr);
int		ft_putnbr_hexa(unsigned int n, char *base);
int		ft_putnbr_void_pointer(void *nbr);
int		ft_len(int n);
int		ft_len_hexa(unsigned long n);
int		ft_len_hexa_p(unsigned long n);
int		ft_strlen_string(int nb);
int		ft_strlen_string_u(unsigned int nb);

#endif
