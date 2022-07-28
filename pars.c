/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:04:37 by acoinus           #+#    #+#             */
/*   Updated: 2022/07/28 16:55:56 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	check_open(char *s_cub, t_data *data)
{
	int	fd;
	char *line;

	fd = 0;
	fd = open(s_cub, O_DIRECTORY);
	if (fd > 0)
		return (ft_error(2, fd));
	fd = open(s_cub, O_RDONLY);
	if (fd < 0)
		return (ft_error(3, fd));
	if (fd > 0)
	{
		printf("OK fd = [%d]\n", fd);
		if (elmt_checker(0, fd, line, data))
			return (1);
	}
	close(fd);
	return (0);
}

int	check_cub(char *s, char *cub, int cub_len)
{
	int	s_len;

	if (!s)
		return (1);
	s_len = ft_strlen(s);
	while (cub_len >= 0)
	{
		if (s[s_len] == cub[cub_len])
		{
			s_len--;
			cub_len--;
		}
		else
			break;
	}
	if (cub_len == -1 && (s[s_len] && s[s_len] != '.' && s[s_len] != '/'))
	{
		printf("CHECK_CUB OK\n");
		return (0);
	}
	return (1);
}

int pars(t_data *data)
{
	if (check_cub(data->s_cub, ".cub", 4))
		return (ft_error(1, -1));
	if (check_open(data->s_cub, data))
		return (1);
}
