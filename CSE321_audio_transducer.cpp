/**
 * @author Caroline Hart, cmhart2@buffalo.edu
 * @date December 10, 2021
 * @brief This file contains the code used to control the input from the audio transducer
 * @functions:
 *      void setup()
 *      void setState(int state)
 *      int getState()

**/

#ifndef AUDIOTRANSDUCER_H
#include "CSE321_audio_transducer.h"
#endif

CSE321_AudioTransducer::CSE321_AudioTransducer(PinName v_cc, PinName out) {
    _state = OFF;
}

/** setup
 * 
 * @version 1.0
 * @brief enables the clock and port mode registers
 */
void CSE321_AudioTransducer::setup() {
    /* Turn on the AHB2 Peripheral Clock Enable */
    RCC->AHB2ENR |= 0x4;    // bit 2 needs to be set to 1

    /* Set the mode for Vcc to General Purpose Output (01) */
    GPIOC->MODER &= ~(0x80);    // bit 7 needs to be 0
    GPIOC->MODER |= 0x40;       // bit 6 needs to be 1

    /* Set the mode for Output from Audio Transducer to Input mode */
    GPIOC->MODER &= ~(0x300);   // bits 9 and 8 both need to be 0

    /* Turn Vcc on */
    GPIOC->ODR |= 0x8;  // bit 3 needs to be 1

    /* Initialize state as OFF */
    _state = OFF;
}

/** setState
 *
 * @version 1.0
 * @brief set the state of the vibration motor
 * @param state 0 for off, 1 for on
 */ 
void CSE321_AudioTransducer::setState(int state) {
    if (state == OFF || _state == ON) { /* If state is either on or off */
        _state = state; /* Set the state */
    }
}

/** getState
 *
 * @version 1.0
 * @brief fetch the current state of the audio transducer
 * @return 1 if audio transducer is on, 0 otherwise
 */
int CSE321_AudioTransducer::getState() {
    if ((GPIOC->IDR & 0x10) == 0x10) { /* If audio transducer is outputting 1 */
        _state = ON; /* Set state to ON */
    } else if ((GPIOC->IDR & 0x10) == 0) { /* If audio transducer is outputting 0 */
        _state = OFF; /* Set state to OFF*/
    }
    return _state;
}