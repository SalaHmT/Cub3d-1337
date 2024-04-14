/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate < shamsate@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:32:12 by zbendahh          #+#    #+#             */
/*   Updated: 2024/04/14 12:30:39 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"

float	normalize_angle(float ray_angle)
{
	ray_angle = remainder(ray_angle, TWO_PI);
	if (ray_angle < 0)
		ray_angle = TWO_PI + ray_angle;
	return (ray_angle);
}

float	distance_between_points(float x1, float y1, float x2, float y2) {
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void cast_ray(t_data *data, float rayAngle, int stripId) {
	int     isRayFacingDown = rayAngle > 0 && rayAngle < PI;
	int     isRayFacingUp = !isRayFacingDown;
	int     isRayFacingRight = rayAngle < 0.5 * PI || rayAngle > 1.5 * PI;
	int     isRayFacingLeft = !isRayFacingRight;
	float   x_intercept;
	float   y_intercept;
	float   x_step;
	float   y_step;

	///////////////////////////////////////////
	// HORIZONTAL RAY-GRID INTERSECTION CODE
	///////////////////////////////////////////
	int foundHorzWallHit = 0;
	float horzWallHitX = 0;
	float horzWallHitY = 0;
	int horzWallContent = 0;

	y_intercept = floor(data->player.y_player / TILE_SIZE) * TILE_SIZE;
	y_intercept += isRayFacingDown ? TILE_SIZE : 0;

	x_intercept = data->player.x_player + (y_intercept - data->player.y_player) / tan(rayAngle);

	y_step = TILE_SIZE;
	y_step *= isRayFacingUp ? -1 : 1;

	x_step = TILE_SIZE / tan(rayAngle);
	x_step *= (isRayFacingLeft && x_step > 0) ? -1 : 1;
	x_step *= (isRayFacingRight && x_step < 0) ? -1 : 1;

	float nextHorzTouchX = x_intercept;
	float nextHorzTouchY = y_intercept;

	while (nextHorzTouchX >= 0 && nextHorzTouchX <= data->mlx.size_x && nextHorzTouchY >= 0 && nextHorzTouchY <= data->mlx.size_y) {
		float xToCheck = nextHorzTouchX;
		float yToCheck = nextHorzTouchY + (isRayFacingUp ? -1 : 0);
		if (data->map.map[(int)yToCheck / TILE_SIZE][(int)xToCheck / TILE_SIZE] != '0') {
			horzWallHitX = nextHorzTouchX;
			horzWallHitY = nextHorzTouchY;
			horzWallContent = data->map.map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)] - 48;
			foundHorzWallHit = 1;
			break;
		} else {
			nextHorzTouchX += x_step;
			nextHorzTouchY += y_step;
		}
	}

	
	///////////////////////////////////////////
	// VERTICAL RAY-GRID INTERSECTION CODE
	///////////////////////////////////////////
	int foundVertWallHit = 0;
	float vertWallHitX = 0;
	float vertWallHitY = 0;
	int vertWallContent = 0;

	x_intercept = floor(data->player.x_player / TILE_SIZE) * TILE_SIZE;
	x_intercept += isRayFacingRight ? TILE_SIZE : 0;

	y_intercept = data->player.y_player + (x_intercept - data->player.x_player) * tan(rayAngle);

	x_step = TILE_SIZE;
	x_step *= isRayFacingLeft ? -1 : 1;

	y_step = TILE_SIZE * tan(rayAngle);
	y_step *= (isRayFacingUp && y_step > 0) ? -1 : 1;
	y_step *= (isRayFacingDown && y_step < 0) ? -1 : 1;

	float nextVertTouchX = x_intercept;
	float nextVertTouchY = y_intercept;

	while (nextVertTouchX >= 0 && nextVertTouchX <= data->mlx.size_x && nextVertTouchY >= 0 && nextVertTouchY <= data->mlx.size_y) {
		float xToCheck = nextVertTouchX + (isRayFacingLeft ? -1 : 0);
		float yToCheck = nextVertTouchY;
		
		if (data->map.map[(int)yToCheck / TILE_SIZE][(int)xToCheck / TILE_SIZE] != '0') {
			vertWallHitX = nextVertTouchX;
			vertWallHitY = nextVertTouchY;
			vertWallContent = data->map.map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)] - 48;
			foundVertWallHit = 1;
			break;
		} else {
			nextVertTouchX += x_step;
			nextVertTouchY += y_step;
		}
	}

	float horzHitDistance = foundHorzWallHit
		? distance_between_points(data->player.x_player, data->player.y_player, horzWallHitX, horzWallHitY)
		: FLT_MAX;
	float vertHitDistance = foundVertWallHit
		? distance_between_points(data->player.x_player, data->player.y_player, vertWallHitX, vertWallHitY)
		: FLT_MAX;

	if (vertHitDistance < horzHitDistance) {
		data->ray[stripId].distance = vertHitDistance;
		data->ray[stripId].wallHitX = vertWallHitX;
		data->ray[stripId].wallHitY = vertWallHitY;
		data->ray[stripId].wallHitContent = vertWallContent;
		data->ray[stripId].wasHitVertical = 0;
	} else {
		data->ray[stripId].distance = horzHitDistance;
		data->ray[stripId].wallHitX = horzWallHitX;
		data->ray[stripId].wallHitY = horzWallHitY;
		data->ray[stripId].wallHitContent = horzWallContent;
		data->ray[stripId].wasHitVertical = 1;
	}
	data->ray[stripId].rayAngle = rayAngle;
	data->ray[stripId].isRayFacingDown = isRayFacingDown;
	data->ray[stripId].isRayFacingUp = isRayFacingUp;
	data->ray[stripId].isRayFacingLeft = isRayFacingLeft;
	data->ray[stripId].isRayFacingRight = isRayFacingRight;
}

void cast_all_rays(t_data *data) {
	float ray_angle;

	ray_angle = data->player.player_rotation_angle - (FOV_ANGLE / 2);
	for (int stripId = 0; stripId < NUM_RAYS; stripId++) {
		cast_ray(data, normalize_angle(ray_angle), stripId);
		// mlx_line_dda(data, data->player.x_player , data->player.y_player , data->ray[stripId].wallHitX , data->ray[stripId].wallHitY , 0xFFFFFF);
		ray_angle += FOV_ANGLE / NUM_RAYS;
   }
}

void generate3DProjection(t_data* data) {
	for (int i = 0; i < NUM_RAYS; i++) {
		float perpDistance = data->ray[i].distance * cos(data->ray[i].rayAngle - data->player.player_rotation_angle);
		float distanceProjPlane = (data->mlx.size_x / 2) / tan(FOV_ANGLE / 2);
		float projectedWallHeight = (TILE_SIZE / perpDistance) * distanceProjPlane;

		int wallStripHeight = (int)projectedWallHeight;

		int wallTopPixel = (data->mlx.size_y / 2) - (wallStripHeight / 2);
		wallTopPixel = wallTopPixel < 0 ? 0 : wallTopPixel;

		int wallBottomPixel = (data->mlx.size_y / 2) + (wallStripHeight / 2);
		wallBottomPixel = wallBottomPixel > data->mlx.size_y ? data->mlx.size_y : wallBottomPixel;

		// render the wall from wallTopPixel to wallBottomPixel
		for (int y = wallTopPixel; y < wallBottomPixel; y++) {
			int color = data->ray[i].wasHitVertical ? 0x8B322C : 0xDD5746;
			img_pix_put(&data->mlx, i, y, color);
		}
	}
}

int keyPressed(int keycode, t_data *data) {
	
	if (keycode == 126)
		data->player.walk_direction = +1;
	else if (keycode == 125)
		data->player.walk_direction = -1;
	else if (keycode == 124)
		data->player.turn_direction = +1;
	else if (keycode == 123)
		data->player.turn_direction = -1;
	return 0;
}

int keyReleased(int keycode, t_data *data) {
	if (keycode == 126 || keycode == 125)
		data->player.walk_direction = 0;
	else if (keycode == 124 || keycode == 123)
		data->player.turn_direction = 0;
	return (0);
}

int update(t_data *data)
{
	backround(data);
	generate3DProjection(data);
	// map_building(data);
	player_building(data);
	cast_all_rays(data);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->mlx.img_ptr, 0, 0);
	return (0);
}

void    mlx_setup(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, data->mlx.size_x, data->mlx.size_y, ".....C U B 3 D.....");
	data->mlx.img_ptr = mlx_new_image(data->mlx.mlx_ptr, data->mlx.size_x, data->mlx.size_y);
	data->mlx.addr_ptr = mlx_get_data_addr(data->mlx.img_ptr, &data->mlx.bits_per_pixel, &data->mlx.line_length, &data->mlx.endian);
	mlx_hook(data->mlx.win_ptr, 2, 1L<<0, keyPressed, data);
	mlx_hook(data->mlx.win_ptr, 03, 1, keyReleased, data);
	mlx_loop_hook(data->mlx.mlx_ptr, update, data);
	mlx_loop(data->mlx.mlx_ptr);
}