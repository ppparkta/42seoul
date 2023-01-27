/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:07:20 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/27 13:21:48 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_line(t_game *game, char *gnl, int i)
{
	int	j;

	j = 0;
	while (j < game->width)
	{
		if (!(gnl[j] == '1' || gnl[j] == '0' || gnl[j] == 'P' || \
		gnl[j] == 'C' || gnl[j] == 'E' || gnl[j] == '\n'))
			return (0);
		if (i == 0 || i == game->height - 1)
		{
			if (gnl[j] != '1')
				return (0);
		}
		else
		{
			if (j == 0 || j == game->width - 1)
				if (gnl[j] != '1')
					return (0);
		}
		j++;
	}
	if (j != game->width)
		return (0);
	return (1);
}

void	check_game(t_game *game)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * game->height);
	if (!map)
		destroy_game(game);
	i = 0;
	while (i < game->height)
	{
		map[i] = malloc(sizeof(char) * game->width + 1);
		if (!map[i])
			destroy_game(game);
		i++;
	}
	check_objects(game, map);
	if (game->p_cnt != 1 || game->e_cnt != 1 || game->c_cnt < 1)
		destroy_game(game);
	i = check_dfs(game, map, game->x, game->y);
	free_map(game, map);
	if (!i)
		destroy_game(game);
}

void	read_map(char *file, t_game *game)
{
	int		fd;
	int		i;
	char	*gnl;

	i = 0;
	fd = open(file, O_RDONLY);
	game->map = malloc(sizeof(char *) * game->height);
	if (!game->map)
		destroy_game(game);
	while (i < game->height)
	{
		gnl = get_next_line(fd);
		game->map[i] = gnl;
		if (!read_line(game, gnl, i))
		{
			game->height = i;
			destroy_game(game);
		}
		i++;
	}
	close(fd);
	check_game(game);
}

void	open_map(char *file, t_game *game)
{
	int		fd;
	char	*gnl;

	init(game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		destroy_game(game);
	gnl = get_next_line(fd);
	if (!gnl)
		destroy_game(game);
	while (gnl[game->width + 1])
		game->width++;
	free(gnl);
	gnl = " ";
	while (gnl)
	{
		gnl = get_next_line(fd);
		free(gnl);
		game->height++;
	}
	close(fd);
	read_map(file, game);
}