/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:04:37 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/27 13:50:34 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void key_hook_move_event(t_game *game, int x, int y)
{
    if (game->map[game->y + y][game->x + x] == '1')
        return;
    if (game->map[game->y + y][game->x + x] == 'E' && game->c_cnt < game->collect)
        return;
    if (game->map[game->y + y][game->x + x] == 'C')
        game->c_cnt++;
    game->cnt++;
    game->map[game->y][game->x] = '0';
    game->map[game->y + y][game->x + x] = 'P';
    game->x = game->x + x;
    game->y = game->y + y;
    set_map_image(game);
    if (game->map[game->y][game->x] == 'E' && game->c_cnt == game->collect)
        destroy_game(game);
}

int key_hook(int keycode, t_game *game)
{
    if (keycode == 'ESC')
        destroy_game(game);
    else if (keycode == 'KEY_W')
        key_hook_move_evnet(game, 0, 1);
    else if (keycode == 'KEY_A')
        key_hook_move_evnet(game, -1, 0);
    else if (keycode == 'KEY_S')
        key_hook_move_evnet(game, 0, -1);
    else if (keycode == 'KEY_D')
        key_hook_move_evnet(game, 1, 0);
    return (0);
}