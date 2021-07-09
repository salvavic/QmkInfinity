/*
Copyright 2017 Fred Sundvik

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

// Currently we are assuming that both the backlight and LCD are enabled
// But it's entirely possible to write a custom visualizer that use only
// one of them
#ifndef LCD_BACKLIGHT_ENABLE
#error This visualizer requires that LCD backlight is enabled
#endif

#ifndef LCD_ENABLE
#error This visualizer requires that LCD is enabled
#endif

#include "./simple_visualizer.h"
#include "util.h"
#include "layers.h"

static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    // Default saturation is 127/255 (50%)
    uint8_t saturation = 127;
    uint8_t intensity = 255;
    // Increase the saturation if Caps Lock is turned on
    if (state->status.leds & (1u << USB_LED_CAPS_LOCK)) {
        saturation = 255;
        intensity = 255;
        state->target_lcd_color = LCD_COLOR(0, saturation, intensity);
    }

    // Set the text and color based on the layout
    switch (biton32(default_layer_state)) {
        case _COLEMAK:
            state->layer_text       = "COLEMAK";
            state->target_lcd_color = LCD_COLOR(200, saturation, intensity);  // yellow=35
            break;

        case _QWERTY:
            state->layer_text       = "QWERTY";
            state->target_lcd_color = LCD_COLOR(0, 0, intensity);  // red
            break;
    }

    // If a function layer is active, set the text/color for that instead
    switch (biton32(state->status.layer)) {
        // case _COLEMAK:
        //     state->layer_text       = "COLEMAK";
        //     state->target_lcd_color = LCD_COLOR(200, saturation, intensity);  // yellow=35
        //     break;

        // case _QWERTY:
        //     state->layer_text       = "QWERTY";
        //     state->target_lcd_color = LCD_COLOR(0, 0, intensity);  // red
        //     break;

        case _MOUSE:
            state->layer_text       = "RATON";
            state->target_lcd_color = LCD_COLOR(160, saturation, intensity);  // purple
            break;
        case _FN:
            state->layer_text       = "FUNCION";
            state->target_lcd_color = LCD_COLOR(80, saturation, intensity);
            break;
        case _SIMBOLOS:
            state->layer_text       = "SIMBOLOS";
            state->target_lcd_color = LCD_COLOR(0, saturation, intensity);
            break;
        case _NUMERICO:
            state->layer_text       = "TEC NUMERICO";
            state->target_lcd_color = LCD_COLOR(20, saturation, intensity);
            break;

        default:
            // If we're not on one of the special layers, don't change
            // (so we'll show the default layer state, set above)
            break;
    }
}
