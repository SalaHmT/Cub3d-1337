#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "../parssing/parssing.h"

#include "../mlx42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <float.h>
#include <math.h>
#include <string.h>


#define FALSE 0
#define TRUE 1
#define PI 3.14159265
#define PI_2 6.28318530
#define TILE_SIZE 32
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20
#define NUM_TEXTURES 8
#define MINIMAP_SCALE_FACTOR 0.2
#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64
#define FOV_ANGLE (60 * (PI / 180))
#define NUM_RAYS 1248
#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)
#define BPP sizeof(int32_t)

const int map[MAP_NUM_ROWS][MAP_NUM_COLS];

typedef struct s_player {
    float   x;
    float   y;
    float   width;
    float   height;
    int     turnDirection;
    int     walkDirection;
    float   rotationAngle;
    float   walkSpeed;
    float   turnSpeed;
    int     prev_x;
}   t_player;

typedef struct s_ray {
    float   rayAngle;
    float   distance;
    float   wallHitX;
    float   wallHitY;
    int     wasHitVertical;
    int     wallHitContent;
    int     isRayFacingUp;
    int     isRayFacingDown;
    int     isRayFacingLeft;
    int     isRayFacingRight;
}   t_rays;

typedef struct s_cast
{
	float	x_step;
	float	y_step;
	float	x_to_check;
	float	y_to_check;
	float	x_intercept;
	float	y_intercept;
	float	horz_wall_hit_x;
	float	horz_wall_hit_y;
	float	vert_wall_hit_x;
	float	vert_wall_hit_y;
	float	next_horz_touch_y;
	float	next_horz_touch_x;
	float	next_vert_touch_x;
	float	next_vert_touch_y;
	float	horz_hit_distance;
	float	vert_hit_distance;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	int		is_ray_facing_left;
	int		found_horz_wall_hit;
	int		found_vert_wall_hit;
	int		horz_wall_content;
	int		vert_wall_content;
}   t_cast;

typedef struct s_cast_3d
{
    int     floor_color;
    int     ceiling_color;
    int     texture_color;
    int     wallTopPixel;
    int     wallBottomPixel;
    int     wallStripHeight;
    int     textureOffsetX;
    int     textureOffsetY;
    int     distanceFromTop;
    float   perpDistance;
    float   distanceProjPlane;
    float   projectedWallHeight;
}   t_cast_3d;

typedef struct s_mlx
{
    int             x_win;
    int             y_win;
    mlx_t	        *mlx_ptr;
    mlx_image_t     *current_texture;
    mlx_image_t     *img_ptr;
    mlx_texture_t	*mlx_texture[4];
    mlx_image_t     *mlx_texture_img[4];
}   t_mlx;

typedef struct s_data
{
    t_mlx       mlx;
    t_map       map;
    t_cast      cast;
    t_player    player;
    t_cast_3d   cast_3d;
    t_rays      rays[NUM_RAYS];
}   t_data;



int32_t get_rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
int32_t mlx_get_pixel(mlx_image_t* image, uint32_t x, uint32_t y);
//int     map_has_wall_at(t_data *data, float x, float y);
float   distance_between_points(float x1, float y1, float x2, float y2);
float   normalize_angle(float angle);
void    cast_ray(t_data *data, float rayAngle, int stripId);
void    is_horizontal(t_data *data, float ray_angle);
void    is_vertical(t_data *data, float ray_angle);
void    cast_all_rays(t_data *data);
void    cast__3d(t_data *data);

void	hook(t_data *data);
void	mouse(t_data *data);
void	reset(t_data *data);
void    update(t_data *data);
void    movePlayer(t_data *data);
void	clear(t_data *data);
void    player_init_(t_data *data);
void    setup(t_data *data);

#endif