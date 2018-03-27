// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "keymap_jp.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols and media

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |  6   |           |   7  |   8  |   9  |   0  |   -  |   ~^ |   |    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   @    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  [{  |   }]   |
 * |--------+------+------+------+------+------|  '"  |           |  '"  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,<  |  .>  |  /?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |  Opt |  Cmd | Eisu |                                       | kana |  ;:  |  :*  |  `   |    _   |
 *   `----------------------------------'                                       `------------------------------------'
 *                                     ,--------------.           ,--------------.
 *                                     |   *  |   +   |           |  =   |   :  |
 *                             ,-------|------|-------|           |------+-------+-------.
 *                             |       |      | Left  |           |  Up  |       |       |
 *                             | Back  |  DEL |-------|           |------| Space | Enter |
 *                             | Space |      | Right |           | Down |       |       |
 *                             `---------------------'            `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
// layer 0 : default
[BASE] = KEYMAP(
        // left hand
        KC_ESC,         KC_1,       KC_2,     KC_3,       KC_4,      KC_5,   KC_6,
        KC_TAB,         KC_Q,       KC_W,     KC_E,       KC_R,      KC_T,   KC_NO,
        KC_LCTL,        KC_A,       KC_S,     KC_D,       KC_F,      KC_G,
        KC_LSFT,        KC_Z,       KC_X,     KC_C,       KC_V,      KC_B,   KC_QUOTE,
        KC_NO,          KC_NO,      KC_LALT,  KC_LGUI,    KC_LANG2,

                        KC_ASTERISK,   JP_PLUS,   /* KC_KP_EQUAL,    KC_COLON, */
                                       KC_LEFT,   /* KC_UP, */
        KC_BSPACE,      KC_DELETE,     KC_RIGHT,  /* KC_DOWN, KC_SPACE, KC_ENT */

        // right hand
        KC_7,           KC_8,       KC_9,       KC_0,       KC_MINS,    JP_CIRC,    JP_YEN,
        KC_NO,          KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_AT,
                        KC_H,       KC_J,       KC_K,       KC_L,       JP_LBRC,    JP_RBRC,
        KC_QUOTE,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                    KC_LANG1,   KC_SCLN,    KC_BSLASH,  KC_GRAVE,   JP_BSLS,


        /*              KC_ASTERISK,   KC_PLUS, */  KC_KP_EQUAL,  JP_COLN,
        /*                             KC_LEFT, */  KC_UP,
        /* KC_BSPACE,   KC_DELETE,     KC_RIGHT,*/  KC_DOWN, KC_SPACE, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Opt+Sp|      |------|       |------|VolDwn| VolUp|
 *                                 |      |      |      |       | Mute |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                          LALT(KC_SPC),KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
       KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_F12,
                KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_TRNS,KC_TRNS,
       KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                        KC_TRNS,KC_DOT, KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_MUTE, KC_VOLD, KC_VOLU
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
