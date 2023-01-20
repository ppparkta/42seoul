#include "../mlx/mlx.h"

int main(void)
{
	void	*mlx;
	void	*win;
	
	mlx=mlx_init();
	win=mlx_new_window(mlx, 900,500,"hello world!");
	if(!win){
		return(0);
	}

	mlx_loop(mlx);
}
