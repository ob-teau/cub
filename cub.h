/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:55:19 by acoinus           #+#    #+#             */
/*   Updated: 2022/07/21 19:11:33 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

#define BUFFER_SIZE 8

typedef struct s_img
{
    void    *mlx_img;
    char    *addr;
    int        bpp; /* bits per pixel */
    int        line_len;//amount of bytes taken by one row of our image. (ATTENTION : 1 pixel = 8 bytes!)
    int        endian;//Endianness means that the bytes in computer memory are read in a certain order.
    int        ceil_color;
    int        floor_color;
}    t_img;

typedef struct s_play
{
    int    px;
    int    py;
//    int    width; // A retirer plus tard
//    int    height; // A retirer plus tard
    int    color;
}    t_play;

typedef struct s_map
{
    int    mapX;
    int    mapY;
    int    mapS;
    int    len_mapXS;
    int    len_mapYS;
    int    map[8];
}    t_map;

typedef struct    s_data
{
//	char	*s_cub;
	int		fd;
    void    *mlx_ptr;
    void    *win_ptr;
    t_img    img;
    t_play    play;
    t_map    map;
	char	*txtr[7];
}    t_data;

int		pars(t_data *data, char *s_cub);
void	putstr_fd(char *s, int fd);
char	*ft_strdup(const char *s);
int		ft_strlen(char *str);
int		ft_error(int err, int fd);
int		ft_free(t_data *data, char *s_cub, int ret, int niv);
int		ft_strn(char *s);
char    *ft_strjoin_gnl(char *s1, char *s2);
int		get_next_line(int fd, char **line);
int	elmt_checker(int i, int j, char *line, t_data *data);
int	map_checker();

#endif
