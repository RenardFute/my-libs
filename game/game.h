/*
** EPITECH PROJECT, 2022
** B-MUL-100-NAN-1-1-myhunter-axel.eckenberg
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <math.h>
#include "my.h"

#define PERSPECTIVE_FACTOR 0.3
#define PARALLAX_FACTOR 0.5

typedef struct arg {
    char *key;
    char *value;
} arg_t;

typedef struct scene scene_t;
typedef struct event event_t;
typedef struct game game_t;
typedef struct entity entity_t;

typedef void (*callback_t)(game_t *game, event_t *event, scene_t *scene,
entity_t *entity);

typedef struct variable {
    char *name;
    void *value;
} variable_t;

typedef struct event {
    char         *name;
    sfEventType   type;
    sfKeyCode     code;
    sfMouseButton button;
    sfVector2i    mouse;
    callback_t    callback;
    sfEvent       *event;
    bool          on_whole_scene;
} event_t;

typedef struct hitbox {
    char             *name;
    sfFloatRect       rect;
    sfRectangleShape *shape;
    entity_t         *parent;
    bool              is_trigger;
    int               reset_counter;
} hitbox_t;

typedef struct entity {
    char        *name;
    event_t    **events;
    sfSprite    *sprite;
    sfTexture   *texture;
    sfClock     *clock;
    sfVector3f   position;
    sfVector3f   base_position;
    sfVector2f   base_size;
    sfVector2f   size;
    bool         perspective_enabled;
    void (*update)(game_t *game, scene_t *scene, entity_t *entity);
    bool         is_animated;
    int          frame_count;
    int          current_frame;
    int          frame_duration;
    int          frame_duration_counter;
    sfVector2f   frame_size;
    hitbox_t     **hitboxes;
} entity_t;

typedef struct text {
    char       *id;
    char       *value;
    sfText     *text;
} text_t;

typedef struct gui {
    text_t      **texts;
    char        *font_path;
    sfFont      *font;
} gui_t;

typedef struct scene {
    char       *name;
    entity_t **entities;
    sfClock    *clock;
    gui_t      *gui;
} scene_t;

typedef struct game {
    char      *name;
    arg_t    **params;
    scene_t   *active_scene;
    scene_t  **scenes;
    sfRenderWindow *window;
    sfTexture *icon;
    variable_t **variables;
} game_t;


// Game management
void     switch_scene(game_t *game, int index);
void     switch_scene_by_name(game_t *game, char *name);
void     force_switch_scene(game_t *game, scene_t *scene);
scene_t *get_scene_by_name(game_t *game, char *name);
scene_t *get_scene(game_t *game, int index);
void     add_scene_by_name(game_t *game, char *name);
int      get_scene_count(game_t *game);
int      get_param_count(game_t *game);
void     add_scene(game_t *game, scene_t *scene);
void     add_param(game_t *game, arg_t *arg);
game_t  *get_empty_game(char *name);
void     free_game(game_t *game);
void     exit_game(game_t *game, int status);
void     add_variable(game_t *game, char *name, void *value);
void     *get_variable(game_t *game, char *name);
void     set_variable(game_t *game, char *name, void *value);
int      get_variable_count(game_t *game);
void     free_variable(variable_t *variable);
void     free_variables(variable_t **variables);
variable_t *create_variable(char *name, void *value);
void     increase_variable(game_t *game, char* name, int delta);
void increase_variable_float(game_t *game, char* name, float delta);
void set_variable_to_i(game_t *game, char *name, int value);
void set_variable_to_f(game_t *game, char *name, float value);

// Render
void     render(game_t *game);
void     render_scene(game_t *game, scene_t *scene);
void     render_entity(game_t *game, scene_t *scene, entity_t *entity);
const sfUint8 *get_pixels_from_texture(sfTexture *texture);
void     show_hitbox(game_t *game, entity_t *entity);
void     update_animation(entity_t *entity);

// Events
void     handle_events(game_t *gme);
void call_events(game_t *game, event_t **events, entity_t *e, sfEvent event);
event_t *create_event(char *name, callback_t callback);
event_t *create_event_full(char *name, callback_t callback, int type, int code);
void free_events(game_t *game, entity_t *entity);
void free_event(game_t *game, event_t *event);
bool is_event(entity_t *entity, sfEventType type);
void reverse_texture(entity_t *entity);

// Scenes
scene_t *get_empty_scene(char *name);
void     free_scene(game_t *game, scene_t *scene);
int      get_entity_count(scene_t *scene);
void     add_entity(scene_t *scene, entity_t *entity);
void     sort_entities(scene_t *scene);
void     compare_and_swap(scene_t *scene, int i, int j, entity_t *tmp);
void     remove_entity(scene_t *scene, entity_t *entity);

// Params
void     free_param(arg_t *arg);
bool     is_arg(game_t *game, char *arg);
bool     arg(game_t *game, char *arg, char *value);
arg_t   *get_arg_by_key(game_t *game, char *key);
arg_t   *get_arg(game_t *game, int index);
void     parse_params(game_t *game, int ac, char **av);

// Entities
void      free_entity(game_t *game, entity_t *entity);
void      free_entities(game_t *game, scene_t *scene);
entity_t *create_entity(char *name, char *path, sfVector3f pos);
int       get_event_count(entity_t *entity);
void      add_event(entity_t *entity, event_t *event);
bool      is_texture_path_valid(char *path);
void      set_size(entity_t *entity, sfVector2f size);
sfTexture *create_missing_texture(int width, int height);
void      setup_animation(entity_t *entity, int frame_count,
int frame_duration, sfVector2f frame_size);
bool      is_colliding(entity_t *a, entity_t *b);
hitbox_t **get_colliders(entity_t *a, scene_t *scene);
void      add_hitbox(entity_t *entity, hitbox_t *hitbox);
void      update_hitboxes(entity_t *entity);
hitbox_t *create_hitbox(sfFloatRect rect, char *name);
int       get_hitbox_count(entity_t *entity);
void      change_texture(entity_t *entity, char *path);
void      update_pos_and_size(hitbox_t *hitbox);
hitbox_t **get_hitbox(entity_t *a, scene_t *scene, hitbox_t **colliders,
hitbox_t *hitbox);
sfTexture *get_texture(char *path);
hitbox_t **is_entity_colliding(hitbox_t *hitbox, entity_t *entity);
bool       is_hitbox_colliding(hitbox_t *a, hitbox_t *b);

// GUI
void     free_gui(game_t *game, gui_t *gui);
void     add_text(gui_t *gui, text_t *text);
gui_t   *create_gui(game_t *game, char *font_path);
void     render_gui(game_t *game, gui_t *gui);
void     add_text_full(gui_t *gui, char *str, sfVector2f pos, int size);
text_t  *create_text(char *id, char *str, sfVector2f pos, int size);
void     set_text(gui_t *gui, char *id, char *str);
void     change_text(gui_t *gui, char *id, char *str);

// Utils
sfVector3f lerp_v3f(sfVector3f a, sfVector3f b, float t);
int        get_array_size(void **array);
bool       is_float_equal(float a, float b, float delta);
