#include <linux/input.h>

#include "recovery_ui.h"
#include "common.h"
#include "extendedcommands.h"


int device_toggle_display(volatile char* key_pressed, int key_code) {
    return 0;
}

int device_handle_key(int key_code, int visible) {
    if (visible) {
        switch (key_code) {
            case KEY_ENTER:
            case KEY_DOWN:
            case KEY_VOLUMEDOWN:
            case KEY_SEARCH:
                return HIGHLIGHT_DOWN;

            case KEY_HOME:
            case KEY_UP:
            case KEY_VOLUMEUP:
            case KEY_MENU:
                return HIGHLIGHT_UP;

            case KEY_LEFT:
            case KEY_POWER:
            case BTN_LEFT:
            /*case BTN_TOUCH:*/
                return SELECT_ITEM;
            
            case KEY_ESC:
            case KEY_RIGHT:
            case BTN_RIGHT:
                if (ui_menu_level > 0) {
                    return GO_BACK;
                }
        }
    }

    return NO_ACTION;
}
