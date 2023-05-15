/*
 * This program defines two functions: to_decimal and handleGpsInput.
 * to_decimal takes a double as input and converts it to a decimal number with two decimal places.
 * handleGpsInput takes a string and an array of doubles as input, and extracts four double values from the string.
 * The string is expected to have comma-separated values in the format: value1,N/S,value2,E/W.
 * The first value is converted to a decimal using the to_decimal function.
 * The second value is a character indicating whether the latitude is North or South, and is converted to a binary value (0 for North, 1 for South).
 * The third value is converted to a decimal using the to_decimal function.
 * The fourth value is a character indicating whether the longitude is East or West, and is converted to a binary value (0 for East, 1 for West).
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <string.h>  
#include <stdlib.h>
#include <stdio.h>
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"

 // Function to convert from degrees and minutes to decimal format
double to_decimal(double x) {
    int dint = (int)x;
    x -= dint;
    return dint + x * 5.0 / 3.0;
}

// Function to extract four double values from a comma-separated string
void handleGpsInput(char* str, double* res) {
    char* temp;

    // Extract the first value and discard it
    strtok(str, ",");

    // Extract the second value and convert it to latitude
    temp = strtok(NULL, ",");
    res[0] = to_decimal(atof(temp) / 100);

    // Extract the third value and convert it to binary
    temp = strtok(NULL, ",");
    res[1] = temp[0] == 'N' ? 0 : 1;

    // Extract the fourth value and convert it to longitude
    temp = strtok(NULL, ",");
    res[2] = to_decimal(atof(temp) / 100);

    // Extract the fifth value and convert it to binary
    temp = strtok(NULL, ",");
    res[3] = temp[0] == 'E' ? 0 : 1;
}
