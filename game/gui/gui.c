/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "../game.h"

gui_t *create_gui(game_t *game, char *font_path)
{
    gui_t *gui = malloc(sizeof(gui_t));
    gui->texts = malloc(sizeof(text_t *) * 1);
    gui->texts[0] = NULL;
    gui->font_path = my_strdup(font_path);
    gui->font = sfFont_createFromFile(gui->font_path);
    return gui;
}

void add_text(gui_t *gui, text_t *text)
{
    int i = 0;
    text_t **new_texts = malloc(sizeof(text_t *)
    * (get_array_size((void **) gui->texts) + 2));

    while (gui->texts[i] != NULL) {
        new_texts[i] = gui->texts[i];
        i++;
    }
    new_texts[i] = text;
    new_texts[i + 1] = NULL;
    free(gui->texts);
    gui->texts = new_texts;
}

void add_text_full(gui_t *gui, char *str, sfVector2f pos, int size)
{
    int text_count = get_array_size((void **) gui->texts);
    char *name = my_itoa(text_count);
    text_t *text = create_text(name, str, pos, size);
    add_text(gui, text);
}

void render_gui(game_t *game, gui_t *gui)
{
    for (int i = 0; gui->texts[i] != NULL; i++) {
        text_t *t = gui->texts[i];
        sfText *text = t->text;
        sfText_setFont(text, gui->font);
        sfText_setString(text, t->value);
        sfRenderWindow_drawText(game->window, text, NULL);
    }
}
