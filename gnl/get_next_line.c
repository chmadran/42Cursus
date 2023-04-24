/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlottemadrangeas <charlottemadrangea    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:08:42 by chmadran          #+#    #+#             */
/*   Updated: 2022/12/01 09:23:44 by charlottema      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_line(char *str, int nbytesRead)
{
	int	i;

	i = 0;
	while (i < nbytesRead)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_clean_line(char *buf)
{
	char	*newbuf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	newbuf = malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	i++;
	while (buf[i])
		newbuf[j++] = buf[i++];
	newbuf[j] = '\0';
	free (buf);
	return (newbuf);
}

char	*ft_fill_line(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_read(char *buf, int fd)
{
	char	*temp_buf;
	int		nbytes_read;

	if (!buf)
		buf = ft_calloc(1, 1);
	temp_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nbytes_read = 1;
	while (nbytes_read > 0)
	{
		nbytes_read = read(fd, temp_buf, BUFFER_SIZE);
		if (nbytes_read == -1)
		{
			free(temp_buf);
			return (NULL);
		}
		temp_buf[nbytes_read] = '\0';
		buf = ft_strcat(buf, temp_buf);
		if (ft_check_line(temp_buf, nbytes_read))
			break ;
	}
	free(temp_buf);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = ft_read(buf, fd);
	if (!buf)
		return (NULL);
	line = ft_fill_line(buf);
	buf = ft_clean_line(buf);
	return (line);
}

/* int	open_fd(void)
{
	int	fd;

	fd = open("42fichier.c", O_RDONLY);
	if (fd == -1)
		return (0);
	return (fd);
}

int	main(void)
{
	int	fd;
	char	*str;

	fd = open_fd();

	str = get_next_line(fd);
	printf("%s", str);
	// free (str);
} */
