#include "includes.h"

void	fill_map(int *tab, char *current_map, int y)
{
	t_data	*data;
	int		tmp;
	int		str_x;
	int		fill_x;

	str_x = 0;
	fill_x = 0;
	data = get_data(NULL);
	while (current_map[str_x])
	{
		if (current_map[str_x] == '1' || current_map[str_x] == '0')
			tab[fill_x++] = current_map[str_x] - '0';
		else if (current_map[str_x] == ' ')
			tab[fill_x++] = -1;
		else if (current_map[str_x] == '\t')
		{
			tmp = 0;
			while (tmp++ < 4)
				tab[fill_x++] = -1;
		}
		else if (current_map[str_x] == 'N')
		{
			tab[fill_x++] = 0;
			data->mlx.player_pos.pos_player.x = str_x * MAP_SIZE + MAP_SIZE / 2;
			data->mlx.player_pos.pos_player.y = y * MAP_SIZE + MAP_SIZE / 2;
		}
		str_x++;
	}
	while (fill_x < data->mlx.map.col)
		tab[fill_x++] = -1;
}