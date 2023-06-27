#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
	float	h;
	float	w;
	char	c;
}		t_map;

typedef struct s_rectangle
{
	char	m;
	float	x;
	float	y;
	float	w;
	float	h;
	char	c;
}	t_rectangle;

int	ft_floor(float x)
{
	int	num;

	num = (int)x;
	if (x >= num)
		return (num);
	else
		return (num - 1);
}

void	paint_rect(char **map, t_map *m_info, t_rectangle *rect)
{
	int	x = ft_floor(rect->x);
	int y = ft_floor(rect->y);
	float x_b = (rect->x + rect->w);
	float y_b = (rect->y + rect->h);

	for (int i = 0; i < m_info->h; i++)
	{
		for (int j = 0; j < m_info->w; j++)
		{
			if (rect->m == 'r')
			{
				if (i == y && j >= x && j < x_b)
					map[i][j] = rect->c;
				if (j == x && i >= y && i < y_b)
					map[i][j] = rect->c;
				if (i < y_b && i >= y_b - 1 && j >= x && j < x_b)
					map[i][j] = rect->c;
				if (j < x_b && j >= x_b - 1 && i >= y && i < y_b)
					map[i][j] = rect->c;
			}
			else if (rect->m == 'R')
			{
				if (i >= y && i <= y_b && j >= x && j <= x_b)
					map[i][j] = rect->c;
			}
		}
	}
}

void	print_map(char **map, t_map *m_info)
{
	char	c;

	for (int i = 0; i < m_info->h; i++)
	{
		for (int j = 0; j < m_info->w; j++)
		{
			c = map[i][j];
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	t_map		m_info;
	t_rectangle	rect_info;
	FILE		*fp;
	char		**map;
	int			result;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	result = fscanf(fp, "%f %f %c\n", &m_info.h, &m_info.w, &m_info.c);
	if (result != 3 || m_info.h <= 0 || m_info.h > 300 || m_info.w <= 0 || m_info.w > 300)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	map = (char **)malloc(sizeof(char *) * m_info.h);
	for (int i = 0; i < m_info.h; i++)
		map[i] = (char *)malloc(sizeof(char) * (m_info.w + 1));
	for (int i = 0; i < m_info.h; i++)
	{
		for (int j = 0; j <= m_info.w; j++)
		{
			if (j == (int)m_info.w)
				map[i][j] = '\0';
			else
				map[i][j] = m_info.c;
		}
	}
	result = fscanf(fp, "%c %f %f %f %f %c\n", &rect_info.m, &rect_info.x, \
	&rect_info.y, &rect_info.w, &rect_info.h, &rect_info.c);
	if (result != 6)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (rect_info.m != 'r' && rect_info.m != 'R')
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (rect_info.w <= 0 || rect_info.h <= 0)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	paint_rect(map, &m_info, &rect_info);
	while (result == 6)
	{
		result = fscanf(fp, "%c %f %f %f %f %c\n", &rect_info.m, &rect_info.x, \
			&rect_info.y, &rect_info.w, &rect_info.h, &rect_info.c);
		if (result != 6)
			break ;
		if (rect_info.m != 'r' && rect_info.m != 'R')
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);
		}
		if (rect_info.w <= 0 || rect_info.h <= 0)
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return (1);
		}
		paint_rect(map, &m_info, &rect_info);
	}
	if (result != -1)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	print_map(map, &m_info);
	return (0);
}

