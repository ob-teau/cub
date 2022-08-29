/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elmt_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:45:22 by acoinus           #+#    #+#             */
/*   Updated: 2022/08/25 15:13:09 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	fill_fc(char *s, char *dup, int i, int x)
{
	int	rgb[3];
	int	j;
	int	sz;

	j = -1;
	sz = ft_strlen(s);
	while (i + x < sz && s[i + x] && j < 3)
	{
		if (s[i + x] == ',')
			continue ;
		while (s[i + x] && s[i + x] != ',')
			x++;
		dup = ft_strdup_n(&s[i], x);
		rgb[++j] = ft_atoi(dup);
		if (rgb[j] < 0 || rgb[j] > 255)
			return (0);
		free(dup);
		i = i + x + 1;
		x = 0;
	}
	return ((rgb[0] << 16) + (rgb[1] << 8) + rgb[2]);
}

static int	check_fc(char *s, int i)
{
	int	vir;

	vir = 0;
	while (s && s[++i])
		if (s[i] == ',')
			vir++;
	if (vir != 2 || ft_isdigit_cub(s) || s[0] == ',' || s[i - 1] == ',')
		return (0);
	return (fill_fc(s, NULL, 0, 0));
}

static int	valid_path(char *s, char c, t_data *data)
{
	int	fc;

/*	if (c == 'N')
		data->txtr[0] = mlx_xpm_file_o_image(data->mlx_ptr, s, 64, 64);
	if (c == 'S')
		data->txtr[1] = mlx_xpm_file_o_image(data->mlx_ptr, s, 64, 64);
	if (c == 'E')
		data->txtr[2] = mlx_xpm_file_o_image(data->mlx_ptr, s, 64, 64);
	if (c == 'W')
		data->txtr[3] = mlx_xpm_file_o_image(data->mlx_ptr, s, 64, 64);*/
	if (c == 'C' || c == 'F')
	{
		fc = check_fc(s, -1);
		if (fc <= 0)
			return (1);
		if (c == 'C')
		{
			data->c = fc;
printf(BLUE"c = [%d]"RESET"\n", data->c);
		}
		if (c == 'F')
		{
			data->f = fc;
printf(BLUE"f = [%d]"RESET"\n", data->f);
		}
	}
/*	if ((c == 'N' && !data->txtr[0]) || (c == 'S' && !data->txtr[1])
		|| (c == 'E' && !data->txtr[2]) || (c == 'W' && !data->txtr[3])
		|| (c == 'F' && !data->f) || (c == 'C' && !data->c))
		return (1);*/
	return (0);
}

static int	elmt_checker_suite(int i, char c, char *l, t_data *data)
{
	int		j;
	int		x;
	char	*s;

	j = i + 1;
	if (l[i] && ((l[i] == 'N' && l[j] == 'O') || (l[i] == 'S' && l[j] == 'O')
			|| (l[i] == 'E' && l[j] == 'A') || (l[i] == 'W' && l[j] == 'E')))
		i += 2;
	else
		i++;
	while (l[i] && l[i] == ' ')
		i++;
	j = i;
	while (l[j] && l[j] != ' ')
		j++;
	x = j;
	while (l[j] && l[j] == ' ')
		j++;
	if (l[j])
		return (1);
	s = ft_strdup_n(&l[i], (x - i));
printf(BLUE"strdup %c = [%s]"RESET"\n", c, l);
	if (valid_path(&l[i], c, data))
		return (free(s), 1);
	return (free(s), 0);
}

int	elmt_checker(int i, char *line, t_data *data, int x)
{
printf("******elmt_checker******\n");
	while (get_next_line(data->fd, &line) && ++x)
	{
		i = 0;
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '\n' || !line[i] && !(data->f && data->c))
		{
			free(line);
			line = NULL;
			continue ;
		}
		if (data->f && data->c && line[i])/* &&data->txtr[0] && data->txtr[1] && data->txtr[2]
			&& data->txtr[3])*/
			return (map_checker(line, 0, data, x));
		if (line[i] && (line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != 'F' && line[i] != 'C'))
			return (free(line), ft_error(4, data->fd));
		else
			if (!(data->f && data->c) &&elmt_checker_suite(i, line[i], line, data))
				return (free(line), ft_error(4, data->fd));
		free(line);
		line = NULL;
	}
	return (free(line), ft_error(5, data->fd));
}
