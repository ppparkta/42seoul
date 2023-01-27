/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:04:37 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/27 18:41:24 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_event(t_game *game, int nx, int ny)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			ft_printf("%c %d %d\n", game->map[i][j], nx, ny);
		}
	}
}

int key_hook(int keycode, t_game *game)
{
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
