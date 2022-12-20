/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

sfTexture *get_texture(char *path)
{
    sfTexture *texture;
    if (is_texture_path_valid(path)) {
        texture = sfTexture_createFromFile(path, NULL);
    } else
        texture = create_missing_texture(400, 400);
    return texture;
}

bool is_texture_path_valid(char *path)
{
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        return false;
    }
    fclose(file);
    return true;
}
