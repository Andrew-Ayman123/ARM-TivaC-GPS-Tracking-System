# GPS_Locater-ASU-Embedded_Project

This is a GPS tracking device project that receives GPS data from UART5 and calculates the displacement and total distance traveled using GPS data. The program also sends the results to UART0 for display.

## Files

The project includes several header files for standard libraries, as well as several source files for custom functions:

- `displacement_calculator.h`: Contains a function to calculate the displacement between two GPS latitude and longitude positions using the Haversine formula.
- `distance_total.h`: Contains functions to calculate the total distance traveled by the device using GPS data.
- `initialization.h`: Contains functions to initialize clock frequency, UART ports, and GPIO ports.
- `string_handler.h`: Contains a function to extract the latitude and longitude position from a GPS data string.
- `uart_receive_gps.h`: Contains a function to receive GPS data from UART5.
- `uart_send_receive.h`: Contains functions to send and receive data using UART0.
- `distance_checker.h`: Contains a function to check the distance between the current position and the target position and turn on the appropriate LED.

The `main.c` file contains the main function of the program, which initializes several variables, calls the initialization functions, enters a while loop that continuously receives GPS data, calculates the displacement and total distance traveled, and sends the results to UART0.

## Dependencies

This project requires the TivaWare library and the Tiva C Series TM4C123G LaunchPad microcontroller.

## Usage

To use this project, connect the Tiva C Series TM4C123G LaunchPad microcontroller to a GPS device using UART5 and connect the microcontroller to a display device using UART0. Upload the project files to the microcontroller and run the program. The program will continuously receive GPS data, calculate the displacement and total distance traveled, and display the results on the display device.
