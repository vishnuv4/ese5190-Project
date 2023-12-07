/*
 * main.c
 *
 * Created: 11/23/2023 2:28:37 PM
 *  Author: vishn
 */ 
#include "speaker.h"
#include "main.h"

#define rxPin 10
#define txPin 11

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
    speaker_begin();
	_delay_ms(1000);
    uint8_t filenum=1;

    //0 - reading, 1 - learning
    int mode = 0;

    while(1)
    {
//        speaker_play(speaker_lookup['0' - ' ']);
//        filenum += 1;
//        filenum = filenum%36;
//        _delay_ms(3000);
	}
}
