/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:12:50 by acoinus           #+#    #+#             */
/*   Updated: 2022/07/11 14:13:05 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	len;
	size_t	i;

	len = ft_strlen((char *)s);
	d = (char *)malloc(sizeof(char) * len + 1);
	if (d == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (s[i])
		{
			d[i] = s[i];
			i++;
		}
		d[i] = '\0';
		return (d);
	}
}

