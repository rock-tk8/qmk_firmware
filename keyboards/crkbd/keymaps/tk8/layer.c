#include QMK_KEYBOARD_H
#include "enums.h"
#include "layer.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_BASE 0
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_NUMPAD (1<<_NUMPAD)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_BASE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_NUMPAD:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: NumPad");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
