#include "main_header_v2.h"

int		ft_cub(char *cub, int bmp)
{
	t_all *aio;

	if (!(aio = (t_all *)malloc_gc(sizeof(t_all))))
		return(ft_strerror(-8));
	ft_initialization(aio);
	aio->mlx.ptr = mlx_init();
	mlx_get_screen_size(aio->mlx.ptr, &aio->res.display_x, &aio->res.display_y);
	ft_printf("YOUR DISPLAY RES = %dx%d\n",  aio->res.display_x, aio->res.display_y);
	if (ft_parse(aio, cub) == -1)
		return (ft_close(aio, 0));
ft_print_parse(aio);
	if (bmp == 1)
		return (ft_bmp_save(aio));
	aio->win.ptr = mlx_new_window(aio->mlx.ptr, aio->res.map_x, aio->res.map_y, "cub3D");
	ft_draw(aio);
	mlx_hook(aio->win.ptr, 2, 0, ft_press, aio);
	mlx_hook(aio->win.ptr, 3, 0, ft_release, aio);
	//mlx_hook(aio->win.ptr, 6, 0, ft_mouse, &s);
	mlx_hook(aio->win.ptr, 17, 0, ft_close, aio);
	mlx_loop_hook(aio->mlx.ptr, ft_key, aio);
	mlx_loop(aio->mlx.ptr);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 3 && ft_namecheck(av[1], "cub") && ft_savecheck(av[2], "--save"))
		ft_cub(av[1], 1);
	else if (ac == 2 && ft_namecheck(av[1], "cub"))
		ft_cub(av[1], 0);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}
