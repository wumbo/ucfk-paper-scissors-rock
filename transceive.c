#include "system.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "tinygl.h"

char transceive(char my_symbol)
{
	int i;
	char their_symbol;

	while (1)
	{
		ir_uart_putc(my_symbol);

		if (ir_uart_read_ready_p()) {
			for (i = 0; i < 50; i++) {
				ir_uart_putc(my_symbol);
			}
			their_symbol = ir_uart_getc();
			for (i = 0; i < 50; i++) {
				ir_uart_putc(my_symbol);
			}
			return their_symbol;
		}
	}
}