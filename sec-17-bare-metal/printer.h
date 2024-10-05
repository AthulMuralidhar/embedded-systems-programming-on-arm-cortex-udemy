/*
 * printer.h
 *
 *  Created on: Aug 28, 2024
 *      Author: athul-muralidhar
 */

#ifndef PRINTER_H_
#define PRINTER_H_

// Define the ITM Stimulus Port register address (usually 0xE0000000 + offset)
#define ITM_STIMULUS_PORT0 (*(volatile uint32_t*)0xE0000000)

// Define the ITM_TCR (Trace Control Register) address (usually 0xE0000E80)
#define ITM_TCR (*(volatile uint32_t*)0xE0000E80)

// Define the ITM_TER (Trace Enable Register) address (usually 0xE0000E00)
#define ITM_TER (*(volatile uint32_t*)0xE0000E00)

// Function to send a character through ITM
void ITM_SendChar(char ch) {
	// Check if ITM_TCR.ITMENA is set
	if (ITM_TCR & 1) {
		// Check if stimulus port 0 is enabled
		if (ITM_TER & 1) {
			// Check if the stimulus port 0 is ready
			while (ITM_STIMULUS_PORT0 == 0);
			// Write the character to the stimulus port 0
			ITM_STIMULUS_PORT0 = ch;
		}
	}
}

// Function to send a string through ITM
void ITM_SendString(const char *str) {
	while (*str) {
		ITM_SendChar(*str++);
	}
}


#endif /* PRINTER_H_ */
