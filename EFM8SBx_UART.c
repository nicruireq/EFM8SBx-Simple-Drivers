/*
 * EFM8SBx_UART.c
 *
 *  Created on: 2 de jul. de 2020
 *      Author: Nicolas
 */

#include "EFM8SBx_UART.h"

void UART_Initialize(float baud_rate) {
	uint8_t reload_value;
	uint8_t TCON_save;

	reload_value = (uint8_t) (256.0f
			- (UART_SYSCLK / 12.0f) / (2.0f * baud_rate));

	TCON_save = TCON;
	//Stop Timers
	TCON &= ~TCON_TR0__BMASK & ~TCON_TR1__BMASK;
	TH1 = (0xF7 << TH1_TH1__SHIFT);
	//Restore Timer Configuration
	TCON |= (TCON_save & TCON_TR0__BMASK) | (TCON_save & TCON_TR1__BMASK);
	// Timer 1 mode 2
	TMOD = TMOD_T0M__MODE0 | TMOD_T1M__MODE2 | TMOD_CT0__TIMER
			| TMOD_GATE0__DISABLED | TMOD_CT1__TIMER | TMOD_GATE1__DISABLED;
	TCON |= TCON_TR1__RUN;
	// UART reception enabled
	SCON0 |= SCON0_REN__RECEIVE_ENABLED;
}

void UART_send(uint8_t payload) {
	SBUF0 = payload;
	while (SCON0_TI == 0)
		;
	SCON0_TI = 0;
}

uint8_t UART_Receive() {
	uint8_t rx_payload;
	while (SCON0_RI == 0)
		;
	rx_payload = SBUF0;
	SCON0_RI = 0;
	return (rx_payload);
}

void UART_Send_string(uint8_t * str)
{
	while (*str != '\0')
	{
		UART_send(*str);
		++str;
	}
}

