#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *trailer;
    lv_obj_t *obj0;
    lv_obj_t *obj0__panel_top_nav_bar;
    lv_obj_t *obj0__label_active_page_title;
    lv_obj_t *obj0__label_interior_temperature_value;
    lv_obj_t *obj0__label_interior_temperature_measurement_type;
    lv_obj_t *obj0__label_current_date_time;
    lv_obj_t *obj1;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_TRAILER = 2,
};

void create_screen_main();
void tick_screen_main();

void create_screen_trailer();
void tick_screen_trailer();

void create_user_widget_top_nav_bar(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_top_nav_bar(void *flowState, int startWidgetIndex);

enum Themes {
    THEME_ID_RIVIAN_LIGHT,
    THEME_ID_RIVIAN_DARK,
};
enum Colors {
    COLOR_ID_BACKGROUND_BLACK,
    COLOR_ID_BACKGROUND_CONTENT,
    COLOR_ID_BACKGROUND_PANEL,
    COLOR_ID_BACKGROUND_NOT_SELECTED,
    COLOR_ID_BACKGROUND_SELECTED,
    COLOR_ID_FOREGROUND_WHITE,
    COLOR_ID_ACCENT_COLOR,
    COLOR_ID_COOL,
    COLOR_ID_HOT,
    COLOR_ID_SUCCESS,
    COLOR_ID_PRIMARY_TEXT_COLOR,
    COLOR_ID_SECONDARY_TEXT_COLOR,
};
void change_color_theme(uint32_t themeIndex);
extern uint32_t theme_colors[2][12];

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/