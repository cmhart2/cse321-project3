/**
 * @author Caroline Hart, cmhart2@buffalo.edu
 * @date December 10, 2021
 * @brief This file contains the headers needed for vibration_motor.cpp
 * @functions:
 *      void setup()
 *      void setState(int state)
 *      int getState()
 * @variable:
 *      private int _state
**/

#ifndef PINNAMES_H
#include "PinNames.h"
#endif

#ifndef MBED_H
#include "mbed.h"
#endif

#define V_in PC_0

#ifndef ON
#define ON 1
#define OFF 0
#endif

class CSE321_VibrationMotor {
public:
    /**
     * Constructor
     * 
     * @param pin   Pin to use for the Vcc connection of the Vibration Motor
     */
     CSE321_VibrationMotor(PinName pin = PC_0);

    /** setup
     *
     * @brief enables the clock and port mode registers
     */
    void setup();

    /** setState
     *
     * @brief set the state of the vibration motor
     * @param state 0 for off, 1 for on
     */ 
    void setState(int state);

    /** getState
     *
     * @brief gets the current state of the vibration motor
     * @return 0 if the motor is off, 1 if the motor is on
     */
    int getState();

private:
    int _state;
};