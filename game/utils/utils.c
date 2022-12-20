/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

sfVector3f lerp_v3f(sfVector3f a, sfVector3f b, float t)
{
    sfVector3f result;
    result.x = a.x + (b.x - a.x) * t;
    result.y = a.y + (b.y - a.y) * t;
    result.z = a.z + (b.z - a.z) * t;
    return result;
}

bool is_float_equal(float a, float b, float delta)
{
    return (a - delta <= b && a + delta >= b);
}

int get_array_size(void **array)
{
    int i = 0;
    while (array[i++] != NULL);
    return i - 1;
}
