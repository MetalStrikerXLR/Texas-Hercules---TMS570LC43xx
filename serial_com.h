/*
 * serial_com.h
 *
 *  Created on: Jul 28, 2019
 *      Author: MetalStriker
 */

#ifndef FQMC_SYSTEM_INCLUDE_SERIAL_COM_H_
#define FQMC_SYSTEM_INCLUDE_SERIAL_COM_H_

#include "HL_sci.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Serialbegin(int baudrate)
{
    sciInit();
    sciSetBaudrate(sciREG1, baudrate);
}

void Serialprint(char * String_data)
{
    uint32 length = strlen(String_data);
    sciSend(sciREG1, length, (unsigned char*) String_data);
}

void Serialprint_n(int value)
{
    unsigned char data[15] = { 0 };
    unsigned int length = ltoa(value, (char *) data);
    sciSend(sciREG1, length, data);
}

void Serialprint_f(float value)
{
    char data[15] = { 0 };

    sprintf(&data[0], "%f", value);

    uint32 length = strlen((char*) data);
    sciSend(sciREG1, length, (unsigned char*) data);
}

void Serialprintln(char * String_data)
{
    uint32 length = strlen(String_data);
    sciSend(sciREG1, length, (unsigned char*) String_data);
    sciSend(sciREG1, 2, (unsigned char*) "\r\n");
}

#endif /* FQMC_SYSTEM_INCLUDE_SERIAL_COM_H_ */
