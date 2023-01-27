/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:16:29 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/26 16:17:05 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_S      		1
# define KEY_D      		2
# define KEY_W      		13
# define KEY_ESC    		53
# define KEY_A      		0
# define X_EVENT_KEY		2
# define X_EVENT_DESTROY	17

# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*w;
	void	*g;
	void	*c;
	void	*e;
	void	*p;
	char	**map;
	int		x;
	int		y;
	int		width;
	int		height;
	int		cnt;
	int		c_cnt;
	int		p_cnt;
	int		e_cnt;
	int		collect;
}	t_game;

void	open_map(char *file, t_game *game)
void	read_map(char *file, t_game *game);
int		read_line(t_game *game, char *gnl, int i);
void	check_game(t_game *game);
void	check_objects(t_game *game, char **map);
int		check_dfs(t_game *game, char **map, int x, int y);
void	free_map(t_game *game, char **map);
void	init_img(t_game *game);
void	set_map_image(t_game *game);
void	key_hook_move_event(t_game *game, int x, int y);
int 	key_hook(int keycode, t_game *game);


#endif
