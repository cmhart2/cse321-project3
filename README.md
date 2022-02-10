# Caroline Hart

## CSE 321 - Real Time Embedded Operating Systems

## Project 3

## December 10, 2021

## About

This project is an all-in-one audio feedback device. To account for disability, this device will be designed using universal design principles. Universal design principles are based on the idea that a device or service should be accessible to any operator.
Oftentimes, devices and systems are not developed using principles of universal design. This means that there is a distinct amount of devices that a certain number of disabled people would not be able to fully operate.  In many cases, devices operate on the notion that abled people are the norm, and designing for disabilities is considered outside the scope of the device's functionality.
According to Rosmaita, the best way to design for accessibility is to incorporate it at each and every step in the design process (Rosmaita, J.B. 2006, p 278).
However, there is a distinct lack of mainstream accessible designs.
This device's purpose is to bridge the gap between inaccessible design and disabled people by providing visual and vibration feedback when audio is detected.

## Applications

This device's purpose is to provide visual as well as vibration feedback when audio is detected. The LEDs will light up and the vibration motor will vibrate when audio within the minimum threshold is detected.

## Outcomes

The user will be able to implement the system and use it to interpret audio as both light and vibration. Many mainstream designs use audio to communicate information to the user (ex. a traditional timer emits noise when the time is up). This device intends to make these mainstream devices more accessible. In the case where the user is deaf, hard of hearing, or has difficulties with auditory processing, this device allows the user to use and benefit from mainstream devices that may otherwise be unusable to them.

## Implementation Details

### Watchdog

The Watchdog timer’s purpose is to safeguard against the system getting stuck. It allows the system to reset itself into a safe state and reinitialize things. For this project, the watchdog timer was configured with the maximum allowed time by the system [4]. This time was chosen because the system must wait for an audio signal before it can operate. Because the device’s purpose when audio is not detected is to simply wait for an audio signal, it would be undesirable to have the system reset within a short period of time. Any time an audio signal is detected, the watchdog is once again reset to the maximum allowed time.

### Synchronization

Common synchronization techniques include flags, semaphores, mutexes, messages, and mailboxes. Without the use of proper synchronization techniques, data that is either being stored or being transmitted may be corrupted. Therefore, it is important to ensure that events are synchronized. This project uses a semaphore to synchronize its tasks. The tasks consist of system initialization and the audio response. Because these tasks access the same data, it is critical to ensure that these data are only being accessed by one task at any given time. In this project, whenever shared data needs to be accessed, the semaphore is acquired. When the task is completed accessing the shared data, the semaphore is released so that the next task has the semaphore available to it. This ensures that the data will be preserved between tasks. 

### Bitwise Drivers

Bitwise drivers are used to control the function of input and output devices. This project contains bitwise drivers for the audio transducer, as well as the vibration motor. This allows the program to call driver functions to control the input/output devices, rather than making the necessary bitwise configurations each time the state of an input/output device needs to be altered. 

### Critical Section Protection

The critical section is an important part of the code to protect. For this project, the critical section was protected by removing access to global variables, and by implementing mutual exclusion. In order to achieve mutual exclusion, a semaphore was utilized. 
Initially when beginning this project, a mutex was to be used to protect the critical section. However, after reading the Mbed OS documentation , it is evident that the Mutex::lock() and Mutex::unlock() functions cannot be called from an ISR context [2]. Due to the nature of the project, having the audio transducer trigger an interrupt is an ideal solution, therefore, more research into critical section protection methods was conducted. 
A semaphore was used to protect the critical section, because the Semaphore::try_acquire() method can be called from an ISR context [3]. The use of a semaphore in this project was significant because it prevents the audio interrupt from interrupting the LED and vibration motor response in the case that they are already responding to an audio signal. 

### Thread

Threads are used to execute a sequence of instructions which are independent of other tasks or threads. In this project, a thread was used to control the response when audio is detected. The response thread is started when the audio interrupt is triggered, and handles the output response (LEDs and vibration motor).

### Interrupt

Interrupts are hardware triggered events used to interrupt the normal program flow. In this project, an interrupt was used to jump to the response thread when audio is detected. The use of an interrupt was influential in this design process, because when synchronization techniques were considered, there was a possibility that this interrupt may be removed. However, this did not happen, because using an interrupt to respond to audio was preferred over using a Mutex for synchronization and critical section protection. 

## BOM

* Nucleo-L4R5ZI
* Solderless Breadboard
* Jumper Wires
* 8x LED
* 8x 100 ohm Resistors
* Audio Transducer
* Vibration Motor

## Getting Started

### Schematic Diagram

<img src="https://github.com/CSE321-Fall2021/cse321-portfolio-cmhart2/blob/main/Project%203/Resources/CSE321%20-%20Project%203%20Schematic.png" alt="Vibration Motor: Vcc connects to pin PC0, GND connects to GND pin. Audio Transducer: OUT connects to pin PC4, Vcc connects to pin PC3, GND connects to GND pin. LEDs: LED 1 connects to pin PB15, LED 2 connects to pin PB13, LED 3 connects to pin PB12, LED 4 connects to pin PB4, LED 5 connects to pin PB5, LED 6 connects to pin PB3, LED 7 connects to PB8, LED 8 connects to PB9."></img>

### Instructions to Build

<details>
    <ol>
        <li>Gather materials. see <a href="https://github.com/CSE321-Fall2021/cse321-portfolio-cmhart2/blob/main/Project%203/README.md#bom">BOM</a></li>
        <li>Ensure that the vibration motor is adhered to a surface. This will prevent the jumpers from being freed from the force of the vibration.</li>
        <li>Connect the Audio Transducer.
        <ol>
            <li>Connect three jumpers to the three pins of the audio transducer.</li>
            <li>Connect the jumper connected to “OUT” on the audio transducer to pin PC4 on the Nucleo.</li>
            <li>Connect the jumper connected to “GND” on the audio transducer to either the ground rail of the breadboard, or any GND on the Nucleo.</li>
            <li>Connect the jumper connected to “VCC” on the audio transducer to pin PC3 on the Nucleo.</li>
        </ol>
        </li>
        <li>Connect the Vibration Motor
        <ol>
            <li>Connect the two wires of the vibration motor to two separate rows on the breadboard. This will help prevent the wires from being freed by the force of the vibration.</li>
            <li>Using a jumper, connect the row of the breadboard where the red wire (Vcc) of the vibration motor was connected to pin PC0 of the Nucleo.</li>
            <li>Using a jumper, connect the row of the breadboard where the blue wire (GND) of the vibration motor was connected to either the ground rail of the breadboard or any GND on the Nucleo</li>
        </ol>
        </li>
        <li>Connect the LEDs
        <ol>
            <li>Place each of the 8 LEDs in its own row on the breadboard.</li>
            <li>Connect a resistor to the row of the breadboard where the negative terminal of the first LED is connected. Connect the other end of the resistor to the ground rail of the breadboard.</li>
            <li>Repeat step 5.2 for each of the 7 other LEDs and resistors</li>
            <li>Using a jumper, connect the positive terminal of LED 1 to pin PB15 of the Nucleo.</li>
            <li>Using a jumper, connect the positive terminal of LED 2 to pin PB13 of the Nucleo</li>
            <li>Using a jumper, connect the positive terminal of LED 3 to pin PB12 of the Nucleo</li>
            <li>Using a jumper, connect the positive terminal of LED 4 to pin PB4 of the Nucleo</li>
            <li>Using a jumper, connect the positive terminal of LED 5 to pin PB5 of the Nucleo</li>
            <li>Using a jumper, connect the positive terminal of LED 6 to pin PB3 of the Nucleo</li>
            <li>Using a jumper, connect the positive terminal of LED 7 to pin PB8 of the Nucleo</li>
            <li>Using a jumper, connect the positive terminal of LED 8 to pin PB9 of the Nucleo</li>
        </ol>
        </li>
        <li>Insert the micro-USB cable into the USER PWR port of the Nucleo. Insert the other end of the cable into your computer. Ensure the connection between the Nucleo and the computer is complete by checking that the COM light on the Nucleo is now lit.</li>
    </ol>
</details>

### Instructions to Use

<details>
    <ol>
        <li>Clone this repository. </li>
        <li>On your computer, launch Mbed Studio. Open the directory in which the repository was cloned. Ensure `Project 3` is selected as the active program.</li>
        <li>Ensure that the following files are present within Project 3.
        <ol>
            <li>CSE321_LED_Blinky.cpp</li>
            <li>CSE321_LED_Blinky.h</li>
            <li>CSE321_Project-3_main.cpp</li>
            <li>CSE321_Project-3_main.h</li>
            <li>CSE321_audio_transducer.cpp</li>
            <li>CSE321_audio_transducer.h</li>
            <li>CSE321_vibration_motor.cpp</li>
            <li>CSE321_vibration_motor.h</li>
        </ol></li>
        <li>Ensure that Project 3 is selected as the active program.</li>
        <li>Prepare a clean build of Project 3.</li>
        <li>Run Project 3.</li>
        <li>Wait for the message ` --- SETUP COMPLETE --- ` to display on the serial output.</li>
        <li>Drop something/knock next to the audio transducer. You may need to use a small phillips head screwdriver to adjust the sensitivity of the audio transducer.</li>
        <li>You should see the LEDs light up as well as feel the vibration motor vibrate for a moment whenever a loud noise is detected.</li>
    </ol>
</details>

## References

[1]	B.J. Rosmaita.  “Accessibility Now! Teaching Accessible Computing at the Introductory Level,” Assets '06: Proceedings of the 8th International ACM SIGACCESS Conference on Computers and Accessibility. 22, October, 2006. [Online] Available: https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.563.5479&rep=rep1&type=pdf. [Accessed Nov. 1, 2021]

[2]	Mbed OS. “Mutex Class,” _os.mbed.com_ [Online] Available: https://os.mbed.com/docs/mbed-os/v6.15/mbed-os-api-doxy/group__rtos___mutex.html#gaa81aed607133209dade63a226818224d. [Accessed Dec. 1, 2021]

[3]	Mbed OS. “Semaphore,” _os.mbed.com_ [Online] Available: https://os.mbed.com/docs/mbed-os/v6.15/apis/semaphore.html. [Accessed Dec. 3, 2021]

[4]	Mbed OS. “Watchdog,” _os.mbed.com_ [Online] Available: https://os.mbed.com/docs/mbed-os/v6.15/apis/watchdog.html. [Accessed Dec. 1, 2021]