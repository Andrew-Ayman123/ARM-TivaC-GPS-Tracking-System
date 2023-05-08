/*
 * This code defines a function called receive_UART5_gps that receives data from a GPS device over UART5.
 * The function takes a character array as input and returns a boolean value indicating whether data was received successfully.
 * The function reads characters from UART5 and checks whether they match the expected sequence of characters for a GPS data message.
 * If the message is detected, the function reads the remaining characters until a newline character is received, and stores them in the input character array.
 * The function returns true if a valid GPS message was received and false otherwise.
 */
#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"

#include "./uart_send_receive.h"

bool receive_UART5_gps(char* str) {

int i = 0;
char m0, m1, m2, m3, m4, m5, m6, m7;

// Read the first character from UART5
m0 = UART5_Input();

// Check if the first character is '$'
if (m0 == '$') {
    // Read the next character
    m1 = UART5_Input();

    // Check if the second character is 'G'
    if (m1 == 'G') {
        // Read the next character
        m2 = UART5_Input();

        // Check if the third character is 'P'
        if (m2 == 'P') {
            // Read the next character
            m3 = UART5_Input();

            // Check if the fourth character is 'G'
            if (m3 == 'G') {
                // Read the next character
                m4 = UART5_Input();

                // Check if the fifth character is 'G'
                if (m4 == 'G') {
                    // Read the next character
                    m5 = UART5_Input();

                    // Check if the sixth character is 'A'
                    if (m5 == 'A') {
                        // Read the next character
                        m6 = UART5_Input();

                        // Check if the seventh character is ','
                        if (m6 == ',') {
                            // Read the eighth character
                            m7 = UART5_Input();

                            // Read and store the remaining characters until a newline character is received
                            while (m7 != '\n') {
                                str[i] = m7;
                                m7 = UART5_Input();
                                i++;
                            }

                            // Add null terminator to the end of the string
                            str[i] = '\0';

                            // Return true to indicate that a valid GPS message was received
                            return true;
                        }
                    }
                }
            }
        }
    }
}

// Return false to indicate that a valid GPS message was not received
return false;
}
