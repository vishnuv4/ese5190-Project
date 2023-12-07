#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include "ASCII_LUT.h"
#include "speaker.h"
// Define the CPU frequency (16 MHz for the Arduino).
// This is necessary for _delay_ms() to work properly.


#include "uart.h"
//#define BAUD_RATE 9600

/*************************Function Prototypes****************************/

void Initialize(void);
void ADC_Init(void);
void Buzzer_PWMInit(void);
void TimerInit(void);
uint16_t adc_read = 512;
char String[25];/*string for printing data over uart*/

const char speaker_lookup[95] = {
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
	36, //'0',
	28, //'1',
	29, //'2',
	30, //'3',
	31, //'4',
	32, //'5',
	33, //'6',
	34, //'7',
	35, //'8',
	1, //'9',
	0b01001000, //':',
	0b00011000, //';',
	0, //'<',
	0, //'=',
	0, //'>',
	0, //'?',
	0, //'@',
	0b00000100, //'A',
	0b00001100, //'B',
	0b00100100, //'C',
	0b01100100, //'D',
	0b01000100, //'E',
	0b00101100, //'F',
	0b01101100, //'G',
	0b01001100, //'H',
	0b00101000, //'I',
	0b00011010, //'J',
	0b00010100, //'K',
	0b00011100, //'L',
	0b00110100, //'M',
	0b01110100, //'N',
	0b01010100, //'O',
	0b00111100, //'P',
	0b01111100, //'Q',
	0b01011100, //'R',
	0b00111000, //'S',
	0b01111000, //'T',
	0b10010100, //'U',
	0b10011100, //'V',
	0b11101000, //'W',
	0b00101100, //'X',
	0b11110100, //'Y',
	0b11010100, //'Z',
	0, //'[',
	0, //'\\',
	0, //']',
	0, //'^',
	0, //'_',
	0, //'`',
	2, //'a',
	3, //'b',
	4, //'c',
	5, //'d',
	6, //'e',
	7, //'f',
	8, //'g',
	9, //'h',
	10, //'i',
	11, //'j',
	12, //'k',
	13, //'l',
	14, //'m',
	15, //'n',
	16, //'o',
	17, //'p',
	18, //'q',
	19, //'r',
	20, //'s',
	21, //'t',
	22, //'u',
	23, //'v',
	24, //'w',
	25, //'x',
	26, //'y',
	27, //'z',
	0, //'{',
		0, //'|',
		0, //'~',
	};


int main(void)
{
    Initialize();
	char ChSel = 0;
	char ChCount = 0;
	int16_t offset = 0;
	
	while (1) // loop forever
	{
		speaker_play(speaker_lookup['f'-' ']);
		_delay_ms(10000);
		// if(((600 < adc_read )  && (adc_read < 1024))|| (adc_read < 400))
		// {
		// 	offset = ((adc_read ) < 512)?-1:1;
		// 	adc_read  = 1024 ;//max impossible value for adc
		// 	if(ChSel == 1)
		// 	{
		// 		//print
		// 		if((offset < 0) && (ChCount == 0))
		// 		{
		// 			ChCount = 64;
		// 		}
		// 		ChCount += offset; 
		// 		if(offset > 0)
		// 		{
		// 			//sprintf(String,"Next Character\n");
		// 			//UART_SendData(String);
		// 		}
		// 		else
		// 		{
		// 			//sprintf(String,"Prev Character\n");
		// 			//UART_SendData(String);
		// 		}
		// 		OCR2A = 70;
		// 		_delay_ms(1000);
		// 		OCR2A = 0;
		// 	}
		// 	else
		// 	{
		// 		ChSel = 1;
		// 		//sprintf(String,"Character sel started\n");
		// 		//UART_SendData(String);
		// 	}
		// }
		// if((400 < adc_read) && (adc_read < 600))
		// {
		// 	if(ChSel)
		// 	{
		// 		ChSel = 0;
		// 		ChCount = ChCount%64;
		// 		if(ChCount >= 12 && ChCount <= 16)
		// 		{
		// 			ChCount = (ChCount - 12) + 11;
		// 		}
		// 		//sprintf(String,"INPUT READ = %c ch count = %d\n",char_value[ChCount],ChCount);
		// 		//UART_SendData(String);
		// 		PORTD = char_lookup[ChCount];
		// 		/*speaker play module*/
		// 		speaker_play(char_value[ChCount] - ' ');
		// 	}
		// }
	}
}

/***************************Function Definitions*****************************/
void Initialize(void)
{
    //disable interrupt
	cli();
	UART_init();
	//DDRD |= (1<<PORTD2) | (1<<PORTD3) | (1<<PORTD4) | (1<<PORTD5) | (1<<PORTD6) | (1<<PORTD7);
	//TimerInit();
	//ADC_Init();
	//Buzzer_PWMInit();
	speaker_begin();
	_delay_ms(1000);
	sei();
}


void ADC_Init(void)
{
	/*Select Vref = AVcc*/
	ADMUX |= (1 << REFS0);
	/*Trigger conversion on Timer0 compare match A*/
	ADCSRB |= (1 << ADTS0) | (1 << ADTS2);
	/*Enable ADC conversion, auto trigger and interrupt generate */
	ADCSRA |= (1 << ADEN) | (1 << ADATE) | (1 << ADIE);
	/*start ADC cpnversion*/
	ADCSRA |= (1 << ADSC);
	
}

void Buzzer_PWMInit(void)
{
    DDRB |= (1 << PB3);
    /*Set to CTC mode and toggle OC0A for every output compare match*/
    TCCR2A |= (1 << WGM20) | (1 << COM2A0);
    /*Set Prescaler Value for TIMER0 to 256*/
    TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << WGM22);
    /*Set output compare register for 440Hz to 70: ((F_CPU / (2 * prescaler * 440)) - 1) */
    //OCR2A = 70;
}

void TimerInit(void)
{
	//Enable prescaling for clock source
	CLKPR |= (1 << CLKPCE);
	/*CTC mode*/
	//Setting 16-bit control register:Prescaling = 1024 for input compare register
	TCCR1B |= (1 << CS12);// | (1<<CS10);//|(1 << WGM12);
	/*Hit and trial value for tick tick big enough*/
	OCR1B = 200;
	//Enable output compare interrupt for output compare B
	TIMSK1 |= (1<< OCIE1B);
}

ISR(ADC_vect)
{
	adc_read = (unsigned char)ADCL;
	adc_read |= ((ADCH & 0x03)<<8);
	//sprintf(String,"ADC read triggered = %d\n",adc_read);
	//UART_SendData(String);
}

ISR(TIMER1_COMPB_vect)
{
	
}


