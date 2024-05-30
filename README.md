<div align="center">

  <h1> GPS Tracking System

</h1>
  
  <img src="https://img.shields.io/badge/ARM_TivaC-0091BD?style=for-the-badge&logo=arm&logoColor=white" alt="Made with love in Egypt">
  <img src="https://img.shields.io/badge/Made_With_Love-B32629?style=for-the-badge&logo=undertale&logoColor=white" alt="Made with love in Egypt">
  <img src="https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white" alt="Made with love in Egypt">
  
  <h3>  Tiva C Series TM4C123G Microcontroller based GPS tracking device to send you to the right destincation.</h3>
  
  <img src="./assets/GPS Tracking System.png" alt="logo" />


</div>



## :star2: About The Project
The GPS Locater is a GPS tracking device project that utilizes a Tiva C Series TM4C123G microcontroller to receive GPS data from UART5 and calculate displacement and total distance traveled using GPS data.

The program also sends the results to UART0 for display on PC or UART7 for display on Bluetooth android device. This project includes various header files for standard libraries and source files for custom functions such as displacement calculator, distance total, initialization, string handler, UART receive GPS, and UART send-receive.
The program will continuously receive GPS data and display the results on the display device.
<img src="./assets/GPS Tracking System irl.jfif" alt="logo" />
The project includes several header files for standard libraries, as well as several source files for custom functions:

- `displacement_calculator.h`: Contains a function to calculate the displacement between two GPS latitude and longitude positions using the Haversine formula.
- `distance_total.h`: Contains functions to calculate the total distance traveled by the device using GPS data.
- `initialization.h`: Contains functions to initialize clock frequency, UART ports, and GPIO ports.
- `string_handler.h`: Contains a function to extract the latitude and longitude position from a GPS data string.
- `uart_receive_gps.h`: Contains a function to receive GPS data from UART5.
- `uart_send_receive.h`: Contains functions to send and receive data using UART0.
- `distance_checker.h`: Contains a function to check the distance between the current position and the target position and turn on the appropriate LED.

The `main.c` file contains the main function of the program, which initializes several variables, calls the initialization functions, enters a while loop that continuously receives GPS data, calculates the displacement and total distance traveled, and sends the results to UART0.

## 📹 Sample Video

https://github.com/Andrew-Ayman123/GPS_Locater-ASU-Embedded_Project/assets/88400418/e157f188-758a-4cc2-b353-1c27f9f4a274



## :toolbox: Installation
This project requires the TivaWare library and the Tiva C Series TM4C123G LaunchPad microcontroller.

To use this project, connect the Tiva C Series TM4C123G LaunchPad microcontroller to a GPS device using UART5 and connect the microcontroller to a display device using UART0. Upload the project files to the microcontroller and run the program. The program will continuously receive GPS data, calculate the displacement and total distance traveled, and display the results on the display device.
