/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:00:04 by cclaude           #+#    #+#             */
/*   Updated: 2020/10/04 18:44:05 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
void	ft_print_parse(t_all aio)
{
	int i;

	i = 0;
	while(aio.map.tab[i])
	{
		printf("%s\n", aio.map.tab[i]);
		i++;
	}
	// printf("", aio.win.x, aio.win.y, aio.map.y, aio.map.x);
	printf("MAP w=%d h=%d\n", aio.map.x, aio.map.y);
	printf("res=%dx%d\n", aio.win.y, aio.win.x);
	printf("PLAYER\n pos_x=%f pos_y=%f dir_x%f dir_y%f\n", aio.pos.x, aio.pos.y, aio.dir.x, aio.dir.y);
	printf("RAY x=%f y=%f i=%d v=%f w=%f\n", aio.ray.x, aio.ray.y, aio.ray.i,aio.ray.v,aio.ray.w);
	printf("HIT x=%f y=%f d=%f", aio.hit.x, aio.hit.y, aio.hit.d);
}
///////////////////////////////////////////////////////////////////////////////////////////////////

void	ft_draw(t_all *s)
{
	t_ray	ray;
	t_hit	hit;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.w = 0;
	hit.x = 0;
	hit.y = 0;
	hit.d = 0;
	s->ray = ray;
	s->hit = hit;
	ft_screen(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);

ft_print_parse(*s);

	free(s->img.ptr);
	free(s->img.adr);
}

int		ft_cubed(t_all s, char *cub, int bmp)
{
	t_pos	pos;
	t_dir	dir;

	pos.x = 0;
	pos.y = 0;
	dir.x = 0;
	dir.y = 0;
	s.pos = pos;
	s.dir = dir;
	s.mlx.ptr = mlx_init();
	if (ft_parse(&s, cub) == -1)
		return (ft_close(&s, 0));

ft_print_parse(s);

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
	return (1);
}

void	ft_declare(t_all s, char *cub, int bmp)
{
	t_map	map;
	t_tex	tex;
	t_spr	*spr;
	t_stk	*stk;

	map.tab = NULL;
	tex.n = NULL;
	tex.s = NULL;
	tex.e = NULL;
	tex.w = NULL;
	tex.i = NULL;
	spr = NULL;
	stk = NULL;
	map.x = 0;
	map.y = 0;
	map.spr = 0;
	tex.c = NONE;
	tex.f = NONE;
	s.map = map;
	s.tex = tex;
	s.spr = spr;
	s.stk = stk;
	ft_cubed(s, cub, bmp);
}

void	ft_init(char *cub, int bmp)
{
	t_all	s;
	t_mlx	mlx;
	t_win	win;
	t_img	img;
	t_err	err;

	mlx.ptr = NULL;
	win.ptr = NULL;
	img.ptr = NULL;
	img.adr = NULL;
	win.x = 0;
	win.y = 0;
	img.fsh = 0;
	err.n = 0;
	err.m = 0;
	err.p = 0;
	s.mlx = mlx;
	s.win = win;
	s.img = img;
	s.err = err;
	ft_declare(s, cub, bmp);
}

int		main(int ac, char **av)
{
	if (ac == 3 && ft_namecheck(av[1], "cub") && ft_savecheck(av[2], "--save"))
		ft_init(av[1], 1);
	else if (ac == 2 && ft_namecheck(av[1], "cub"))
		ft_init(av[1], 0);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
}

