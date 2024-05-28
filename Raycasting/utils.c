#include "raycasting.h"

void	clear(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->mlx.x_win)
	{
		j = 0;
		while (j < data->mlx.y_win)
			mlx_put_pixel(data->mlx.img_ptr, i, j++, 0x00000000);
		i++;
	}
}

int32_t get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
  return (r << 24 | g << 16 | b << 8 | a);
}

int32_t mlx_get_pixel(mlx_image_t* image, uint32_t x, uint32_t y)
{
	uint8_t* pixelstart;
  	if (x >= image->width || y >= image->height)
    	return 0xFF000000;
  	pixelstart = image->pixels + (y * image->width + x) * sizeof(int32_t);
  	return get_rgba(pixelstart[0], pixelstart[1], pixelstart[2], pixelstart[3]);
}