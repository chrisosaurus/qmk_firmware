#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2

/* some cute options
 * LCTL_T(KC_Z) -> Left control when held, kc_z when tapped
 * LSFT(KC_X) -> sends shift + KC_X
 * LT(_RAISE, KC_Z) -> turn on layer when held, kc_z when tapped
 * DF(_RAISE) -> switches default layer
 * MO(_RAISE) -> activates layer while held (momentary)
 * OSL(_RAISE) -> activates layer for 1 key press (one shot layer)
 * TG(_RAISE) -> toggle layer on/off
 * OSM(MOD_LSFT) -> when pressed activiates modifier for next key press
 * MT(mod, kc) -> mod when held, kc when tapped
 */

/* change default to qwerty */
#define DF_QWE DF(_QWERTY)
/* change default to colemak */
#define DF_COL DF(_COLEMAK)
/* momentarily enable lower (while held) */
#define MO_LOW MO(_LOWER)
/* toggle lower */
#define TG_LOW TG(_LOWER)
/* activate left shift for next keypress
 * acts as shift when held down!?!
 */
#define OS_LSFT OSM(MOD_LSFT)
/* same for right shift */
#define OS_RSFT OSM(MOD_RSFT)

/* esc when pressed, alt when held */
#define ESCALT MT(MOD_LALT, KC_ESC)

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

/* things to consider
 *  - leader key
 *  - shift-alternative side key enforcement
 *      one of my bad typing habits is using left shift with LHS keys and vice versa
 *      using layers we can enforce this correctly
 *      LHS-shift instead could activate layer when held which only changes RHS side keys all to LSFT(KC_X)
 *      RHS-shift instead could activate layer when held which only changes LHS side keys all to LSFT(KC_X)
 *      alternatively, any key on LHS could be chosen to be layer shift when held
 *          e.g. LT(_RHS, KC_C) -> turn on _RHS layer when held, KC_C when pressed
 *          e.g. LT(_LHS, KC_M) -> turn on _LHS layer when held, KC_M when pressed
 *          holding C or M isn't useful in Vim currently
 * - symbol layer to keep fingers near home row
 *          e.g. LT(_SYMBOLS, KC_V) -> turn on _SYMBOLS layer when held, KC_V when pressed
 *          holding V isn't useful in Vim currently
 */

#define SIMPLE 1

#if SIMPLE
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x6(
        KC_EQL , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,

        KC_TAB , KC_Q  ,KC_W   , KC_E  , KC_R  , KC_T  ,                                        KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLS,
        ESCALT , KC_A  ,KC_S   , KC_D  , KC_F  , KC_G  ,                                        KC_H   , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        OS_LSFT, KC_Z  ,KC_X   , KC_C  , KC_V  , KC_B  ,                                        KC_N   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,OS_RSFT,

        KC_LSFT, KC_GRV,MO_LOW ,KC_LEFT,KC_RGHT,KC_BSPC,                                        KC_SPC , KC_UP ,KC_DOWN,KC_LBRC,KC_RBRC,TG_LOW ,
                                                KC_LSFT,KC_LGUI,KC_LCTL,        KC_LCTL,KC_RGUI,KC_ENT ,
                                                                KC_HOME,        KC_PGUP,
                                                                KC_END ,        KC_PGDN
    ),

    [_COLEMAK] = LAYOUT_6x6(
        KC_EQL , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,

        KC_TAB , KC_Q  ,KC_W   , KC_F  , KC_P  , KC_G  ,                                        KC_J   , KC_L  , KC_V  , KC_Y  ,KC_SCLN,KC_BSLS,
        ESCALT, KC_A  ,KC_R   , KC_S  , KC_T  , KC_D  ,                                        KC_H   , KC_N  , KC_E  , KC_I  , KC_O  ,KC_QUOT,
        KC_LSFT, KC_Z  ,KC_X   , KC_C  , KC_V  , KC_B  ,                                        KC_K   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,

        OS_LSFT, KC_GRV,MO_LOW ,KC_LEFT,KC_RGHT,KC_BSPC,                                        KC_SPC , KC_UP ,KC_DOWN,KC_LBRC,KC_RBRC,TG_LOW ,
                                                KC_LSFT,KC_LGUI,KC_LCTL,        KC_LCTL,KC_RGUI,KC_ENT ,
                                                                KC_HOME,        KC_PGUP,
                                                                KC_END ,        KC_PGDN
    ),

    [_LOWER] = LAYOUT_6x6(
        KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                       KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        _______,DF_QWE ,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,DF_COL ,_______,_______,_______,_______,                                       MS_L   ,MS_D   ,MS_U   ,MS_R   ,_______,_______,
        _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,_______,MS_L   ,MS_R   ,_______,                                       MS_B2  ,MS_U   ,MS_D   ,_______,_______,_______,
                                                _______,_______,_______,       _______,_______,MS_B1  ,
                                                                _______,       _______,
                                                                _______,       _______
    )
};
#endif // SIMPLE

