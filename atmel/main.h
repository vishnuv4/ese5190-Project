/*
 * main.h
 *
 * Created: 11/26/2023 10:08:14 PM
 *  Author: vishn
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 16000000UL
#define BAUD_RATE 9600
#define BAUD_PRESCALER ((((F_CPU) / ((BAUD_RATE) * 16UL))) - 1)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

extern const char char_lookup[95];

void UART_init();
void UART_send(unsigned char data);
void UART_putstring(char* StringPtr);

#endif /* MAIN_H_ */