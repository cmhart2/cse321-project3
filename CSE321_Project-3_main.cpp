/**
 * @author Caroline Hart, cmhart2@buffalo.edu
 * @date December 10, 2021
 * @brief This file is the master control for the device. 
 * @functions: 
 *      void audio_interrupt()
 *      void vibrationResponse()
 *
 * Resources: 
 *      Mbed OS. “Mutex Class,” os.mbed.com [Online] Available: https://os.mbed.com/docs/mbed-os/v6.15/mbed-os-api-doxy/group__rtos___mutex.html#gaa81aed607133209dade63a226818224d. [Accessed Dec. 1, 2021]
 *      Mbed OS. “Semaphore,” os.mbed.com [Online] Available: https://os.mbed.com/docs/mbed-os/v6.15/apis/semaphore.html. [Accessed Dec. 3, 2021]
 *      Mbed OS. “Watchdog,” os.mbed.com [Online] Available: https://os.mbed.com/docs/mbed-os/v6.15/apis/watchdog.html. [Accessed Dec. 1, 2021]
**/

#include "CSE321_Project-3_main.h"
#include <cstdio>

/* Instanciate Vibration Motor */
CSE321_VibrationMotor vibratingMotor(V_in);

/* Instanciate Audio Transducer */
CSE321_AudioTransducer audioTransducer(Vcc, OUT);

/* Instanciate Threads */
Thread response;

/* Instanciate EventQueue */
EventQueue q(32*EVENTS_EVENT_SIZE);

/* Instanciate Audio Interrupt */
InterruptIn audio_signal(OUT);

/* Instanciate Semaphore */
Semaphore semaphore(1);

bool is_acquired = 0;

/** main
 *
 * @version 1.2
 */
int main() {
    /* Acquire Semaphore to mark Critical Resources as In-Use */
    semaphore.acquire();

    /* Initialize the Watchdog */
    Watchdog &watchdog = Watchdog::get_instance();

    /* Start the watchdog with a maximum timeout time */
    watchdog.start(watchdog.get_max_timeout());
    //unsigned long watchdog_timeout = watchdog.get_timeout()*100;
    //printf("   --- Watchdog initialized to %lu s. ---\r\n", watchdog_timeout);

    /* Initialize the vibration motor */
    vibratingMotor.setup();
    //vibratingMotor.setState(ON);
    //wait_us(ONE_SECOND_US);
    //vibratingMotor.setState(OFF);

    /* Initialize the audio transducer */
    audioTransducer.setup();

    /* Attach Interrupt to Callback Function */
    audio_signal.rise(&audio_interrupt);

    /* Enable Interrupt */
    audio_signal.enable_irq();

    /* Set up the LEDs */
    setupLEDs();
    setAllLEDs(ON);
    wait_us(ONE_SECOND_US/16);
    setAllLEDs(OFF);

    /* Attach thread to callback method and start the thread */
    response.start(callback(&q, &EventQueue::dispatch_forever));
    q.event(&audio_interrupt);
    response.set_priority(osPriorityAboveNormal1);
    
    /* Release Semaphore after Critical Section */
    semaphore.release();

    /* Setup is Complete */
    printf("   --- SETUP COMPLETE ---\n");
    cycleThroughLEDs(ONE_SECOND_US/16);

    while(1) {

    }
    return 0;
}

/** audio_interrupt
 * 
 * @brief this function handles the response when audio is detected
 * @version 1.4
 */
void audio_interrupt() {
    /* Attempt to acquire the Semaphore */
    bool is_semaphore_free = semaphore.try_acquire(); // returns 0 if semaphore is in use, 1 if free
    if (is_semaphore_free) { /* If semaphore is free, activate the audio response. Otherwise, do nothing */

        /* Audio has been detected, kick the dog to prevent system timeout */
        Watchdog &watchdog = Watchdog::get_instance();
        watchdog.kick();

        /* Debounce by waiting 1/8 of a second */
        wait_us(ONE_SECOND_US/8);

        /* Turn on vibration motor */
        vibratingMotor.setState(ON);

        /* Turn on cycling LEDs */
        cycleThroughLEDs(ONE_SECOND_US/16);
        cycleThroughLEDs(ONE_SECOND_US/16);
        cycleThroughLEDs(ONE_SECOND_US/16);
        cycleThroughLEDs(ONE_SECOND_US/16);
        cycleThroughLEDs(ONE_SECOND_US/16);

        /* Turn off vibration motor */
        vibratingMotor.setState(OFF);

        /* Release Semaphore after running Critical Section*/
        semaphore.release();
    }
    
}