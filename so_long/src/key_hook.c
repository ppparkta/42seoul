/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:04:37 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/27 19:45:57 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_event(t_game *game, int nx, int ny)
{
	int	i;
	int	j;
	if (!(game||nx||ny))
		return ;
	i = 0;
	j = 0;
	ft_printf("%d %d %c", i ,j, game->map[i][j]);
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			ft_printf("%s %d %d\n", game->map[i], nx, ny);
		}
	}
}

int key_hook(int keycode, t_game *game)
{
	// for (int i=0;i<game->height;i++)
	// {
	// 	for(int j=0;j<game->width;j++)
	// 		ft_printf("%c ", game->map[i][j]);
	// 	ft_printf("\n");
	// }
	if (keycode == KEY_ESC)
		destroy_game(game, "exit game");
	else if (keycode == KEY_W)
		move_event(game, 0, 1);
	else if (keycode == KEY_A)
		move_event(game, -1, 0);
	else if (keycode == KEY_S)
		move_event(game, 0, -1);
	else if (keycode == KEY_D)
		move_event(game, 1, 0);
	return (0);
}
