/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:16:17 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/27 13:50:07 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->x = 0;
	game->y = 0;
	game->cnt = 0;
	game->c_cnt = 0;
	game->e_cnt = 0;
	game->p_cnt = 0;
	game->collect = 0;
}

void destroy_game(t_game *game)
{
	ft_printf("map error");
	if (game->map)
		free_map(game, game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
		destroy_game(&game);
	open_map(argv[1], &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64,
							  "so_long");
	init_img(&game);
	mlx_hook(game.win, X_EVENT_KEY, 0, key_hook, &game);
	mlx_hook(game.win, X_EVENT_DESTROY, 0, destroy_game, &game);
	mlx_loop(&game);
	return (0);
}
