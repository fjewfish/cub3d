#include "main_header_v2.h"

int		ft_draw(t_all *aio)
{
	if (aio->img.ptr == NULL)
		aio->img.ptr = (void *)malloc_gc(sizeof(1));
	free(aio->img.ptr);
	if (aio->img.adr == NULL)
		aio->img.adr = (unsigned int *)malloc_gc(sizeof(1));
	free(aio->img.adr);
	ft_screen(aio);
	mlx_put_image_to_window(aio->mlx.ptr, aio->win.ptr, aio->img.ptr, 0, 0);
	return (0);
}

void	ft_screen(t_all *aio)
{
	aio->img.ptr = mlx_new_image(aio->mlx.ptr, aio->res.map_x, aio->res.map_y);
	aio->img.adr = (unsigned int *)mlx_get_data_addr(aio->img.ptr, &aio->img.bpp, &aio->img.sl, &aio->img.end);
	//ft_sky(s);
	//aio->ray.i = 0;
	//while (aio->ray.i < aio->res.map_y / 2)
	//	ft_floor(s);
	aio->stk = malloc_gc(sizeof(t_stk) * aio->res.map_x);
	aio->ray.i = 0;
	while (aio->ray.i < aio->res.map_x)
	{
		ft_ray(aio);
		ft_dir(aio);
		ft_ver(aio);
		ft_hor(aio);
		ft_stock(aio);
		ft_column(aio, ft_size(aio));
		aio->ray.i++;
	}
	//ft_sprite(s);
	//ft_hud(s);
}

void	ft_ray(t_all *aio)
{
	double	angle;
	double	dist;

	angle = ((double)aio->ray.i - (aio->res.map_x / 2)) * ANG / (aio->res.map_x / 2);
	aio->ray.x = aio->plr.dir_x * cos(angle) - aio->plr.dir_y * sin(angle);
	aio->ray.y = aio->plr.dir_y * cos(angle) + aio->plr.dir_x * sin(angle);
	dist = hypot(aio->ray.x, aio->ray.y);
	aio->ray.x /= dist;
	aio->ray.y /= dist;
}

void	ft_dir(t_all *aio)
{
	if (aio->ray.x >= 0)
		aio->ray.v = 1;
	else
		aio->ray.v = 0;
	if (aio->ray.y >= 0)
		aio->ray.w = 1;
	else
		aio->ray.w = 0;
}

void	ft_ver(t_all *aio)
{
	double	x;
	double	y;
	char	c;

	x = floor(aio->plr.pos_x) + aio->ray.v;
	y = aio->plr.pos_y + (x - aio->plr.pos_x) * (aio->ray.y / aio->ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < aio->res.map_y)
	{
		c = aio->map.map[(int)floor(y)][(int)floor(x - 1 + aio->ray.v)];
		//if (ft_is(WALL, c) || ft_is(DOOR, c))
		if (ft_is(WALL , c))
		{
			aio->hit.x = x;
			aio->hit.y = y;
			aio->hit.d = hypot(x - aio->plr.pos_x, y - aio->plr.pos_y);
			aio->hit.c = c;
			//ft_is(DOOR, c) ? ft_verdoor(s, x, y) : 0;
			return ;
		}
		x += (2 * aio->ray.v - 1);
		y += (2 * aio->ray.v - 1) * aio->ray.y / aio->ray.x;
	}
	aio->hit.x = aio->plr.pos_x;
	aio->hit.y = aio->plr.pos_y;
	aio->hit.d = 1000000000;
	aio->hit.c = 0;
}

int		ft_is(int n, char c)
{
	if (n == WALL && (c == '1' || c == '2' || c == '3' || c == '4'))
		return (1);
	else if (n == WALL && (c == '4' || c == '5' || c == '6'))
		return (1);
	else if ((n == SPRITE || n == PICK) && (c == '7' || c == '8' || c == '-'))
		return (1);
	else if ((n == SPRITE || n == DECOR) && (c == '9' || c == '+' || c == '#'))
		return (1);
	else if ((n == SPRITE || n == DECOR) && (c == '&' || c == '$' || c == '*'))
		return (1);
	else if (n == ENEMY && (c == '+' || c == '#' || c == '&'))
		return (1);
	else if (n == ENEMY && (c == '$' || c == '*'))
		return (1);
	else if (n == POS && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		return (1);
	else if (n == 0 && (c == '0' || c == 'O' || c == 'X'))
		return (1);
	else if (n == DOOR && c == 'D')
		return (1);
	else
		return (0);
}

void	ft_hor(t_all *aio)
{
	double	y;
	double	x;
	char	c;

	y = floor(aio->plr.pos_y) + aio->ray.w;
	x = aio->plr.pos_x + (y - aio->plr.pos_y) * (aio->ray.x / aio->ray.y);
	while ((int)floor(x) > 0 && (int)floor(x) < aio->res.map_x)
	{
		c = aio->map.map[(int)floor(y - 1 + aio->ray.w)][(int)floor(x)];
		//if (ft_is(WALL, c) || ft_is(DOOR, c))
		if (ft_is(WALL, c))
		{
			if (aio->hit.d > hypot(x - aio->plr.pos_x , y - aio->plr.pos_y) && ft_is(WALL, c))
			{
				aio->hit.x = x;
				aio->hit.y = y;
				aio->hit.d = hypot(x - aio->plr.pos_x, y - aio->plr.pos_y);
				aio->hit.c = c;
			}
			//else if (s->hit.d > hypot(x - s->pos.x, y - s->pos.y))
			//	ft_hordoor(s, x, y);
			return ;
		}
		y += (2 * aio->ray.w - 1);
		x += (2 * aio->ray.w - 1) * aio->ray.x / aio->ray.y;
	}
}

void			ft_stock(t_all *aio)
{
	aio->stk[aio->ray.i].x = aio->ray.x;
	aio->stk[aio->ray.i].y = aio->ray.y;
	aio->stk[aio->ray.i].d = aio->hit.d;
}

int				ft_size(t_all *aio)
{
	double	correc;
	double	fisheye;

	fisheye = fabs((double)aio->ray.i / (aio->res.map_x / 2) - 1);
	fisheye *= 28 * M_PI / 180;
	correc = (double)aio->hit.d * cos(fisheye);
	return (round(aio->res.map_y / correc));
}

unsigned int	ft_pixel(t_all *aio, double i)
{
	int	index;

	if (floor(aio->hit.y) == aio->hit.y)
	{
		index = 64 * floor(64 * i) + 64 * (aio->hit.x - floor(aio->hit.x));
		if (aio->ray.w == 1)
			return (aio->tex.so[index]);
		else if (aio->ray.w == 0)
			return (aio->tex.no[index]);
	}
	else if (floor(aio->hit.x) == aio->hit.x)
	{
		index = 64 * floor(64 * i) + 64 * (aio->hit.y - floor(aio->hit.y));
		if (aio->ray.v == 1)
			return (aio->tex.ea[index]);
		else if (aio->ray.v == 0)
			return (aio->tex.we[index]);
	}
	return (BLACK);
}

void			ft_column(t_all *aio, int size)
{
	unsigned int	color;
	int				start;
	int				count;

	start = aio->res.map_x * (aio->res.map_y - size) / 2;
	if (size > aio->res.map_y)
		count = (size - aio->res.map_y) / 2;
	else
		count = 0;
	color = aio->tex.ce;
	while (aio->ray.i < aio->res.map_x * aio->res.map_y)
	{
		if (aio->ray.i >= start && count < size)
		{
			color = ft_pixel(aio, (double)count / size);
			count++;
		}
		else if (count == size)
			color = aio->tex.fl;
		aio->img.adr[aio->ray.i] = mlx_get_color_value(aio->mlx.ptr, color);
		aio->ray.i += aio->res.map_x;
	}
	aio->ray.i -= aio->res.map_x * aio->res.map_y;
}
