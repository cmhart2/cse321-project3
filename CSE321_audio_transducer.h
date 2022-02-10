/**
 * @author Caroline Hart, cmhart2@buffalo.edu
 * @date December 10, 2021
 * @brief This file contains the headers needed for audio_transducer.cpp
 * @functions:
 *      void setup()
 *      void setState(int state)
 *      int getState()
 * @variable:
 *      private int _state
**/

#ifndef MBED_H
#include "mbed.h"
#endif

#ifndef PINNAMES_H
#include "PinNames.h"
#endif

#define Vcc PC_3
#define OUT PC_4

#ifndef ON
#define ON 1
#define OFF 0
#endif

class CSE321_AudioTransducer {
public:
    /**
     * Constructor
     *
     * @param v_cc Pin to use for the Vcc connection
     * @param out Pin to use for the audio transducer output connection 
     */
     CSE321_AudioTransducer(PinName v_cc = Vcc, PinName out = OUT);


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
      * @brief fetch the current state of the audio transducer
      * @return 1 if audio transducer is on, 0 otherwise
      */
    int getState();
    
private:
    int _state;
};