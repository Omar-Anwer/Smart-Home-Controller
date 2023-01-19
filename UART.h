#ifndef UART
#define UART

#include "AVR_lib.h"

void UART_init();
void UART_SendByte(char data);
char UART_ReceiveByte(void);
void UART_SendStr(char *str);
void UART_ReceiveStr(char* str);

#endif