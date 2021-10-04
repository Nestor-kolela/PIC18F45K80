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

// get/set Potentiometer aliases
#define Potentiometer_TRIS                 TRISAbits.TRISA0
#define Potentiometer_LAT                  LATAbits.LATA0
#define Potentiometer_PORT                 PORTAbits.RA0
#define Potentiometer_ANS                  ANCON0bits.ANSEL0
#define Potentiometer_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define Potentiometer_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define Potentiometer_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define Potentiometer_GetValue()           PORTAbits.RA0
#define Potentiometer_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define Potentiometer_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define Potentiometer_SetAnalogMode()      do { ANCON0bits.ANSEL0 = 1; } while(0)
#define Potentiometer_SetDigitalMode()     do { ANCON0bits.ANSEL0 = 0; } while(0)

// get/set microphone aliases
#define microphone_TRIS                 TRISAbits.TRISA1
#define microphone_LAT                  LATAbits.LATA1
#define microphone_PORT                 PORTAbits.RA1
#define microphone_ANS                  ANCON0bits.ANSEL1
#define microphone_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define microphone_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define microphone_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define microphone_GetValue()           PORTAbits.RA1
#define microphone_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define microphone_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define microphone_SetAnalogMode()      do { ANCON0bits.ANSEL1 = 1; } while(0)
#define microphone_SetDigitalMode()     do { ANCON0bits.ANSEL1 = 0; } while(0)

// get/set tempSensor aliases
#define tempSensor_TRIS                 TRISAbits.TRISA2
#define tempSensor_LAT                  LATAbits.LATA2
#define tempSensor_PORT                 PORTAbits.RA2
#define tempSensor_ANS                  ANCON0bits.ANSEL2
#define tempSensor_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define tempSensor_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define tempSensor_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define tempSensor_GetValue()           PORTAbits.RA2
#define tempSensor_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define tempSensor_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define tempSensor_SetAnalogMode()      do { ANCON0bits.ANSEL2 = 1; } while(0)
#define tempSensor_SetDigitalMode()     do { ANCON0bits.ANSEL2 = 0; } while(0)

// get/set extMicrophone aliases
#define extMicrophone_TRIS                 TRISAbits.TRISA3
#define extMicrophone_LAT                  LATAbits.LATA3
#define extMicrophone_PORT                 PORTAbits.RA3
#define extMicrophone_ANS                  ANCON0bits.ANSEL3
#define extMicrophone_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define extMicrophone_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define extMicrophone_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define extMicrophone_GetValue()           PORTAbits.RA3
#define extMicrophone_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define extMicrophone_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define extMicrophone_SetAnalogMode()      do { ANCON0bits.ANSEL3 = 1; } while(0)
#define extMicrophone_SetDigitalMode()     do { ANCON0bits.ANSEL3 = 0; } while(0)

// get/set Buzzer aliases
#define Buzzer_TRIS                 TRISCbits.TRISC0
#define Buzzer_LAT                  LATCbits.LATC0
#define Buzzer_PORT                 PORTCbits.RC0
#define Buzzer_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define Buzzer_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define Buzzer_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define Buzzer_GetValue()           PORTCbits.RC0
#define Buzzer_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define Buzzer_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

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

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

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