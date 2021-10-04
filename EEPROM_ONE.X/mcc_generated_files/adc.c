/**
  ADC Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adc.c

  @Summary
    This is the generated driver implementation file for the ADC driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides implementations for driver APIs for ADC.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F45K80
        Driver Version    :  2.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB             :  MPLAB X 5.45
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "adc.h"
#include "device_config.h"


void (*ADC_InterruptHandler)(void);

/**
  Section: ADC Module APIs
*/
typedef union
{
    struct
    {
        uint8_t lowByte;
        uint8_t highByte;
    };
    uint16_t value;
}ADC;

extern volatile ADC myAdcValue;

typedef enum
{
    RECORD = 1,
    PLAY,
    IDLE,
}state;

extern volatile state myState;
typedef enum
{
    ON,
    OFF,
}flag;
extern volatile flag myFlag;
extern volatile uint8_t readBufOne[128];
extern volatile uint8_t readBufTwo[128];

extern volatile uint8_t bufNumber;

extern volatile uint8_t writeBufOne[128];
extern volatile uint8_t writeBufTwo[128];


extern volatile uint16_t page;
extern volatile uint8_t count;

extern volatile uint32_t numOfBytesWritten;
extern volatile bool readOneIsFull;
extern volatile bool readTwoIsFull;

void ADC_Initialize(void)
{
    // set the ADC to the options selected in the User Interface
    
    // GO_nDONE stop; ADON enabled; CHS AN0; 
    ADCON0 = 0x01;
    
    // TRIGSEL Timer1; VNCFG AVSS; VCFG AVDD; CHSN AVss; 
    ADCON1 = 0x80;
    
    // ADFM Left; ACQT 2_Tad; ADCS FOSC/64; 
    ADCON2 = 0x0E;
    
    // ADRESH 0; 
    ADRESH = 0x00;
    
    // ADRESL 0; 
    ADRESL = 0x00;
    
    // Enabling ADC interrupt.
    PIE1bits.ADIE = 1;
	
	// Set Default Interrupt Handler
    ADC_SetInterruptHandler(ADC_DefaultInterruptHandler);
}

void ADC_StartConversion(adc_channel_t channel)
{
    // select the A/D channel
    ADCON0bits.CHS = channel;

    // Turn on the ADC module
    ADCON0bits.ADON = 1;

    
    // Start the conversion
    ADCON0bits.GO_nDONE = 1;
}

bool ADC_IsConversionDone(void)
{
    // Start the conversion
    return ((unsigned char)(!ADCON0bits.GO_nDONE));
}

adc_result_t ADC_GetConversionResult(void)
{
    // Conversion finished, return the result
    return ((adc_result_t)((ADRESH << 8) + ADRESL));
}

adc_result_t ADC_GetConversion(adc_channel_t channel)
{
    // Select the A/D channel
    ADCON0bits.CHS = channel;

    // Turn on the ADC module
    ADCON0bits.ADON = 1;


    // Start the conversion
    ADCON0bits.GO_nDONE = 1;

    // Wait for the conversion to finish
    while (ADCON0bits.GO_nDONE)
    {
    }
    
    // Conversion finished, return the result
    return ((adc_result_t)((ADRESH << 8) + ADRESL));
}

void ADC_TemperatureAcquisitionDelay(void)
{
    __delay_us(200);
}

void ADC_ISR(void)
{
    // Clear the ADC interrupt flag
    PIR1bits.ADIF = 0;
	
	if(ADC_InterruptHandler)
    {
        ADC_InterruptHandler();
    }
}

void ADC_SetInterruptHandler(void (* InterruptHandler)(void)){
    ADC_InterruptHandler = InterruptHandler;
}

void ADC_DefaultInterruptHandler(void) {
    // add your ADC interrupt custom code
    myAdcValue.value = ADC_GetConversionResult();
    if (myState == RECORD) 
    {

        if (bufNumber == 1) {

            readBufOne[count++] = myAdcValue.highByte;
            if (count == 128) 
            {
                bufNumber = 2;
                count = 0;
                readTwoIsFull = false;
                readOneIsFull = true;
                return; //return here brother
            }
        } else if (bufNumber == 2) {
            readBufTwo[count++] = myAdcValue.highByte; //read this
            if (count == 128) 
            {
                bufNumber = 1;
                count = 0;
                readOneIsFull = false;
                readTwoIsFull = true;
                return;
            }

        }
    }
    // or set custom function using ADC_SetInterruptHandler()
}


/**
 End of File
 */