/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

const sfUint8 *get_pixels_from_texture(sfTexture *texture)
{
    sfImage *image = sfTexture_copyToImage(texture);
    const sfUint8 *pixels = sfImage_getPixelsPtr(image);
    return pixels;
}
