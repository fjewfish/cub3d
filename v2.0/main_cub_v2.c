#include "main_header_v2.h"

void	ft_cub(char *cub, int bmp)
{
	t_all *aio;

	if (!(aio = (t_all *)malloc_gc(sizeof(t_all))))
		return(ft_strerror(-8));
	ft_initialization(aio);
	aio->mlx.ptr = mlx_init();
	mlx_get_screen_size(aio->mlx.ptr, &aio->res.display_x, &aio->res.display_y);
	ft_printf("YOUR DISPLAY RES = %dx%d",  aio->res.display_x, aio->res.display_y);
if (ft_parse(aio, cub) == -1)
		return (ft_close(aio, 0));
	if (bmp == 1)
		return (ft_bitmap(&s));
	ft_rotate(&s, 1);
	ft_move(&s, 1);
	ft_rotate(&s, -1);
	ft_move(&s, -1);
	s.win.ptr = mlx_new_window(s.mlx.ptr, s.win.x, s.win.y, "cub3D");
	ft_draw(&s);
	mlx_hook(s.win.ptr, 2, 0, ft_key, &s);
	mlx_hook(s.win.ptr, 17, 0, ft_close, &s);
	mlx_loop(s.mlx.ptr);
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
