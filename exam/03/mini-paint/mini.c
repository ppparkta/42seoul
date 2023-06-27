#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

typedef struct s_data{
	int w;
	int h;
	char c;
}	t_data;

typedef struct s_shape{
	float r;
	float x;
	float y;
	char c;
	char bg;
}	t_shape;

void display_canvas(char *canvas, t_data data)
{
	int x;
	int y;

	y = -1;
	while (++y < data.h)
	{
		x = -1;
		while (++x < data.w)
		{
			write(1, &canvas[y * data.w + x], 1);
		}
		write(1, "\n", 1);
	}
}

int is_shape(t_shape shape, int x, int y)
{
	return (sqrtf(powf(shape.x - x, 2) + powf(shape.y - y, 2)) <= shape.r);
}

int is_border(t_shape shape, int x, int y)
{
	return (sqrtf(powf(shape.x - x, 2) + powf(shape.y - y, 2)) > shape.r - 1);
}

void draw(char *canvas, t_data data, t_shape shape)
{
	int x;
	int y;

	y = -1;
	while (++y < data.h)
	{
		x = -1;
		while (++x < data.w)
		{
			if (shape.c == 'C' && is_shape(shape, x, y))
				canvas[y * data.w + x] = shape.bg;
			if (shape.c == 'c' && is_shape(shape, x, y) && is_border(shape, x, y))
				canvas[y * data.w + x] = shape.bg;
		}
	}
}

int mini_paint(FILE *file)
{
	t_data	data;
	t_shape	shape;
	char	*canvas;

	if (fscanf(file, "%d %d %c\n", &data.w, &data.h, &data.c) != 3)
		return 1;
	if (data.w <= 0 || data.h <= 0 || data.w > 300 || data.h > 300)
		return 1;
	canvas = malloc(sizeof(char) * data.w * data.h);
	if (!canvas)
		return 1;
	memset(canvas, data.c, data.w * data.h);
	while (fscanf(file, "%c %f %f %f %c\n", &shape.c, &shape.x, &shape.y, &shape.r, &shape.bg) == 5)
	{
		if (shape.r <= 0 || (shape.c !='c' && shape.c !='C'))
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

	if (ac == 2){
		if (!(file = fopen(av[1], "r")) || mini_paint(file) == 1)
		{
			write(1, "error: file error\n", 32);
			return 1;
		}
	}
	else
	{
		write(1, "error: argument\n", 16);
		return 1;
	}
	return 0;
}