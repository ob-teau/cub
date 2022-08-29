/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:21:23 by acoinus           #+#    #+#             */
/*   Updated: 2022/08/27 18:05:51 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	*ft_strjoin_map_suite(int *j, t_data *data, int *str, int n)
{
	int i;

	while (j[0] < data->map.mini_x)
	{
		str[++j[1]] = 32;
		j[0]++;
	}
	i = -1;
	data->map.s_map = malloc(sizeof(int) * (n * data->map.mini_x));
	while (++i < n * data->map.mini_x)
	{
		data->map.s_map[i] = str[i];
		printf(GREEN"%d ", data->map.s_map[i]);
	}
	printf(RESET"\n\n");
	free(str);
	str = NULL;
	return (str);
}

int	*ft_strjoin_map(t_data *data, char *s2, int i, int n)
{
	int		j[2];
	int		*str;

//printf("******strjoin******\n");
	j[1] = -1;
	j[0] = -1;
	str = malloc(sizeof(int) * (n * data->map.mini_x));
	if (str == NULL)
		return (NULL);
	while (data->map.s_map && i < (n - 1) * data->map.mini_x)
		str[++j[1]] = data->map.s_map[i++];
	if (data->map.s_map)
	{
		free(data->map.s_map);
		data->map.s_map = NULL;
	}
	while (s2 && s2[++j[0]])
	{
		if ((int)s2[j[0]] >= 48 && (int)s2[j[0]] < 58)
			str[++j[1]] = (int)s2[j[0]] - 48;
		else
			str[++j[1]] = (int)s2[j[0]];
	}
	return (ft_strjoin_map_suite(j, data, str, n));
}

/*
int	*ft_strjoin_map(t_data *data, char *s2, int i, int n)
{
	int j;
	int	k;
	int	x;
	int		*str;

printf("******strjoin******\n");
	k = -1;
	j = -1;
	str = malloc(sizeof(int) * (n * data->map.mini_x));
	if (str == NULL)
		return (NULL);
	while (data->map.s_map && i < (n - 1) * data->map.mini_x)
		str[++k] = data->map.s_map[i++];
	if (data->map.s_map)
	{
		free(data->map.s_map);
		data->map.s_map = NULL;
	}
	printf("[");
	while (s2 && s2[++j])
	{
		if ((int)s2[j] >= 48){
			str[++k] = (int)s2[j] - 48;
//printf(RED"str[%d] = [%d]"RESET"\n", k, str[k]);
		}
		else
		{
			str[++k] = (int)s2[j];
//printf(RED"str[%d] = [%d]"RESET"\n", k, str[k]);
		}
	}
	while (j < data->map.mini_x)
	{
		str[++k] = 32;
		j++;
	}

	printf("]\n");
	i = -1;
	data->map.s_map = malloc(sizeof(int) * (n * data->map.mini_x));
	while (++i < n * data->map.mini_x)
	{
		data->map.s_map[i] = str[i];
		printf(GREEN"[%d]", data->map.s_map[i]);
	}
	printf(RESET"\n");
	free(str);
	str = NULL;
	return (str);
}*/
