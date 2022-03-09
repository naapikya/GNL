/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:12:47 by naapikya          #+#    #+#             */
/*   Updated: 2021/04/18 19:23:16 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*ft_new_line(char *tmp)
{
	char	*ptr;
	int		i;

	i = 0;
	while (tmp && tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	if (!(ptr = malloc((i + 1))))
		return (NULL);
	i = 0;
	while (tmp && tmp[i] != '\0' && tmp[i] != '\n')
	{
		ptr[i] = tmp[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_clearmemory(char *memory)
{
	char	*temp;
	int		length;
	int		i;
	int		j;

	i = 0;
	if (!memory)
		return (NULL);
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\0')
	{
		free(memory);
		return (NULL);
	}
	length = ft_strlen(memory) - i;
	if (!(temp = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	i++;
	j = 0;
	while (memory[i] != '\0')
		temp[j++] = memory[i++];
	temp[j] = '\0';
	free(memory);
	return (temp);
}

int		get_next_line(int fd, char **line)
{
	int				r;
	char			*buffer;
	static	char	*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(BUFFER_SIZE + 1)))
		return (-1);
	r = 1;
	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (ft_strchr(tmp, '\n') || ft_strchr(tmp, '\0'))
			break ;
	}
	free(buffer);
	if (r < 0)
		return (-1);
	*line = ft_new_line(tmp);
	tmp = ft_clearmemory(tmp);
	if (r == 0 && !tmp)
		return (0);
	return (1);
}
