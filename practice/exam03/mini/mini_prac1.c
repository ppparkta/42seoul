#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

char bg;
char color;
char type;
char *draw;
int h;
int w;
float x;
float y;
float r;

void	output()
{
	int	i = -1;
	while (++i < h)
	{
		write(1, draw + i * w, w);
		write(1, "\n", 1);
	}
	free(draw);
}

int check(float nx, float ny)
{
	int distance = sqrtf(powf(nx - x, 2) + powf(ny - y, 2));
	if (distance <= r)
	{
		if (distance <= r - 1)
			return (1);
		return (2);
	}
	return (0);
}

void drawing(void)
{
	int nx;
	int ny;
	int hit;

	nx = -1;
	while (++nx < w)
	{
		ny = -1;
		while(++ny < h)
		{
			hit = check((float)nx, (float)ny);
			if (hit == 2 || (hit == 1 && type == 'C'))
				draw[nx + ny * w] = color;
		}
	}
}

int parser(FILE *file)
{
	int	scanf_res=0;
	int	i = -1;

	//fscanf(3)
	if (fscanf(file, "%d %d %c\n", &w, &h, &bg) != 3)
		return (1);
	//draw보드 범ㅟ
	if (w <= 0 || w > 300 || h <= 0 || h > 300)
		return (1);
	//malloc 예외처리
	if (!(draw=malloc(w*h)))
		return (1);
	//draw배열 init
	while(++i < w * h)
		draw[i] = bg;
	//fscanf(5) 반복문
	while ((scanf_res = fscanf(file, "%c %f %f %f %c\n",&type, &x, &y, &r, &color)) == 5)
	{
		//받아온 인자 예외처리
		if (r <= 0 || (type != 'c' && type != 'C'))
			return (1);
		drawing();
	}
	//fscanf 리턴값 -1 예외처리
	if (scanf_res != -1)
		return (1);
	output();
	return (0);
}

int main(int argc, char **argv)
{
	FILE *file;
	if (argc != 2)
	{
		write(1, "Error: arguments\n", 17);
		return (1);
	}
	if (!(file=fopen(argv[1], "r")) || parser(file))
	{
		write(1, "Error: Open\n", 12);
		return (1);
	}
	fclose(file);
	return (0);
}