/*
 * main.h
 *
 *  Created on: Sep 28, 2024
 *      Author: athul-muralidhar
 */

#ifndef MAIN_H_
#define MAIN_H_

// number of tasks
#define MAX_TASKS 4

// stack sizes
#define SIZE_TASK_STACK  1024U
#define SIZE_SCHEDULER_STACK  1024U
// SRAM
#define SRAM_START 0x20000000U
#define SIZE_SRAM  ((128) * (1024))
#define SRAM_END  ((SRAM_START) + SIZE_SRAM)
// tasks
#define T1_STACK_START SRAM_END
#define T2_STACK_START ((SRAM_END) - (SIZE_TASK_STACK))
#define T3_STACK_START ((SRAM_END) - (2 * SIZE_TASK_STACK))
#define T4_STACK_START ((SRAM_END) - (3 * SIZE_TASK_STACK))
// scheduler
#define SCHEDULER_STACK_START ((SRAM_END) - (SIZE_TASK_STACK))
// desired exception frequency
#define EXCEPTION_FREQUENCY 1000U
// high speed internal clock - the value is given in the st32f4xxx reference manual
#define HSI_CLOCK  16000000U
#define SYSTICK_TIMER_CLOCK HSI_CLOCK

#define DUMMY_XPSR  0x01000000U  // this is for the T bit of the ARM processor

// this is a magic number for Link Register in Cortex M chips
// The specific value 0xFFFFFFFD indicates that the processor should return
// to Thread mode using the main stack pointer (MSP
#define RETURN_TO_THREAD_MODE 0xFFFFFFFD

#endif /* MAIN_H_ */
