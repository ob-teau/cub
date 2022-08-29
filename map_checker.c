/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:07:21 by acoinus           #+#    #+#             */
/*   Updated: 2022/08/27 13:55:12 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	map_storing(char *line, t_data *data, int x)
{
	printf("******map storing******\n");
	int	n;
	close(data->fd);
	data->fd = open(data->s_cub, O_RDONLY);
	get_next_line(data->fd, &line);
	while (--x > 0)
	{
		free(line);
		get_next_line(data->fd, &line);
	}
	free(line);
	line = NULL;
	n = 1;
	while (get_next_line(data->fd, &line))
	{
		ft_strjoin_map(data, line, 0, n);
		n++;
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	if (!data->map.s_map)
		return(ft_error(5, data->fd));
	return (p_checker(data, -1));
}

int	map_checker(char *line, int i, t_data *data, int x)
{
	int n;

	n = 1;
	printf("******map checker******\n");
	data->map.mini_y = 0;
	data->map.mini_x = ft_strlen(line);
	while (line)
	{
		printf(GREEN"[%s]"RESET"\n", line);
		if (line[0] == '\0' && !n)
			return (free(line), map_storing(NULL, data, x - 1));
		else if (line[0] == '\0' && n)
			return (free(line), ft_error(5, data->fd));
		++data->map.mini_y;
		if (ft_strlen(line) > data->map.mini_x)
			data->map.mini_x = ft_strlen(line);
		free(line);
		line = NULL;
		n = get_next_line(data->fd, &line);
	}
	return (0);
}
