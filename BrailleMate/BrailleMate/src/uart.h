// #ifndef UART_HEADER
// #define UART_HEADER

// /*Macros*/
// #ifndef F_CPU
// /* prevent compiler error by supplying a default */
// # warning "F_CPU not defined for uart.h"
// # define F_CPU 16000000UL
// #endif

// #define  BAUD_RATE_REGISTER(BAUD_RATE) ((F_CPU/(BAUD_RATE * 16UL)) - 1)

// /*Function prototypes*/
// extern void UART_Init(unsigned short baudrate);
// extern void UART_SendData(char *Data);

// #endif //UART_HEADER







#ifndef UART_H
#define UART_H

void UART_init(void);
void UART_send(unsigned char data);
void UART_putstring(char* StringPtr);




#endif 