
// udemy course content link: https://github.com/niekiran/CortexMxProgramming/tree/master/Source_code/015_task_scheduler

/*
COMPILATION

- we should use the arm-none-eabi-gcc:
arm-none-eabi-gcc -c -mcpu=cortex-m4 -mthumb main.c -o main.o


the main.c goes through these steps: main.c -> main.i -> main.s -> main.o
main.i is intermediate representation
main.s is assemnbly
main.o is pure binary


- `-c`: stop at compile time, do not link
- `-S`: stop at assmebly language do not compile


- to find the disassembly:
arm-none-eabi-objdump -d main.o > main.log
for all sections:
arm-none-eabi-objdump -D main.o > main.log


 */

#include <stdint.h>
#include <stdio.h>
#include "main.h"
#include "printer.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// system tick timer initialization
void init_systick_timer(uint32_t freq);
// scheduler stack initialization
__attribute__((naked)) void init_scheduler_stack(uint32_t top_of_stack);
// tasks
void task1_handler();
void task2_handler();
void task3_handler();
void task4_handler();
// enable all faults
void enable_processor_faults();
// naked function to switch from MSP to PSP
__attribute__((naked)) void switch_sp_to_psp();
// Initialize tasks to dummy variables
void init_task_stacks();

uint32_t PSP_of_tasks[MAX_TASKS] = {
	T1_STACK_START,
	T2_STACK_START,
	T3_STACK_START,
	T4_STACK_START};

uint32_t task_handlers[MAX_TASKS];

uint8_t current_task = 1; // task 2 is running

int main(void)
{

	enable_processor_faults();

	init_scheduler_stack(SCHEDULER_STACK_START);

	task_handlers[0] = (uint32_t)task1_handler;
	task_handlers[1] = (uint32_t)task2_handler;
	task_handlers[2] = (uint32_t)task3_handler;
	task_handlers[3] = (uint32_t)task4_handler;

	init_task_stacks();

	init_systick_timer(EXCEPTION_FREQUENCY);

	switch_sp_to_psp(); // we have to switch so that we can run the task in thread mode

	task1_handler();

	/* Loop forever */
	for (;;)
	{
	};
}

__attribute__((naked)) void SysTick_Handler()
{
	__asm volatile("PUSH {LR}"); // save LR before it gets corrupted by helper functions

	// save the context of the current task
	// 1. get the current PSP value
	__asm volatile("MRS R0, PSP");
	__asm volatile("STMDB R0!, {R4-R11}");
	// 3.save the new value of PSP after storing the extra content
	__asm volatile("BL save_psp_value");

	// retrieve the context of the next task
	// 1. set the next task to run
	__asm volatile("BL update_next_task");
	// 2. get the PSP value of new task
	__asm volatile("BL get_psp_value");
	// 3. load registers r4-r11
	__asm volatile("LDR R4, [R0], #4");
	__asm volatile("LDR R5, [R0], #4");
	__asm volatile("LDR R6, [R0], #4");
	__asm volatile("LDR R7, [R0], #4");
	__asm volatile("LDR R8, [R0], #4");
	__asm volatile("LDR R9, [R0], #4");
	__asm volatile("LDR R10, [R0], #4");
	__asm volatile("LDR R11, [R0], #4");

	// 4. update PSP and exit
	__asm volatile("MSR PSP, R0");
	// retrieve LR so that we can go back to main
	__asm volatile("POP {LR}");

	// return to main
	__asm volatile("BX LR");
}

void update_next_task()
{
	current_task++;
	current_task %= MAX_TASKS;
}

void save_psp_value(uint32_t current_psp_value)
{
	PSP_of_tasks[current_task] = current_psp_value;
}

uint32_t get_psp_value()
{
	return PSP_of_tasks[current_task];
}

__attribute__((naked)) void switch_sp_to_psp()
{
	// 1. Initialize PSP to task 1 stack start - as this is the first task we want to run
	__asm volatile("PUSH {LR}");
	// save LR value for later so that we can return back to main function
	// get the value of PSP of the current task
	__asm volatile("BL get_psp_value");
	// the uint32 return value is stored in r0 which we can use
	__asm volatile("MSR PSP,R0");
	// Initialize PSP to point to our current task
	__asm volatile("POP {LR}");
	// return LR to point to main function

	// 2. change from SP to PSP using the CONTROL register
	__asm volatile("MOV R0,#0x02");
	// setting the 2nd bit in r0
	// this writes r0 to CONTROL register, thereby setting the 2nd bit to one and
	// changing execution from MSP to PSP
	__asm volatile("MSR CONTROL, R0");

	// 3. return to main
	__asm volatile("BX LR");
}

void enable_processor_faults()
{
	uint32_t *pSHCSR_ADDRESS = (uint32_t *)0xE000ED24; // System Handler Control and State Register

	*pSHCSR_ADDRESS |= (1 << 16); // UsageFault enable bit
	*pSHCSR_ADDRESS |= (1 << 17); // BusFault enable bit,
	*pSHCSR_ADDRESS |= (1 << 18); // MemManage enable bit,
}

void init_task_stacks()
{
	uint32_t *pPSP;

	for (int i = 0; i < MAX_TASKS; i++)
	{
		pPSP = (uint32_t *)PSP_of_tasks[i]; // gets the current task's stack start

		// XPSR
		pPSP--; // full descending stack
		*pPSP = DUMMY_XPSR;

		// PC
		pPSP--;
		// the task handlers have to be maintained at 1 as the least significant bit is the
		// T bit which has to be set to 1 always
		*pPSP = task_handlers[i];

		// LR
		pPSP--;
		*pPSP = RETURN_TO_THREAD_MODE;

		// for GPIO registers r0 to r12
		for (int j = 0; j < 13; j++)
		{
			pPSP--;
			*pPSP = 0;
		}

		// NOTE: we need to save the value back to the PSP_of_tasks
		// only then does the processor pop all the states for us
		PSP_of_tasks[i] = (uint32_t)pPSP;
	}
}

// naked function as MSP is a special register and it is not accessible through C code
__attribute__((naked)) void init_scheduler_stack(uint32_t top_of_stack)
{
	__asm volatile("MSR MSP,%0" ::"r"(top_of_stack) :);
	// return to the caller
	__asm volatile("BX LR");
}

void init_systick_timer(uint32_t freq)
{
	// SYSTICK reload value register: 0xE000E014
	uint32_t *pSystick_Reload_Value_Register = (uint32_t *)0xE000E014;
	// SYSTICK control and status register (SCSR): 0xE000E010
	uint32_t *pSystick_Control_And_Status_Register = (uint32_t *)0xE000E010;

	uint32_t count_value = SYSTICK_TIMER_CLOCK / freq - 1;

	// clear the value in the SVR
	*pSystick_Reload_Value_Register &= ~(0x00FFFFFFFF); // only 0 to 24 bits are valid in this register

	// load value
	*pSystick_Reload_Value_Register |= count_value;

	// settings for the SCSR
	*pSystick_Control_And_Status_Register |= (1 << 1); // Enables SysTick exception request
	*pSystick_Control_And_Status_Register |= (1 << 2); // sets the clock source to processor clock

	// enables the SYSTICK
	*pSystick_Control_And_Status_Register |= (1 << 0);
}

void task1_handler()
{
	char buffer[50]; // global buffer for the printer
	while (1)
	{
		snprintf(buffer, sizeof(buffer), "in task 1 handler\n");
		ITM_SendString(buffer);
	}
}

void task2_handler()
{
	char buffer[50]; // global buffer for the printer
	while (1)
	{
		snprintf(buffer, sizeof(buffer), "in task 2 handler\n");
		ITM_SendString(buffer);
	}
}

void task3_handler()
{
	char buffer[50]; // global buffer for the printer
	while (1)
	{
		snprintf(buffer, sizeof(buffer), "in task 3 handler\n");
		ITM_SendString(buffer);;
	}
}

void task4_handler()
{
	char buffer[50]; // global buffer for the printer
	while (1)
	{
		snprintf(buffer, sizeof(buffer), "in task 4 handler\n");
		ITM_SendString(buffer);
	}
}

void HardFault_Handler()
{
	printf("exception in hard fault\n");
	while (1)
	{
	};
}

void MemManage_Handler()
{
	printf("exception in MemManage_Handler\n");
	while (1)
	{
	};
}
void BusFault_Handler()
{
	printf("exception in BusFault_Handlern");
	while (1)
	{
	};
}
