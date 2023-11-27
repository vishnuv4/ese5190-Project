/*
 * main.c
 *
 * Created: 11/23/2023 2:28:37 PM
 *  Author: vishn
 */ 
#include "main.h"

char rcv;

ISR(USART_RX_vect)
{
	rcv = UDR0;
	PORTD = char_lookup[rcv-' '];
}

ISR(TIMER1_CAPT_vect)
{
	UART_send('n');
	_delay_ms(50);
}

void init()
{
	cli();
	UART_init();
	DDRB |= (1<<PORTB5);
	DDRB |= (1<<PORTD2) | (1<<PORTD3) | (1<<PORTD4) | (1<<PORTD5) | (1<<PORTD6) | (1<<PORTD7);
	TCCR1B |= (1<<ICES1) | (1<<ICNC1);
	TIMSK1 |= (1<<ICIE1);
	sei();	
}

char str1[10];
int flag=1;
int main(void)
{
	init();
	_delay_ms(1000);
    while(1)
    {
	}
}
