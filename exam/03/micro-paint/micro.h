#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_data{
	int w;
	int h;
	char c;
}	t_data;

typedef struct s_shape{
	char c;
	char bg;
	float w;
	float h;
	float x;
	float y;
}	t_shape;
