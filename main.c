/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:39:06 by acoinus           #+#    #+#             */
/*   Updated: 2022/07/22 11:45:55 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_free(t_data *data, char *s_cub, int ret, int niv)
{
	if (niv)
	{
		free(s_cub);
		if (niv < 1)
			{} //free map
	}
	return (ret);
}

static void	init(t_data *data, int i)
{
	data->fd = 0;
	while (++i < 5)
		data->txtr[i] = NULL;
	data->txtr[6] = '\0';
}

int main(int ac, char **av)
{
	t_data	data;
	char	*s_cub;

	init(&data, -1);
	if (ac != 2)
		return (ft_error(0, -1));
	s_cub = ft_strdup(av[1]);
	printf("s_cub = [%s]\n", s_cub);
	if (pars(&data, s_cub))
		return (ft_free(&data, s_cub, 1, 0));
	return (ft_free(&data, s_cub, 0, 1));
}
