/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:27:02 by acoinus           #+#    #+#             */
/*   Updated: 2022/07/22 12:37:45 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_error(int err, int fd)
{
	if (err == 0)
		putstr_fd("Error\n./Wrong argument number\n", 2);
	else if (err == 1)
		putstr_fd("Error\n./Wrong file path or extension [file.cub]\n", 2);
	else if (err == 2)
		putstr_fd("Error\n./File required instead of a directory\n", 2);
	else if (err == 3)
		putstr_fd("Error\n./Error while opening the file\n", 2);
	else if (err == 4)
		putstr_fd("Error\n./Error with map elements part in file\n", 2);
	if (err > 1)
		close(fd);
	return (1);
}
