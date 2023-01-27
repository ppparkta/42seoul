/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:09:07 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/27 17:13:03 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_objects(t_game *game, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'C')
				game->c_cnt++;
			else if (game->map[i][j] == 'E')
				game->e_cnt++;
			else if (game->map[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
				game->p_cnt++;
			}
			map[i][j] = game->map[i][j];
		}
		map[i][j] = '\0';
	}
	game->collect = game->c_cnt;
}

int	check_dfs(t_game *game, char **map, int x, int y)
{
	if (map[y][x] != '1')
	{
		if (map[y][x] == 'C')
			game->c_cnt--;
		if (map[y][x] == 'E')
			game->e_cnt--;
		map[y][x] = '1';
		if (map[y][x + 1] != '1')
			check_dfs(game, map, x + 1, y);
		if (map[y][x - 1] != '1')
			check_dfs(game, map, x - 1, y);
		if (map[y + 1][x] != '1')
			check_dfs(game, map, x, y + 1);
		if (map[y - 1][x] != '1')
			check_dfs(game, map, x, y - 1);
		if (game->c_cnt == 0 && game->e_cnt == 0)
			return (1);
	}
	return (0);
}

void	free_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}
