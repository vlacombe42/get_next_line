/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlacombe <vlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 14:41:08 by vlacombe          #+#    #+#             */
/*   Updated: 2020/09/17 14:52:51 by vlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>

int		get_next_line(const int fd, char **line);
int		ft_search_eol(const char *s, char c);
int		line_check(char **line, char **rest_string);
void	ft_free(char **ptr);
char	*ft_strjoin_free(char const *s1, char const *s2);

#endif
