/*
Copyright 2020 KnoblesseOblige
Copyright 2018 Sekigon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "app_ble_func.h"

enum custom_keycodes {
    AD_WO_L = SAFE_RANGE, /* Start advertising without whitelist  */
    BLE_DIS,              /* Disable BLE HID sending              */
    BLE_EN,               /* Enable BLE HID sending               */
    USB_DIS,              /* Disable USB HID sending              */
    USB_EN,               /* Enable USB HID sending               */
    DELBNDS,              /* Delete all bonding                   */
    ADV_ID0,              /* Start advertising to PeerID 0        */
    ADV_ID1,              /* Start advertising to PeerID 1        */
    ADV_ID2,              /* Start advertising to PeerID 2        */
    ADV_ID3,              /* Start advertising to PeerID 3        */
    ADV_ID4,              /* Start advertising to PeerID 4        */
    BATT_LV,              /* Display battery level in milli volts */
    DEL_ID0,              /* Delete bonding of PeerID 0           */
    DEL_ID1,              /* Delete bonding of PeerID 1           */
    DEL_ID2,              /* Delete bonding of PeerID 2           */
    DEL_ID3,              /* Delete bonding of PeerID 3           */
    DEL_ID4,              /* Delete bonding of PeerID 4           */
    ENT_DFU,              /* Start bootloader                     */
    ENT_SLP,              /* Deep sleep mode                      */
    QWERTY,
    COLEMAK,
    DVORAK,
    LOWER,
    RAISE,
    ADJUST,
    LEAVE_DEBUG,
    //BACKLIT,
    //EISU,
    //KANA,
    //RGBRST
};

extern keymap_config_t keymap_config;

enum layer_number {
  _BASE = 0,
  _DEBUG = 1
  /*_LOWER,
  _RAISE,*/
};


const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // [0] = LAYOUT(
  //   KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
  //   LT(1, KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,
  //   LT(1, KC_QUOT), KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, LT(2, KC_ENT),
  //   KC_LCTL, MO(2), KC_LGUI, KC_NO, KC_NO, KC_SPC, KC_NO, KC_RSFT, KC_LALT, TG(3)
  // ),
  // [1] = LAYOUT(
  //   KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  //   KC_TRNS, KC_BSLS, KC_QUOT, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_DOWN, KC_UP, KC_LEFT, KC_RIGHT, KC_TRNS,
  //   KC_TRNS, KC_ESC, BL_STEP, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_MSTP, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS,
  //   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET
  // ),
  // [2] = LAYOUT(
  //   KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
  //   KC_ESC, KC_PIPE, KC_DQT, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_4, KC_5, KC_6, KC_VOLU, KC_TRNS,
  //   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_VOLD, KC_TRNS,
  //   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  // ),
  // [3] = LAYOUT(
  //   KC_TRNS, BATT_LV, AD_WO_L, DELBNDS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS,
  //   KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS,
  //   KC_LSFT, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS,
  //   KC_TRNS, KC_LALT, KC_B, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  // )

  [_BASE] = LAYOUT( \
    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    LCTL_T(KC_TAB), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_UP, KC_SLSH,
    MO(1), KC_LALT, KC_LGUI, KC_NO, KC_NO,        KC_SPC,     KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [_DEBUG] =LAYOUT( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    _______, BATT_LV, AD_WO_L, DELBNDS, _______, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

/* SECRET DEBUG COMBO */
bool l_pressed = false;
bool r_pressed = false;
bool u_pressed = false;
bool d_pressed = false;
bool debug_layer = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  char str[16];

  if (record->event.pressed) {
    switch (keycode) {
      case DELBNDS:
        delete_bonds();
        return false;
      case AD_WO_L:
        restart_advertising_wo_whitelist();
        return false;
      case USB_EN:
        set_usb_enabled(true);
        return false;
        break;
      case USB_DIS:
        set_usb_enabled(false);
        return false;
        break;
      case BLE_EN:
        set_ble_enabled(true);
        return false;
        break;
      case BLE_DIS:
        set_ble_enabled(false);
        return false;
        break;
      case ADV_ID0:
        restart_advertising_id(0);
        return false;
      case ADV_ID1:
        restart_advertising_id(1);
        return false;
      case ADV_ID2:
        restart_advertising_id(2);
        return false;
      case ADV_ID3:
        restart_advertising_id(3);
        return false;
      case ADV_ID4:
        restart_advertising_id(4);
        return false;
      case DEL_ID0:
        delete_bond_id(0);
        return false;
      case DEL_ID1:
        delete_bond_id(1);
        return false;
      case DEL_ID2:
        delete_bond_id(2);
        return false;
      case DEL_ID3:
        delete_bond_id(3);
        return false;
      case BATT_LV:
        sprintf(str, "%4dmV", get_vcc());
        send_string(str);
        return false;
      case ENT_DFU:
        bootloader_jump();
        return false;
    }
  } else if (!record->event.pressed) {
    switch (keycode) {
      case ENT_SLP:
        sleep_mode_enter();
        return false;
    }
  }

  return true;
};
