/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:39:06 by acoinus           #+#    #+#             */
/*   Updated: 2022/07/28 16:55:17 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_free(t_data *data, int ret, int niv)
{
	if (data->s_cub)
		free(data->s_cub);
	if (niv < 1)
	{
		//free map
	}
	return (ret);
}

static void	init(t_data *data, int i)
{
	data->fd = 0;
	while (++i < 2)
		data->txtr[i] = NULL;
	data->txtr[3] = '\0';
	i = -1;
	data->f = 0;
	data->c = 0;
}

int main(int ac, char **av)
{
	t_data	data;

	init(&data, -1);
	if (ac != 2)
		return (ft_error(0, -1));
	data.s_cub = ft_strdup(av[1]);
	printf("s_cub = [%s]\n", data.s_cub);
	if (pars(&data))
		return (ft_free(&data, 1, 0));
	return (ft_free(&data, 0, 1));
}
