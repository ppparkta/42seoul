/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyang <sooyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:12:59 by sooyang           #+#    #+#             */
/*   Updated: 2023/01/27 17:14:04 by sooyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->e, \
				j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->c, \
				j * 64, i * 64);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->w, \
				j * 64, i * 64);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->p, \
				j * 64, i * 64);
		}
	}
}

void	init_img(t_game *game)
{
	int	img_w;
	int	img_h;

	game->m_cnt = 1;
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
	set_map_image(game);
}
