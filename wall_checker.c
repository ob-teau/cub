/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:52:26 by acoinus           #+#    #+#             */
/*   Updated: 2022/08/27 18:45:48 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int wall_checker(t_data *data, int *s, int sz, int x)
{
	int	i;

	i = -1;
	while (++i < sz && data->map.s_map)
		if ((i < x || !((i + 1) % x) || !((i + 1) % x - 1) || i > sz - x) && s[i] == 0)
		{
			printf(YELLOW"\n s[i] = [%d], i  = %d, %d - %d = %d"RESET"\n", s[i], i, sz, x, sz - x);
			return (ft_error(5, data->fd));
		}
	i = 0;
	while (i < sz && data->map.s_map)
	{
		printf(RED"%d"RESET" ", data->map.s_map[i]);
		if (data->map.s_map[i] == 0)
		
			if (s[i - x - 1] == 32 || s[i - x] == 32 || s[i - x + 1] == 32
			|| s[i - 1] == 32 || s[i + 1] == 32 || s[i + x - 1] == 32
			|| s[i + x] == 32 || s[i + x + 1] == 32)
			{
				printf(CYAN"\n i = %d\n"RESET"", i);
				return (ft_error(5, data->fd));
			}
		i++;
	}
	return (0);
}

int	p_checker(t_data *data, int i)
{
	int sz;
	int	p;

	p = 0;
	sz = (data->map.mini_y * (data->map.mini_x));
	printf("\n******wall_checker******\nsz= [%d]\n", sz);
	while (++i < sz && data->map.s_map)
	{
		printf(GREEN"%d"RESET" ", data->map.s_map[i]);
		if (data->map.s_map[i] != 'N' && data->map.s_map[i] != 'S'
				&& data->map.s_map[i] != 'E' && data->map.s_map[i] != 'W'
				&& data->map.s_map[i] != 1 && data->map.s_map[i] != 0
				&& data->map.s_map[i] != 32)
		{
			printf(RED"s_map[%d] = [%d]"RESET"\n", i, data->map.s_map[i]);
			return (ft_error(5, data->fd));
		}
		if (data->map.s_map[i] == 'N' || data->map.s_map[i] == 'S'
				|| data->map.s_map[i] == 'E' || data->map.s_map[i] == 'W')
			p++;
	}
	printf(RESET"\n");
	if (p != 1)
		return (ft_error(5, data->fd));
	return (wall_checker(data, data->map.s_map, sz, data->map.mini_x));
}
