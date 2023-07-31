/*
 * spi_test.c
 *
 * Created: 2023-07-31 오후 3:31:24
 * Author : WARP000046N
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include "spi.h"
#include "uart.h"

int main(void)
{
	sei();
    SPI_init();
    while (1) 
    {
    }
}

ISR(SPI0_INT_vect)
{
	uint8_t received_byte = SPI0_GetRxData();
	SPI0.INTFLAGS = SPI_RXCIF_bm;
	UART_sendChar(received_byte);
	received_byte = 0;
}