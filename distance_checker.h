/*
 * This code defines two functions to control the LEDs on the Tiva C Series TM4C123G LaunchPad microcontroller based on a distance displacement value.
 *
 * The first function, PortF_LED_Output(), takes a char value as input and sets the output value of Port F pins 1, 2, and 3 based on the input value.
 *
 * The second function, distanceCheck(), takes a double value as input and uses the value to determine which LED to turn on or off using the PortF_LED_Output() function. If the displacement is less than 2, the red LED (PF1) is turned on. If the displacement is between 2 and 5, the blue LED (PF2) and the red LED are turned on. If the displacement is greater than 5, the green LED (PF3) is turned on, and the blue and red LEDs are turned off.
 */

#pragma once

#include <stdint.h>
#include "inc/tm4c123gh6pm.h"

 // Function to set the output value of Port F pins 1, 2, and 3 based on the input value
void PortF_LED_Output(char x) {
    GPIO_PORTF_DATA_R &= ~0x0E; // Clear bits 1, 2, and 3
    GPIO_PORTF_DATA_R |= x; // Set bits 1, 2, and 3 based on input value
}

// Function to determine which LED to turn on or off based on the displacement value
void distanceCheck(double displacement) {
    if (displacement < 2) {
        PortF_LED_Output(0x08); // Turn on red LED (PF1)
    }
    else if (displacement < 5) {
        PortF_LED_Output(0x0A); // Turn on blue and red LEDs (PF2 and PF1) to make a green
    }
    else {
        PortF_LED_Output(0x02); // Turn on green LED (PF3)
    }
}

