/**
 * @author Caroline Hart, cmhart2@buffalo.edu
 * @date December 10, 2021
 * @brief This file contains the headers for master control for the device. 
 * @functions: 
 *      void audio_interrupt()
 *      void vibrationResponse()
 *
 * Resources: 
 *      Mbed OS. “Mutex Class,” os.mbed.com [Online] Available: https://os.mbed.com/docs/mbed-os/v6.15/mbed-os-api-doxy/group__rtos___mutex.html#gaa81aed607133209dade63a226818224d. [Accessed Dec. 1, 2021]
 *      Mbed OS. “Semaphore,” os.mbed.com [Online] Available: https://os.mbed.com/docs/mbed-os/v6.15/apis/semaphore.html. [Accessed Dec. 3, 2021]
 *      Mbed OS. “Watchdog,” os.mbed.com [Online] Available: https://os.mbed.com/docs/mbed-os/v6.15/apis/watchdog.html. [Accessed Dec. 1, 2021]
**/

#ifndef AUDIOTRANSDUCER_H
#include "CSE321_audio_transducer.h"
#endif

#ifndef VIBRATIONMOTOR_H
#include "CSE321_vibration_motor.h"
#endif

#ifndef LED_H
#include "CSE321_LED_Blinky.h"
#endif

#ifndef MBED_H
#include "mbed.h"
#endif

#ifndef PINNAMES_H
#include "PinNames.h"
#endif

#include "mbed_wait_api.h"
#include <Watchdog.h>
#include <stdio.h>

#define ONE_SECOND_US 1000000 /* 1 s in microseconds */
#define ONE_SECOND_MS 1000 /* 1 s in miliseconds */

#define RUNNING_FLAG 0000
#define READY_FLAG 0001
#define WAITING_EVENT_FLAG 0010

/* Instanciate Callback Function for Audio Interrupt */
void audio_interrupt();

/** vibrationResponse
 * 
 * @brief this function makes the vibrating motor turn on and off a few times *
 */
void vibrationResponse();