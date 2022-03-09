/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 19:14:43 by naapikya          #+#    #+#             */
/*   Updated: 2021/04/18 19:22:30 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int		ft_get_line_size(char *s);
char	*ft_clearmemory(char *memory);
char	*ft_new_line(char *s);

#endif

