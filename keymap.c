/*
 * Copyright (c) 2023-2025 Andrew Domingues
 *
 * Corne (crkbd) Clover - Custom Keymap
 * --------------------------------------------------------
 * Features:
 *   - Tap-Dance for Tab/Esc
 *   - Mod-Tap for Left Shift/Caps lock
 *   - Homerow mods for fast typing and ergonomic modifier access
 *   - Layer system with symbols, navigation, and media controls
 *   - OLED display support with layer and caps lock status
 *   - RGB Matrix effects
 *   - Encoder support for volume/navigation control
 *
 * File: keymap.c
 * Version: 1.0
 * Last updated: May 17, 2025
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LOWER,
    _UPPER,
    _EXTRAS
};

enum {
    TD_TAB_ESC,
};

// Hold for left Super, tap "A" (home row mods)
#define HM_A LGUI_T(KC_A)
// Hold for left Alt, tap "S" (home row mods)
#define HM_S LALT_T(KC_S)
// Hold for left Control, tap "D" (home row mods)
#define HM_D LCTL_T(KC_D)
// Hold for left Shift, tap "F" (home row mods)
#define HM_F LSFT_T(KC_F)
// Hold for right Shift, tap "J" (home row mods)
#define HM_J RSFT_T(KC_J)
// Hold for right Control, tap "K" (home row mods)
#define HM_K RCTL_T(KC_K)
// Hold for right Alt, tap "L" (home row mods)
#define HM_L RALT_T(KC_L)
// Hold for right Super, tap ";" (home row mods)
#define HM_SCLN RGUI_T(KC_SCLN)
// Mod-tap hold LOWER layer, tap Space
#define LOWER_SPC LT(_LOWER, KC_SPC)
// Mod-tap hold UPPER layer, tap Space
#define UPPER_SPC LT(_UPPER, KC_SPC)
// Mod-tap hold EXTRAS layer, tap Delete
#define DEL_EXT LT(_EXTRAS, KC_DEL)
// Mod-tap hold EXTRAS layer, tap Enter
#define DEL_ENT LT(_EXTRAS, KC_ENT)
// Mod-Tap Caps lock/Left Shift
#define CAPS_SFT MT(MOD_LSFT, KC_CAPS)

tap_dance_action_t tap_dance_actions[] = {
    [TD_TAB_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | Tab/ |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bksp |
     * |  Esc |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Ctrl |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |      | GUI/ | ALT/ | CTL/ | SFT/ |      |                    |      | SFT/ | CTL/ | ALT/ | GUI/ |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |Caps/ |   Z  |   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  |   /  |  `   |
     * |Shift |      |      |      |      |      |                    |      |      |      |      |      |      |
     * `------+------+------+------+------+------+------.      ,------+------+------+------+------+------+------'
     *                             | GUI  |UPPER |Del   |      | Ent  |LOWER | ALT  |
     *                             |      |Space |EXTRAS|      |      |Space |      |
     *                             `--------------------'      `--------------------'
     */
    [_BASE] = LAYOUT_split_3x6_3(
        TD(TD_TAB_ESC), KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL,        HM_A,    HM_S,   HM_D,    HM_F,    KC_G,           KC_H,    HM_J,      HM_K,    HM_L,    HM_SCLN, KC_QUOT,
        CAPS_SFT,       KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,           KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_GRV,
                                 KC_LGUI, UPPER_SPC, DEL_EXT,              DEL_ENT,  LOWER_SPC, KC_RALT
    ),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | Tab  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   8  | Bksp |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Trns |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |  `   |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |Shift |   +  |   _  |   |  |   {  |   }  |                    |   [  |   ]  |   \  |   -  |   =  |Shift |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * `------+------+------+------+------+------+------.      ,------+------+------+------+------+------+------'
     *                             |      |      |      |      |      |      |      |
     *                             |      |      |      |      |      |      |      |
     *                             `--------------------'      `--------------------'
     */
    [_LOWER] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
        KC_LSFT, KC_PLUS, KC_UNDS, KC_PIPE, KC_LCBR, KC_RCBR,                    KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS, KC_EQL,  KC_RSFT,
                                   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO
    ),

    /* UPPER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Trns |      |      |      |      |      |                    | Left | Down | Up   |Right |      | F11  |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |Shift |      | Cut  | Copy | Paste|      |                    | Home | PgUp | PgDn | End  |      | F12  |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * `------+------+------+------+------+------+------.      ,------+------+------+------+------+------+------'
     *                             |      |      |      |      |      |      |      |
     *                             |      |      |      |      |      |      |      |
     *                             `--------------------'      `--------------------'
     */
    [_UPPER] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_F11,
        KC_LSFT, KC_NO,   C(KC_X), C(KC_C), C(KC_V), KC_NO,                       KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_NO,   KC_F12,
                                   KC_NO,   KC_NO,   KC_NO,                       KC_NO,   KC_NO,   KC_NO
    ),

    /* EXTRAS (Midia, Brighness and RGB)
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |RGB   | Prev | Next |Play/ | Vol- | Vol+ |                    |      |      |      |      |      |Reset |
     * |Effect|      |      |Pause |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |Boot  |      |      |      |      |Brght+|                    |Speed+| Hue+ | Sat+ | Val+ |      |Boot  |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |Reset |      |      |      |      |Brght-|                    |Speed-| Hue- | Sat- | Val- |      |RGB   |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |Toggle|
     * `------+------+------+------+------+------+------.      ,------+------+------+------+------+------+------'
     *                             |      |      |      |      |      |      |      |
     *                             |      |      |      |      |      |      |      |
     *                             `--------------------'      `--------------------'
     */
    [_EXTRAS] = LAYOUT_split_3x6_3(
        RGB_MOD, KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD, KC_VOLU,                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, EE_CLR,
        QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BRIU,                    RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, QK_BOOT,
        EE_CLR,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BRID,                    RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, RGB_TOG,
                                   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO
    )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_A:
        case HM_S:
        case HM_D:
        case HM_F:
        case HM_J:
        case HM_K:
        case HM_L:
        case HM_SCLN:
            return TAPPING_TERM;
        default:
            return QUICK_TAP_TERM;
    }
}

#if defined(ENCODER_MAP_ENABLE)
    const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
        [_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
        [_LOWER] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
        [_UPPER] = {ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
        [_EXTRAS] = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    };
#endif

#ifdef RGB_MATRIX_ENABLE
    void keyboard_post_init_user(void) {
        rgb_matrix_enable_noeeprom();

        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    
        rgb_matrix_sethsv_noeeprom(128, 255, 80);
    }
#endif


#ifdef OLED_ENABLE
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

     static void oled_render_boot(bool bootloader) {
        oled_clear();
        
         oled_set_cursor(0, 1);
        if (bootloader) {
            oled_write_P(PSTR("Awaiting\n"), false);
            oled_write_P(PSTR("firmware..."), false);
        } else {
            oled_write_P(PSTR("Rebooting..."), false);
        }
        
        oled_render_dirty(true);
    }

    static void render_status(void) {
        oled_write_P(PSTR("Clover "), false);

        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_P(PSTR("BASE\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("LOWER\n"), false);
                break;
            case _UPPER:
                oled_write_P(PSTR("UPPER\n"), false);
                break;
            case _EXTRAS:
                oled_write_P(PSTR("EXTRAS\n"), false);
                break;
            default:
                oled_write_ln_P(PSTR("UNKN"), false);
        }

        led_t led_state = host_keyboard_led_state();
        oled_write_P(PSTR(""), false);
        oled_write_P(led_state.caps_lock ? PSTR("Caps on") : PSTR("       "), false);
    }

    static void render_crkbd_logo(void) {
        oled_write_P(crkbd_logo, false);
    }

    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        if (!is_keyboard_master()) {
            return OLED_ROTATION_180;
        }
        return rotation;
    }

    bool oled_task_user(void) {
        if (is_keyboard_master()) {
            render_status();
        } else {
            render_crkbd_logo();
            oled_scroll_left();
        }
        return false;
    }

    bool shutdown_user(bool jump_to_bootloader) {
        oled_render_boot(jump_to_bootloader);
        return false;
    }
#endif
