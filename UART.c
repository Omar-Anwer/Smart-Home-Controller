#include "UART.h"

void UART_init()
{
	UBRRH = 0;                         // Set baud rate */
	UBRRL = 51;              
	UCSRB = (1<<TXEN)  | (1<<RXEN);       // Enable transmitter and Receiver
	UCSRC = (1<<URSEL) | (3<<UCSZ0);   // Set frame format: 8data, 1stop bit
}

void UART_SendByte(char data)
{
	while (!(UCSRA & (1<<UDRE)));     // Wait for empty transmit buffer
	UDR = data;                        	//Put data into buffer, sends the data
}


char UART_ReceiveByte(void)
{
	while (!(UCSRA & (1<<RXC)));                 	// Wait for empty transmit buffer
	return (UDR);                                   // Put data into buffer, sends the
}


void UART_SendStr(char *str) /* Send string of USART data function */
{
	unsigned int i = 0;
	while (str[i] != 0)
	{
		UART_SendByte(str[i++]); /* Send each char of string till the NULL */
	}
}


void UART_ReceiveStr(char* str)
{
	unsigned int i = 0;
	while(1)
	{
		str[i] = UART_ReceiveByte();
		if ( (str[i] == '\0') || (str[i] == '\n') || (str[i] == '\r') )
		{
			str[i] = 0;
			break;
		}
		++i;
	}
	
}
