#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_S      1
# define KEY_D      2
# define KEY_W      13
# define KEY_ESC    53
# define KEY_A      0

# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *w;
    void    *g;
    void    *c;
    void    *e;
    void    *p;
    char    *map;
    int     x;
    int     y;
    int     width;
    int     height;
    int     img_w;
    int     img_h;
    int		cnt; 
}   t_game;

#endif
