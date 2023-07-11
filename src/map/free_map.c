#include "../includes/cub3d.h"

void free_map(t_cub3d *cub3d)
{
    cub3d->index = 0;
    while (cub3d->file[cub3d->index])
        free(cub3d->file[cub3d->index++]);
    free(cub3d->file);
    cub3d->index = 0;
    while (cub3d->coordinate[cub3d->index])
        free(cub3d->coordinate[cub3d->index++]);
    free(cub3d->coordinate);
        cub3d->index = 0;
/*     while (cub3d->verify_floor[cub3d->index])
        free(cub3d->verify_floor[cub3d->index++]);
    free(cub3d->verify_floor);
    cub3d->index = 0; */
    /* while (cub3d->verify_ceiling[cub3d->index])
        free(cub3d->verify_ceiling[cub3d->index++]);
    free(cub3d->verify_ceiling); */
    cub3d->index = 0;
    while (cub3d->map[cub3d->index])
        free(cub3d->map[cub3d->index++]);
    free(cub3d->map);
}