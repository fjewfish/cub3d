#include "main_header_v2.h"

int		ft_close(t_all *aio, int win)
{
	//int	i;

	//i = 0;
	//while (i < s->map.height)
	//	free(s->map.map[i++]);
	//free(s->map.map);
	//free(s->tex.n);
	//free(s->tex.s);
	//free(s->tex.e);
	//free(s->tex.w);
	//free(s->tex.i);
	//memory_manager(NULL, M_ADD);
	if (win == 1)
		mlx_destroy_window(aio->mlx.ptr, aio->win.ptr);
	free(aio->mlx.ptr);
	exit(0);
	return (1);
}

int		ft_strerror(int err)
{
	(err == -1) ? write(2, "Error : Couldn't open file (FD)\n", 32) : 0;
	(err == -2) ? write(2, "Error : Couldn't parse file (GNL)\n", 34) : 0;
	(err == -3) ? write(2, "Error : Resolution specified twice\n", 35) : 0;
	(err == -4) ? write(2, "Error : Invalid resolution\n", 27) : 0;
	(err == -5) ? write(2, "Error : Floor/ceiling specified twice\n", 38) : 0;
	(err == -6) ? write(2, "Error : Invalid floor/ceiling line\n", 35) : 0;
	(err == -7) ? write(2, "Error : Texture path specified twice\n", 37) : 0;
	(err == -8) ? write(2, "Error : Malloc fail (texture path)\n", 35) : 0;
	(err == -9) ? write(2, "Error : Invalid texture image\n", 30) : 0;
	(err == -10) ? write(2, "Error : Invalid line in file\n", 29) : 0;
	(err == -11) ? write(2, "Error : Malloc fail (map table)\n", 32) : 0;
	(err == -12) ? write(2, "Error : Invalid map\n", 20) : 0;
	(err == -13) ? write(2, "Error : Map isn't a rectangle\n", 30) : 0;
	(err == -14) ? write(2, "Error : No resolution specified\n", 32) : 0;
	(err == -15) ? write(2, "Error : Missing texture\n", 24) : 0;
	(err == -16) ? write(2, "Error : Missing floor/ceiling color\n", 26) : 0;
	(err == -17) ? write(2, "Error : No starting position\n", 29) : 0;
	(err == -18) ? write(2, "Error : Multiple starting positions\n", 36) : 0;
	(err == -19) ? write(2, "Error : Map isn't surrounded by walls\n", 38) : 0;
	return (-1);
}
