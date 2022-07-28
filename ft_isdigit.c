/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:48:53 by acoinus           #+#    #+#             */
/*   Updated: 2022/07/26 16:30:14 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_isdigit_cub(char *s)
{
	int i;

	i = -1;
	while (s && s[++i])
	{
		if (s[i] == ',')
			continue;
		if (s[i] <= 48 && s[i] >= 57)
			return (1);
	}
	return (0);
}

