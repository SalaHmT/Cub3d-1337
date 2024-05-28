#include "raycasting.h"

void	hook(t_data *data)
{
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_LEFT))
		data->player.walkDirection = 1;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_RIGHT))
		data->player.walkDirection = -1;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_W) || \
		mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_UP))
		data->player.walkDirection = 1;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_S) || \
		mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_DOWN))
		data->player.walkDirection = -1;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_D))
		data->player.turnDirection = 1;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_A))
		data->player.turnDirection = -1;
	if (mlx_is_key_down(data->mlx.mlx_ptr, MLX_KEY_ESCAPE))
		exit(1);
}

void	mouse(t_data *data)
{
	int	y;
	int	x;

	mlx_get_mouse_pos(data->mlx.mlx_ptr, &x, &y);
		data->player.rotationAngle += \
		((x - data->player.prev_x) / (float)data->mlx.x_win) * PI;
	data->player.prev_x = x;
}

void	reset(t_data *data)
{
	data->player.walkDirection = 0;
	data->player.turnDirection = 0;
}

void	mlx_line_dda(t_data *data, int y_first, int x_first, int y_last, int x_last, int color)
{
	float	x;
	float	y;
	int		i;
	int		x_int;
	int		y_int;
	int		steps;

	i = 0;
	x_int = x_last - x_first;
	y_int = y_last - y_first;
	if (abs(x_int) > abs(y_int))
		steps = abs(x_int);
	else
		steps = abs(y_int);
	x = x_first;
	y = y_first;
	while (i <= steps)
	{
		mlx_put_pixel(data->mlx.img_ptr, round(y), round(x), color);
		x += (x_int / (float) steps);
		y += (y_int / (float) steps);
		i++;
	}
}

void	mlx_square(t_data *data, int x_old, int y_old, int color)
{
	int		x_new;
	int		y_new;

	x_new = 0;
	y_new = 0;
	x_new = x_old;
	while (x_new < x_old + TILE_SIZE)
	{
		y_new = y_old;
		while (y_new < y_old + TILE_SIZE)
		{
			mlx_put_pixel(data->mlx.img_ptr, x_new, y_new, color);
			y_new++;
		}
		x_new++;
	}
}

void	render_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map.map_y)
	{
		j = 0;
		while (j < data->map.map_x)
		{
			if (data->map.map[i][j] == 48 || data->map.map[i][j] == 83)
				mlx_square(data, (j * TILE_SIZE), \
					(i * TILE_SIZE), 0xFF76ABAE);
			else if (data->map.map[i][j] == 49)
				mlx_square(data, (j * TILE_SIZE), \
					(i * TILE_SIZE), 0xFFA0153E);
			j++;
		}
		i++;
	}
}

void update(t_data *data) {
    clear(data);
	//render_map(data);
   	mouse(data);
	hook(data);
	movePlayer(data);
    reset(data);
	cast_all_rays(data);
	//mlx_line_dda(data, data->player.x, data->player.y, data->rays->wallHitX, data->rays->wallHitY, 0xFFFFFFFF);
    cast__3d(data);
}