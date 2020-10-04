#include "main_header_v2.h"

// void	ft_reset(t_all *s)
// {
// 	//s->map.map = NULL;
// 	//s->tex.n = NULL;
// 	//s->tex.s = NULL;
// 	//s->tex.e = NULL;
// 	//s->tex.w = NULL;
// 	//s->tex.d = NULL;
// 	//s->tex.x = NULL;
// 	//s->tex.f = NULL;
// 	//s->tex.c = NULL;
// 	//s->tex.i = NULL;
// 	//s->tex.j = NULL;
// 	//s->res.map_x = 0;
// 	//s->res.map_y = 0;
// 	//s->map.width = 0;
// 	//s->map.height = 0;
// 	//s->map.spr = 0;
// 	//s->err.m = 0;
// 	//s->err.n = 0;
// 	//s->err.p = 0;
// }

// void	ft_free(t_all *aio)
// {
// 	//int	i;

// 	//i = 0;
// 	//while (i < s->map.height)
// 	//	free(s->map.map[i++]);
// 	//free(s->map.map);
// 	//free(s->spr);
// 	//free(s->tex.n);
// 	//free(s->tex.s);
// 	//free(s->tex.e);
// 	//free(s->tex.w);
// 	//free(s->tex.d);
// 	//free(s->tex.x);
// 	//free(s->tex.f);
// 	//free(s->tex.c);
// 	//free(s->tex.i);
// 	//free(s->tex.j);
// }

// int		ft_set(t_all *aio, int key, int set)
// {
// 	if (key == ESC)
// 		aio->key.e = set;
// 	else if (key == W)
// 		aio->key.w = set;
// 	else if (key == A)
// 		aio->key.a = set;
// 	else if (key == S)
// 		aio->key.s = set;
// 	else if (key == D)
// 		aio->key.d = set;
// 	else if (key == LEFT)
// 		aio->key.l = set;
// 	else if (key == RIGHT)
// 		aio->key.r = set;
// 	//else if (key == SHIFT && set)
// 	//	ft_open(s);
// 	//else if (key == SPACE)
// 	//	s->kdey.x = set;
// 	return (1);
// }

// int		ft_press(int key, void *arg)
// {
// 	ft_set(arg, key, 1);
// 	return (1);
// }

// int		ft_release(int key, void *arg)
// {
// 	ft_set(arg, key, 0);
// 	return (1);
// }

// //int		ft_mouse(int x, int y, t_all *s)
// //{
// //	(void)y;


// //	if (MOUSE && s->win.m != 10000)
// //		ft_rotate(s, (x - s->win.m) / 5);
// //	s->win.m = x;
// //	ft_key(s);
// //	return (0);
// //}

// void	ft_move(t_all *aio, double coeff)
// {
// 	char	c;

// 	aio->plr.pos_x += coeff * (aio->plr.dir_x * SPEED / 100);
// 	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
// 	if (ft_is(WALL, c) || ft_is(DECOR, c) || ft_is(DOOR, c))
// 		aio->plr.pos_x -= coeff * (aio->plr.dir_x* SPEED / 100);
// 	aio->plr.pos_y += coeff * (aio->plr.dir_y * SPEED / 100);
// 	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
// 	if (ft_is(WALL, c) || ft_is(DECOR, c) || ft_is(DOOR, c))
// 		aio->plr.pos_y -= coeff * (aio->plr.dir_y * SPEED / 100);
// 	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
// 	//if (ft_is(PICK, c))
// 	//{
// 	//	if (c == '7')
// 	//		s->hud.h += 35;
// 	//	else if (c == '8')
// 	//		s->hud.s += 1000;
// 	//	else if (c == '-')
// 	//		s->hud.a += 3;
// 	//	s->map.map[(int)floor(s->plr.pos_y)][(int)floor(s->plr.pos_x)] = '0';
// 	//	s->map.spr--;
// 	//	ft_slist(s);
// 	//}
// }

// void	ft_strafe(t_all *aio, double coeff)
// {
// 	char	c;

// 	aio->plr.pos_x -= coeff * (aio->plr.dir_y * SPEED / 100);
// 	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
// 	if (ft_is(WALL, c) || ft_is(DECOR, c) || ft_is(DOOR, c))
// 		aio->plr.pos_x += coeff * (aio->plr.dir_y * SPEED / 100);
// 	aio->plr.pos_y += coeff * (aio->plr.dir_x * SPEED / 100);
// 	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
// 	if (ft_is(WALL, c) || ft_is(DECOR, c) || ft_is(DOOR, c))
// 		aio->plr.pos_y -= coeff * (aio->plr.dir_x * SPEED / 100);
// 	c = aio->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)];
// 	//if (ft_is(PICK, c))
// 	//{
// 	//	if (c == '7')
// 	//		s->hud.h += 35;
// 	//	else if (c == '8')
// 	//		s->hud.s += 1000;
// 	//	else if (c == '-')
// 	//		s->hud.a += 3;
// 	//	s->map.map[(int)floor(aio->plr.pos_y)][(int)floor(aio->plr.pos_x)] = '0';
// 	//	s->map.spr--;
// 	//	ft_slist(s);
// 	//}
// }

// void	ft_rotate(t_all *aio, double c)
// {
// 	double	dist;

// 	aio->plr.dir_x = aio->plr.dir_x * cos(c * TURN) - aio->plr.dir_y * sin(c * TURN);
// 	aio->plr.dir_y = aio->plr.dir_y * cos(c * TURN) + aio->plr.dir_x* sin(c * TURN);
// 	dist = hypot(aio->plr.dir_x, aio->plr.dir_y);
// 	aio->plr.dir_x /= dist;
// 	aio->plr.dir_y /= dist;
// 	dist = hypot(aio->plr.dir_x, aio->plr.dir_y);
// 	if (aio->plr.dir_y <= 0)
// 		aio->plr.dir_a = acos(aio->plr.dir_x / dist) * 180 / M_PI;
// 	else
// 		aio->plr.dir_a = 360 - acos(aio->plr.dir_x / dist) * 180 / M_PI;
// }

// int		ft_key(t_all *aio)
// {
// 	if (aio->key.e)
// 		ft_close(aio, 1);
// 	if (aio->key.w)
// 		ft_move(aio, 1);
// 	if (aio->key.a)
// 		ft_strafe(aio, -1);
// 	if (aio->key.s)
// 		ft_move(aio, -1);
// 	if (aio->key.d)
// 		ft_strafe(aio, 1);
// 	if (aio->key.l)
// 		ft_rotate(aio, -1);
// 	if (aio->key.r)
// 		ft_rotate(aio, 1);
// 	//if (aio->key.x)
// 	//{
// 	//	if (aio->hud.f == 0)
// 	//		s->hud.f++;
// 	//}



// 	ft_draw(aio);
// 	// ft_map_mode(aio);




// 	//ft_global_map(aio);
// 	return (1);
// }

// //ft_global_map(t_all *aio)
// //{
// //	aio->img.ptr = NULL;
// //	aio->img.adr = NULL;
// //	free(aio->img.ptr);
// //	free(aio->img.adr);
// //	ft_map_mod(aio);
// //	mlx_put_image_to_window(aio->mlx.ptr, aio->win.ptr, aio->img.ptr, 0, 0);
// //}

// //void	ft_map_mod(t_all *aio)
// //{
// //	aio->img.ptr = mlx_new_image(aio->mlx.ptr, aio->res.map_x, aio->res.map_y);
// //	aio->img.adr = (unsigned int *)mlx_get_data_addr(aio->img.ptr, &aio->img.bpp, &aio->img.sl, &aio->img.end);

// //}


// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// // unsigned int	ft_pixel(t_all *s, double i)
// // {
// // 	int	index;

// // 	if (floor(s->hit.y) == s->hit.y)
// // 	{
// // 		index = 64 * floor(64 * i) + 64 * (s->hit.x - floor(s->hit.x));
// // 		if (s->ray.w == 1)
// // 			return (s->tex.so[index]);
// // 		else if (s->ray.w == 0)
// // 			return (s->tex.no[index]);
// // 	}
// // 	else if (floor(s->hit.x) == s->hit.x)
// // 	{
// // 		index = 64 * floor(64 * i) + 64 * (s->hit.y - floor(s->hit.y));
// // 		if (s->ray.v == 1)
// // 			return (s->tex.ea[index]);
// // 		else if (s->ray.v == 0)
// // 			return (s->tex.we[index]);
// // 	}
// // 	return (BLACK);
// // }

// // void			ft_column(t_all *s, int size)
// // {
// // 	unsigned int	color;
// // 	int				start;
// // 	int				count;

// // 	start = s->res.map_x * (s->res.map_y - size) / 2;
// // 	if (size > s->res.map_y)
// // 		count = (size - s->res.map_y) / 2;
// // 	else
// // 		count = 0;
// // 	color = s->tex.ce;
// // 	while (s->ray.i < s->res.map_x * s->res.map_y)
// // 	{
// // 		if (s->ray.i >= start && count < size)
// // 		{
// // 			color = ft_pixel(s, (double)count / size);
// // 			count++;
// // 		}
// // 		else if (count == size)
// // 			color = s->tex.fl;
// // 		s->img.adr[s->ray.i] = mlx_get_color_value(s->mlx.ptr, color);
// // 		s->ray.i += s->res.map_x;
// // 	}
// // 	s->ray.i -= s->res.map_x * s->res.map_y;
// // }

// // int				ft_size(t_all *s)
// // {
// // 	double	correc;
// // 	double	fisheye;

// // 	fisheye = fabs((double)s->ray.i / (s->res.map_x / 2) - 1);
// // 	fisheye *= 28 * M_PI / 180;
// // 	correc = (double)s->hit.d * cos(fisheye);
// // 	return (round(s->res.map_y / correc));
// // }

// // void			ft_stock(t_all *s)
// // {
// // 	s->stk[s->ray.i].x = s->ray.x;
// // 	s->stk[s->ray.i].y = s->ray.y;
// // 	s->stk[s->ray.i].d = s->hit.d;
// // }












// // void	ft_ray(t_all *s)
// // {
// // 	double	angle;
// // 	double	dist;

// // 	angle = ((double)s->ray.i - (s->res.map_x / 2)) * 33 / (s->res.map_x / 2);
// // 	angle = angle * M_PI / 180;
// // 	s->ray.x = s->plr.dir_x * cos(angle) - s->plr.dir_y * sin(angle);
// // 	s->ray.y = s->plr.dir_y * cos(angle) + s->plr.dir_x * sin(angle);
// // 	dist = hypot(s->ray.x, s->ray.y);
// // 	s->ray.x /= dist;
// // 	s->ray.y /= dist;
// // }

// // void	ft_dir(t_all *s)
// // {
// // 	if (s->ray.x >= 0)
// // 		s->ray.v = 1;
// // 	else
// // 		s->ray.v = 0;
// // 	if (s->ray.y >= 0)
// // 		s->ray.w = 1;
// // 	else
// // 		s->ray.w = 0;
// // }

// // void	ft_ver(t_all *s)
// // {
// // 	double	x;
// // 	double	y;

// // 	x = floor(s->plr.pos_x) + s->ray.v;
// // 	y = s->plr.pos_y + (x - s->plr.pos_x) * (s->ray.y / s->ray.x);
// // 	while ((int)floor(y) > 0 && (int)floor(y) < s->map.height)
// // 	{
// // 		if (s->map.map[(int)floor(y)][(int)(x - 1 + s->ray.v)] == '1')
// // 		{
// // 			s->hit.x = x;
// // 			s->hit.y = y;
// // 			s->hit.d = hypot(x - s->plr.pos_x, y - s->plr.pos_y);
// // 			return ;
// // 		}
// // 		x += (2 * s->ray.v - 1);
// // 		y += (2 * s->ray.v - 1) * s->ray.y / s->ray.x;
// // 	}
// // 	s->hit.x = s->plr.pos_x;
// // 	s->hit.y = s->plr.pos_y;
// // 	s->hit.d = 1000000000;
// // }

// // void	ft_hor(t_all *s)
// // {
// // 	double	y;
// // 	double	x;

// // 	y = floor(s->plr.pos_y) + s->ray.w;
// // 	x = s->plr.pos_x + (y - s->plr.pos_y) * (s->ray.x / s->ray.y);
// // 	while ((int)floor(x) > 0 && (int)floor(x) < s->map.width)
// // 	{
// // 		if (s->map.map[(int)(y - 1 + s->ray.w)][(int)floor(x)] == '1')
// // 		{
// // 			if (s->hit.d > hypot(x - s->plr.pos_x, y - s->plr.pos_y))
// // 			{
// // 				s->hit.x = x;
// // 				s->hit.y = y;
// // 				s->hit.d = hypot(x - s->plr.pos_x, y - s->plr.pos_y);
// // 			}
// // 			return ;
// // 		}
// // 		y += (2 * s->ray.w - 1);
// // 		x += (2 * s->ray.w - 1) * s->ray.x / s->ray.y;
// // 	}
// // }






// // void	ft_screen(t_all *s)
// // {
// // 	int		bpp;
// // 	int		sl;
// // 	int		end;

// // 	s->img.ptr = mlx_new_image(s->mlx.ptr, s->res.map_x, s->res.map_y);
// // 	s->img.adr = (unsigned int *)mlx_get_data_addr(s->img.ptr, &bpp, &sl, &end);
// // 	s->stk = malloc(sizeof(t_stk) * s->res.map_x);
// // 	while (s->ray.i < s->res.map_x)
// // 	{
// // 		ft_ray(s);
// // 		ft_dir(s);
// // 		ft_ver(s);
// // 		ft_hor(s);
// // 		ft_stock(s);
// // 		ft_column(s, ft_size(s));
// // 		s->ray.i++;
// // 	}
// // 	// ft_sprite(s);
// // }


int	ft_draw(t_all *s)
{
	ft_screen(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);

ft_print_parse(s);

	s->img.ptr = NULL;
	s->img.adr = NULL;
	free(s->img.ptr);
	free(s->img.adr);
	return (0);
}


// // int		ft_is(int n, char c)
// // {
// // 	if (n == WALL && (c == '1' || c == '2' || c == '3' || c == '4'))
// // 		return (1);
// // 	else if (n == WALL && (c == '4' || c == '5' || c == '6'))
// // 		return (1);
// // 	else if ((n == SPRITE || n == PICK) && (c == '7' || c == '8' || c == '-'))
// // 		return (1);
// // 	else if ((n == SPRITE || n == DECOR) && (c == '9' || c == '+' || c == '#'))
// // 		return (1);
// // 	else if ((n == SPRITE || n == DECOR) && (c == '&' || c == '$' || c == '*'))
// // 		return (1);
// // 	else if (n == ENEMY && (c == '+' || c == '#' || c == '&'))
// // 		return (1);
// // 	else if (n == ENEMY && (c == '$' || c == '*'))
// // 		return (1);
// // 	else if (n == POS && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
// // 		return (1);
// // 	else if (n == 0 && (c == '0' || c == 'O' || c == 'X'))
// // 		return (1);
// // 	else if (n == DOOR && c == 'D')
// // 		return (1);
// // 	else
// // 		return (0);
// // }


void	ft_move(t_all *s, double coeff)
{
	char	c;

	s->plr.pos_x += coeff * (s->plr.dir_x * SPEED / 100);
	c = s->map.map[(int)floor(s->plr.pos_y)][(int)floor(s->plr.pos_x)];
	if (ft_is(WALL, c) || ft_is(DECOR, c) || ft_is(DOOR, c))
		s->plr.pos_x -= coeff * (s->plr.dir_x * SPEED / 100);
	s->plr.pos_y += coeff * (s->plr.dir_y * SPEED / 100);
	c = s->map.map[(int)floor(s->plr.pos_y)][(int)floor(s->plr.pos_x)];
	if (ft_is(WALL, c) || ft_is(DECOR, c) || ft_is(DOOR, c))
		s->plr.pos_y -= coeff * (s->plr.dir_y * SPEED / 100);
	c = s->map.map[(int)floor(s->plr.pos_y)][(int)floor(s->plr.pos_x)];
	//if (ft_is(PICK, c))
	//{
	//	if (c == '7')
	//		s->hud.h += 35;
	//	else if (c == '8')
	//		s->hud.s += 1000;
	//	else if (c == '-')
	//		s->hud.a += 3;
	//	s->map.map[(int)floor(s->plr.pos_y)][(int)floor(s->plr.pos_x)] = '0';
	//	s->map.spr--;
	//	ft_slist(s);
	//}
}

void	ft_strafe(t_all *s, double coeff)
{
	char	c;

	s->plr.pos_x -= coeff * (s->plr.dir_y * SPEED / 100);
	c = s->map.map[(int)floor(s->plr.pos_y)][(int)floor(s->plr.pos_x)];
	if (ft_is(WALL, c) || ft_is(DECOR, c) || ft_is(DOOR, c))
		s->plr.pos_x += coeff * (s->plr.dir_y * SPEED / 100);
	s->plr.pos_y += coeff * (s->plr.dir_x * SPEED / 100);
	c = s->map.map[(int)floor(s->plr.pos_y)][(int)floor(s->plr.pos_x)];
	if (ft_is(WALL, c) || ft_is(DECOR, c) || ft_is(DOOR, c))
		s->plr.pos_y -= coeff * (s->plr.dir_x * SPEED / 100);
	c = s->map.map[(int)floor(s->plr.pos_y)][(int)floor(s->plr.pos_x)];
	//if (ft_is(PICK, c))
	//{
	//	if (c == '7')
	//		s->hud.h += 35;
	//	else if (c == '8')
	//		s->hud.s += 1000;
	//	else if (c == '-')
	//		s->hud.a += 3;
	//	s->map.map[(int)floor(s->plr.pos_y)][(int)floor(s->plr.pos_x)] = '0';
	//	s->map.spr--;
	//	ft_slist(s);
	//}
}

void	ft_rotate(t_all *s, double c)
{
	double	dist;

	s->plr.dir_x = s->plr.dir_x* cos(c * TURN) - s->plr.dir_y * sin(c * TURN);
	s->plr.dir_y = s->plr.dir_y * cos(c * TURN) + s->plr.dir_x * sin(c * TURN);
	dist = hypot(s->plr.dir_x, s->plr.dir_y);
	s->plr.dir_x /= dist;
	s->plr.dir_y /= dist;
	dist = hypot(s->plr.dir_x, s->plr.dir_y);
	if (s->plr.dir_y <= 0)
		s->plr.dir_a = acos(s->plr.dir_x / dist) * 180 / M_PI;
	else
		s->plr.dir_a = 360 - acos(s->plr.dir_x / dist) * 180 / M_PI;
}

int		ft_key(t_all *s)
{
	if (s->key.e)
		ft_close(s, 1);
	if (s->key.w)
		ft_move(s, 1);
	if (s->key.a)
		ft_strafe(s, -1);
	if (s->key.s)
		ft_move(s, -1);
	if (s->key.d)
		ft_strafe(s, 1);
	if (s->key.l)
		ft_rotate(s, -1);
	if (s->key.r)
		ft_rotate(s, 1);
	// if (s->key.x)
	// {
	// 	if (s->hud.f == 0)
	// 		s->hud.f++;
	// }


	// 	ft_draw(aio);
// 	// ft_map_mode(aio);
	ft_draw(s);
	return (1);
}

// void	ft_reset(t_all *s)
// {
// 	s->map.map = NULL;
// 	s->tex.n = NULL;
// 	s->tex.s = NULL;
// 	s->tex.e = NULL;
// 	s->tex.w = NULL;
// 	s->tex.d = NULL;
// 	s->tex.x = NULL;
// 	s->tex.f = NULL;
// 	s->tex.c = NULL;
// 	s->tex.i = NULL;
// 	s->tex.j = NULL;
// 	s->res.map_x = 0;
// 	s->res.map_y = 0;
// 	s->map.width = 0;
// 	s->map.height = 0;
// 	s->map.spr = 0;
// 	s->err.m = 0;
// 	s->err.n = 0;
// 	s->err.p = 0;
// }

// void	ft_free(t_all *s)
// {
// 	int	i;

// 	i = 0;
// 	while (i < s->map.height)
// 		free(s->map.map[i++]);
// 	free(s->map.map);
// 	free(s->spr);
// 	free(s->tex.n);
// 	free(s->tex.s);
// 	free(s->tex.e);
// 	free(s->tex.w);
// 	free(s->tex.d);
// 	free(s->tex.x);
// 	free(s->tex.f);
// 	free(s->tex.c);
// 	free(s->tex.i);
// 	free(s->tex.j);
// }

// int		ft_close(t_all *s, int win)
// {
// 	// ft_free(s);
// 	// free(s->hud.l);
// 	// free(s->hud.n);
// 	// free(s->hud.k);
// 	// free(s->hud.p);
// 	// free(s->hud.b);
// 	// free(s->tex.k);
// 	// free(s->tex.g);
// 	if (win == 1)
// 		mlx_destroy_window(s->mlx.ptr, s->win.ptr);
// 	free(s->mlx.ptr);
// 	// kill(s->mlx.pid + 1, SIGTERM);
// 	exit(0);
// 	return (1);
// }

int		ft_set(t_all *s, int key, int set)
{
	if (key == ESC)
		s->key.e = set;
	else if (key == W)
		s->key.w = set;
	else if (key == A)
		s->key.a = set;
	else if (key == S)
		s->key.s = set;
	else if (key == D)
		s->key.d = set;
	else if (key == LEFT)
		s->key.l = set;
	else if (key == RIGHT)
		s->key.r = set;
	// else if (key == SHIFT && set)
	// 	ft_open(s);
	// else if (kedy == SPACE)
	// 	s->key.x = set;
	return (1);
}

int		ft_press(int key, void *arg)
{
	ft_set(arg, key, 1);
	return (1);
}

int		ft_release(int key, void *arg)
{
	ft_set(arg, key, 0);
	return (1);
}



void	ft_ray(t_all *s)
{
	double	angle;
	double	dist;

	angle = ((double)s->ray.i - (s->res.map_x / 2)) * ANG / (s->res.map_x / 2);
	s->ray.x = s->plr.dir_x * cos(angle) - s->plr.dir_y * sin(angle);
	s->ray.y = s->plr.dir_y * cos(angle) + s->plr.dir_x * sin(angle);
	dist = hypot(s->ray.x, s->ray.y);
	s->ray.x /= dist;
	s->ray.y /= dist;
}

void	ft_dir(t_all *s)
{
	if (s->ray.x >= 0)
		s->ray.v = 1;
	else
		s->ray.v = 0;
	if (s->ray.y >= 0)
		s->ray.w = 1;
	else
		s->ray.w = 0;
}

void	ft_ver(t_all *s)
{
	double	x;
	double	y;
	char	c;

	x = floor(s->plr.pos_x) + s->ray.v;
	y = s->plr.pos_y + (x - s->plr.pos_x) * (s->ray.y / s->ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < s->map.height)
	{
		c = s->map.map[(int)floor(y)][(int)floor(x - 1 + s->ray.v)];
		if (ft_is(WALL, c))
		{
			s->hit.x = x;
			s->hit.y = y;
			s->hit.d = hypot(x - s->plr.pos_x, y - s->plr.pos_y);
			s->hit.c = c;
			//ft_is(DOOR, c) ? ft_verdoor(s, x, y) : 0;
			return ;
		}
		x += (2 * s->ray.v - 1);
		y += (2 * s->ray.v - 1) * s->ray.y / s->ray.x;
	}
	s->hit.x = s->plr.pos_x;
	s->hit.y = s->plr.pos_y;
	s->hit.d = 1000000000;
	s->hit.c = 0;
}

void	ft_hor(t_all *s)
{
	double	y;
	double	x;
	char	c;

	y = floor(s->plr.pos_y) + s->ray.w;
	x = s->plr.pos_x + (y - s->plr.pos_y) * (s->ray.x / s->ray.y);
	while ((int)floor(x) > 0 && (int)floor(x) < s->map.width)
	{
		c = s->map.map[(int)floor(y - 1 + s->ray.w)][(int)floor(x)];
		if (ft_is(WALL, c))
		{
			if (s->hit.d > hypot(x - s->plr.pos_x, y - s->plr.pos_y) && ft_is(WALL, c))
			{
				s->hit.x = x;
				s->hit.y = y;
				s->hit.d = hypot(x - s->plr.pos_x, y - s->plr.pos_y);
				s->hit.c = c;
			}
			//else if (s->hit.d > hypot(x - s->plr.pos_x, y - s->plr.pos_y))
			//	ft_hordoor(s, x, y);
			return ;
		}
		y += (2 * s->ray.w - 1);
		x += (2 * s->ray.w - 1) * s->ray.x / s->ray.y;
	}
}

void	ft_screen(t_all *s)
{
	int		bpp;
	int		sl;
	int		end;

	s->img.ptr = mlx_new_image(s->mlx.ptr, s->res.map_x, s->res.map_y);
	s->img.adr = (unsigned int *)mlx_get_data_addr(s->img.ptr, &bpp, &sl, &end);
	//ft_sky(s);
	//s->ray.i = 0;
	//while (s->ray.i < s->res.map_y / 2)
	//	ft_floor(s);
	s->stk = malloc(sizeof(t_stk) * s->res.map_x);
	s->ray.i = 0;
	while (s->ray.i < s->res.map_x)
	{
		ft_ray(s);
		ft_dir(s);
		ft_ver(s);
		ft_hor(s);
		ft_stock(s);
		ft_column(s, ft_size(s));
		s->ray.i++;
	}
	//ft_sprite(s);
	//ft_hud(s);
}


unsigned int	ft_pixel(t_all *s, double i)
{
	int	index;

	if (floor(s->hit.y) == s->hit.y || floor(s->hit.y) + 0.5 == s->hit.y)
		index = 64 * floor(64 * i) + 64 * (s->hit.x - floor(s->hit.x));
	else if (floor(s->hit.x) == s->hit.x || floor(s->hit.x) + 0.5 == s->hit.x)
		index = 64 * floor(64 * i) + 64 * (s->hit.y - floor(s->hit.y));
	if (s->hit.c == '1')
		return (s->tex.no[index]);
	else if (s->hit.c == '2')
		return (s->tex.so[index]);
	else if (s->hit.c == '3')
		return (s->tex.ea[index]);
	else if (s->hit.c == '4' || s->hit.c == '6')
		return (s->tex.we[index]);
	// else if (s->hit.c == '5')
	// 	return (s->tex.x[index]);
	// else if (s->hit.c == 'D')
	// 	return (s->tex.d[index]);
	return (BLACK);
}

void			ft_column(t_all *s, int size)
{
	unsigned int	color;
	int				start;
	int				count;

	start = s->res.map_x * (s->res.map_y - size) / 2;
	if (size > s->res.map_y)
		count = (size - s->res.map_y) / 2;
	else
		count = 0;
	color = NONE;
	while (s->ray.i < s->res.map_x * s->res.map_y)
	{
		if (s->ray.i >= start && count < size)
		{
			color = ft_pixel(s, (double)count / size);
			count++;
		}
		else if (count == size)
			color = NONE;
		if (color != NONE)
			s->img.adr[s->ray.i] = ft_shadow(s, color);
		s->ray.i += s->res.map_x;
	}
	s->ray.i -= s->res.map_x * s->res.map_y;
}

int				ft_size(t_all *s)
{
	double	correc;
	double	fisheye;

	fisheye = fabs((double)s->ray.i / (s->res.map_x / 2) - 1);
	fisheye *= 28 * M_PI / 180;
	correc = (double)s->hit.d * cos(fisheye);
	return (round(s->res.map_y / correc));
}

void			ft_stock(t_all *s)
{
	s->stk[s->ray.i].x = s->ray.x;
	s->stk[s->ray.i].y = s->ray.y;
	s->stk[s->ray.i].d = s->hit.d;
}

unsigned int	ft_shadow(t_all *s, unsigned int col)
{
	double	shadow;
	int		r;
	int		g;
	int		b;

	if (SHADOW == 0)
		return (col);
	shadow = 1 - hypot(s->plr.pos_x - s->hit.x, s->plr.pos_y - s->hit.y) / SHADOW;
	if (shadow < 0)
		shadow = 0;
	r = (col / (256 * 256) % 256) * shadow;
	g = (col / 256 % 256) * shadow;
	b = (col % 256) * shadow;
	col = r * 256 * 256 + g * 256 + b;
	return (col);
}
