#include "main_header_v2.h"

void		ft_initialization(t_all *aio)
{
	aio->mlx.ptr = NULL;
	aio->win.ptr = NULL;
	aio->img.adr = NULL;
	aio->img.ptr = NULL;
	aio->map.height = 0;
	aio->map.map = NULL;
	aio->map.width = 0;
	aio->map.x = 0;
	aio->map.y = 0;
	aio->tex.east = NULL;
	aio->tex.north = NULL;
	aio->tex.south = NULL;
	aio->tex.sprite = NULL;
	aio->tex.west = NULL;
	aio->res.map_x = 0;
	aio->res.map_y = 0;
	aio->map.err_map = 0;
	aio->map.err_map = 0;
	aio->res.display_x = 0;
	aio->res.display_y = 0;
	aio->plr.dir_x = 0;
	aio->plr.dir_y = 0;
	aio->plr.pos_x = 0;
	aio->plr.pos_y = 0;
}
