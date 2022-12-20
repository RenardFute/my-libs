/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

void set_size(entity_t *entity, sfVector2f size)
{
    sfVector2f base = entity->base_size;
    sfVector2f scale = {size.x / base.x, size.y / base.y};
    entity->size = size;
    sfSprite_setScale(entity->sprite, scale);
}

void set_color(sfUint8 *pixel, sfColor color)
{
    pixel[0] = color.r;
    pixel[1] = color.g;
    pixel[2] = color.b;
    pixel[3] = color.a;
}

void reverse_texture(entity_t *entity)
{
    sfTexture *texture = entity->texture;
    sfVector2u size = sfTexture_getSize(texture);
    const sfUint8 *pixels = get_pixels_from_texture(texture);
    sfUint8 *new_pixels = malloc(sizeof(sfUint8) * size.x * size.y * 4);
    for (int i = 0; i < size.x; i++) {
        for (int j = 0; j < size.y; j++) {
            sfUint8 *pixel = (sfUint8 *) &pixels[(i + j * size.x) * 4];
            sfColor color = sfColor_fromRGBA(pixel[0], pixel[1],
            pixel[2], pixel[3]);
            set_color(&new_pixels[(size.x - i - 1)
            * 4 + j * size.x * 4], color);
        }
    }
    sfTexture_updateFromPixels(texture, new_pixels, size.x, size.y, 0, 0);
    free(new_pixels);
}

sfTexture *create_missing_texture(int width, int height)
{
    sfTexture *texture = sfTexture_create(width, height);
    sfUint8 *pixels = malloc(width * height * 4);
    sfColor purple = sfColor_fromRGB(255, 0, 255);
    sfColor black = sfColor_fromRGB(0, 0, 0);

    for (int i = 0; i < width * height * 4; i += 4) {
        int x = (i / 4) % width;
        int y = (i / 4) / width;
        bool x_invert = (x / 16) % 2 == 0;
        bool y_invert = (y / 16) % 2 == 0;
        if (x_invert == y_invert) {
            set_color(&pixels[i], purple);
        } else {
            set_color(&pixels[i], black);
        }
    }
    sfTexture_updateFromPixels(texture, pixels, width, height, 0, 0);
    free(pixels);
    return texture;
}

void change_texture(entity_t *entity, char *path)
{
    if (!is_texture_path_valid(path))
        return;
    sfTexture_destroy(entity->texture);
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    entity->texture = texture;
}
