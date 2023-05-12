/*
 * This code is the main function of a program for a GPS tracking device that receives GPS data from UART5 and calculates the displacement and total distance traveled using GPS data. The program also sends the results to UART0 for display.
 *
 * The program includes several header files for standard libraries, as well as several source files for custom functions.
 *
 * The main function initializes several variables, including the total distance traveled, the current and previous latitude and longitude positions, the target latitude and longitude position, and the displacement between the current position and the target position.
 *
 * The main function then calls several initialization functions for clock frequency, UART ports, and GPIO ports.
 *
 * The program then enters a while loop that continuously receives GPS data from UART5. When GPS data is received, the program extracts the latitude and longitude position from the GPS data string using the handleGpsInput() function, calculates the displacement between the current position and the target position using the calculateDisplacement() function, calculates the total distance traveled using the distance_total_calculator() function, and checks the distance using the distanceCheck() function.
 *
 * The program then sends the remaining displacement and total distance traveled to UART0 using the UART0_SendString() function.
 */

#include <string.h>  
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "./displacement_calculator.h" // custom function to calculate displacement
#include "./distance_total.h" // custom function to calculate total distance
#include "./initlization.h" // custom function to initialize clock frequency, UART ports, and GPIO ports
#include "./string_handler.h" // custom function to extract latitude and longitude position from GPS data string
#include "./uart_recieve_gps.h" // custom function to receive GPS data from UART5
#include "./uart_send_receive.h" // custom functions to send and receive data using UART0
#include "./distance_checker.h" // custom function to check distance and turn on appropriate LED


int main(void) {
  bool print_to_pc = false;
  double distanceTotal = 0; // variable to hold total distance traveled
  char str_main[100]; // string buffer to hold GPS data string
  double displacement = 0; // variable to hold displacement between current position and target position

  double lat_long_pos_now[4] = { 0,0,0,0 }; // array to hold current latitude and longitude position
  double lat_long_pos_prev[4] = { 0,0,0,0 }; // array to hold previous latitude and longitude position
  double lat_long_target[4] = { 30.0635057,0,31.2797673,0 }; // array to hold target latitude and longitude position

  setClock16MHz(); // initialize clock frequency
  PortF_Init(); // initialize GPIO port for LEDs
  PortE_Init_UART5(); // initialize UART5 for communication with GPS device

  if (print_to_pc) {
    PortA_Init_UART0(); // initialize UART0 for communication with PC
  }
  else {
    PortE_Init_UART7(); // initialize UART7 for communication with Bluethooth
  }

  while (1) { // enter infinite loop
    if (receive_UART5_gps(str_main)) { // if GPS data is received
      handleGpsInput(str_main, lat_long_pos_now); // extract latitude and longitude position from GPS data string

      displacement = calculateDisplacement(lat_long_pos_now, lat_long_target); // calculate displacement between current position and target position

      distanceCheck(displacement); // check distance and turn on appropriate LED
      distanceTotal = distance_total_calculator(lat_long_pos_prev, lat_long_pos_now); // calculate total distance traveled


      // Output to computer through usb or bluethooth module
      sprintf(str_main, "Remaining Displacement is: %.2f Total Distance: %.2f", displacement, distanceTotal); // format remaining displacement as string
      if (print_to_pc) {
        strcat(str_main, "\r\n");
        UART0_SendString(str_main); // send remaining displacement to display device using UART0   
      }
      else {
        UART7_SendString(str_main); // send total distance to display device using UART7
      }
      str_main[0] = '\0'; // clear GPS data string buffer
    }
  }
}
