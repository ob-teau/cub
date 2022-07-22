/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elmt_map_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:45:22 by acoinus           #+#    #+#             */
/*   Updated: 2022/07/22 12:51:16 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_checker()
{
}

static int	valid_path()
{
	
}

static int	elmt_checker_suite(int i, int j, char *line, t_data *data)
{
	int	x;

printf("2\n");
	if ((line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'S' && line[i + 1]
		== 'O') || (line[i] == 'E' &&  line[i + 1] == 'A')
		|| (line[i] == 'W' && line[i + 1] == 'E'))
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	j = i;
	while (line[j] && line[j] != ' ')
		j++;
	x = j;
	while (line[j] == ' ')
		j++;
	if (line[j])
		return (1);
	if (valid_path())
		return (1);
	return (0);
}

int	elmt_checker(int i, int fd, char *line, t_data *data)
{
	printf("\n***********\n1\n");
	get_next_line(fd, &line);
	while (line)
	{
		i = 0;
printf("ici ?\n");
		if (line[0] == '\n')
		{
			get_next_line(fd, &line);
			continue;
		}
printf("lol\n");
		while (line[i] == ' ')
			i++;
printf("ok\n");
		if (line[i] != 'N' || line[i] != 'S' || line[i] != 'E'
		|| line[i] != 'W' || line[i] != 'F' || line[i] != 'C')
			{printf("ah\n");
			return (ft_error(4, fd));}
		else
			if (elmt_checker_suite(++i, 0, line, data))
				return (ft_error(4, fd));
	}
	printf("3\n");
	if (!data->txtr[0] && !data->txtr[1] && !data->txtr[2] && !data->txtr[3])
		return (ft_error(4, fd));
	return (0);
}

