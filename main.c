
#include "AVR_lib.h"
#include "LCD.h"
#include "UART.h"


int main(void)
{
    UART_init();
	LCD_init();
	
    while (1)
    {
		char message[32] = {};           // message of 32 Char LCD 16x2 = 32

		UART_ReceiveStr(message);

 		LCD_Clear();
		LCD_String(message);
		if (message[16] != 0)
		{
			char line2[16] = {};
			for(int i = 0; i<16; i++)
			{
				line2[i] = message[i+16];		
			}
			LCD_setCursor(1,0);
			LCD_String(line2);
		}
		UART_SendStr(message);
			_delay_ms(500);
    }
}

