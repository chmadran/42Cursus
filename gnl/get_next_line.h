/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:27 by chmadran          #+#    #+#             */
/*   Updated: 2022/11/30 18:04:41 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<stdio.h>
# include<stdlib.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include<string.h>
# include<unistd.h>
# include <stdint.h>

char	*ft_clean_line(char *buf);
char	*ft_fill_line(char *buf);
char	*ft_read(char *buf, int fd);
char	*get_next_line(int fd);
//int	open_fd(void);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcat(char *buff, char *temp_buff);
int		ft_strlen(char *str);
int		ft_check_line(char *str, int nbytesRead);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);

#endif
