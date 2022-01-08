/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyolando <jyolando@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:57:47 by jyolando          #+#    #+#             */
/*   Updated: 2021/10/10 18:01:33 by jyolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strclr(char *rem, char *buf)
{
	char	*temp;

	temp = ft_strjoin(rem, buf);
	free(rem);
	return (temp);
}

char	*get_left_line(char *rem)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (rem[i] && rem[i] != '\n')
		i++;
	if (!rem[i])
	{
		free(rem);
		return (NULL);
	}
	line = (char *)ft_calloc((ft_strlen(rem) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (rem[i])
		line[j++] = rem[i++];
	free(rem);
	return (line);
}

char	*get_line(char *rem)
{
	char	*line;
	int		i;

	i = 0;
	if (!rem[i])
		return (NULL);
	while (rem[i] && rem[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (rem[i] && rem[i] != '\n')
	{
		line[i] = rem[i];
		i++;
	}
	if (rem[i] && rem[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_fd(int fd, char *rem)
{
	char	*buf;
	int		bytes;

	if (!rem)
		rem = (char *)ft_calloc(1, 1);
	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = 0;
		rem = ft_strclr(rem, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (rem);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rem[MAX_FD];

	if (fd < 0 || fd > MAX_FD || read(fd, 0, 0) < 0)
		return (NULL);
	rem[fd] = read_fd(fd, rem[fd]);
	if (!rem[fd])
		return (NULL);
	line = get_line(rem[fd]);
	rem[fd] = get_left_line(rem[fd]);
	return (line);
}
