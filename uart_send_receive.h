

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"



char UART5_Input(void) {

    // Wait for the receive buffer to be not empty
    while ((UART5_FR_R & 0x10) != 0);
    // Return the received character (lower 8 bits of UART0_DR_R)
    return (UART5_DR_R & 0xFF);
}

// This function sends a character of characters via UART0
void UART0_SendCharacter(char c) {
    // Wait until the transmit buffer is empty
    while ((UART0_FR_R & 0x20) != 0);
    // Write the character to the data register
    UART0_DR_R = c;


}

// This function sends a string of characters via UART0
void UART0_SendString(char* str) {
    // Loop through the string until the null terminator is reached

    while (*str != '\0') {
        UART0_SendCharacter(*str);
        // Move to the next character in the string
        str++;
    }
}

// This function sends a character of characters via UART7
void UART7_SendCharacter(char c) {
    // Wait until the transmit buffer is empty
    while ((UART7_FR_R & 0x20) != 0);
    // Write the character to the data register
    UART7_DR_R = c;


}

// This function sends a string of characters via UART7
void UART7_SendString(char* str) {
    // Loop through the string until the null terminator is reached

    while (*str != '\0') {
        UART7_SendCharacter(*str);
        // Move to the next character in the string
        str++;
    }
}
