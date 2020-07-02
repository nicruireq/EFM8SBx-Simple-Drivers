/*
 * EFM8SBx_UART.h
 *
 *  Created on: 2 de jul. de 2020
 *      Author: Nicolas
 *
 *      Minimal configuration for uart
 *
 *      pre:
 *      	SYSCLK is HFOSC / 1
 */

#ifndef INC_EFM8SBX_UART_H_
#define INC_EFM8SBX_UART_H_

#include <stdint.h>

#define EFM8BB1

#ifdef EFM8SB1
#include <SI_EFM8SB1_Register_Enums.h>
#endif
#ifdef EFM8SB2
#include <SI_EFM8SB2_Register_Enums.h>
#endif
#ifdef EFM8BB1
#include <SI_EFM8BB1_Register_Enums.h>
#endif

// Default frequency from HFOSC clock
#define UART_SYSCLK 24500000.0f

void UART_Initialize(float baud_rate);

/**
 * \brief Send one byte, blocking,
 * 		  polling implementation
 */
void UART_send(uint8_t payload);

/**
 * \brief Waits until receives a byte,
 * 		  polling implementation
 */
uint8_t UART_Receive();
void UART_Send_string(uint8_t * str);

#endif /* INC_EFM8SBX_UART_H_ */
