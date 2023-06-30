#include "../includes/cub3d.h"

void free_map(t_cub3d *cub3d)
{
    int i;

    i = 0;
    while (cub3d->file[i])
        free(cub3d->file[i++]);
    free(cub3d->file);
}