/*
 * ble.h
 *
 *  Created on:
 *      Author:
 */
//***********************************************************************************
// Include files
//***********************************************************************************
#ifndef	BLE_GUARD_H
#define	BLE_GUARD_H

//** Standard Libraries
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// Driver functions
#include "leuart.h"
#include "gpio.h"


//***********************************************************************************
// defined files
//***********************************************************************************

#define HM10_LEUART0		LEUART0
#define HM10_BAUDRATE		9600
#define	HM10_DATABITS		leuartDatabits8
#define HM10_ENABLE			leuartEnable
#define HM10_PARITY			leuartNoParity
#define HM10_REFFREQ		0					// use reference clock
#define HM10_STOPBITS		leuartStopbits1

#define LEUART0_TX_ROUTE	_LEUART_ROUTELOC0_TXLOC_LOC18   	// Route to ...
#define LEUART0_RX_ROUTE	_LEUART_ROUTELOC0_RXLOC_LOC18   	// Route to ...

#define CIRC_TEST 			true
#define CIRC_OPER 			false

//***********************************************************************************
// global variables
//***********************************************************************************
#define CSIZE 				64
typedef struct {
	char 		cbuf[CSIZE];
	uint8_t 	size_mask;
	uint32_t 	size;
	uint32_t 	read_ptr;
	uint32_t 	write_ptr;
} BLE_CIRCULAR_BUF;

#define CIRC_TEST_SIZE 		3
typedef struct {
	char 		test_str[CIRC_TEST_SIZE][CSIZE];
	char 		result_str[CSIZE];
} CIRC_TEST_STRUCT;

//***********************************************************************************
// function prototypes
//***********************************************************************************
void ble_open(uint32_t tx_event, uint32_t rx_event);
void ble_write(char *string);

bool ble_test(char *mod_name);

void circular_buff_test(void);
bool ble_circ_pop(bool test);


#endif


