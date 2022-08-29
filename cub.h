/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:55:19 by acoinus           #+#    #+#             */
/*   Updated: 2022/08/27 13:53:40 by acoinus          ###   ########.fr       */
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

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"
# define COMP "10CEP"
# define SUCCESS 1
# define FAIL 0
# define BUFFER_SIZE 1024

typedef struct	s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp; /* bits per pixel */
	int			line_len;//amount of bytes taken by one row of our image. (ATTENTION : 1 pixel = 8 bytes!)
	int			endian;//Endianness means that the bytes in computer memory are read in a certain order.
	int			ceil_color;
	int			floor_color;
}	t_img;

typedef struct	s_play
{
    int			px;
    int			py;
    int			color;
}	t_play;

typedef struct	s_map
{
    int			mini_x;
    int			mini_y;
    int			mini_xy;
    int			mini_len_x;
    int			mini_len_y;
	int			*s_map;
}	t_map;

typedef struct	s_data
{
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_play		play;
	t_map		map;
	void		*txtr[4]; //NO|SO|EA|WE|F|Ci
	int			f;
	int			c;
	char		*s_cub;
}	t_data;

int				pars(t_data *data);
void			putstr_fd(char *s, int fd);
char			*ft_strdup(const char *s);
char			*ft_strdup_n(const char *s, int n);
int				*ft_strjoin_map(t_data *data, char *s2, int i, int j);
int				ft_strlen(char *str);
int				ft_strlen_i(int *str);
int				ft_error(int err, int fd);
int				ft_free(t_data *data, int ret, int niv);
int				ft_strn(char *s);
char			*ft_strjoin_gnl(char *s1, char *s2);
int				get_next_line(int fd, char **line);
int				elmt_checker(int i, char *line, t_data *data, int x);
int				ft_isdigit_cub(char *s);
int				ft_atoi(const char *str);
unsigned long	ft_putnbr_base(int nbr, char *base);
int				map_checker(char *s, int i, t_data *data, int x);
int				p_checker(t_data *data, int i);

#endif
