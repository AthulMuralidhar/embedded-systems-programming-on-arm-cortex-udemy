/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#define SRAM_START 0x20000000U
#define SRAM_SIZE  (128*1024)
#define SRAM_END  ((SRAM_START) + (SRAM_SIZE))

#define STACK_START  (SRAM_END)
#define STACK_MSP_START  (STACK_START)
#define STACK_MSP_END  ((STACK_MSP_START) - 512)
#define STACK_PSP_START  (STACK_MSP_END)

void generate_exception();
void __attribute__((naked)) change_stack_pointer_to_process_stack_pointer();

int main(void)
{
	change_stack_pointer_to_process_stack_pointer();


	int result;

	result = add(1,2);

	printf("result: %d\n", result);

	generate_exception();


    /* Loop forever */
	for(;;);
}

void generate_exception() {
	__asm volatile("SVC #0x2");
}


void SVC_Handler() {
	printf("fake exception in svc handler");
}


void __attribute__((naked)) change_stack_pointer_to_process_stack_pointer() {
	// assembly macros
	__asm volatile(".equ SRAM_END, (0x20000000 + (128*1024))");
	__asm volatile(".equ STACK_PSP_START, (SRAM_END - 512)");

	// Initialize process_stack_pointer
	__asm volatile("LDR R0,=STACK_PSP_START");
	// copy r0 to process_stack_pointer
	__asm volatile("MSR PSP,R0");
	// change stack pointer to process_stack_pointer

	__asm volatile("MOV R0,0x02");   // the 1st bit when set to 1 sets the stack pointer to process_stack_pointer
	__asm volatile("MSR CONTROL,R0");
}

int add(int a, int b) {
	return a+b;
}
