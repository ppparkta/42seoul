#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data
{
	int w;
	int h;
	char c;
}	t_data;

typedef struct s_shape
{
	char	c;
	char	bg;
	float	x;
	float	y;
	float	w;
	float	h;
}	t_shape;

int main(int ac, char **av)
{
	FILE	*file;
	t_data	data;
	t_shape	shape;
	int		x;
	int		y;
	int		exits;

	if (ac != 2)
	{
		write(1, "\n", 16);
		return (1);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		write(1, "\n", 32);
		return (1);
	}
	
}