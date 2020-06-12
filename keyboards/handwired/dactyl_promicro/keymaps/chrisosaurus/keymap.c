#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2

/* some cute options
 * LCTL_T(KC_Z) -> Left control when held, kc_z when tapped
 * LT(_RAISE, KC_Z) -> turn on layer when held, kc_z when tapped
 * DF(_RAISE) -> switches default layer
 * MO(_RAISE) -> activates layer while held (momentary)
 * OSL(_RAISE) -> activates layer for 1 key press (one shot layer)
 * TG(_RAISE) -> toggle layer on/off
 * OSM(MOD)   -> when pressed activiates modifier for next key press
 */

/* change default to qwerty */
#define DF_QWE DF(_QWERTY)
/* change default to colemak */
#define DF_COL DF(_COLEMAK)
/* momentarily enable lower (while held) */
#define MO_LOW MO(_LOWER)
/* toggle lower */
#define TG_LOW TG(_LOWER)
/* activate shift for next keypress */
#define OS_LSFT OSM(KC_LSFT)

/*
 * KC_MS_UP    -> Mouse Cursor Up
 * KC_MS_DOWN  -> Mouse Cursor Down
 * KC_MS_LEFT  -> Mouse Cursor Left
 * KC_MS_RIGHT -> Mouse Cursor Right
 * KC_MS_BTN1  -> Mouse Button 1
 * KC_MS_BTN2  -> Mouse Button 2
*/

#define MS_U  KC_MS_UP
#define MS_D  KC_MS_DOWN
#define MS_L  KC_MS_LEFT
#define MS_R  KC_MS_RIGHT
#define MS_B1 KC_MS_BTN1
#define MS_B2 KC_MS_BTN2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x6(
        KC_EQL , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,

        KC_TAB , KC_Q  ,KC_W   , KC_E  , KC_R  , KC_T  ,                                        KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
        KC_ESC , KC_A  ,KC_S   , KC_D  , KC_F  , KC_G  ,                                        KC_H   , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z  ,KC_X   , KC_C  , KC_V  , KC_B  ,                                        KC_N   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,

        OS_LSFT, KC_GRV,MO_LOW ,KC_LEFT,KC_RGHT,KC_BSPC,                                        KC_SPC , KC_UP ,KC_DOWN,KC_LBRC,KC_RBRC,TG_LOW ,
                                                KC_LSFT,KC_LGUI,KC_LCTL,        KC_LALT,KC_RGUI,KC_ENT ,
                                                                KC_HOME,        KC_PGUP,
                                                                KC_END ,        KC_PGDN
    ),

    [_COLEMAK] = LAYOUT_6x6(
        KC_EQL , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,

        KC_TAB , KC_Q  ,KC_W   , KC_F  , KC_P  , KC_G  ,                                        KC_J   , KC_L  , KC_V  , KC_Y  ,KC_SCLN,KC_BSLS,
        KC_ESC , KC_A  ,KC_R   , KC_S  , KC_T  , KC_D  ,                                        KC_H   , KC_N  , KC_E  , KC_I  , KC_O  ,KC_QUOT,
        KC_LSFT, KC_Z  ,KC_X   , KC_C  , KC_V  , KC_B  ,                                        KC_K   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,

        OS_LSFT, KC_GRV,MO_LOW ,KC_LEFT,KC_RGHT,KC_BSPC,                                        KC_SPC , KC_UP ,KC_DOWN,KC_LBRC,KC_RBRC,TG_LOW ,
                                                KC_LSFT,KC_LGUI,KC_LCTL,        KC_LALT,KC_RGUI,KC_ENT ,
                                                                KC_HOME,        KC_PGUP,
                                                                KC_END ,        KC_PGDN
    ),

    [_LOWER] = LAYOUT_6x6(
        KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                       KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                       MS_L   ,MS_D   ,MS_U   ,MS_R   ,_______,_______,
        _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                                       MS_B2  ,_______,_______,_______,_______,TG_LOW ,
                                                _______,_______,_______,       _______,_______,MS_B1  ,
                                                                _______,       _______,
                                                                _______,       _______
    )
};

