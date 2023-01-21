#include "so_long.h"

static void	init(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->img_w = 0;
	game->img_h = 0;
	game->x = 0;
	game->y = 0;
	game->cnt = 0;
	game->w = mlx_xpm_file_to_image(game->mlx, "../images/w.xpm", &game->img_w, &game->img_h);
	game->g = mlx_xpm_file_to_image(game->mlx, "../images/g.xpm", &game->img_w, &game->img_h);
	game->e = mlx_xpm_file_to_image(game->mlx, "../images/e.xpm", &game->img_w, &game->img_h);
	game->c = mlx_xpm_file_to_image(game->mlx, "../images/c.xpm", &game->img_w, &game->img_h);
	game->p = mlx_xpm_file_to_image(game->mlx, "../images/p.xpm", &game->img_w, &game->img_h);
}

void destroy_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void open_map(char *filename, t_game *game)
{
	int		fd;
	char	*gnl;

	init(game);
	fd = open(filename, O_RDONLY);
	gnl = get_next_line(fd);
	if (fd < 0 || !gnl)
		destroy_game(game);
	while (gnl[game->width + 1])
		game->width++;
	free(gnl);
	while (gnl)
	{
		gnl = get_next_line(fd);
		free(gnl);
		game->height++;
	}
	close(fd);
	
}

int main(int argc, char **argv)
{
	t_game	game;
	
	if (argc != 2)
	{
		ft_printf("map error\n");
		destroy_game(&game);
	}
	open_map(argv[1], &game);
	init(&game);
	game.win = mlx_new_window(game.mlx, game.width * 64, game.height * 64, "so_long");
	mlx_loop(game.mlx);
	return (0);
}
