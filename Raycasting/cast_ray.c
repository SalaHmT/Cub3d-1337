/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:31:01 by shamsate          #+#    #+#             */
/*   Updated: 2024/05/27 20:31:41 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

// int map_has_wall_at(t_data *data, float x, float y) {
//     if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
//         return (1);
//     if (data->map.map[])
//     return  0;
// }

float   normalize_angle(float angle) {
    angle = remainder(angle, PI_2);

    if (angle < 0)
        angle = PI_2 + angle;
    return angle;
}

float distance_between_points(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void check_derction(t_data *data, float ray_angle)
{
    data->cast.is_ray_facing_down = ray_angle > 0 && ray_angle < PI;
    data->cast.is_ray_facing_up = !data->cast.is_ray_facing_down;
    data->cast.is_ray_facing_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
    data->cast.is_ray_facing_left = !data->cast.is_ray_facing_right;
}

void incidence_distances(t_data *data)
{
    if (data->cast.found_horz_wall_hit)
        data->cast.horz_hit_distance = distance_between_points(data->player.x, data->player.y, data->cast.horz_wall_hit_x, data->cast.horz_wall_hit_y);
    else
        data->cast.horz_hit_distance = FLT_MAX;
    if (data->cast.found_vert_wall_hit)
        data->cast.vert_hit_distance = distance_between_points(data->player.x, data->player.y, data->cast.vert_wall_hit_x, data->cast.vert_wall_hit_y);
    else
        data->cast.vert_hit_distance = FLT_MAX;
}

void cast_ray(t_data *data, float ray_angle, int strip_id)
{
    check_derction(data, ray_angle);
    is_horizontal(data, ray_angle);
    is_vertical(data, ray_angle);
    incidence_distances(data);
    if (data->cast.vert_hit_distance < data->cast.horz_hit_distance)
    {
        data->rays[strip_id].distance = data->cast.vert_hit_distance;
        data->rays[strip_id].wallHitX = data->cast.vert_wall_hit_x;
        data->rays[strip_id].wallHitY = data->cast.vert_wall_hit_y;
        data->rays[strip_id].wallHitContent = data->cast.vert_wall_content;
        data->rays[strip_id].wasHitVertical = 1;
    }
    else
    {
        data->rays[strip_id].distance = data->cast.horz_hit_distance;
        data->rays[strip_id].wallHitX = data->cast.horz_wall_hit_x;
        data->rays[strip_id].wallHitY = data->cast.horz_wall_hit_y;
        data->rays[strip_id].wallHitContent = data->cast.horz_wall_content;
        data->rays[strip_id].wasHitVertical = 0;
    }
    data->rays[strip_id].rayAngle = ray_angle;
    data->rays[strip_id].isRayFacingDown = data->cast.is_ray_facing_down;
    data->rays[strip_id].isRayFacingUp = data->cast.is_ray_facing_up;
    data->rays[strip_id].isRayFacingLeft = data->cast.is_ray_facing_left;
    data->rays[strip_id].isRayFacingRight = data->cast.is_ray_facing_right;
}

void cast_all_rays(t_data *data) {
    float   ray_angle;
    int     strip_id;
    
    strip_id = 0;
    ray_angle = data->player.rotationAngle - (FOV_ANGLE / 2);
    while (strip_id < NUM_RAYS)
        cast_ray(data, (normalize_angle(ray_angle += FOV_ANGLE / NUM_RAYS)), strip_id++);
}