#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum iris_layers {
    _QWERTY,
    _MOUSE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    MOUSE,
    LOWER,
    RAISE,
    ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ,-----------------------------------------.                        ,-----------------------------------------.
     * |  =   |  1   |  2   |  3   |  4   |  5   |                        |  6   |  7   |  8   |  9   |  0   |  -   |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * | Tab  |  Q   |  W   |  E   |  R   |  T   |                        |  Y   |  U   |  I   |  O   |  P   | Bksp |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * | Ctrl |  A   |  S   |  D   |  F   |  G   |                        |  H   |  J   |  K   |  L   |  ;   |  "   |
     * |------+------+------+------+------+------+------.          ,------+------+------+------+------+------+------|
     * | Shift|  Z   |  X   |  C   |  V   |  B   |  `   |          | Esc  |  N   |  M   |  ,   |  .   |  /   |Enter |
     * `------+------+------+------+------+------+------|          |------+------+------+------+------+------+------'
     *                             | LGUI |LOWER |Enter |          |Space |RAISE | LALT  |
     *                             `------+------+------'          `-----'-------+------'
     */
    [_QWERTY] = LAYOUT(
        KC_EQL,         KC_1,           KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                 KC_MINS,
        KC_TAB,         KC_Q,           KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                 KC_BSPC,
        CTL_T(KC_ESC) , KC_A,           KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    LT(_MOUSE, KC_SCLN),  RGUI_T(KC_QUOT),
        KC_LSFT,        CTL_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    LCAG_T(KC_GRV),   KC_GRV,  KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLSH),       RSFT_T(KC_ENT),
                                                          KC_LGUI, LOWER,   KC_ENT,           KC_SPC,  RAISE,   KC_LALT
    ),

    /*
     * ,-----------------------------------------.                        ,-----------------------------------------.
     * |      |      |QWERTY|      |      |      |                        |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * |      |      |MClick| MS_U |RClick|      |                        |      |RClick| WH_U |MClick|      |      |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * |      |LClick| MS_L | MS_D | MS_R |LClick|                        |LClick| WH_L | WH_D | WH_R |      |      |
     * |------+------+------+------+------+------+------.          ,------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |          |      |      |      |      |      |      |      |
     * `------+------+------+------+------+------+------|          |------+------+------+------+------+------+------'
     *                             |      |      |      |          |      |      |      |
     *                             `------+------+------'          `-----'-------+------'
     */
    [_MOUSE] = LAYOUT(
        _______,        _______,        QWERTY,  _______, _______, _______,                            _______, _______, _______, _______, _______,              _______,
        _______,        _______,        KC_BTN3, KC_MS_U, KC_BTN2, _______,                            _______, KC_BTN2, KC_WH_U, KC_BTN3, _______,              _______,
        _______,        KC_BTN1,        KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,                            KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, _______,              _______,
        _______,        _______,        _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,              _______,
                                                          _______, _______, _______,          _______, _______, _______
    ),

    /*
     * ,-----------------------------------------.                        ,-----------------------------------------.
     * |  ~   |  !   |  @   |  #   |  $   |  %   |                        |  ^   |  &   |  *   |  (   |  )   | Bksp |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * |  `   |  1   |  2   |  3   |  4   |  5   |                        |  6   |  7   |  8   |  9   |  0   | Del  |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * |Capslk|      | Left | Right|  Up  |  [   |                        |  ]   |  4   |  5   |  6   |  +   |  |   |
     * |------+------+------+------+------+------+------.          ,------+------+------+------+------+------+------|
     * |      |      |      |      | Down |  {   |  (   |          |  )   |  }   |  1   |  2   |  3   |  -   |      |
     * `------+------+------+------+------+------+------|          |------+------+------+------+------+------+------'
     *                             |      |      |      |          | Del  |      |  0   |
     *                             `------+------+------'          `-----'-------+------'
     */
    [_LOWER] = LAYOUT(
        KC_TILD,        KC_EXLM,        KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,              KC_BSPC,
        KC_ESC,         KC_1,           KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                 KC_DEL,
        KC_CAPS,        _______,        KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                            KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS,              KC_PIPE,
        _______,        _______,        _______, _______, KC_DOWN, KC_LCBR, KC_LPRN,          KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS,              _______,
                                                          _______, _______, _______,          KC_DEL,  _______, KC_P0
    ),

    /*
     * ,-----------------------------------------.                        ,-----------------------------------------.
     * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                        |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * |  ~   |  !   |  @   |  #   |  $   |  %   |                        |  ^   |  &   |  *   |  (   |  )   | F12  |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * |      |      |      |      | PgUp |  _   |                        |  =   | Home | Esc  |  `   |  :   |  /   |
     * |------+------+------+------+------+------+------.          ,------+------+------+------+------+------+------|
     * |      |      |      |      | PgDn |  -   |  [   |          |   ]  |  +   | End  |      |      |      |      |
     * `------+------+------+------+------+------+------|          |------+------+------+------+------+------+------'
     *                             |      |      | Bksp |          |      |      |      |
     *                             `------+------+------'          `-----'-------+------'
     */
    [_RAISE] = LAYOUT(
        KC_F12,         KC_F1,          KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,               KC_F11,
        KC_TILD,        KC_EXLM,        KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,              KC_F12,
        _______,        _______,        _______, _______, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, KC_GRV,  KC_ESC,  KC_COLN,              KC_BSLS,
        _______,        _______,        _______, _______, KC_PGDN, KC_MINS, KC_LBRC,          KC_RBRC, KC_PLUS, KC_END,  _______, _______, _______,              _______,
                                                          _______, _______, KC_BSPC,          _______, _______, _______
    ),

    /*
     * ,-----------------------------------------.                        ,-----------------------------------------.
     * | RESET| F14  | F15  |QWERTY| MOUSE|Normal|                        | Swap | Prev | Play | Next | Mute | Vol- |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * | RGBT |      |      |  Up  |      |      |                        |      |      |  Up  |      |      | Vol+ |
     * |------+------+------+------+------+------|                        |------+------+------+------+------+------|
     * | RGBM |      | Left | Down | Right|      |                        |      | Left | Down | Right|      | RGBM |
     * |------+------+------+------+------+------+------.          ,------+------+------+------+------+------+------|
     * |  BL  |      | VAL- | SAT- | HUE- |      |      |          |      |      | HUE+ | SAT+ | VAL+ |      | BRTG |
     * `------+------+------+------+------+------+------|          |------+------+------+------+------+------+------'
     *                             |      |      |      |          |      |      |      |
     *                             `------+------+------'          `-----'-------+------'
     */
    [_ADJUST] = LAYOUT(
        RESET,          KC_F14,         KC_F15,  QWERTY,  MOUSE,   AG_NORM,                            AG_SWAP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,              KC_VOLD,
        RGB_TOG,        _______,        _______, KC_UP,   _______, _______,                            _______, _______, KC_UP,   _______, _______,              KC_VOLU,
        RGB_RMOD,       _______,        KC_LEFT, KC_DOWN, KC_RGHT, _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,              RGB_MOD,
        BL_STEP,        _______,        RGB_VAD, RGB_SAD, RGB_HUD, _______, _______,          _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______,              BL_BRTG,
                                                          _______, _______, _______,          _______, _______, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case MOUSE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MOUSE);
            }
            return false;
            break;
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
