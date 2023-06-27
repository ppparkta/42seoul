#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_data{
	int w;
	int h;
	char bg;
}	t_data;

typedef struct s_shape{
	char c;
	char bg;
	float x;
	float y;
	float w;
	float h;
}	t_shape;

void display_canvas(char *canvas, t_data data){
	int x=-1;
	int y=-1;

	while (++y < data.h){
		x = -1;
		while (++x < data.w){
			write(1, &canvas[y * data.w + x], 1);
		}
		write(1, "\n", 1);
	}
}

int in_shape(t_shape shape, int x, int y)
{
	return (shape.x <= x && x <= shape.x + shape.w
	&& shape.y <= y && y <= shape.y + shape.h);
}

int in_border(t_shape shape, int x, int y)
{
	return (x < shape.x + 1 || x > shape.x + shape.w - 1
	|| y < shape.y + 1 || y > shape.y + shape.h - 1);
}

void	draw(char *canvas, t_data data, t_shape shape){
	int	x;
	int	y;

	y = -1;
	while (++y < data.h){
		x = -1;
		while (++x < data.w){
			if (shape.c == 'R' && in_shape(shape, x, y))
				canvas[y * data.w + x] = shape.bg;
			else if (shape.c == 'r' && in_shape(shape, x, y) && in_border(shape, x, y))
				canvas[y * data.w + x] = shape.bg;
		}
	}
}

int	micro_paint(FILE *file){
	t_data	data;
	t_shape	shape;
	char	*canvas;

//printf("살아남음?\n");
	if (fscanf(file, "%d %d %c\n", &data.w, &data.h, &data.bg) != 3)
		return 1;
	//printf("살아남음\n");
	if (data.h <= 0 || data.w <= 0 || data.h > 300 || data.w > 300)
		return 1;
	//printf("살아남음2\n");
	canvas = malloc(sizeof(char) * data.w * data.h);
	if (!canvas)
		return 1;
	//printf("살아남음3\n");
	memset(canvas, data.bg, data.h * data.w);
	while ((fscanf(file, "%c %f %f %f %f %c\n", &shape.c, &shape.x, &shape.y, &shape.w, &shape.h, &shape.bg) == 6)){
		if (shape.w <= 0 || shape.h <= 0 || (shape.c != 'r' && shape.c != 'R'))
		{
			free(canvas);
			return 1;
		}
		//printf("살아남음~~\n");
		draw(canvas, data, shape);
	}
	display_canvas(canvas, data);
	free(canvas);
	return 0;
}

int main(int argc, char **argv){
	FILE *file;

	if (argc == 2)
	{
		if (!(file = fopen(argv[1], "r")) || micro_paint(file) == 1)
			write(1, "Error: Operation file corrupted\n", 32);
			return 1;
	}
	else{
		write(1, "Error: argument\n", 16);
		return 1;
	}
	return 0;
}