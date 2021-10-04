/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F45K80
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANCON1bits.ANSEL10 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANCON1bits.ANSEL10 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISCbits.TRISC1
#define LED_LAT                  LATCbits.LATC1
#define LED_PORT                 PORTCbits.RC1
#define LED_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define LED_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define LED_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define LED_GetValue()           PORTCbits.RC1
#define LED_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set Thyristor aliases
#define Thyristor_TRIS                 TRISDbits.TRISD0
#define Thyristor_LAT                  LATDbits.LATD0
#define Thyristor_PORT                 PORTDbits.RD0
#define Thyristor_ANS                  ANCON1bits.ANSEL11
#define Thyristor_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define Thyristor_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define Thyristor_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define Thyristor_GetValue()           PORTDbits.RD0
#define Thyristor_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define Thyristor_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define Thyristor_SetAnalogMode()      do { ANCON1bits.ANSEL11 = 1; } while(0)
#define Thyristor_SetDigitalMode()     do { ANCON1bits.ANSEL11 = 0; } while(0)

// get/set RD1 aliases
#define RD1_TRIS                 TRISDbits.TRISD1
#define RD1_LAT                  LATDbits.LATD1
#define RD1_PORT                 PORTDbits.RD1
#define RD1_ANS                  ANCON1bits.ANSEL12
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()           PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetAnalogMode()      do { ANCON1bits.ANSEL12 = 1; } while(0)
#define RD1_SetDigitalMode()     do { ANCON1bits.ANSEL12 = 0; } while(0)

// get/set IO_RD2 aliases
#define IO_RD2_TRIS                 TRISDbits.TRISD2
#define IO_RD2_LAT                  LATDbits.LATD2
#define IO_RD2_PORT                 PORTDbits.RD2
#define IO_RD2_ANS                  ANCON1bits.ANSEL13
#define IO_RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IO_RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IO_RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IO_RD2_GetValue()           PORTDbits.RD2
#define IO_RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IO_RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define IO_RD2_SetAnalogMode()      do { ANCON1bits.ANSEL13 = 1; } while(0)
#define IO_RD2_SetDigitalMode()     do { ANCON1bits.ANSEL13 = 0; } while(0)

// get/set SW1 aliases
#define SW1_TRIS                 TRISEbits.TRISE1
#define SW1_LAT                  LATEbits.LATE1
#define SW1_PORT                 PORTEbits.RE1
#define SW1_ANS                  ANCON0bits.ANSEL6
#define SW1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define SW1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define SW1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define SW1_GetValue()           PORTEbits.RE1
#define SW1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define SW1_SetAnalogMode()      do { ANCON0bits.ANSEL6 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANCON0bits.ANSEL6 = 0; } while(0)

// get/set SW2 aliases
#define SW2_TRIS                 TRISEbits.TRISE2
#define SW2_LAT                  LATEbits.LATE2
#define SW2_PORT                 PORTEbits.RE2
#define SW2_ANS                  ANCON0bits.ANSEL7
#define SW2_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define SW2_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define SW2_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define SW2_GetValue()           PORTEbits.RE2
#define SW2_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define SW2_SetAnalogMode()      do { ANCON0bits.ANSEL7 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANCON0bits.ANSEL7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/