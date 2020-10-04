#include "main_header_v2.h"
void            my_mlx_pixel_put(t_img *data, double x, double y, int color, int scale);

void	ft_map_mode(t_all *aio)
{
	//int		bpp;
	//int		sl;
	//int		end;

	aio->img.ptr = mlx_new_image(aio->mlx.ptr, aio->res.map_x, aio->res.map_y);
	aio->img.adr = (unsigned int *)mlx_get_data_addr(aio->img.ptr, &aio->img.bits_per_pixel, &aio->img.line_length, &aio->img.endian);




	int max_x;
	int max_y;
	int scale;
	char    *dst;
	ft_print_parse(aio);

	max_x = aio->res.map_x / aio->map.width;
	max_y = aio->res.map_y / aio->map.height;
	if (max_x <= max_y)
		scale = max_x;
	else
		scale = max_y;
	int i = 0;
	int j = 0;

	while (aio->map.map[i])
	{
		j = 0;
		while (aio->map.map[i][j])
		{
			if (aio->map.map[i][j] == '1')
			{
				my_mlx_pixel_put(&aio->img, j, i, RED, scale);
			}
			j++;
		}
		i++;
	}
	my_mlx_pixel_put(&aio->img, (int)aio->plr.pos_x, (int)aio->plr.pos_y, GREEN, scale);

	mlx_put_image_to_window(aio->mlx.ptr, aio->win.ptr, aio->img.ptr, 0, 0);
		unsigned l = 0;
	aio->img.ptr = NULL;
	aio->img.adr = NULL;
	free(aio->img.ptr);
	free(aio->img.adr);
}


void            my_mlx_pixel_put(t_img *data, double x, double y, int color, int scale)
 {
     char    *dst;
 	int save_x;
 	int save_y;
	//scale /= 4;
 	x = x*scale;
 	y = y*scale;
 	save_y = y;
 	save_x = x;
	while (x < save_x+scale)
	{
 		y = save_y;
		while (y< save_y+scale)
 		{
 			dst = (char *)(data->adr + (int)(y * (double)data->line_length + x * ((double)data->bits_per_pixel / 8))/4);
 			*(unsigned int*)dst = color;
			y++;
		}
		x++;
 	}
 }
