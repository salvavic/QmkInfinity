#include QMK_KEYBOARD_H
#include "version.h"
#include "layers.h"
#include "keymap_spanish.h"
//#define UNICODE_SELECTED_MODES UC_LNX 


#define _QWERTY     0  // default QWERTY base layer
#define _COLEMAK    1  // default QWERTY base layer
#define _FN         2  // Capa Funciones
#define _SIMBOLOS   3  // Capa SIMBOLOS
#define _MOUSE      4  // Capa RATON
#define _NUMERICO   5  // Capa Teclado Numerico

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,  // can always be here
    EPRM,
    VRSN,
    RGB_SLD,
    QWERTY,
    COLEMAK,
    MCO,MCOD, // Comentarios en visual studio
    MSW
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
    TD_INT, TD_EXC, TD_ANG, TD_LLA, TD_PAR, TD_PAC, TD_DOT, TD_MAY
};

#define QWERTY DF(_QWERTY)
#define COLEMA DF(_COLEMAK)
#define FN MO(_FN)
#define FNDEL LT(_FN, KC_DEL)
#define SIMBO MO(_SIMBOLOS)
#define SIMBOENT LT(_SIMBOLOS, KC_ENTER)
#define MOUSE MO(_MOUSE)
#define NUMERIC MO(_NUMERICO)

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

/* const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DELETE); */
/* const key_override_t bspace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DELETE, KC_BSPC); */

/* const key_override_t **key_overrides = (const key_override_t *[]){ */
/*     &delete_key_override, */
/*     &bspace_key_override, */
/*     NULL // Null terminate the array of overrides! */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE (QWERTY)
     *
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │ ESC  │  1 │  2 │  3 │  4 │  5 │CLMK│              │TNUM│  6 │  7 │  8 │  9 │  0 │  '   │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │ TAB  │  Q │  W │  E │  R │  T │MOUS│              │MOUS│  Y │  U │  I │  O │  P │  `   │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │BLOQM │  A │  S │  D │  F │  G ├────┤              ├────┤  H │  J │  K │  L │  Ñ │ Entr │
     * ├──────┼────┼────┼────┼────┼────┤  º │              │FN  ├────┼────┼────┼────┼────┼──────┤
     * │MAYUS │  Z │  X │  C │  V │  B │    │              │    │  N │  M │  , │  . │  - │MAYUS │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │LCtl│LGUI|Num │ FN │SIMB│                                  │SIMB│ FN │MOUS│    │    │
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │Home│ End│    │RAlt│RCtl│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │PGUP│    │INS │    │    │
     *                            │ [] │ Del├────┤    ├────┤Entr│ [] │
     *                            │    │    │PGDO│    │MENU│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_QWERTY] = LAYOUT_ergodox(  // QWERTY persistent layer
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5, COLEMA,
        KC_CAPS,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    TG(_MOUSE),
        KC_TAB, HOME_A,    LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),      KC_G,
        TD(TD_MAY), KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    ES_MORD,
        KC_LCTL, LALT_T(KC_LGUI), NUMERIC, FNDEL,  SIMBOENT,
                                            KC_HOME, KC_END,
                                                       KC_PGUP,
                                   KC_SPC, KC_DEL,    KC_PGDN,
        // right hand
        TG(_NUMERICO), KC_6, KC_7, KC_8, KC_9,KC_0, KC_BSPC,
        TG(_MOUSE), KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
                 KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), KC_SCLN,  KC_QUOT,
        TG(_FN), KC_N, KC_M, TD(TD_PC), KC_DOT,  KC_SLSH,  KC_ENT,
                            SIMBOENT, FNDEL, NUMERIC, KC_RALT, KC_RGUI,
                                    KC_RALT, KC_RCTL,
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
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5, DF(_QWERTY),
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,      KC_G, TT(_MOUSE),
        KC_CAPS, LGUI_T(KC_A),    LALT_T(KC_R),    LCTL_T(KC_S),    LSFT_T(KC_T),      KC_D,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B, ES_MORD,
        KC_LCTL, LALT_T(KC_LGUI), TT(_NUMERICO), TT(_FN),  TT(_SIMBOLOS),
                                            KC_HOME, KC_END,
                                                       KC_PGUP,
                                   KC_BSPC, KC_DEL,    KC_PGDN,
        // right hand
        TG(_NUMERICO), KC_6, KC_7, KC_8, KC_9,KC_0, KC_BSPC,
        TG(_MOUSE), KC_J,     KC_L,    KC_U,     KC_Y,    KC_SCLN,  KC_LBRC,
                 KC_H,     RSFT_T(KC_N),    RCTL_T(KC_E),     RALT_T(KC_I),    KC_O, KC_QUOT,
        TG(_FN), KC_K, KC_M, TD(TD_PC), TD(TD_DOT),  KC_SLSH,  KC_ENT,
                            TT(_SIMBOLOS), TT(_FN), TG(_MOUSE), KC_RALT, KC_RCTL,
        KC_RALT, KC_RCTL,
        KC_INS,
        KC_APP, KC_ENT,   KC_SPC),

/* SIMBOLOS : Simbolos2
     * ┌──────┬────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┬──────┐
     * │      │    │    │    │    │    │ [  │              │ ]  │    │    │    │    │    │      │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │      │  = │  * │  + │  @ │  \ │ {  │              │ }  │ €  │  $ │  [ │ ]  │ º  │  ´   │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │  " │  ' │  / │  & │  | ├────┤              ├────┤ ¡  │  ! │  ( │ )  │ '  │      │
     * ├──────┼────┼────┼────┼────┼────┤ (  │              │ )  ├────┼────┼────┼────┼────┼──────┤
     * │      │ <  │ >  │  % │  - │  # │    │              │    │ ¿  │  ? │  { │ }  │ `  │      │
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
        _______, S(KC_0),S(KC_RBRC),KC_RBRC,ALGR(KC_2),ALGR(KC_GRV), ES_LCBR,
        _______, S(KC_2), KC_MINS, S(KC_7), S(KC_6),ALGR(KC_1),
        _______, KC_NUBS,S(KC_NUBS),S(KC_5), KC_SLSH,ALGR(KC_3), S(KC_8),
        _______, _______, _______, _______, _______,
                                            _______, _______,
                                                     _______,
                                   _______, _______, _______,
        // right hand
        ES_RBRC, _______,_______,_______,_______,_______, KC_DEL,
        ES_RCBR, ALGR(KC_5),S(KC_4),ALGR(KC_LBRC),ALGR(KC_RBRC),KC_GRV,_______,
                 KC_EQL, S(KC_1),  S(KC_8),S(KC_9), KC_MINS, S(KC_LBRC),
        ES_RPRN, S(KC_EQL),S(KC_MINS),ALGR(KC_QUOT), ALGR(KC_NUHS),KC_LBRC, KC_GRV,
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
        _______, _______, KC_LALT, _______, _______, _______,
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
     * │ CatP │ F1 │ F2 │ F3 │ F4 │ F5 │PrtS│              │    │ F6 │ F7 │ F8 │ F9 │ F11│  F11 │
     * ├──────┼────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┼──────┤
     * │ App  │C_kc│C_ku│swag│    │    │CatP│              │PGUP│    │    │    │    │    │  F12 │
     * ├──────┼────┼────┼────┼────┼────┤    │              │    ├────┼────┼────┼────┼────┼──────┤
     * │      │    │    │    │    │ CF4├────┤              ├────┤    │    │  ↑ │    │    │      │
     * ├──────┼────┼────┼────┼────┼────┤    │              │PGDW├────┼────┼────┼────┼────┼──────┤
     * │      │REDO│UNDO│C C │C V │ C C│C SP│              │    │HOME│  ← │  ↓ │ →  │END │      │
     * └─┬────┼────┼────┼────┼────┼────┴────┘              └────┴────┼────┼────┼────┼────┼────┬─┘
     *   │    │    │    │    │BACK│                                  │    │    │    │    │    │
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
        C(KC_PSCR), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_PSCR,
        KC_APP, MCO, MCOD, MSW , XXXXXXX, XXXXXXX, SGUI(KC_S),
        _______, _______, _______, _______, _______, M_CF4,
        G(KC_TAB), G(C(KC_LEFT)), G(C(KC_RIGHT)), _______, _______, _______, C(KC_SPC),
        _______, _______, _______, _______, KC_BSPC,
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
        _______,   _______    , _______   , _______       , _______, _______, QK_BOOT,
        _______, _______    , KC_MS_UP  , _______       ,  _______, KC_MS_ACCEL0, _______,
        _______, KC_MS_LEFT , KC_MS_DOWN, KC_MS_RIGHT   ,  _______, KC_MS_ACCEL1,
        _______, KC_WH_U    , KC_WH_D   , KC_MS_BTN1  ,  KC_MS_BTN2, KC_MS_ACCEL2, _______,
        _______, _______    , _______   , _______       ,  _______,
                                            KC_WBAK, KC_WFWD,  // Web forward/back
                                                         _______,
                                      _______,  _______, _______,
        // right hand
        QK_BOOT, _______,  _______, _______, _______, _______, _______,
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
     *   │    │    │    │    │    │                                  │    │    │    │    │CS(m│
     *   └────┴────┴────┴────┴────┘    ┌────┬────┐    ┌────┬────┐    └────┴────┴────┴────┴────┘
     *                                 │WbBk│WbFd│    │Prev│Next│
     *                            ┌────┼────┼────┤    ├────┼────┼────┐
     *                            │    │    │    │    │Vol+│    │    │
     *                            │    │    ├────┤    ├────┤Mute│Play│
     *                            │    │    │    │    │Vol-│    │    │
     *                            └────┴────┴────┘    └────┴────┴────┘
     */
    [_ADJUST] = LAYOUT_ergodox(
        // left hand
        _______,QK_BOOT, DB_TOGG, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______,  _______,
                                            KC_WBAK, KC_WFWD,
                                                         _______,
                                      _______,  _______, _______,
        // right hand
        _______, _______,  _______, _______, _______, _______, _______,
        _______, _______, _______, _______,  _______, _______, _______,
                 _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______,  _______,
                          _______, _______,  _______, _______, RCS(KC_M),
        KC_MPRV, KC_MNXT,
        KC_VOLU,
        KC_VOLD, KC_MUTE, KC_MPLY),
};

tap_dance_action_t tap_dance_actions[] = {
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
  [TD_11] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_F11),
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
  [TD_MAY] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SIMBOLOS, _FN, _ADJUST);
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

        case MCO:
            if (record->event.pressed) {
                // when keycode MCOMENT is pressed
                SEND_STRING(SS_DOWN(X_LCTL)"kc");
            } else {
                // when keycode MCOMENT is released
            }
            break;
        case MCOD:
            if (record->event.pressed) {
                // when keycode MCOMENT is pressed
                SEND_STRING(SS_DOWN(X_LCTL)"ku");
            } else {
                // when keycode MCOMENT is released
            }
            break;

        case MSW:
            if (record->event.pressed) {
                // when keycode MCOMENT is pressed
                SEND_STRING("swagger-ui");
            } else {
                // when keycode MCOMENT is released
            }
            break;

    }
    return true;
}

// Runs just one time when the keyboard initializes.
//void matrix_init_user(void){
    // Start in Linux mode for unicode input
//    set_unicode_input_mode(UC_LNX);
//};

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

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
            return true;
        case HOME_S:
            return true;
        case HOME_D:
            return true;
        case HOME_F:
            return true;
        case HOME_J:
            return true;
        case HOME_K:
            return true;
        case HOME_L:
            return true;
        case HOME_NT:
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
        case HOME_A:
            return true;
        case HOME_S:
            return true;
        case HOME_D:
            return true;
        case HOME_F:
            return true;
        case HOME_J:
            return true;
        case HOME_K:
            return true;
        case HOME_L:
            return true;
        case HOME_NT:
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
        case HOME_A:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_S:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_D:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_F:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_J:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_K:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_L:
            return TAPPING_TERM + LONG_TAPPING_TERM;
        case HOME_NT:
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

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_QWERTY 0
#define L_SIMBOLOS 8
#define L_FN 4
#define L_NUMERICO 32
#define L_ADJUST 64

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case L_SIMBOLOS:
            oled_write_ln_P(PSTR("SIMB"), false);
            break;
        case L_FN:
            oled_write_ln_P(PSTR("FN"), false);
            break;
        case L_NUMERICO:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case L_ADJUST:
            oled_write_ln_P(PSTR("AJUSTE"), false);
            break;
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        //oled_render_logo();
        oled_render_layer_state();
        oled_render_keylog();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE
