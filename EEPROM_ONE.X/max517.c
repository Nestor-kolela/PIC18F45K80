/*
 * File:   max517.c
 * Author: nestor
 *
 * Created on July 26, 2021, 3:56 PM
 */


#include <xc.h>
#include "I2C.h"


void MAX517_Init(void)
{
    return;
}
void MAX517_Update(const uint8_t data)
{
    i2c_start(); //send a start bit
    
    i2c_write(0x58); //send this  to the device
    
    i2c_write(0x00); //send this  to the device
    
    i2c_write(data); //send the value
    
    i2c_stop(); //send a stop bit
}
