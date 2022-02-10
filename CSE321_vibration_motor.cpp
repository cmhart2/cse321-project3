/**
 * @author Caroline Hart, cmhart2@buffalo.edu
 * @date December 10, 2021
 * @brief This file contains the code to control the output vibration motor
 * @functions:
 *      void setup()
 *      void setState(int state)
 *      int getState()
**/

#ifndef VIBRATIONMOTOR_H
#include "CSE321_vibration_motor.h"
#endif

/* Constructor */
CSE321_VibrationMotor::CSE321_VibrationMotor(PinName pin) {
    _state = OFF;
}

/** setup
 * 
 * @brief enables the clock and port mode registers
 * @version 1.0
 */
void CSE321_VibrationMotor::setup() {
    /* Turn on the AHB2 Peripheral Clock Enable */
    RCC->AHB2ENR |= 0x4;    // bit 2 needs to be set to 1

    /* Set the mode to General Purpose Output (01) */
    GPIOC->MODER |= 0x1;    // bit 0 needs to be 1
    GPIOC->MODER &= ~(0x2); // bit 1 needs to be 0
}

/** setState
 *
 * @brief set the state of the vibration motor
 * @version 1.0
 * @param state 0 for off, 1 for on
 */ 
void CSE321_VibrationMotor::setState(int state) {
    if (state == OFF) {         /* OFF */
        GPIOC->ODR &= ~(0x1);   // bit 0 needs to be 0
        _state = state;         // set state to OFF
    }
    else if (state == ON) {     /* ON */
        GPIOC->ODR |= 0x1;      // bit 0 needs to be 1
        _state = state;         // set state to ON
    }
}

/** getState
 *
 * @brief gets the current state of the vibration motor
 * @version 1.0
 * @return 0 if the motor is off, 1 if the motor is on
 */
int CSE321_VibrationMotor::getState() {
    return _state;
}