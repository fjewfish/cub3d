#include "main_header_v2.h"

int		ft_spaceskip(char *line, int *i)
{
	while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
	|| (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
		(*i)++;
	return (1);
}

void	ft_print_parse(t_all *aio)
{
	int i;

	i = 0;
	while(aio->map.map[i])
	{
		printf("%s\n", aio->map.map[i]);
		i++;
	}
	printf("MAP w=%d h=%d\n", aio->map.width, aio->map.height);
	printf("res=%dx%d\ntex\n%s\n%s\n%s\n%s\n%s\n", aio->res.map_y, aio->res.map_x, aio->tex.east, aio->tex.north, aio->tex.south, aio->tex.sprite, aio->tex.west);
	printf("PLAYER\n pos_x=%f pos_y=%f dir_x%f dir_y%f\n", aio->plr.pos_x, aio->plr.pos_y, aio->plr.dir_x, aio->plr.dir_y);
	printf("RAY x=%f y=%f i=%d v=%f w=%f\n", aio->ray.x, aio->ray.y, aio->ray.i,aio->ray.v,aio->ray.w);
	printf("HIT x=%f y=%f c=%c d=%f", aio->hit.x, aio->hit.y, aio->hit.c, aio->hit.d);
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
