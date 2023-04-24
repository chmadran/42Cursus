/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:22:34 by chmadran          #+#    #+#             */
/*   Updated: 2023/01/02 18:51:25 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	ft_reception(int signal);
void	ft_encoding(char c, int pid);
void    ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_handle_signal(int sig, siginfo_t *info, void *str);

#endif
