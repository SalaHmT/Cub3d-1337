#include "raycasting/raycasting.h"
#include "parssing/parssing.h"


int32_t main(int argc, char **argv)
{
	t_data *data;

    if (argc != 2)
		return (printf("INVALID ARGUMENTS\n"), 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->map.map_x = 0;
	data->map.map_y = 0;
	extension_check(argv[1]);
	read_file_map(argv[1], &data->map);
    setup(data);
    return (EXIT_SUCCESS);
}