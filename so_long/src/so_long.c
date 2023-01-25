/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:16:17 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/25 21:26:10 by sooyang          ###   ########.fr       */
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
	game->collect = 0;
}

void	destroy_game(t_game *game)
{
	ft_printf("map error");
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

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
	ft_printf("탈출조건 불만족");
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
	// ft_printf("폭 : %d\n", game->width);
	// ft_printf("높이 : %d\n", game->height);
	close(fd);
	read_map(file, game);
}

void	set_map_image(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->g, \
			j * 64, i * 64);
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->p, \
				j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->e, \
				j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->c, \
				j * 64, i * 64);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->w, \
				j * 64, i * 64);
		}
	}
}

void	init_img(t_game *game)
{
	int	img_w;
	int	img_h;

	game->w = mlx_xpm_file_to_image(game->mlx, "./images/w.xpm", \
	&img_w, &img_h);
	game->g = mlx_xpm_file_to_image(game->mlx, "./images/g.xpm", \
	&img_w, &img_h);
	game->e = mlx_xpm_file_to_image(game->mlx, "./images/e.xpm", \
	&img_w, &img_h);
	game->c = mlx_xpm_file_to_image(game->mlx, "./images/c.xpm", \
	&img_w, &img_h);
	game->p = mlx_xpm_file_to_image(game->mlx, "./images/p.xpm", \
	&img_w, &img_h);
	ft_printf("완료\n");
	set_map_image(game);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		destroy_game(&game);
	open_map(argv[1], &game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, \
	"so_long");
	init_img(&game);
	mlx_loop(&game);
	return (0);
}
