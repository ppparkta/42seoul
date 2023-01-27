/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:07:20 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/27 17:17:23 by sooyang          ###   ########.fr       */
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

int	check_line(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i] != 0)
	{
		j = 0;
		while (game->map[i][j] != 0)
			j++;
		if (j != game->width)
			return (0);
	}
	return (1);
}

void	check_game(t_game *game)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * game->height);
	if (!map)
		destroy_game(game, "error: null");
	i = -1;
	while (++i < game->height)
	{
		map[i] = malloc(sizeof(char) * game->width + 1);
		if (!map[i])
			destroy_game(game, "error: null");
	}
	check_objects(game, map);
	if (game->p_cnt != 1 || game->e_cnt != 1 || game->c_cnt < 1)
		destroy_game(game, "error: wrong map format");
	i = check_dfs(game, map, game->x, game->y);
	free_map(game, map);
	if (!i)
		destroy_game(game, "error: wrong map format");
}

void	read_map(char *file, t_game *game)
{
	int		fd;
	int		i;
	char	*gnl;

	i = -1;
	fd = open(file, O_RDONLY);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		destroy_game(game, "error: null");
	while (++i < game->height)
	{
		gnl = get_next_line(fd);
		game->map[i] = gnl;
		if (!(read_line(game, gnl, i) || check_line(game)))
			destroy_game(game, "error: wrong map format");
	}
	game->map[i] = 0;
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
		destroy_game(game, "error: do not read file");
	gnl = get_next_line(fd);
	if (!gnl)
		destroy_game(game, "error: null");
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
