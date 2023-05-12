/*
 * This code defines three functions to initialize and configure the GPIO and UART modules on the Tiva C Series TM4C123G LaunchPad microcontroller.
 *
 * The first function, setClock16MHz(), sets the system clock frequency to 16 MHz using the PLL and the external 16 MHz crystal oscillator.
 *
 * The second function, PortA_Init_UART0(), initializes and configures the UART0 module on Port A for serial communication. It sets the GPIO pins to alternate function mode and configures the UART0 module with a baud rate of 9600, 8 data bits, 1 stop bit, and no parity.
 *
 * The third function, PortE_Init_UART5(), initializes and configures the UART5 module on Port E for serial communication. It sets the GPIO pins to alternate function mode and configures the UART5 module with a baud rate of 9600, 8 data bits, 1 stop bit, and no parity.
 *
 * The fourth function, PortF_Init(), initializes and configures Port F for input and output. It sets PF4 and PF0 as input pins with pull-up resistors enabled, and PF3, PF2, and PF1 as output pins.
 */


#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"

 // Function to set system clock frequency to 16 MHz
void setClock16MHz(void) {
    SysCtlClockSet(SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_SYSDIV_12_5);
}

// Function to initialize and configure UART0 module on Port A for serial communication
void PortA_Init_UART0(void) {
    // Enable clock for UART0 and Port A
    SYSCTL_RCGCUART_R |= 0x01;
    SYSCTL_RCGCGPIO_R |= 0x01;

    // Wait for the UART0 module and Port A to be ready
    while ((SYSCTL_PRUART_R & 0x00000001) == 0);
    while ((SYSCTL_PRGPIO_R & 0x01) == 0);

    // Configure GPIO pins for alternate function mode
    GPIO_PORTA_AFSEL_R |= 0x03;
    GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & ~0xFF) | 0x11;
    GPIO_PORTA_DEN_R |= 0x03;
    GPIO_PORTA_AMSEL_R &= ~0x03;

    // Configure UART0 module with 9600 baud rate, 8 data bits, 1 stop bit, and no parity
    UART0_CTL_R &= ~0x01;
    UART0_IBRD_R = 104;
    UART0_FBRD_R = 11;
    UART0_CC_R = 0;
    UART0_LCRH_R = 0x0070;
    UART0_CTL_R |= 0x0301;
}

// Function to initialize and configure UART5 module on Port E for serial communication
void PortE_Init_UART5(void) {
    //PE4 U5Rx, PE5 U5Tx
    // Enable clock for UART5 and Port E
    SYSCTL_RCGCUART_R |= 0x20;
    SYSCTL_RCGCGPIO_R |= 0x10;

    // Wait for the UART5 module and Port E to be ready
    while ((SYSCTL_PRUART_R & 0x00000020) == 0);
    while ((SYSCTL_PRGPIO_R & 0x10) == 0);

    // Configure GPIO pins for alternate function mode
    GPIO_PORTE_AFSEL_R |= 0x30;
    GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & ~0xFF0000) | 0x110000;
    GPIO_PORTE_DEN_R |= 0x30;
    GPIO_PORTE_AMSEL_R &= ~0x30;

    // Configure UART5 module with 9600 baud rate, 8 data bits, 1 stop bit, and no parity
    UART5_CTL_R &= ~0x01;
    UART5_IBRD_R = 104;
    UART5_FBRD_R = 11;
    UART5_CC_R = 0;
    UART5_LCRH_R = 0x0070;
    UART5_CTL_R |= 0x0301;
}

// Function to initialize and configure UART5 module on Port E for serial communication
void PortE_Init_UART7(void) {
    //PE0 U7Rx, PE1 U7Tx
    // Enable clock for UART5 and Port E
    SYSCTL_RCGCUART_R |= 0x80;
    SYSCTL_RCGCGPIO_R |= 0x10;

    // Wait for the UART5 module and Port E to be ready
    while ((SYSCTL_PRUART_R & 0x00000080) == 0);
    while ((SYSCTL_PRGPIO_R & 0x10) == 0);

    // Configure GPIO pins for alternate function mode
    GPIO_PORTE_AFSEL_R |= 0x03;
    GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R & ~0xFF) | 0x11;
    GPIO_PORTE_DEN_R |= 0x03;
    GPIO_PORTE_AMSEL_R &= ~0x03;

    // Configure UART5 module with 9600 baud rate, 8 data bits, 1 stop bit, and no parity
    UART7_CTL_R &= ~0x01;
    UART7_IBRD_R = 104;
    UART7_FBRD_R = 11;
    UART7_CC_R = 0;
    UART7_LCRH_R = 0x0070;
    UART7_CTL_R |= 0x0301;
}
// Function to initialize and configure Port F for input and output
void PortF_Init(void) {
    // Enable clock for Port F
    SYSCTL_RCGCGPIO_R |= 0x20;

    // Wait for Port F to be ready
    while ((SYSCTL_PRGPIO_R & 0x20) == 0);

    // Unlock Port F PF0 and allow changes to PF4-0
    GPIO_PORTF_LOCK_R = 0x4C4F434B;
    GPIO_PORTF_CR_R = 0x1F;

    // Disable analog function, clear PCTL, set direction, and enable digital pins
    GPIO_PORTF_AMSEL_R = 0x00;
    GPIO_PORTF_PCTL_R = 0x00000000;
    GPIO_PORTF_DIR_R = 0x0E;
    GPIO_PORTF_AFSEL_R = 0x00;
    GPIO_PORTF_PUR_R = 0x11;
    GPIO_PORTF_DEN_R = 0x1F;
}

