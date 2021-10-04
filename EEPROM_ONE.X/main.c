/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F45K80
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "I2C.h"
#include "EEPROM.h"
#include "max517.h"
void EUSART1_putrs(const uint8_t * ptr);

void EUSART1_puts(uint8_t * ptr);

uint8_t Nestor;
/*
                         Main application
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

typedef union
{
    struct
    {
        uint8_t lowByte;
        uint8_t highByte;
    };
    
    uint16_t value;
}timerValue;
typedef enum
{
    ON,
    OFF,
}flag;

volatile flag myPlayFlag = OFF;
typedef enum
{
    RECORD = 1,
    PLAY,
    IDLE,
}state;

volatile state myState = IDLE;
volatile ADC myAdcValue;
volatile flag myFlag = OFF;
#define MAX_VALUE 120000

volatile uint8_t readBufOne[128];
volatile uint8_t readBufTwo[128];

volatile uint8_t bufNumber;

volatile uint8_t writeBufOne[128];
volatile uint8_t writeBufTwo[128];

volatile uint16_t page;
volatile uint8_t count;

volatile bool readOneIsFull;
volatile bool readTwoIsFull;

volatile uint24_t numOfBytesWritten;
volatile uint8_t stateMachine;
volatile uint8_t bufNum; 
void main(void)
{
    // Initialize the device

    
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();

    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    ADC_StartConversion(3); //read from channel 3

    I2C_INTIALIZE(400000);

    timerValue myTimer;

    myTimer.value = 0;
    
    page = 0;
    
    bufNum = 1;
    
    readOneIsFull = false;
    readTwoIsFull = false;
    
    numOfBytesWritten = 0;
   
#if 0
    TMR0_StopTimer();
    TMR0_WriteTimer(0); //set it to zero
    TMR0_StartTimer(); //start the timer brother LOL
    
    
    MAX517_Update(128);
    
    TMR0_StopTimer(); //stop the timer

    myTimer.value = TMR0_ReadTimer(); // 

    uint16_t result = 16 * myTimer.value;
    sprintf((char *) addr, "\r\nValue is %u microseconds\r\n", result);
    EUSART1_puts((uint8_t *) addr);
#endif
    myState = IDLE;
    
    
    while (1) 
    {
        // Add your application code
#if 0
        if (SW2_GetValue() == 0) 
        {
            __delay_ms(20);
            
            if(SW2_GetValue() == 0)
            {
                while(SW2_GetValue() == 0)
                {
                    continue;
                }
                
                LED_Toggle();
#if 0
                TMR0_StopTimer();
                TMR0_WriteTimer(0); //set it to zero
                TMR0_StartTimer(); //start the timer brother LOL
                
                EEPROM_WritePg(9, buf);
                
                //EUSART1_puts(EEPROM_ReadPg(0, buf));
                
                //EEPROM_gets(buf, 4*128, (4*128) + 127);
                //EEPROM_Read(0);
                
                
                //if(cnt == 3)
                //{
                //    cnt = 0;
                //}
                
                TMR0_StopTimer(); //stop the timer
                EEPROM_ReadPg(9, buf);
                EUSART1_putrs(buf);
                

                myTimer.value = TMR0_ReadTimer(); // 
                
                uint16_t result = 16 * myTimer.value;
                sprintf((char *)addr, "\r\nValue is %u microseconds\r\n", result);
                EUSART1_puts((uint8_t * ) addr);
                
#endif
                
                
                
            }//end if
        }
#endif
#if 0
        if (myFlag == ON) 
        {
            myFlag = OFF;
            sprintf(addr, "%u\r\n", myAdcValue.highByte);
            EUSART1_puts(addr);
        }
#endif
#if 1
        if(SW2_GetValue() == 0)
        {
            __delay_ms(20);
            if(SW2_GetValue() == 0)
            {
                while(SW2_GetValue() == 0)
                {
                    continue;
                }
                LED_Toggle(); //toggle the LED
                Buzzer_SetHigh();
                __delay_ms(1000);
                Buzzer_SetLow();
                // Disable high priority global interrupts
                INTERRUPT_GlobalInterruptHighDisable();

                // Disable low priority global interrupts.
                INTERRUPT_GlobalInterruptLowDisable();
                count = 0;
                page = 0;
                bufNumber = 1;
                readOneIsFull = false;
                readTwoIsFull = false;
                numOfBytesWritten = 0;
                PIE1bits.ADIE = 1;
                myState = RECORD; //set it to high

                // Enable high priority global interrupts
                INTERRUPT_GlobalInterruptHighEnable();

                // Enable low priority global interrupts.
                INTERRUPT_GlobalInterruptLowEnable();
                
            }
        }
        
        if(SW1_GetValue() == 0)
        {
            __delay_ms(20);
            if(SW1_GetValue() == 0)
            {
                while(SW1_GetValue() == 0)
                {
                    continue;
                }
                
                
#if 0
                TMR0_StopTimer();
                TMR0_WriteTimer(0); //set it to zero
                TMR0_StartTimer(); //start the timer brother LOL
                
                //EEPROM_WritePg(9, buf);
                
                EEPROM_Read(0);
                
                TMR0_StopTimer();
                
                myTimer.value = TMR0_ReadTimer(); // 
                
                uint16_t result = 16 * myTimer.value;
                sprintf((char *)addr, "\r\nValue is %u microseconds\r\n", result);
                EUSART1_puts((uint8_t * ) addr);
#endif 

#if 1
                LED_Toggle();
                Buzzer_SetHigh();
                __delay_ms(1000);
                Buzzer_SetLow();
                
                INTERRUPT_GlobalInterruptHighDisable();

                // Disable low priority global interrupts.
                INTERRUPT_GlobalInterruptLowDisable();
                
                count = 0;
                page = 0;
                bufNum = 1;
                readOneIsFull = false;
                readTwoIsFull = false;
                numOfBytesWritten = 0;
                
                PIE1bits.ADIE = 0;
                
                EEPROM_ReadPg(page++, (uint8_t *) readBufOne); //read it
                TMR1_Reload(); //
                myState = PLAY; //set it to high
                
                // Enable high priority global interrupts
                INTERRUPT_GlobalInterruptHighEnable();

                // Enable low priority global interrupts.
                INTERRUPT_GlobalInterruptLowEnable();
#endif

            }
        }
        if (myState == RECORD) 
        {
            if (readOneIsFull == true) 
            {
                readOneIsFull = false;
                EEPROM_WritePg(page++, (uint8_t *) readBufOne);
                
                numOfBytesWritten += 128;
            }
            if (readTwoIsFull == true) 
            {
                readTwoIsFull = false;
                EEPROM_WritePg(page++, (uint8_t *) readBufTwo);
                numOfBytesWritten += 128;
            }
            if (numOfBytesWritten >= 128000) 
            {
                //block the device from writing 
                myState = IDLE;
                Buzzer_SetHigh();
                __delay_ms(1000);
                Buzzer_SetLow();
            }
        } else if (myState == PLAY) //if(myState == PLAY)
        {
            if (myPlayFlag == ON) 
            {
                // Disable high priority global interrupts.
                INTERRUPT_GlobalInterruptHighDisable();
                myPlayFlag = OFF;
                // Enable high priority global interrupts
                INTERRUPT_GlobalInterruptHighEnable();
                if(bufNum == 1)
                {
                    MAX517_Update(readBufOne[count]);
                }else if(bufNum == 2)
                {
                    MAX517_Update(readBufTwo[count]);
                } 
            }
            if((count == 0) && (bufNum == 1))
            {
                //INTERRUPT_GlobalInterruptHighDisable();
                EEPROM_ReadPg(page++, (uint8_t *) readBufTwo); //read it
                //INTERRUPT_GlobalInterruptHighEnable();
            }else if ((count == 0) && (bufNum == 2))
            {
                //INTERRUPT_GlobalInterruptHighDisable();
                EEPROM_ReadPg(page++, (uint8_t *)readBufOne); //read it
                //INTERRUPT_GlobalInterruptHighEnable();
            }
            if (numOfBytesWritten >= 128000) 
            {
                //block the device from writing 
                MAX517_Update(0);
                myState = IDLE;
                Buzzer_SetHigh();
                __delay_ms(1000);
                Buzzer_SetLow();
            }
        }else
        {
            
        }
#endif
    }
}

void EUSART1_putrs(const uint8_t * ptr)
{
    while(*ptr) 
    {
        EUSART1_Write(*ptr++);
        while(!EUSART1_is_tx_done());
    }
     
}

void EUSART1_puts(uint8_t * ptr)
{
    while(*ptr)
    {
        EUSART1_Write(*ptr++);
        while(!EUSART1_is_tx_done());
    }
}
/**
 End of File
*/