#include "raycasting.h"

void movePlayer(t_data *data) {
    data->player.rotationAngle += data->player.turnDirection * data->player.turnSpeed * (2 * (PI / 180));
    float moveStep = data->player.walkDirection * data->player.walkSpeed * (2 * (PI / 180));

    float newPlayerX = data->player.x + cos(data->player.rotationAngle) * moveStep;
    float newPlayerY = data->player.y + sin(data->player.rotationAngle) * moveStep;

    if ((data->map.map[(int)floor(newPlayerY / TILE_SIZE)][(int)floor(newPlayerX / TILE_SIZE)]) != 49) {
        data->player.x = newPlayerX;
        data->player.y = newPlayerY;
    }
}