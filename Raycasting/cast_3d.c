/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 00:17:57 by zbendahh          #+#    #+#             */
/*   Updated: 2024/05/24 18:24:46 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Cub3d.h"
/*wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww*/

mlx_texture_t *load_png_tex(char *path)
{
    // Allocate memory for the texture structure
    mlx_texture_t *texture = malloc(sizeof(mlx_texture_t));
    if (!texture) {
        return NULL; // Memory allocation failed
    }

    // Load the PNG texture
    mlx_texture_t *loaded_texture = mlx_load_png(path); // Assuming mlx_load_png returns the texture structure
    if (!loaded_texture) {
        free(texture); // Free the texture structure if texture loading fails
        printf("Failed to load texture from path: %s\n", path);
        return NULL;
    }

    // Copy texture properties
    texture->width = loaded_texture->width;
    texture->height = loaded_texture->height;
    texture->bytes_per_pixel = loaded_texture->bytes_per_pixel;

    // Allocate memory for pixel data and copy it
    size_t pixel_count = texture->width * texture->height;
    texture->pixels = malloc(pixel_count * texture->bytes_per_pixel);
    if (!texture->pixels) {
        free(texture); // Free the texture structure if memory allocation fails
        free(loaded_texture); // Free the loaded texture structure
        printf("Failed to allocate memory for texture pixels\n");
        return NULL;
    }
    memcpy(texture->pixels, loaded_texture->pixels, pixel_count * texture->bytes_per_pixel);

    // Free the loaded texture structure as it's no longer needed
    free(loaded_texture);

    return texture;
}

// Function to create an integer representation of a color from RGBA components
int get_rgb(int r, int g, int b, int a)
{
    int type_color = (r << 24) | (g << 16) | (b << 8) | (a);
    return type_color;
}

// Function to get color from an image texture at specified coordinates
int get_color_from_image(mlx_texture_t *texture, int x, int y)
{
    int color;
    int r, g, b, a;

    if (x < 0 || x >= (int)texture->width || y < 0 || y >= (int)texture->height)
        return 0;

    // Calculate the index of the pixel in the texture pixel array
    int index = (y * texture->width + x) * texture->bytes_per_pixel;

    // Extract RGBA components from the texture pixel data
    r = texture->pixels[index];
    g = texture->pixels[index + 1];
    b = texture->pixels[index + 2];
    a = texture->pixels[index + 3];

    // Create an integer representation of the color and return it
    color = get_rgb(r, g, b, a);
    return color;
}

// Function to render textures on walls
// Function to render textures on walls
// Function to render textures on walls
void texture(t_data *data)
{
    int     i, j;
    float   perp_distance;
    float   distance_proj_plane;
    float   projected_wall_height;
    int     wall_top_pixel;
    int     wall_bottom_pixel;
    int     wall_strip_height;

    // Load textures for all four sides of the wall
    mlx_texture_t *front_texture = load_png_tex(data->map.no);
    mlx_texture_t *back_texture = load_png_tex(data->map.so);
    mlx_texture_t *left_texture = load_png_tex(data->map.we);
    mlx_texture_t *right_texture = load_png_tex(data->map.ea);

    // Check if texture loading failed
    if (!front_texture || !back_texture || !left_texture || !right_texture) {
        printf("Failed to load wall textures\n");
        // Handle texture loading failure
        return;
    }

    i = 0;
    while (i < data->mlx.win_x)
    {
        perp_distance = data->ray[i].distance * \
            cos(data->ray[i].ray_angle - data->player.player_rotation_angle);
        distance_proj_plane = (data->mlx.win_x / 2) / tan(FOV_ANGLE / 2);
        projected_wall_height = (TILE_SIZE / perp_distance) * distance_proj_plane;
        wall_strip_height = (int)projected_wall_height;
        wall_top_pixel = (data->mlx.win_y / 2) - (wall_strip_height / 2);
        wall_bottom_pixel = (data->mlx.win_y / 2) + (wall_strip_height / 2);
        if (wall_top_pixel < 0)
            wall_top_pixel = 0;
        if (wall_bottom_pixel > data->mlx.win_y)
            wall_bottom_pixel = data->mlx.win_y;

        j = wall_top_pixel;
        while (j < wall_bottom_pixel)
        {
            // Select the appropriate texture based on the side of the wall
            mlx_texture_t *current_texture;
            if (data->ray[i].is_ray_facing_left) {
                current_texture = left_texture;
            } else if (data->ray[i].is_ray_facing_right) {
                current_texture = right_texture;
            } else if (data->ray[i].is_ray_facing_up) {
                current_texture = back_texture;
            } else {
                current_texture = front_texture;
            }

            // Calculate texture coordinates without scaling
            int texture_x = (int)(((float)i / (float)data->mlx.win_x) * current_texture->width) % current_texture->width;
            int texture_y = (int)(((float)(j - wall_top_pixel) / (float)(wall_bottom_pixel - wall_top_pixel)) * current_texture->height) % current_texture->height;

            // Get the color of the pixel from the texture
            int texture_color = get_color_from_image(current_texture, texture_x, texture_y);

            // Draw the pixel using the sampled color
            mlx_put_pixel(data->mlx.img_ptr, i, j, texture_color);
            j++;
        }
        i++;
    }

    // Free the textures for all four sides of the wall
    free(front_texture->pixels);
    free(front_texture);
    free(back_texture->pixels);
    free(back_texture);
    free(left_texture->pixels);
    free(left_texture);
    free(right_texture->pixels);
    free(right_texture);
}











