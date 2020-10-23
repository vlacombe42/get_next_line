/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlacombe <vlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:40:09 by vlacombe          #+#    #+#             */
/*   Updated: 2020/09/10 09:28:56 by vlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*join;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = '\0';
	free((void*)s1);
	s1 = NULL;
	return (join);
}

/*
** it's serve for my get_next_line for concatenate my static rest_string
** and buff.
*/

int		ft_search_eol(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
** this function search_eol(end of line) allow to find the position of '\n'.
*/

void	ft_free(char **ptr)
{
 	free(*ptr);
 	*ptr = NULL;
}

/*
** this function will be created to free the malloc inside
** my programm get_next-line.
*/

int		line_check(char **line, char **rest_string)
{
	char	*str;
	int		i;

	i = ft_search_eol(*rest_string, '\n');
	if (i != -1)
	{
		*line = (char*)(malloc(sizeof(char) * (i + 1)));
		ft_memcpy(*line, *rest_string, i);
		(*line)[i] = '\0';
		str = ft_strdup(*rest_string + i + 1);
		ft_free(rest_string);
		*rest_string = str;
		return (1);
	}
	*line = ft_strdup(*rest_string);
	ft_free(rest_string); 
	if (ft_strlen(*line) > 0)
		return (1);
	return (0);
}

/*
** this function allow to check every line and that the file must do.
*/

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buff[BUFF_SIZE + 1];
	static	char	*rest_string = NULL;

	if (!line)
		return (-1);
	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!rest_string)
		rest_string = ft_strnew(0);
	while (ft_search_eol(rest_string, '\n') == -1
		&& (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(rest_string = ft_strjoin_free(rest_string, buff)))
			return (-1);
	}
	return (line_check(line, &rest_string));
}

/*
** using function 'read', this allows to read line by line until '\0'
** we return 0 or 1 if we read the line
** and finished the reading. The process is available
** until there are no more lines to read.
*/
