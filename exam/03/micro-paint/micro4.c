#include "micro.h"

void display_canvas(char *canvas, t_data data)
{
	int x=-1;
	int y=-1;
	while (++y < data.h)
	{
		x=-1;
		while (++x < data.w)
		{
			write(1, &canvas[y * data.w + x], 1);
		}
		write(1, "\n", 1);
	}
}

int is_shape(t_shape shape, int x, int y)
{
	return (shape.x <= x && x <= shape.x + shape.w
			&&shape.y <= y && y <= shape.y + shape.h);
}

int is_border(t_shape shape, int x, int y)
{
	return (x < shape.x + 1 || x > shape.x + shape.w - 1
			|| y < shape.y + 1 || y > shape.y + shape.h - 1);
}

void draw(char *canvas, t_data data, t_shape shape)
{
	int x=-1;
	int y=-1;
	while (++y < data.h)
	{
		x=-1;
		while (++x < data.w)
		{
			if (shape.c == 'R' && is_shape(shape, x, y))
				canvas[y * data.w + x] = shape.bg;
			if (shape.c == 'r' && is_shape(shape, x, y) && is_border(shape, x, y))
				canvas[y * data.w + x] = shape.bg;
		}
	}
}

int micro_paint(FILE *file)
{
	t_data data;
	t_shape shape;
	char *canvas;

	if (fscanf(file, "%d %d %c\n", &data.w, &data.h, &data.c) != 3)
		return 1;
	if (data.w <= 0 || data.h <= 0 || data.w > 300 || data.h > 300)
		return 1;
	canvas = malloc(sizeof(char) * data.w * data.h);
	if (!canvas)
		return 1;
	memset(canvas, data.c, data.w * data.h);
	while (fscanf(file, "%c %f %f %f %f %c\n", &shape.c, &shape.x, &shape.y, &shape.w, &shape.h, &shape.bg) == 6)
	{
		if (shape.w <= 0 || shape.h <= 0 || (shape.c != 'r' && shape.c != 'R'))
		{
			free(canvas);
			return 1;
		}
		draw(canvas, data, shape);
	}
	display_canvas(canvas, data);
	free(canvas);
	return 0;
}

int main(int ac, char **av)
{
	FILE *file;

	if (ac == 2)
	{
		if (!(file = fopen(av[1], "r")) || micro_paint(file) == 1)
		{
			write(1, "Error: Operation file corrupted\n", 32);
			return 1;
		}
	}
	else
	{
		write(1, "Error: argument\n", 16);
		return 1;
	}
	return 0;
}
