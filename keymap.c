#include QMK_KEYBOARD_H
#include "version.h"
#include "layers.h"
#include "keymap_spanish.h"

#define _QWERTY     0  // default QWERTY base layer
#define _COLEMAK    1  // default QWERTY base layer
#define _FN         2  // Capa Funciones
#define _SIMBOLOS   3  // Capa SIMBOLOS
#define _MOUSE      4  // Capa RATON
#define _NUMERICO   5  // Capa Teclado Numerico

#define REDO LCTL(KC_Y)
#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define M_CF4 LCTL(KC_F4)
#define M_WE G(KC_E)

#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)


// COLEMAK - home row mods
#define HOMEQ_A LGUI_T(KC_A)
#define HOMEQ_R LALT_T(KC_R)
#define HOMEQ_S LSFT_T(KC_S)
#define HOMEQ_T LCTL_T(KC_T)
#define HOMEQ_O LGUI_T(KC_O)
#define HOMEQ_I LALT_T(KC_I)
#define HOMEQ_E RSFT_T(KC_E)
#define HOMEQ_N LCTL_T(KC_N)
// QWERTY - home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)
#define HOME_NT LGUI_T(ES_NTIL)
#define HOME_K RCTL_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_J RSFT_T(KC_J)

// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)


// #define ES_MORD KC_GRV  // º
// #define ES_QUOT KC_MINS // '
// #define ES_IEXL KC_EQL  // ¡
// #define ES_GRV  KC_LBRC // ` (dead)
// #define ES_PLUS KC_RBRC // +
// #define ES_NTIL KC_SCLN // Ñ
// #define ES_ACUT KC_QUOT // ´ (dead)
// #define ES_CCED KC_NUHS // Ç
// #define ES_LABK KC_NUBS // <
// #define ES_COMM KC_COMM // ,
// #define ES_DOT  KC_DOT  // .
// #define ES_MINS KC_SLSH // -
// #define ES_EXLM S(ES_1)    // !
// #define ES_LPRN S(ES_8)    // (
// #define ES_RPRN S(ES_9)    // )
// #define ES_EQL  S(ES_0)    // =
// #define ES_QUES S(ES_QUOT) // ?
// #define ES_IQUE S(ES_IEXL) // ¿
// #define ES_CIRC S(ES_GRV)  // ^ (dead)
// #define ES_ASTR S(ES_PLUS) // *
// #define ES_RABK S(ES_LABK) // >
// #define ES_SCLN S(KC_COMM) // ;
// #define ES_COLN S(KC_DOT)  // :
// #define ES_UNDS S(ES_MINS) // _
// // Row 1
// #define ES_BSLS ALGR(ES_MORD) // (backslash)
// #define ES_PIPE ALGR(ES_1)    // |
// #define ES_AT   ALGR(ES_2)    // @
// #define ES_HASH ALGR(ES_3)    // #
// #define ES_TILD ALGR(ES_4)    // ~
// #define ES_EURO ALGR(ES_5)    // €
// #define ES_NOT  ALGR(ES_6)    // ¬
// // Row 2
// #define ES_LBRC ALGR(ES_GRV)  // [
// #define ES_RBRC ALGR(ES_PLUS) // ]
// // Row 3
// #define ES_LCBR ALGR(ES_ACUT) // {
// #define ES_RCBR ALGR(ES_CCED) // }
enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here
    EPRM,
    VRSN,
    RGB_SLD,
    QWERTY,
    COLEMAK
};
enum unicode_names {
    // LEFT HAND
    SQUARED, CUBED, PLUSMIN,
    // RIGHT HAND
    DEG, TIMES, ENDASH, EQISH, LEQ, GEQ, DIV, NEQ,
    LEFT, DOWN, UP, RIGHT
};
const uint32_t PROGMEM unicode_map[] = {
    // LEFT HAND
    [SQUARED] = 0x00B2,  // ²
    [CUBED]   = 0x00B3,  // ³
    [PLUSMIN] = 0x00B1,  // ±
    // RIGHT HAND
    [DEG]     = 0x00B0,  // °
    [TIMES]   = 0x00D7,  // ×
    [ENDASH]  = 0x2013,  // –
    [EQISH]   = 0x2248,  // ≈
    [LEQ]     = 0x2264,  // ≤
    [GEQ]     = 0x2265,  // ≥
    [DIV]     = 0x00F7,  // ÷
    [NEQ]     = 0x2260,  // ≠
    [LEFT]  = 0x2190,  // ←
    [DOWN]  = 0x2193,  // ↓
    [UP]    = 0x2191,  // ↑
    [RIGHT] = 0x2192,  // →
};

enum {
    //Teclas de Funcion
    TD_1 = 0,  TD_2, TD_3, TD_4, TD_5, TD_6, TD_7, TD_8, TD_9, TD_10, TD_11, TD_12,
    TD_PC, TD_ALT,
    TD_INT, TD_EXC, TD_ANG, TD_LLA, TD_PAR, TD_PAC, TD_DOT
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F1),
  [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F2),
  [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F3),
  [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F4),
  [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F5),
  [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F6),
  [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F7),
  [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F8),
  [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F9),
  [TD_10] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F10),
  [TD_11] = ACTION_TAP_DANCE_DOUBLE(ES_QUOT, KC_F11),
  [TD_12] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_F12),
  [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, S(KC_COMM)),
  [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, S(KC_DOT)),

  [TD_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_LALT),

  [TD_INT] = ACTION_TAP_DANCE_DOUBLE(ES_IQUE, ES_QUES),
  [TD_EXC] = ACTION_TAP_DANCE_DOUBLE(ES_IEXL, ES_EXLM),
  [TD_ANG] = ACTION_TAP_DANCE_DOUBLE(ES_LABK, ES_RABK),
  [TD_LLA] = ACTION_TAP_DANCE_DOUBLE(ES_LCBR, ES_RCBR),
  [TD_PAR] = ACTION_TAP_DANCE_DOUBLE(ES_LPRN, ES_RPRN),
  [TD_PAC] = ACTION_TAP_DANCE_DOUBLE(ES_LBRC, ES_RBRC),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE (QWERTY)
     *
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │ ESC  │  1 │  2 │  3 │  4 │  5 │CLMK│              │TNUM│  6 │  7 │  8 │  9 │  0 │  '   │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │ TAB  │  Q │  W │  E │  R │  T │MOUS│              │MOUS│  Y │  U │  I │  O │  P │  `   │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │BLOQM │  A │  S │  D │  F │  G ├────┤              ├────┤  H │  J │  K │  L │  Ñ │  ´   │
     * ├──────┼────┼────┼────┼────┼────┤  º │              │FN  ├────┼────┼────┼────┼────┼──────┤
     * │MAYUS │  Z │  X │  C │  V │  B │    │              │    │  N │  M │  , │  . │  - │MAYUS │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │LCtl│LGUI|Num │ FN │SIMB│                                  │SIMB│ FN │MOUS│    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │Home│ End│    │RAlt│RCtl│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │PGUP│    │INS │    │    │
     *                            │BACK│ Del├────┤    ├────┤Entr│ [] │
     *                            │    │    │PGDO│    │MENU│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_QWERTY] = LAYOUT_ergodox(  // QWERTY persistent layer
        // left hand
        KC_ESC,  TD(TD_1),    TD(TD_2),    TD(TD_3),    TD(TD_4),      TD(TD_5),    DF(_COLEMAK),
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    TG(_MOUSE),
        KC_CAPS, LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),      KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    ES_MORD,
        KC_LCTL, LALT_T(KC_LGUI), TT(_NUMERICO), TT(_FN),  TT(_SIMBOLOS),
                                            KC_HOME, KC_END,
                                                       KC_PGUP,
                                   KC_BSPC, KC_DEL,    KC_PGDN,
        // right hand
        TG(_NUMERICO), TD(TD_6), TD(TD_7), TD(TD_8), TD(TD_9),TD(TD_10), TD(TD_11),
        TG(_MOUSE), KC_Y, KC_U, KC_I, KC_O, KC_P, TD(TD_12),
                 KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN),  KC_QUOT,
        TG(_FN), KC_N, KC_M, TD(TD_PC), KC_DOT,  KC_SLSH,  KC_RSFT,
                            TT(_SIMBOLOS), TT(_FN), TG(_MOUSE), KC_RALT, KC_RGUI,
                                    KC_RALT, KC_RCTRL,
        KC_INS,
        KC_APP, KC_ENT,   KC_SPC),

     /* (COLEMAK)
     * https://forum.colemak.com/topic/2519-colemak-para-espanol-latino-win-colemak-for-spanish-la-win/
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │      │  1 │  2 │  3 │  4 │  5 │    │              │    │  6 │  7 │  8 │  9 │  0 │      │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │  Q │  W │  F │  P │  G │    │              │    │  J │  L │  U │  Y │  Ñ │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │  A │  R │  S │  T │  D ├────┤              ├────┤  H │  N │  E │  I │  O │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │  Z │  X │  C │  V │  B │    │              │    │  K │  M │    │    │    │      │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │    │    │    │    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │    │    │    │    │    │
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │    │    │    │
     *                            │    │    ├────┤    ├────┤    │    │
     *                            │    │    │    │    │    │    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_COLEMAK] = LAYOUT_ergodox(  // Colemak persistent layer (default)
        // left hand
        KC_ESC,  TD(TD_1),    TD(TD_2),    TD(TD_3),    TD(TD_4),      TD(TD_5),    DF(_QWERTY),
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,      KC_G, TT(_MOUSE),
        KC_CAPS, LGUI_T(KC_A),    LALT_T(KC_R),    LCTL_T(KC_S),    LSFT_T(KC_T),      KC_D,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B, ES_MORD,
        KC_LCTL, LALT_T(KC_LGUI), TT(_NUMERICO), TT(_FN),  TT(_SIMBOLOS),
                                            KC_HOME, KC_END,
                                                       KC_PGUP,
                                   KC_BSPC, KC_DEL,    KC_PGDN,
        // right hand
        TG(_NUMERICO), TD(TD_6), TD(TD_7), TD(TD_8), TD(TD_9),TD(TD_10), TD(TD_11),
        TG(_MOUSE), KC_J,     KC_L,    KC_U,     KC_Y,    KC_SCLN,  TD(TD_12),
                 KC_H,     RSFT_T(KC_N),    RCTL_T(KC_E),     RALT_T(KC_I),    RGUI_T(KC_O),     (KC_QUOT),
        TG(_FN), KC_K, KC_M, TD(TD_PC), TD(TD_DOT),  KC_SLSH,  KC_RSFT,
                            TT(_SIMBOLOS), TT(_FN), TG(_MOUSE), KC_RALT, KC_RCTRL,
        KC_RALT, KC_RCTRL,
        KC_INS,
        KC_APP, KC_ENT,   KC_SPC),

/* SIMBOLOS : Simbolos2
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │      │    │    │    │    │    │ [  │              │ ]  │    │    │    │    │    │      │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │  = │  * │  + │  @ │  \ │ {  │              │ }  │ €  │  $ │  [ │ ]  │ º  │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │  " │  ' │  / │  & │  | ├────┤              ├────┤ ¡  │  ! │  ( │ )  │    │      │
     * ├──────┼────┼────┼────┼────┼────┤SPAC│              │ )  ├────┼────┼────┼────┼────┼──────┤
     * │      │ <  │ >  │  % │  - │  # │    │              │    │ ¿  │  ? │  { │ }  │    │      │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │    │    │    │    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │    │    │    │    │    │
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │    │    │    │
     *                            │    │    ├────┤    ├────┤    │    │
     *                            │    │    │    │    │    │    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */

    [_SIMBOLOS] = LAYOUT_ergodox(
        // left hand
        _______, _______,   _______,   _______,   _______,   _______,   ES_LBRC,
        _______, ES_EQL, ES_ASTR, ES_PLUS, ES_AT, ES_BSLS, ES_LCBR,
        _______, S(KC_2), ES_QUOT, ES_SLSH, ES_AMPR, ES_PIPE,
        _______, ES_LABK, ES_RABK, S(KC_5), KC_SLSH, ES_HASH, KC_SPC,
        _______, _______, _______, _______, _______,
                                            _______, _______,
                                                     _______,
                                   _______, _______, _______,
        // right hand
        ES_RBRC, _______, _______, _______, _______, _______, _______,
        ES_RCBR, ES_EURO, S(KC_4), ES_LBRC, ES_RBRC, ES_MORD, _______,
                 ES_IEXL, ES_EXLM, ES_LPRN, ES_RPRN, _______, _______,
        ES_RPRN, ES_IQUE, ES_QUES, ES_LCBR, ES_RCBR, _______, _______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______),

/* Teclado Numérico - - Shortcuts
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │      │    │    │    │    │    │    │              │    │    │    │  / │  * │  - │ HOME │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │C(\)│    │    │    │    │    │              │    │    │  7 │  8 │  9 │  + │  END │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    ├────┤              ├────┤    │  4 │  5 │  6 │  - │ PGUP │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    │    │              │    │    │  1 │  2 │  3 │  = │ PGDW │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │  0 │  . │Entr│    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │    │    │    │    │    │
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │    │    │    │
     *                            │    │    ├────┤    ├────┤    │    │
     *                            │    │    │    │    │    │    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */

    [_NUMERICO] = LAYOUT_ergodox(
        // left hand
        _______, _______,   _______,   _______,   _______,   _______,   _______,
        _______, C(KC_BSLS), _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                            _______, _______,
                                                     _______,
                                   _______, _______, _______,
        // right hand
        _______, _______, _______, KC_PSLS, KC_PAST, KC_KP_MINUS, KC_HOME,
        _______, _______, KC_7, KC_8, KC_9, KC_KP_PLUS,  KC_END,
                 _______, KC_4, KC_5, KC_6, KC_KP_MINUS, KC_PGUP,
        _______, _______, KC_1, KC_2, KC_3, KC_KP_EQUAL, KC_PGDN,
                          KC_0, KC_DOT, KC_ENT,  _______,    _______,
        _______, _______,
        _______,
        _______, _______, _______),


    /* FUNCTION LAYER: Function keys and interaction
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │      │ F1 │ F2 │ F3 │ F4 │ F5 │PrtS│              │    │ F6 │ F7 │ F8 │ F9 │ F11│  F11 │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    │CatP│              │PGUP│    │    │    │    │    │  F12 │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │ CF4├────┤              ├────┤    │    │  ↑ │    │    │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │PGDW├────┼────┼────┼────┼────┼──────┤
     * │      │REDO│UNDO│C C │C V │ C C│C SP│              │    │HOME│  ← │  ↓ │ →  │END │      │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │    │    │    │    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │WbBk│WbFd│    │Prev│Next│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │Vol+│    │    │
     *                            │    │    ├────┤    ├────┤Mute│Play│
     *                            │    │    │    │    │Vol-│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_FN] = LAYOUT_ergodox(
        // left hand
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_PSCR,
        _______, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, SGUI(KC_S),
        _______, _______, _______, _______, _______, M_CF4,
        _______, REDO, UNDO, CUT, PASTE, COPY, C(KC_SPC),
        _______, _______, _______, _______, _______,
                                            KC_WBAK, KC_WFWD,  // Web forward/back
                                                     _______,
                                   _______, _______, _______,
        // right hand
        XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
        KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,
                 XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_PGDN, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, XXXXXXX,
                          _______, _______, _______, _______, _______,
        KC_MPRV, KC_MNXT,
        KC_VOLU,
        KC_VOLD, KC_MUTE, KC_MPLY),

    /* MOUSE: Ratón
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │      │    │    │    │    │    │FLAS│              │FLAS│    │    │    │    │    │      │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │    │ RA │    │    │ A0 │    │              │    │    │    │    │ScUp│ScRt│      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │ RL │ RB │ RR │    │ A1 ├────┤              ├────┤    │ B1 │ B2 │ B3 │    │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │ScUp│ScDt│    │    │ A2 │    │              │    │    │    │    │    │    │      │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │    │    │    │    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │WbBk│WbFd│    │Prev│Next│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │Vol+│    │    │
     *                            │    │    ├────┤    ├────┤Mute│Play│
     *                            │    │    │    │    │Vol-│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_MOUSE] = LAYOUT_ergodox(
        // left hand
        _______,   _______    , _______   , _______       , _______, _______, RESET,
        _______, _______    , KC_MS_UP  , _______       ,  _______, KC_MS_ACCEL0, _______,
        _______, KC_MS_LEFT , KC_MS_DOWN, KC_MS_RIGHT   ,  _______, KC_MS_ACCEL1,
        _______, KC_WH_U    , KC_WH_D   , KC_MS_BTN1  ,  KC_MS_BTN2, KC_MS_ACCEL2, _______,
        _______, _______    , _______   , _______       ,  _______,
                                            KC_WBAK, KC_WFWD,  // Web forward/back
                                                         _______,
                                      _______,  _______, _______,
        // right hand
        RESET, _______,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______,  KC_WH_U, KC_WH_R, _______,
                 _______, KC_MS_BTN1, KC_MS_BTN2,  KC_MS_BTN3, _______, _______,
        _______, _______, _______, _______,   _______,  _______,  _______,
                          _______, _______,  _______, _______,   _______,
        KC_MPRV, KC_MNXT,
        KC_VOLU,
        KC_VOLD, KC_MUTE, KC_MPLY),

    /* Capa ajuste:
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │      │Rese|Debu│    │    │    │    │              │    │    │    │    │    │    │      │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    ├────┤              ├────┤    │    │    │    │    │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │    │                                  │    │    │    │    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │    │    │    │    │    │
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │    │    │    │
     *                            │    │    ├────┤    ├────┤    │    │
     *                            │    │    │    │    │    │    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_ADJUST] = LAYOUT_ergodox(
        // left hand
        _______,RESET, DEBUG, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______,  _______,
                                                _______, _______,
                                                         _______,
                                      _______,  _______, _______,
        // right hand
        _______, _______,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______, _______, _______,
                 _______, _______, KC_VOLD,  KC_VOLU, _______, _______,
        _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_MUTE,  _______,
                          _______, _______,  _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SIMBOLOS, _FN, _ADJUST);
}


bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return true;
        case LALT_T(KC_S):
            return true;
        case LCTL_T(KC_D):
            return true;
        case LSFT_T(KC_F):
            return true;
        case RSFT_T(KC_J):
            return true;
        case RCTL_T(KC_K):
            return true;
        case RALT_T(KC_L):
            return true;
        case RGUI_T(KC_SCLN):
            return true;

        case LALT_T(KC_R):
            return true;
        case LSFT_T(KC_S):
            return true;
        case LCTL_T(KC_T):
            return true;
        case RGUI_T(KC_O):
            return true;
        case RALT_T(KC_I):
            return true;
        case RSFT_T(KC_N):
            return true;
        case RCTL_T(KC_E):
            return true;

        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return true;
        case LALT_T(KC_S):
            return true;
        case LCTL_T(KC_D):
            return true;
        case LSFT_T(KC_F):
            return true;
        case RSFT_T(KC_J):
            return true;
        case RCTL_T(KC_K):
            return true;
        case RALT_T(KC_L):
            return true;
        case LGUI_T(KC_SCLN):
            return true;

        case LALT_T(KC_R):
            return true;
        case LSFT_T(KC_S):
            return true;
        case LCTL_T(KC_T):
            return true;
        case RGUI_T(KC_O):
            return true;
        case RALT_T(KC_I):
            return true;
        case RSFT_T(KC_N):
            return true;
        case RCTL_T(KC_E):
            return true;

        default:
            return false;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return true;
        case LALT_T(KC_S):
            return true;
        case LCTL_T(KC_D):
            return true;
        case LSFT_T(KC_F):
            return true;
        case RSFT_T(KC_J):
            return true;
        case RCTL_T(KC_K):
            return true;
        case RALT_T(KC_L):
            return true;
        case LGUI_T(KC_SCLN):
            return true;

        case LALT_T(KC_R):
            return true;
        case LSFT_T(KC_S):
            return true;
        case LCTL_T(KC_T):
            return true;
        case RGUI_T(KC_O):
            return true;
        case RALT_T(KC_I):
            return true;
        case RSFT_T(KC_N):
            return true;
        case RCTL_T(KC_E):
            return true;

        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LALT_T(KC_S):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LCTL_T(KC_D):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LSFT_T(KC_F):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RSFT_T(KC_J):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RCTL_T(KC_K):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RALT_T(KC_L):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LGUI_T(KC_SCLN):
            return TAPPING_TERM + LONG_TAPPING_TERM;

        case LALT_T(KC_R):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LSFT_T(KC_S):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case LCTL_T(KC_T):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RGUI_T(KC_O):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RALT_T(KC_I):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RSFT_T(KC_N):
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case RCTL_T(KC_E):
            return TAPPING_TERM + LONG_TAPPING_TERM;

        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;
        case RGB_SLD:
            if (record->event.pressed) {
                #ifdef RGBLIGHT_ENABLE
                rgblight_mode(1);
            #endif
            }
            return false;
            break;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void){
    // Start in Linux mode for unicode input
    set_unicode_input_mode(UC_LNX);
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

//     /* Capa Vacia
//      * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
//      * │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
//      * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
//      * │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
//      * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
//      * │      │    │    │    │    │    ├────┤              ├────┤    │    │    │    │    │      │
//      * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
//      * │      │    │    │    │    │    │    │              │    │    │    │    │    │    │      │
//      * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
//      *   │    │    │    │    │    │                                  │    │    │    │    │    │
//      *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
//      *                                 │    │    │    │    │    │
//      *                            ┌────┼────┼────┤    ├────┼────┼────┐
//      *                            │    │    │    │    │    │    │    │
//      *                            │    │    ├────┤    ├────┤    │    │
//      *                            │    │    │    │    │    │    │    │
//      *                            └────┴────┴────┘    └────┴────┴────┘
//      */
//     [_MOUSE] = LAYOUT_ergodox(
//         // left hand
//         _______,   _______, _______, _______, _______, _______, _______,
//         _______, _______, _______,    _______,  _______, _______, _______,
//         _______, _______, _______,    _______,  _______, _______,
//         _______, _______, _______,    _______,  _______, _______, _______,
//         _______, _______, _______,    _______,  _______,
//                                                 _______, _______,
//                                                          _______,
//                                       _______,  _______, _______,
//         // right hand
//         _______, _______,  _______, _______, _______, _______, _______,
//         _______, _______, _______, _______,  _______, _______, _______,
//                  _______, _______, _______,  _______, _______, _______,
//         _______, _______, _______, _______,   _______,  _______,  _______,
//                           _______, _______,  _______, _______,   _______,
//         _______, _______,
//         _______,
//         _______, _______, _______),
