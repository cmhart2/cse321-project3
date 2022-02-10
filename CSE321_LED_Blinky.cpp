/**
 * @author Caroline Hart, cmhart2@buffalo.edu
 * @date December 10, 2021
 * @brief This file contains the code that controls the blinking LEDs
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

#ifndef LED_H
#include "CSE321_LED_Blinky.h"
#endif

int LED1_state = OFF;
int LED2_state = OFF;
int LED3_state = OFF;
int LED4_state = OFF;
int LED5_state = OFF;
int LED6_state = OFF;
int LED7_state = OFF;
int LED8_state = OFF;

/** setup
 *
 * @brief Sets the clock and sets pins to output mode
 * @version 1.0
 */
void setupLEDs() {
    /* Turn on Port B */
    RCC->AHB2ENR |= 0x2;

    /* Set LEDs 1-8 to General Purpose Output Mode (01)
     * Bits 31 and 30 need to be 0 & 1, respectively
     * Bits 27 and 26 need to be 0 & 1, respectively
     * Bits 25 and 24 need to be 0 & 1, respectively
     * Bits  9 and  8 need to be 0 & 1, respectively
     * Bits 11 and 10 need to be 0 & 1, respectively
     * Bits  7 and  6 need to be 0 & 1, respectively
     * Bits 17 and 16 need to be 0 & 1, respectively
     * Bits 19 and 18 need to be 0 & 1, respectively */

    /* Bits 7, 9, 11, 17, 19, 25, 27 & 31 need to be 0 */
    GPIOB->MODER &= ~(0x8A0A0A80);

    /* Bits 6, 8, 10, 16, 18, 24, 26 & 30 need to be 1 */
    GPIOB->MODER |= 0x45050540;
}

/** setAllLEDs
 *
 * @brief Sets LEDs 1-8 given state
 * @version 1.0
 */
void setAllLEDs(int state) {
    if (state == ON) { /* if LEDs need to be ON */
        GPIOB->ODR |= 0xB338;    /* Bits 15,13,12,9,8,5,4 & 3 need to be 1 */
    } else if (state == OFF) { /* if LEDs need to be OFF */
        GPIOB->ODR &= ~(0xB338); /* Bits 15,13,12,9,8,5,4 & 3 need to be 0 */
    }
    LED1_state = state; /* Set LED state to input state */
    LED2_state = state; /* Set LED state to input state */
    LED3_state = state; /* Set LED state to input state */
    LED4_state = state; /* Set LED state to input state */
    LED5_state = state; /* Set LED state to input state */
    LED6_state = state; /* Set LED state to input state */
    LED7_state = state; /* Set LED state to input state */
    LED8_state = state; /* Set LED state to input state */
}

/** setLED1
 *
 * @brief sets LED1 to the provided state
 * @version 1.0
 * @param state either ON or OFF
 */
void setLED1(int state) {
    /* PB_15 */
    if (state == ON) {        /* LED needs to be ON */
        GPIOB->ODR |= 0x8000; /* Bit 15 needs to be 1 */
    }
    else if (state == OFF) {    /* LED needs to be OFF */
        GPIOB->ODR &= ~(0x8000); /* Bit 15 needs to be 0 */
    }
    LED1_state = state; /* Set LED state to input state */
}

/** setLED2
 *
 * @brief sets LED2 to the provided state
 * @version 1.0
 * @param state either ON or OFF
 */
void setLED2(int state) {
    /* PB_13 */
    if (state == ON) {        /* LED needs to be ON */
        GPIOB->ODR |= 0x2000; /* Bit 13 needs to be 1 */
    }
    else if (state == OFF) {    /* LED needs to be OFF */
        GPIOB->ODR &= ~(0x2000); /* Bit 13 needs to be 0 */
    }
    LED2_state = state; /* Set LED state to input state */
}

/** setLED3
 *
 * @brief sets LED3 to the provided state
 * @version 1.0
 * @param state either ON or OFF
 */
void setLED3(int state) {
    /* PB_12 */
    if (state == ON) {        /* LED needs to be ON */
        GPIOB->ODR |= 0x1000; /* Bit 12 needs to be 1 */
    }
    else if (state == OFF) {    /* LED needs to be OFF */
        GPIOB->ODR &= ~(0x1000); /* Bit 12 needs to be 0 */
    }
    LED3_state = state; /* Set LED state to input state */
}

/** setLED4
 *
 * @brief sets LED4 to the provided state
 * @version 1.0
 * @param state either ON or OFF
 */
void setLED4(int state) {
    /* PB_4 */
    if (state == ON) {      /* LED needs to be ON */
        GPIOB->ODR |= 0x10; /* Bit 4 needs to be 1 */
    }
    else if (state == OFF) {    /* LED needs to be OFF */
        GPIOB->ODR &= ~(0x10); /* Bit 4 needs to be 0 */
    }
    LED4_state = state; /* Set LED state to input state */
}

/** setLED5
 *
 * @brief sets LED5 to the provided state
 * @version 1.0
 * @param state either ON or OFF
 */
void setLED5(int state) {
    /* PB_5 */
    if (state == ON) {      /* LED needs to be ON */
        GPIOB->ODR |= 0x20; /* Bit 5 needs to be 1 */
    }
    else if (state == OFF) {    /* LED needs to be OFF */
        GPIOB->ODR &= ~(0x20); /* Bit 5 needs to be 0 */
    }
    LED5_state = state; /* Set LED state to input state */
}

/** setLED6
 *
 * @brief sets LED6 to the provided state
 * @version 1.0
 * @param state either ON or OFF
 */
void setLED6(int state) {
    /* PB_3 */
    if (state == ON) {     /* LED needs to be ON */
        GPIOB->ODR |= 0x8; /* Bit 3 needs to be 1 */
    }
    else if (state == OFF) {    /* LED needs to be OFF */
        GPIOB->ODR &= ~(0x8); /* Bit 3 needs to be 0 */
    }
    LED6_state = state; /* Set LED state to input state */
}

/** setLED7
 *
 * @brief sets LED7 to the provided state
 * @version 1.0
 * @param state either ON or OFF
 */
void setLED7(int state) {
    /* PB_8 */
    if (state == ON) {       /* LED needs to be ON */
        GPIOB->ODR |= 0x100; /* Bit 8 needs to be 1 */
    }
    else if (state == OFF) {    /* LED needs to be OFF */
        GPIOB->ODR &= ~(0x100); /* Bit 8 needs to be 0 */
    }
    LED7_state = state; /* Set LED state to input state */
}

/** setLED8
 *
 * @brief sets LED8 to the provided state
 * @version 1.0
 * @param state either ON or OFF
 */
void setLED8(int state) {
    /* PB_9 */
    if (state == ON) {       /* LED needs to be ON */
        GPIOB->ODR |= 0x200; /* Bit 9 needs to be 1 */
    }
    else if (state == OFF) {    /* LED needs to be OFF */
        GPIOB->ODR &= ~(0x200); /* Bit 9 needs to be 0 */
    }
    LED8_state = state; /* Set LED state to input state */
}

/** getLED1
 *
 * @brief Gets the state of LED1
 * @version 1.0
 * @return the current state of LED1, either ON or OFF
 */
int getLED1() {
    return LED1_state;
}

/** getLED2
 *
 * @brief Gets the state of LED2
 * @version 1.0
 * @return the current state of LED2, either ON or OFF
 */
int getLED2() {
    return LED2_state;
}

/** getLED3
 *
 * @brief Gets the state of LED3
 * @version 1.0
 * @return the current state of LED3, either ON or OFF
 */
int getLED3() {
    return LED3_state;
}

/** getLED4
 *
 * @brief Gets the state of LED4
 * @version 1.0
 * @return the current state of LED4, either ON or OFF
 */
int getLED4() {
    return LED4_state;
}

/** getLED5
 *
 * @brief Gets the state of LED5
 * @version 1.0
 * @return the current state of LED5, either ON or OFF
 */
int getLED5() {
    return LED5_state;
}

/** getLED6
 *
 * @brief Gets the state of LED6
 * @version 1.0
 * @return the current state of LED6, either ON or OFF
 */
int getLED6() {
    return LED6_state;
}

/** getLED7
 *
 * @brief Gets the state of LED7
 * @version 1.0
 * @return the current state of LED7, either ON or OFF
 */
int getLED7() {
    return LED7_state;
}

/** getLED8
 * 
 * @brief Gets the state of LED8
 * @version 1.0
 * @return the current state of LED8, either ON or OFF
 */
int getLED8() {
    return LED8_state;
}

/** cycleThroughLEDs
 *
 * @brief Cycles through the LEDs, turning on only the active target LED
 * @version 1.1
 * @param freq Frequency at which to cycle through (measured in microseconds)
 */
 void cycleThroughLEDs(int freq) {
    setLED2(OFF);   /* Turn LED2 Off */
    setLED3(OFF);   /* Turn LED3 Off */
    setLED4(OFF);   /* Turn LED4 Off */
    setLED5(OFF);   /* Turn LED5 Off */
    setLED6(OFF);   /* Turn LED6 Off */
    setLED7(OFF);   /* Turn LED7 Off */
    setLED8(OFF);   /* Turn LED8 Off */
    setLED1(ON);    /* Turn LED1 On  */
    wait_us(freq);  /* wait          */
    setLED2(ON);    /* Turn LED2 On  */
    setLED1(OFF);   /* Turn LED1 Off */
    wait_us(freq);  /* wait          */
    setLED3(ON);    /* Turn LED3 On  */
    setLED2(OFF);   /* Turn LED2 Off */
    wait_us(freq);  /* wait          */
    setLED4(ON);    /* Turn LED3 On  */
    setLED3(OFF);   /* Turn LED3 Off */
    wait_us(freq);  /* wait          */
    setLED5(ON);    /* Turn LED4 On  */
    setLED4(OFF);   /* Turn LED4 Off */
    wait_us(freq);  /* wait          */
    setLED6(ON);    /* Turn LED5 On  */
    setLED5(OFF);   /* Turn LED5 Off */
    wait_us(freq);  /* wait          */
    setLED7(ON);    /* Turn LED6 On  */
    setLED6(OFF);   /* Turn LED6 Off */
    wait_us(freq);  /* wait          */
    setLED8(ON);    /* Turn LED7 On  */
    setLED7(OFF);   /* Turn LED7 Off */
    wait_us(freq);  /* wait          */
    setLED8(OFF);   /* Turn LED8 Off */
 }