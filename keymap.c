#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Default Layer
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_MPRV, KC_MPLY, KC_MNXT, KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RGUI, KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Function Layer
    [1] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  EE_CLR,            KC_MPLY,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
        _______, RGB_HUI, RGB_VAI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,           _______,
        _______, RGB_HUD, RGB_VAD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, _______,          _______,           _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD,  _______,
        _______, _______, _______,                   RGB_MODE_PLAIN,                              _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),
};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};
#endif

// LED matrix logic
#ifdef RGB_MATRIX_ENABLE

static void set_rgb_caps_leds_on(void);
static void set_rgb_caps_leds_off(void);

bool rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        set_rgb_caps_leds_on();
    } else {
      if (rgb_matrix_get_flags() == LED_FLAG_NONE){
        set_rgb_caps_leds_off();
      }
    }
    return false;
}

static void set_rgb_caps_leds_on() {
    rgb_matrix_set_color(0, 255, 0, 0);      // Escape Key
    rgb_matrix_set_color(3, 255, 0, 0);      // capslock key
    rgb_matrix_set_color(5, 255, 0, 0);      // Left CTRL key
    rgb_matrix_set_color(67, 255, 0, 0);     // Left LED 01
    rgb_matrix_set_color(68, 255, 0, 0);     // Right LED 12
    rgb_matrix_set_color(70, 255, 127, 0);   // Left LED 02
    rgb_matrix_set_color(71, 255, 127, 0);   // Right LED 13
    rgb_matrix_set_color(73, 255, 255, 0);   // Left LED 03
    rgb_matrix_set_color(74, 255, 255, 0);   // Right LED 14
    rgb_matrix_set_color(76, 0, 255, 0);     // Left LED 04
    rgb_matrix_set_color(77, 0, 255, 0);     // Right LED 15
    rgb_matrix_set_color(80, 0, 0, 255);     // Left LED 05
    rgb_matrix_set_color(81, 0, 0, 255);     // Right LED 16
    rgb_matrix_set_color(83, 46, 43, 95);    // Left LED 06
    rgb_matrix_set_color(84, 46, 43, 95);    // Right LED 17
    rgb_matrix_set_color(87, 139, 0, 255);   // Left LED 07
    rgb_matrix_set_color(88, 139, 0, 255);   // Right LED 18
    rgb_matrix_set_color(91, 255, 255, 255); // Left LED 08
    rgb_matrix_set_color(92, 255, 255, 255); // Right LED 19
}

static void set_rgb_caps_leds_off() {
    rgb_matrix_set_color(0,  0, 0, 0); // Escape Key
    rgb_matrix_set_color(3,  0, 0, 0); // capslock key
    rgb_matrix_set_color(5,  0, 0, 0); // Left CTRL key
    rgb_matrix_set_color(67, 0, 0, 0); // Left LED 01
    rgb_matrix_set_color(68, 0, 0, 0); // Right LED 12
    rgb_matrix_set_color(70, 0, 0, 0); // Left LED 02
    rgb_matrix_set_color(71, 0, 0, 0); // Right LED 13
    rgb_matrix_set_color(73, 0, 0, 0); // Left LED 03
    rgb_matrix_set_color(74, 0, 0, 0); // Right LED 14
    rgb_matrix_set_color(76, 0, 0, 0); // Left LED 04
    rgb_matrix_set_color(77, 0, 0, 0); // Right LED 15
    rgb_matrix_set_color(80, 0, 0, 0); // Left LED 05
    rgb_matrix_set_color(81, 0, 0, 0); // Right LED 16
    rgb_matrix_set_color(83, 0, 0, 0); // Left LED 06
    rgb_matrix_set_color(84, 0, 0, 0); // Right LED 17
    rgb_matrix_set_color(87, 0, 0, 0); // Left LED 07
    rgb_matrix_set_color(88, 0, 0, 0); // Right LED 18
    rgb_matrix_set_color(91, 0, 0, 0); // Left LED 08
    rgb_matrix_set_color(92, 0, 0, 0); // Right LED 19
}

#endif // RGB_MATRIX_ENABLE
