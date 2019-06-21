/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Scott Shawcroft for Adafruit Industries
 * Copyright (c) 2016 Damien P. George
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

#include <stdint.h>

#include "py/runtime.h"
#include "common-hal/pulseio/PWMOut.h"
#include "shared-bindings/pulseio/PWMOut.h"
#include "shared-bindings/microcontroller/Processor.h"




void common_hal_pulseio_pwmout_never_reset(pulseio_pwmout_obj_t *self) {
    // if (self->timer->is_tc) {
    //     never_reset_tc_or_tcc[self->timer->index] += 1;
    // } else {
    //     never_reset_tc_or_tcc[TC_INST_NUM + self->timer->index] += 1;
    // }

    // never_reset_pin_number(self->pin->number);
}

void common_hal_pulseio_pwmout_reset_ok(pulseio_pwmout_obj_t *self) {
    // if (self->timer->is_tc) {
    //     never_reset_tc_or_tcc[self->timer->index] -= 1;
    // } else {
    //     never_reset_tc_or_tcc[TC_INST_NUM + self->timer->index] -= 1;
    // }
}


pwmout_result_t common_hal_pulseio_pwmout_construct(pulseio_pwmout_obj_t* self,
                                                    const mcu_pin_obj_t* pin,
                                                    uint16_t duty,
                                                    uint32_t frequency,
                                                    bool variable_frequency) {
//     self->pin = pin;
//     self->variable_frequency = variable_frequency;

//     if (pin->timer[0].index >= TC_INST_NUM &&
//         pin->timer[1].index >= TCC_INST_NUM
// #ifdef SAMD51
//         && pin->timer[2].index >= TCC_INST_NUM
// #endif
//         ) {
//         return PWMOUT_INVALID_PIN;
//     }

//     if (frequency == 0 || frequency > 6000000) {
//         return PWMOUT_INVALID_FREQUENCY;
//     }

//     // Figure out which timer we are using.

//     // First see if a tcc is already going with the frequency we want and our
//     // channel is unused. tc's don't have enough channels to share.
//     const pin_timer_t* timer = NULL;
//     uint8_t mux_position = 0;
//     if (!variable_frequency) {
//         for (uint8_t i = 0; i < TCC_INST_NUM && timer == NULL; i++) {
//             if (target_tcc_frequencies[i] != frequency) {
//                 continue;
//             }
//             for (uint8_t j = 0; j < NUM_TIMERS_PER_PIN && timer == NULL; j++) {
//                 const pin_timer_t* t = &pin->timer[j];
//                 if (t->index != i || t->is_tc || t->index >= TCC_INST_NUM) {
//                     continue;
//                 }
//                 Tcc* tcc = tcc_insts[t->index];
//                 if (tcc->CTRLA.bit.ENABLE == 1 && channel_ok(t)) {
//                     timer = t;
//                     mux_position = j;
//                     // Claim channel.
//                     tcc_channels[timer->index] |= (1 << tcc_channel(timer));

//                 }
//             }
//         }
//     }

//     // No existing timer has been found, so find a new one to use and set it up.
//     if (timer == NULL) {
//         // By default, with fixed frequency we want to share a TCC because its likely we'll have
//         // other outputs at the same frequency. If the frequency is variable then we'll only have
//         // one output so we start with the TCs to see if they work.
//         int8_t direction = -1;
//         uint8_t start = NUM_TIMERS_PER_PIN - 1;
//         bool found = false;
//         if (variable_frequency) {
//             direction = 1;
//             start = 0;
//         }
//         for (int8_t i = start; i >= 0 && i < NUM_TIMERS_PER_PIN && timer == NULL; i += direction) {
//             const pin_timer_t* t = &pin->timer[i];
//             if ((!t->is_tc && t->index >= TCC_INST_NUM) ||
//                 (t->is_tc && t->index >= TC_INST_NUM)) {
//                 continue;
//             }
//             if (t->is_tc) {
//                 found = true;
//                 Tc* tc = tc_insts[t->index];
//                 if (tc->COUNT16.CTRLA.bit.ENABLE == 0 && t->wave_output == 1) {
//                     timer = t;
//                     mux_position = i;
//                 }
//             } else {
//                 Tcc* tcc = tcc_insts[t->index];
//                 if (tcc->CTRLA.bit.ENABLE == 0 && channel_ok(t)) {
//                     timer = t;
//                     mux_position = i;
//                 }
//             }
//         }

//         if (timer == NULL) {
//             if (found) {
//                 return PWMOUT_ALL_TIMERS_ON_PIN_IN_USE;
//             }
//             return PWMOUT_ALL_TIMERS_IN_USE;
//         }

//         uint8_t resolution = 0;
//         if (timer->is_tc) {
//             resolution = 16;
//         } else {
//             // TCC resolution varies so look it up.
//             const uint8_t _tcc_sizes[TCC_INST_NUM] = TCC_SIZES;
//             resolution = _tcc_sizes[timer->index];
//         }
//         // First determine the divisor that gets us the highest resolution.
//         uint32_t system_clock = common_hal_mcu_processor_get_frequency();
//         uint32_t top;
//         uint8_t divisor;
//         for (divisor = 0; divisor < 8; divisor++) {
//             top = (system_clock / prescaler[divisor] / frequency) - 1;
//             if (top < (1u << resolution)) {
//                 break;
//             }
//         }

//         set_timer_handler(timer->is_tc, timer->index, TC_HANDLER_NO_INTERRUPT);
//         // We use the zeroeth clock on either port to go full speed.
//         turn_on_clocks(timer->is_tc, timer->index, 0);

//         if (timer->is_tc) {
//             tc_periods[timer->index] = top;
//             Tc* tc = tc_insts[timer->index];
//             #ifdef SAMD21
//             tc->COUNT16.CTRLA.reg = TC_CTRLA_MODE_COUNT16 |
//                                     TC_CTRLA_PRESCALER(divisor) |
//                                     TC_CTRLA_WAVEGEN_MPWM;
//             tc->COUNT16.CC[0].reg = top;
//             #endif
//             #ifdef SAMD51

//             tc->COUNT16.CTRLA.bit.SWRST = 1;
//             while (tc->COUNT16.CTRLA.bit.SWRST == 1) {
//             }
//             tc_set_enable(tc, false);
//             tc->COUNT16.CTRLA.reg = TC_CTRLA_MODE_COUNT16 | TC_CTRLA_PRESCALER(divisor);
//             tc->COUNT16.WAVE.reg = TC_WAVE_WAVEGEN_MPWM;
//             tc->COUNT16.CCBUF[0].reg = top;
//             tc->COUNT16.CCBUF[1].reg = 0;
//             #endif

//             tc_set_enable(tc, true);
//         } else {
//             tcc_periods[timer->index] = top;
//             Tcc* tcc = tcc_insts[timer->index];
//             tcc_set_enable(tcc, false);
//             tcc->CTRLA.bit.PRESCALER = divisor;
//             tcc->PER.bit.PER = top;
//             tcc->WAVE.bit.WAVEGEN = TCC_WAVE_WAVEGEN_NPWM_Val;
//             tcc_set_enable(tcc, true);
//             target_tcc_frequencies[timer->index] = frequency;
//             tcc_refcount[timer->index]++;
//             if (variable_frequency) {
//                 // We're changing frequency so claim all of the channels.
//                 tcc_channels[timer->index] = 0xff;
//             } else {
//                 tcc_channels[timer->index] |= (1 << tcc_channel(timer));
//             }
//         }
//     }

//     self->timer = timer;

//     gpio_set_pin_function(pin->number, GPIO_PIN_FUNCTION_E + mux_position);

//     common_hal_pulseio_pwmout_set_duty_cycle(self, duty);
    return PWMOUT_OK;
}

bool common_hal_pulseio_pwmout_deinited(pulseio_pwmout_obj_t* self) {
    return self->pin == mp_const_none;
}

void common_hal_pulseio_pwmout_deinit(pulseio_pwmout_obj_t* self) {
    // if (common_hal_pulseio_pwmout_deinited(self)) {
    //     return;
    // }
    // const pin_timer_t* t = self->timer;
    // if (t->is_tc) {
    //     Tc* tc = tc_insts[t->index];
    //     tc_set_enable(tc, false);
    //     tc->COUNT16.CTRLA.bit.SWRST = true;
    //     tc_wait_for_sync(tc);
    // } else {
    //     tcc_refcount[t->index]--;
    //     tcc_channels[t->index] &= ~(1 << tcc_channel(t));
    //     if (tcc_refcount[t->index] == 0) {
    //         target_tcc_frequencies[t->index] = 0;
    //         Tcc* tcc = tcc_insts[t->index];
    //         tcc_set_enable(tcc, false);
    //         tcc->CTRLA.bit.SWRST = true;
    //         while (tcc->SYNCBUSY.bit.SWRST != 0) {
    //             /* Wait for sync */
    //         }
    //     }
    // }
    // reset_pin_number(self->pin->number);
    self->pin = mp_const_none;
}

extern void common_hal_pulseio_pwmout_set_duty_cycle(pulseio_pwmout_obj_t* self, uint16_t duty) {
//     const pin_timer_t* t = self->timer;
//     if (t->is_tc) {
//         uint16_t adjusted_duty = tc_periods[t->index] * duty / 0xffff;
//         #ifdef SAMD21
//         tc_insts[t->index]->COUNT16.CC[t->wave_output].reg = adjusted_duty;
//         #endif
//         #ifdef SAMD51
//         Tc* tc = tc_insts[t->index];
//         while (tc->COUNT16.SYNCBUSY.bit.CC1 != 0) {}
//         tc->COUNT16.CCBUF[1].reg = adjusted_duty;
//         #endif
//     } else {
//         uint32_t adjusted_duty = ((uint64_t) tcc_periods[t->index]) * duty / 0xffff;
//         uint8_t channel = tcc_channel(t);
//         Tcc* tcc = tcc_insts[t->index];

//         // Write into the CC buffer register, which will be transferred to the
//         // CC register on an UPDATE (when period is finished).
//         // Do clock domain syncing as necessary.

//         while (tcc->SYNCBUSY.reg != 0) {}

//         // Lock out double-buffering while updating the CCB value.
//         tcc->CTRLBSET.bit.LUPD = 1;
//         #ifdef SAMD21
//         tcc->CCB[channel].reg = adjusted_duty;
//         #endif
//         #ifdef SAMD51
//         tcc->CCBUF[channel].reg = adjusted_duty;
//         #endif
//         tcc->CTRLBCLR.bit.LUPD = 1;
//     }
}

uint16_t common_hal_pulseio_pwmout_get_duty_cycle(pulseio_pwmout_obj_t* self) {
    // const pin_timer_t* t = self->timer;
    // if (t->is_tc) {
    //     Tc* tc = tc_insts[t->index];
    //     tc_wait_for_sync(tc);
    //     uint16_t cv = tc->COUNT16.CC[t->wave_output].reg;
    //     return cv * 0xffff / tc_periods[t->index];
    // } else {
    //     Tcc* tcc = tcc_insts[t->index];
    //     uint8_t channel = tcc_channel(t);
    //     uint32_t cv = 0;

    //     while (tcc->SYNCBUSY.bit.CTRLB) {}

    //     #ifdef SAMD21
    //     // If CCBV (CCB valid) is set, the CCB value hasn't yet been copied
    //     // to the CC value.
    //     if ((tcc->STATUS.vec.CCBV & (1 << channel)) != 0) {
    //         cv = tcc->CCB[channel].reg;
    //     } else {
    //         cv = tcc->CC[channel].reg;
    //     }
    //     #endif
    //     #ifdef SAMD51
    //     if ((tcc->STATUS.vec.CCBUFV & (1 << channel)) != 0) {
    //         cv = tcc->CCBUF[channel].reg;
    //     } else {
    //         cv = tcc->CC[channel].reg;
    //     }
    //     #endif

    //     uint32_t duty_cycle = ((uint64_t) cv) * 0xffff / tcc_periods[t->index];

    //     return duty_cycle;
    // }
}


void common_hal_pulseio_pwmout_set_frequency(pulseio_pwmout_obj_t* self,
                                              uint32_t frequency) {
    // if (frequency == 0 || frequency > 6000000) {
    //     mp_raise_ValueError(translate("Invalid PWM frequency"));
    // }
    // const pin_timer_t* t = self->timer;
    // uint8_t resolution;
    // if (t->is_tc) {
    //     resolution = 16;
    // } else {
    //     resolution = 24;
    // }
    // uint32_t system_clock = common_hal_mcu_processor_get_frequency();
    // uint32_t new_top;
    // uint8_t new_divisor;
    // for (new_divisor = 0; new_divisor < 8; new_divisor++) {
    //     new_top = (system_clock / prescaler[new_divisor] / frequency) - 1;
    //     if (new_top < (1u << resolution)) {
    //         break;
    //     }
    // }
    // uint16_t old_duty = common_hal_pulseio_pwmout_get_duty_cycle(self);
    // if (t->is_tc) {
    //     Tc* tc = tc_insts[t->index];
    //     uint8_t old_divisor = tc->COUNT16.CTRLA.bit.PRESCALER;
    //     if (new_divisor != old_divisor) {
    //         tc_set_enable(tc, false);
    //         tc->COUNT16.CTRLA.bit.PRESCALER = new_divisor;
    //         tc_set_enable(tc, true);
    //     }
    //     tc_periods[t->index] = new_top;
    //     #ifdef SAMD21
    //     tc->COUNT16.CC[0].reg = new_top;
    //     #endif
    //     #ifdef SAMD51
    //     while (tc->COUNT16.SYNCBUSY.reg != 0) {}
    //     tc->COUNT16.CCBUF[0].reg = new_top;
    //     #endif
    // } else {
    //     Tcc* tcc = tcc_insts[t->index];
    //     uint8_t old_divisor = tcc->CTRLA.bit.PRESCALER;
    //     if (new_divisor != old_divisor) {
    //         tcc_set_enable(tcc, false);
    //         tcc->CTRLA.bit.PRESCALER = new_divisor;
    //         tcc_set_enable(tcc, true);
    //     }
    //     while (tcc->SYNCBUSY.reg != 0) {}
    //     tcc_periods[t->index] = new_top;
    //     #ifdef SAMD21
    //     tcc->PERB.bit.PERB = new_top;
    //     #endif
    //     #ifdef SAMD51
    //     tcc->PERBUF.bit.PERBUF = new_top;
    //     #endif
    // }

    // common_hal_pulseio_pwmout_set_duty_cycle(self, old_duty);
}

uint32_t common_hal_pulseio_pwmout_get_frequency(pulseio_pwmout_obj_t* self) {
    // uint32_t system_clock = common_hal_mcu_processor_get_frequency();
    // const pin_timer_t* t = self->timer;
    // uint8_t divisor;
    // uint32_t top;
    // if (t->is_tc) {
    //     divisor = tc_insts[t->index]->COUNT16.CTRLA.bit.PRESCALER;
    //     top = tc_periods[t->index];
    // } else {
    //     divisor = tcc_insts[t->index]->CTRLA.bit.PRESCALER;
    //     top = tcc_periods[t->index];
    // }
    // return (system_clock / prescaler[divisor]) / (top + 1);
    return 0;
}

bool common_hal_pulseio_pwmout_get_variable_frequency(pulseio_pwmout_obj_t* self) {
    return self->variable_frequency;
}