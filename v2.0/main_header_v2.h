#ifndef MAIN_HEADER_V2_H
# define MAIN_HEADER_V2_H

#include "libft/libft.h"
#include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPEED 15
# define TURN 0.05

//MAlLOC_GC
# define M_ADD 1
# define M_REMOVE 0
typedef char		t_bool;

typedef struct	s_mlx
{
	void			*ptr;
	// int				pid;
}				t_mlx;

typedef struct	s_win
{
	void			*ptr;
	// int				x;
	// int				y;
	// int				m;
}				t_win;

typedef struct	s_img
{
	void			*ptr;
	unsigned int	*adr;
	// int				fsh;
}				t_img;

typedef struct	s_tex
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
}				t_tex;

typedef struct	s_res
{
	int			map_x;
	int			map_y;
	int			display_x;
	int			display_y;
}				t_res;

typedef struct	s_map
{
	int			**map;
	int			width;
	int			height;
	int			x;
	int			y;
	int			err_map;
	int			err_parse;
}				t_map;

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
}				t_player;

typedef struct	s_all
{
	t_mlx			mlx;
	t_win			win;
	t_img			img;
	t_tex			tex;
	t_res			res;
	t_map			map;
	t_player		plr;
}				t_all;

//	MALLOC_GC
static void	delete(t_list *lst, void (*del)(void *));
void		ft_lstdelel(t_list **lst, void *content, int (*cmp)(void *, void *),
						void (*del)(void *));
void	*malloc_gc(size_t sizemem);
void	*calloc_gc(size_t nmemb, size_t size);
void	free_gc(void *ptr);
static int		pointer_compare(void *ptr1, void *ptr2);
static void		pointer_free(void *ptr);
void			memory_manager(void *ptr, t_bool action);
char	*ft_strdup_gc(const char *s1);
//	CHEKER
int		ft_savecheck(char *arg, char *save);
int		ft_namecheck(char *arg, char *ext);
//	MAIN_CUB
void	ft_cub(char *cub, int bmp);
//	INITIALIZATION
void		ft_initialization(t_all *aio);
//	PARSE
int		ft_parse(t_all *aio, char *cub);
//	ERROR
int		ft_strerror(int err);
//	USEFUL_FUN
int		ft_spaceskip(char *line, int *i);
#endif
