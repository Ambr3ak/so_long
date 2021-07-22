/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdar <abourdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:37:36 by abourdar          #+#    #+#             */
/*   Updated: 2021/07/19 10:37:39 by abourdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define BUFFER_SIZE 10
# define FALSE 0
# define TRUE 1
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0x4da95a
# define WHITE_PIXEL 0xF8F8FF
# define DARK_PIXEL 0x000000
# define GREY_PIXEL 0x808080
# define BLUE_PIXEL 0x0000FF
# define PI 3.14159265
# define TWO_PI 6.28318530

typedef struct s_recup
{
	int	x;
	int	y;
}				t_recup;

typedef struct s_line
{
	float	start_x;
	float	start_y;
	int		lenght_x;
	int		lenght_y;
	int		color;
	int		deltax;
	int		deltay;
}				t_line;

typedef struct s_img
{
	void	*mlx_img;
	void	*im1;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		*data;
	int		x;
	int		y;
}				t_img;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;

}				t_rect;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_play
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turnDirection;
	int		walkDirection;
	float	rotationAngle;
	float	walkSpeed;
	float	turnSpeed;
}				t_play;

typedef struct s_col
{
	int	x;
	int	y;
	int	eaten;
}				t_col;

typedef struct s_map
{
	t_list		*ptrs;
	t_img		img;
	t_play		*play;
	t_col		*sprite;
	t_img		*txtrs;

	int			nb_line;
	int			error;
	char		**pars;
	int			num_row;
	int			moves;
	float		pos_x;
	float		pos_y;
	int			player;
	int			collectible;
	int			collectible_eat;
	int			tile_size;
	int			num_col;
	int			check;
	int			tyleX;
	int			tyleY;
	int			u;
	int			counter;
	float		E_x;
	float		E_y;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_w;
	int			win_h;

}				t_map;

void	*lst_add(t_map *map, void *ptr);
void	*malloc_list(t_map *map, int size);
void	*free_malloc_lst(t_map *map);

void	init_parser(t_map *map, char *s, int fd);
void	init_struc(t_map *map);
int		get_nb_line(t_map *map, char *file);

int		mapHasWallAt(float x, float y, t_map *map);
void	put_moves_shell(int moves);

void	choose_text(t_map *map, t_recup *r, int tyleX, int tyleY);
int		get_next_line(t_map *map, int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(t_map *map, const char *s1);
char	*ft_strjoin(t_map *map, char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(t_map *map, char *s, unsigned int start, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup_long(t_map *map, const char *s1, int size);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

void	draw_player(t_map *map, t_img txtrs);
void	draw_anim(t_map *map, t_col sprite, t_img txtrs, int x);
void	draw_walls(t_map *map, int tylex, int tyley, t_img txtrs);
void	draw_exit(t_map *map, int tylex, int tyley, t_img txtrs);
int		draw_game(t_map *map);

int		ft_exit(t_map *map);
int		handle_keypress(int keysym, t_map *map);
void	hooks(t_map *map);

void	img_pix_put(t_img *img, int x, int y, int color);
int		pixel_get_color(t_img *txtrs, int x, int y);
int		get_sprite_color(t_img *txtrs, int x, int y, int cubesize);

int		initialize_win(t_map *map);
void	setup(t_map *map);
void	init_collectible(t_map *map);

int		pars_line(t_map *map, char *str);
void	get_player_pos(t_map *map);
void	get_map_size(t_map *map);
int		check_map(t_map *map);

int		draw_rect(t_img *img, t_rect rect);
void	draw_tiles(int x, int y, t_map *map, int color);

void	renderCollectible(t_map *map);
void	renderMap(t_map *map);
int		render(t_map *map);

void	load_textures(t_map *map);
void	fill_txt(t_map *map, t_img *txts, char *path);
void	draw_transparency(t_map *map, int x, int y, int color);

int		exit_at(float x, float y, t_map *map);
int		ft_error(t_map *map, int err_arg);

#endif
