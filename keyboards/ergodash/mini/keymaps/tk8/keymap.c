#include QMK_KEYBOARD_H
#include "keymap_jp.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _NUMPAD 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  NUMPAD,
  ADJUST,
};

#define EISU JP_MEISU
#define KANA JP_MKANA
#define SCRLCK LCTL(LSFT(KC_POWER))   // screen lock (for macOS)
#define KC_SS1 LSFT(LGUI(LCTL(KC_3))) // screenshot
#define KC_SS2 LSFT(LGUI(LCTL(KC_4))) // screenshot(selected area)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |NUMPAD|                    | Bksp |   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |  Esc |  Alt |  GUI | EISU |||||||| Lower|  F10 | Space|||||||| Space| Enter| Raise|||||||| Kana | GUI  | Home |  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    NUMPAD,                         KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_ESC,  KC_LALT, KC_LGUI, EISU,            LOWER,    KC_F10,  KC_SPC,        KC_SPC, KC_ENT , RAISE,            KANA,    KC_RGUI, KC_HOME, KC_END   \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |   ~  |   1  |   2  |   3  |   4  |   5  |   {  |                    |   }  |||||||||||||||  Up  ||||||||PageUp||||||||
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   6  |   7  |   8  |   9  |   0  ||||||||                    |      |||||||| Left | Down | Right|PageDn|      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      |||||||| Lower|      |      ||||||||      |      | Raise||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LCBR,                        KC_RCBR, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, KC_PGUP, XXXXXXX, \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,                        _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______, \
    _______, _______, _______, _______,          LOWER,   _______,_______,        _______,_______, RAISE,            _______, _______, _______, _______  \
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |   `  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * |   ~  |   F1 |   F2 |   F3 |   F4 |   F5 |   {  |                    ||||||||  F11 |  F12 |||||||||||||||||||||| PSCR |
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * |      |   F6 |   F7 |   F8 |   F9 |  F10 ||||||||                    |||||||| BRIUP| BRIDN| MUTE |||||||||||||||SCRST1|
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * |      |      |      | EISU |||||||| Lower||||||||      ||||||||      |      | Raise||||||||      |      |      |SCRST2|
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_GRV , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        XXXXXXX, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, \
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,                        XXXXXXX, KC_BRIU, KC_BRID, KC_MUTE, XXXXXXX, XXXXXXX, KC_SS1,  \
    _______, _______, _______, _______,          LOWER,   XXXXXXX,_______,        _______,_______, RAISE,            _______, _______, _______, KC_SS2   \
    ),

  /* NUMPAD
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |   7  |   8  |   9  |   -  |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |   .  |   4  |   5  |   6  |   +  |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |   0  |   1  |   2  |   3  |   /  |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |   *  |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_NUMPAD] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, KC_PDOT, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, KC_PAST, _______  \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |SCRLCK|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      | PLAIN|      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, SCRLCK,  \
    _______, _______, _______, RGB_M_P, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        tap_code(EISU);
        layer_on(_NUMPAD);
      } else {
        layer_off(_NUMPAD);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
