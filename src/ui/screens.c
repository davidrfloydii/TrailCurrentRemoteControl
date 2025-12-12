#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = lv_event_get_user_data(e);
    (void)flowState;
    
    if (event == LV_EVENT_PRESSED) {
        e->user_data = (void *)0;
        flowPropagateValueLVGLEvent(flowState, 2, 0, e);
    }
}

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 356, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Hello, world!");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 350, 291);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj1, LV_EVENT_ALL, flowState);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Button");
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 60);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            create_user_widget_top_nav_bar(obj, getFlowState(flowState, 4), 3);
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    tick_user_widget_top_nav_bar(getFlowState(flowState, 4), 3);
}

void create_screen_trailer() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.trailer = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    
    tick_screen_trailer();
}

void tick_screen_trailer() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
}

void create_user_widget_top_nav_bar(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // PanelTopNavBar
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 60);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_PRESS_LOCK|LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW|LV_OBJ_FLAG_SNAPPABLE);
            add_style_panel_nav_bar_top(obj);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // LabelActivePageTitle
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_nav_text(obj);
                    lv_label_set_text(obj, "");
                }
                {
                    // LabelInteriorTemperatureValue
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                    lv_obj_set_pos(obj, -70, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                    add_style_label_nav_text(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // LabelInteriorTemperatureMeasurementType
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                    lv_obj_set_pos(obj, -50, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label_nav_text_alternate(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
                {
                    // LabelCurrentDateTime
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                    lv_obj_set_pos(obj, -400, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                    add_style_label_nav_text(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
    }
}

void tick_user_widget_top_nav_bar(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    {
        const char *new_val = evalTextProperty(flowState, 0, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 1]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 1];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 1], new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 2, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 2]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 2];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 2], new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 3, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 3]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 3];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 3], new_val);
            tick_value_change_obj = NULL;
        }
    }
    {
        const char *new_val = evalTextProperty(flowState, 4, 3, "Failed to evaluate Text in Label widget");
        const char *cur_val = lv_label_get_text(((lv_obj_t **)&objects)[startWidgetIndex + 4]);
        if (strcmp(new_val, cur_val) != 0) {
            tick_value_change_obj = ((lv_obj_t **)&objects)[startWidgetIndex + 4];
            lv_label_set_text(((lv_obj_t **)&objects)[startWidgetIndex + 4], new_val);
            tick_value_change_obj = NULL;
        }
    }
}

void change_color_theme(uint32_t theme_index) {
    lv_style_set_bg_color(get_style_style_screen_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_style_set_bg_color(get_style_style_panel_modal_blocker_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_style_set_bg_color(get_style_style_panel_dialog_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][4]));
    
    lv_style_set_bg_color(get_style_style_panel_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    
    lv_style_set_text_color(get_style_label_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][10]));
    
    lv_style_set_text_color(get_style_label_default_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    
    lv_style_set_text_color(get_style_label_secondary_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][11]));
    
    lv_style_set_text_color(get_style_label_nav_text_alternate_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_text_color(get_style_button_navbar_in_active_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][5]));
    
    lv_style_set_text_color(get_style_button_navbar_active_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][5]));
    
    lv_style_set_border_color(get_style_button_navbar_active_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_text_color(get_style_button_navbar_active_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][5]));
    
    lv_style_set_bg_color(get_style_panel_screen_content_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    
    lv_style_set_text_color(get_style_button_list_menu_item_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][10]));
    
    lv_style_set_bg_color(get_style_button_list_menu_item_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][4]));
    
    lv_style_set_bg_color(get_style_style_content_panel_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    
    lv_style_set_text_color(get_style_style_device_status_ind_on_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_text_color(get_style_style_device_status_ind_off_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][10]));
    
    lv_style_set_bg_color(get_style_style_button_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    
    lv_style_set_bg_color(get_style_style_button_default_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][4]));
    
    lv_style_set_border_color(get_style_style_button_default_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_style_default_slider_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_style_default_slider_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][5]));
    
    lv_style_set_bg_color(get_style_style_default_slider_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    
    lv_style_set_text_color(get_style_label_fa_icon_active_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_button_circle_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    
    lv_style_set_text_color(get_style_button_circle_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][10]));
    
    lv_style_set_bg_color(get_style_arc_default_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][5]));
    
    lv_style_set_arc_color(get_style_arc_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    
    lv_style_set_arc_color(get_style_arc_default_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_default_button_matrix_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    
    lv_style_set_text_color(get_style_default_button_matrix_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][10]));
    
    lv_style_set_bg_color(get_style_default_button_matrix_ITEMS_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    
    lv_style_set_bg_color(get_style_default_button_matrix_ITEMS_CHECKED(), lv_color_hex(theme_colors[theme_index][4]));
    
    lv_style_set_bg_color(get_style_message_box_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    
    lv_style_set_bg_color(get_style_checkbox_default_INDICATOR_CHECKED(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_border_color(get_style_checkbox_default_INDICATOR_CHECKED(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_text_color(get_style_checkbox_default_INDICATOR_CHECKED(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_border_color(get_style_checkbox_default_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    
    lv_style_set_text_color(get_style_checkbox_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][10]));
    
    lv_style_set_bg_color(get_style_keyboard_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    
    lv_style_set_bg_color(get_style_keyboard_default_ITEMS_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    
    lv_style_set_bg_color(get_style_roller_default_SELECTED_DEFAULT(), lv_color_hex(theme_colors[theme_index][4]));
    
    lv_style_set_bg_color(get_style_roller_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    
    lv_style_set_text_color(get_style_roller_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][10]));
    
    lv_style_set_bg_color(get_style_switch_default_INDICATOR_CHECKED(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_bar_default_INDICATOR_CHECKED(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_bar_default_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_bar_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    
    lv_style_set_bg_color(get_style_led_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    
    lv_style_set_bg_color(get_style_led_default_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][4]));
    
    lv_style_set_bg_color(get_style_spinner_default_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_arc_color(get_style_spinner_default_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_arc_color(get_style_spinner_default_INDICATOR_FOCUSED(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_spinner_default_INDICATOR_CHECKED(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_bg_color(get_style_spinner_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    
    lv_style_set_arc_color(get_style_spinner_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][4]));
    
    lv_style_set_text_color(get_style_label_fa16_icon_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][10]));
    
    lv_style_set_text_color(get_style_label_fa16_icon_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    
    lv_style_set_text_color(get_style_label_fa32_icon_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][10]));
    
    lv_style_set_text_color(get_style_label_fa32_icon_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    
    lv_obj_invalidate(objects.main);
    lv_obj_invalidate(objects.trailer);
}

extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

static const char *screen_names[] = { "Main", "Trailer" };
static const char *object_names[] = { "main", "trailer", "obj0", "obj0__panel_top_nav_bar", "obj0__label_active_page_title", "obj0__label_interior_temperature_value", "obj0__label_interior_temperature_measurement_type", "obj0__label_current_date_time", "obj1" };
static const char *style_names[] = { "StyleScreenDefault", "StylePanelModalBlocker", "StylePanelDialog", "StylePanelDefault", "StyleButtonSucces", "StylePanelNavBarBottom", "PanelNavBarTop", "LabelDefault", "LabelSecondary", "LabelNavTextAlternate", "LabelNavText", "PanelNavBar", "ButtonNavbarInActive", "ButtonNavbarActive", "PanelScreenContent", "ListDefault", "ListMenu", "ButtonListMenuItem", "LabelListMenuItem", "StyleContentPanel", "StyleTopNavTextNormal", "StyleDeviceStatusIndOn", "StyleDeviceStatusIndOff", "StyleButtonDefault", "NavBarIcon", "StyleDefaultSlider", "LabelFaIconActive", "ButtonCircle", "LabelCircleButton", "ArcDefault", "DefaultButtonMatrix", "MessageBoxDefault", "TabViewDefault", "TabDefault", "CheckboxDefault", "DropdownDefault", "KeyboardDefault", "RollerDefault", "SwitchDefault", "BarDefault", "LEDDefault", "SpinnerDefault", "LabelFa16Icon", "LabelFa32Icon" };
static const char *theme_names[] = { "RivianLight", "RivianDark" };

uint32_t theme_colors[2][12] = {
    { 0xff000000, 0xffebebeb, 0xffe3f2dc, 0xffd0e2c7, 0xff5e635a, 0xffffffff, 0xff52a441, 0xff49e6ff, 0xffff5453, 0xff74fe00, 0xff000000, 0xff83a79b },
    { 0xff000000, 0xff646667, 0xff5b6768, 0xff859194, 0xff9db8bb, 0xffffffff, 0xff00d003, 0xff49e6ff, 0xffff5453, 0xff74fe00, 0xffffffff, 0xffe3f2ee },
};


typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_trailer,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    eez_flow_init_styles(add_style, remove_style);
    
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    eez_flow_init_style_names(style_names, sizeof(style_names) / sizeof(const char *));
    eez_flow_init_themes(theme_names, sizeof(theme_names) / sizeof(const char *), change_color_theme);
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_trailer();
}
