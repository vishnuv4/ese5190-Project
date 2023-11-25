/*
 * main.c
 *
 * Created: 11/23/2023 2:28:37 PM
 *  Author: vishn
 */ 
#define F_CPU 16000000UL
#define BAUD_RATE 9600
#define BAUD_PRESCALER ((((F_CPU) / ((BAUD_RATE) * 16UL))) - 1)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

int isr_entry_cnt=0;
int rxcn_bit_set=0;

void UART_init()
{
	
	/*Set baud rate */
	UBRR0H = (unsigned char)(BAUD_PRESCALER>>8);
	UBRR0L = (unsigned char)BAUD_PRESCALER;
	//Enable receiver and transmitter
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	/* Set frame format: 2 stop bits, 8 data bits */
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00); // 8 data bits
	UCSR0C |= (1<<USBS0); // 2 stop bits
	
	UCSR0B |= (1<<RXCIE0);
}

void UART_send(unsigned char data)
{
	// Wait for empty transmit buffer
	while(!(UCSR0A & (1<<UDRE0)));
	// Put data into buffer and send data
	UDR0 = data;
	
}

const char char_lookup[95] = {
	0, //' ',
	0, //'!',
	0, //'"',
	0, //'#',
	0, //'$',
	0, //'%',
	0, //'&',
	0, //''',
	0, //'(',
	0, //')',
	0, //'*',
	0, //'+',
	0, //',',
	0, //'-',
	0, //'.',
	0, //'/',
	0b110100, //'0',
	0b100, //'1',
	0b1100, //'2',
	0b100100, //'3',
	0b1100100, //'4',
	0b1000100, //'5',
	0b101100, //'6',
	0b1101100, //'7',
	0b1001100, //'8',
	0b101000, //'9',
	0b1001000, //':',
	0b11000, //';',
	0, //'<',
	0, //'=',
	0, //'>',
	0, //'?',
	0, //'@',
	0b100, //'A',
	0b1100, //'B',
	0b100100, //'C',
	0b1100100, //'D',
	0b1000100, //'E',
	0b101100, //'F',
	0b1101100, //'G',
    0b1001100, //'H',
    0b101000, //'I',
    0b11010, //'J',
    0b10100, //'K',
    0b11100, //'L',
    0b110100, //'M',
    0b1110100, //'N',
    0b1010100, //'O',
    0b111100, //'P',
    0b1111100, //'Q',
    0b1011100, //'R',
    0b111000, //'S',
    0b1111000, //'T',
    0b10010100, //'U',
    0b10011100, //'V',
    0b11101000, //'W',
    0b101100, //'X',
    0b11110100, //'Y',
    0b11010100, //'Z',
    0, //'[',
    0, //'\\',
    0, //']',
    0, //'^',
    0, //'_',
    0, //'`',
	0b100, //'a',
	0b1100, //'b',
	0b100100, //'c',
	0b1100100, //'d',
	0b1000100, //'e',
	0b101100, //'f',
	0b1101100, //'g',
    0b1001100, //'h',
    0b101000, //'i',
    0b11010, //'j',
    0b10100, //'k',
    0b11100, //'l',
    0b110100, //'m',
    0b1110100, //'n',
    0b1010100, //'o',
    0b111100, //'p',
    0b1111100, //'q',
    0b1011100, //'r',
    0b111000, //'s',
    0b1111000, //'t',
    0b10010100, //'u',
    0b10011100, //'v',
    0b11101000, //'w',
    0b101100, //'x',
    0b11110100, //'y',
    0b11010100, //'z',
    0, //'{',
    0, //'|',
    0, //'~',
	};

void UART_putstring(char* StringPtr)
{
	while(*StringPtr != 0x00)
	{
		UART_send(*StringPtr);
		StringPtr++;
	}
}
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
