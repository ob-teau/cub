/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elmt_checker2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:07:21 by acoinus           #+#    #+#             */
/*   Updated: 2022/07/28 16:58:11 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	dec_to_hex(int rgb, char *base, int n)
{
	int	q;
	int	r;

	q = rgb / 16;
	while (q > 0)
	{
printf(GREEN"n = [%d]"RESET"\n", n);
		r = rgb - q * 16;
		if (r > 16)
		{
			r %= 16;
			if (r = 0)
				r = 16;
		}
//		n = n * 10 + base[r];
		printf(RED"n = [%c], base[%d] = [%c], q = [%d]"RESET"\n", n, r, base[r], q);
		q /= 16;
	}
	return (n);
}

int	createRGB(int r, int g, int b)
{
	int	r_hex;
	int	g_hex;
	int	b_hex;

	r_hex = dec_to_hex(r, "0123456789ABCDEF", 0);
printf(YELLOW"r = [%d], r_hex = [%d]"RESET"\n", r, r_hex);
	g_hex = dec_to_hex(g, "0123456789ABCDEF", 0);
printf(YELLOW"g = [%d], g_hex = [%d]"RESET"\n", g, g_hex);
	b_hex = dec_to_hex(b, "0123456789ABCDEF", 0);
printf(YELLOW"b = [%d], b_hex = [%d]"RESET"\n", b, b_hex);
    return (((r_hex & 0xff) << 16) + ((g_hex & 0xff) << 8) + (b_hex & 0xff));
}

static int	map_storing(int fd)
{
/*	close(fd);
	get_next_line(fd, &line)*/
	return (0);
}

int	map_checker(char *line, int fd, int i, t_data *data)
{
	int	sz;
	int	line_nb;
	printf("****map checker******\n");

	sz = ft_strlen(line);
	line_nb = 0;
	while (line)
	{
		if (!line[0])
			return (free(line), map_storing(fd));
		line_nb++;
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && line[i] == '\n')
			return (free(line), ft_error(5, fd));
		if (ft_strlen(line) > sz)
			sz = ft_strlen(line);
		free(line);
		get_next_line(fd, &line);
	}
	return (0);
}
