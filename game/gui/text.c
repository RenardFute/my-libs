/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

text_t *create_text(char *id, char *str, sfVector2f pos, int size)
{
    text_t *text = malloc(sizeof(text_t));
    text->text = sfText_create();
    sfText_setPosition(text->text, pos);
    sfText_setCharacterSize(text->text, size);
    text->id = my_strdup(id);
    text->value = my_strdup(str);
    return text;
}

void set_text(gui_t *gui, char *id, char *str)
{
    for (int i = 0; gui->texts[i] != NULL; i++) {
        if (my_strcmp(gui->texts[i]->id, id) == 0) {
            gui->texts[i]->value = my_strdup(str);
            return;
        }
    }
}

void change_text(gui_t *gui, char *id, char *str)
{
    for (int i = 0; gui->texts[i] != NULL; i++) {
        if (my_strcmp(gui->texts[i]->id, id) == 0) {
            free(gui->texts[i]->value);
            gui->texts[i]->value = str;
            return;
        }
    }
}
