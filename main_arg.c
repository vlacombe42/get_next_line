/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlacombe <vlacombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 15:09:33 by vlacombe          #+#    #+#             */
/*   Updated: 2020/09/07 13:49:46 by vlacombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		printf("%d: %s\n", ret, line);
		free(line);
	}
	printf("%d: %s\n", ret, line);
	free(line);
	system("leaks a.out");
	if (argc == 2)
		close(fd);
}
