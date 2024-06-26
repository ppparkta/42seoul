/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:16:17 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/30 17:51:34 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->x = 0;
	game->y = 0;
	game->cnt = 0;
	game->c_cnt = 0;
	game->e_cnt = 0;
	game->p_cnt = 0;
	game->m_cnt = 0;
	game->collect = 0;
	game->map = 0;
}

int	destroy_game(t_game *game, char *msg)
{
	if (ft_strlen(msg) == 5)
		ft_printf("movement count: %d\nclear!\n", game->cnt);
	else
		ft_printf("%s\n", msg);
	if (game->m_cnt)
		mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

void	check_arg(int argc, char *argv[], t_game *game)
{
	if (argc != 2)
	{
		ft_printf("error: too many or no args");
		exit(0);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 1) != 0)
	{
		ft_printf("error: map extension must be '.ber'");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;

	check_arg(argc, argv, &game);
	open_map(argv[1], &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, \
	"so_long");
	init_img(&game);
	mlx_hook(game.win, X_EVENT_KEY, 0, key_hook, &game);
	mlx_hook(game.win, X_EVENT_DESTROY, 0, destroy_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
