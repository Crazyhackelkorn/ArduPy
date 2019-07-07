/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Scott Shawcroft for Adafruit Industries
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "py/mphal.h"
#include "py/runtime.h"
#include <stdint.h>
#include <string.h>

#include "common-hal/microcontroller/Pin.h"
#include "shared-bindings/digitalio/DigitalInOut.h"

digitalinout_result_t common_hal_digitalio_digitalinout_construct(digitalio_digitalinout_obj_t *self, const mcu_pin_obj_t *pin) {
    claim_pin(pin);
    self->pin = pin;
    self->output = false;
    self->open_drain = false;

    return DIGITALINOUT_OK;
}

void common_hal_digitalio_digitalinout_never_reset(digitalio_digitalinout_obj_t *self) {}

bool common_hal_digitalio_digitalinout_deinited(digitalio_digitalinout_obj_t *self) { return self->pin == mp_const_none; }

void common_hal_digitalio_digitalinout_deinit(digitalio_digitalinout_obj_t *self) {
    if (common_hal_digitalio_digitalinout_deinited(self)) {
        return;
    }
    reset_pin_number(self->pin->number);
    self->pin = mp_const_none;
}

void common_hal_digitalio_digitalinout_switch_to_input(digitalio_digitalinout_obj_t *self, digitalio_pull_t pull) {

    self->output = false;
    pinMode(self->pin->number, INPUT);
}

void common_hal_digitalio_digitalinout_switch_to_output(digitalio_digitalinout_obj_t *self, bool value, digitalio_drive_mode_t drive_mode) {

    self->output = true;
    self->open_drain = drive_mode == DRIVE_MODE_OPEN_DRAIN;
    pinMode(self->pin->number, OUTPUT);
}

digitalio_direction_t common_hal_digitalio_digitalinout_get_direction(digitalio_digitalinout_obj_t *self) {
    return self->output ? DIRECTION_OUTPUT : DIRECTION_INPUT;
}

void common_hal_digitalio_digitalinout_set_value(digitalio_digitalinout_obj_t *self, bool value) { digitalWrite(self->pin->number, value); }

bool common_hal_digitalio_digitalinout_get_value(digitalio_digitalinout_obj_t *self) { return digitalRead(self->pin->number); }

void common_hal_digitalio_digitalinout_set_drive_mode(digitalio_digitalinout_obj_t *self, digitalio_drive_mode_t drive_mode) {}

digitalio_drive_mode_t common_hal_digitalio_digitalinout_get_drive_mode(digitalio_digitalinout_obj_t *self) { return DRIVE_MODE_PUSH_PULL; }

void common_hal_digitalio_digitalinout_set_pull(digitalio_digitalinout_obj_t *self, digitalio_pull_t pull) {

    switch (pull) {
    case PULL_UP:
        pinMode(self->pin->number, INPUT_PULLUP);
        self->pin_mode = PULL_UP;
        break;
    case PULL_DOWN:
        pinMode(self->pin->number, INPUT_PULLDOWN);
        self->pin_mode = PULL_DOWN;
        break;
    case PULL_NONE:
        pinMode(self->pin->number, OUTPUT);
        self->pin_mode = PULL_NONE;
    default:
        break;
    }
}

digitalio_pull_t common_hal_digitalio_digitalinout_get_pull(digitalio_digitalinout_obj_t *self) {
    if (self->output) {
        mp_raise_AttributeError("Cannot get pull while in output mode");
        return PULL_NONE;
    } else {
        return self->pin_mode;
    }
}
