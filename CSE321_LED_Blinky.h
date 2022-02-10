/**
 * @author Caroline Hart, cmhart2@buffalo.edu
 * @date December 10, 2021
 * @brief This file contains the headers for the LED Blinking Control
 * @functions: 
 *      void setupLEDs()
 *      void setAllLEDs(int state)
 *      void setLED1(int state)
 *      void setLED2(int state)
 *      void setLED3(int state)
 *      void setLED4(int state)
 *      void setLED5(int state)
 *      void setLED6(int state)
 *      void setLED7(int state)
 *      void setLED8(int state)
 *      int getLED1()
 *      int getLED2()
 *      int getLED3()
 *      int getLED4()
 *      int getLED5()
 *      int getLED6()
 *      int getLED7()
 *      int getLED8()
 *      void cycleThroughLEDs(int freq)
**/

#ifndef MBED_H
#include "mbed.h"
#endif

#ifndef PINNAMES_H
#include "PinNames.h"
#endif

#ifndef ON
#define ON 1
#define OFF 0
#endif

#define LED_1 PB_15
#define LED_2 PB_13
#define LED_3 PB_12
#define LED_4 PB_4
#define LED_5 PB_5
#define LED_6 PB_3
#define LED_7 PB_8
#define LED_8 PB_9

/** setupLEDs
 *
 * @brief Sets the clock and sets pins to output mode
 */
void setupLEDs();

/** setAllLEDs
 *
 * @brief Sets LEDs 1-8 given state
 */
void setAllLEDs(int state);

/** setLED1
 *
 * @brief sets LED1 to the provided state
 * @param state either ON or OFF
 */
void setLED1(int state);

/** setLED2
 *
 * @brief sets LED2 to the provided state
 * @param state either ON or OFF
 */
void setLED2(int state);

/** setLED3
 *
 * @brief sets LED3 to the provided state
 * @param state either ON or OFF
 */
void setLED3(int state);

/** setLED4
 *
 * @brief sets LED4 to the provided state
 * @param state either ON or OFF
 */
void setLED4(int state);

/** setLED5
 *
 * @brief sets LED5 to the provided state
 * @param state either ON or OFF
 */
void setLED5(int state);

/** setLED6
 *
 * @brief sets LED6 to the provided state
 * @param state either ON or OFF
 */
void setLED6(int state);

/** setLED7
 *
 * @brief sets LED7 to the provided state
 * @param state either ON or OFF
 */
void setLED7(int state);

/** setLED8
 *
 * @brief sets LED8 to the provided state
 * @param state either ON or OFF
 */
void setLED8(int state);

/** getLED1
 *
 * @brief Gets the state of LED1
 * @return the current state of LED1, either ON or OFF
 */
int getLED1();

/** getLED2
 *
 * @brief Gets the state of LED2
 * @return the current state of LED2, either ON or OFF
 */
int getLED2();

/** getLED3
 *
 * @brief Gets the state of LED3
 * @return the current state of LED3, either ON or OFF
 */
int getLED3();

/** getLED4
 *
 * @brief Gets the state of LED4
 * @return the current state of LED4, either ON or OFF
 */
int getLED4();

/** getLED5
 *
 * @brief Gets the state of LED5
 * @return the current state of LED5, either ON or OFF
 */
int getLED5();

/** getLED6
 *
 * @brief Gets the state of LED6
 * @return the current state of LED6, either ON or OFF
 */
int getLED6();

/** getLED7
 * 
 * @brief Gets the state of LED7
 * @return the current state of LED7, either ON or OFF
 */
int getLED7();

/** getLED8
 *
 * @brief Gets the state of LED8
 * @return the current state of LED8, either ON or OFF
 */
int getLED8();

/** cycleThroughLEDs
 *
 * @brief Cycles through the LEDs, turning on only the active target LED
 * @param freq Frequency at which to cycle through (measured in microseconds)
 */
 void cycleThroughLEDs(int freq);