	.cpu cortex-m4
	.arch armv7e-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
	.align	1
	.global	ITM_SendChar
	.syntax unified
	.thumb
	.thumb_func
	.type	ITM_SendChar, %function
ITM_SendChar:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	mov	r3, r0
	strb	r3, [r7, #7]
	ldr	r3, .L5
	ldr	r3, [r3]
	and	r3, r3, #1
	cmp	r3, #0
	beq	.L4
	ldr	r3, .L5+4
	ldr	r3, [r3]
	and	r3, r3, #1
	cmp	r3, #0
	beq	.L4
	nop
.L3:
	mov	r3, #-536870912
	ldr	r3, [r3]
	cmp	r3, #0
	beq	.L3
	mov	r2, #-536870912
	ldrb	r3, [r7, #7]	@ zero_extendqisi2
	str	r3, [r2]
.L4:
	nop
	adds	r7, r7, #12
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L6:
	.align	2
.L5:
	.word	-536867200
	.word	-536867328
	.size	ITM_SendChar, .-ITM_SendChar
	.align	1
	.global	ITM_SendString
	.syntax unified
	.thumb
	.thumb_func
	.type	ITM_SendString, %function
ITM_SendString:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #8
	add	r7, sp, #0
	str	r0, [r7, #4]
	b	.L8
.L9:
	ldr	r3, [r7, #4]
	adds	r2, r3, #1
	str	r2, [r7, #4]
	ldrb	r3, [r3]	@ zero_extendqisi2
	mov	r0, r3
	bl	ITM_SendChar
.L8:
	ldr	r3, [r7, #4]
	ldrb	r3, [r3]	@ zero_extendqisi2
	cmp	r3, #0
	bne	.L9
	nop
	nop
	adds	r7, r7, #8
	mov	sp, r7
	@ sp needed
	pop	{r7, pc}
	.size	ITM_SendString, .-ITM_SendString
	.global	PSP_of_tasks
	.data
	.align	2
	.type	PSP_of_tasks, %object
	.size	PSP_of_tasks, 16
PSP_of_tasks:
	.word	537001984
	.word	537000960
	.word	536999936
	.word	536998912
	.global	task_handlers
	.bss
	.align	2
	.type	task_handlers, %object
	.size	task_handlers, 16
task_handlers:
	.space	16
	.global	current_task
	.type	current_task, %object
	.size	current_task, 1
current_task:
	.space	1
	.text
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	bl	enable_processor_faults
	ldr	r0, .L12
	bl	init_scheduler_stack
	ldr	r2, .L12+4
	ldr	r3, .L12+8
	str	r2, [r3]
	ldr	r2, .L12+12
	ldr	r3, .L12+8
	str	r2, [r3, #4]
	ldr	r2, .L12+16
	ldr	r3, .L12+8
	str	r2, [r3, #8]
	ldr	r2, .L12+20
	ldr	r3, .L12+8
	str	r2, [r3, #12]
	bl	init_task_stacks
	mov	r0, #1000
	bl	init_systick_timer
	bl	switch_sp_to_psp
	bl	task1_handler
.L11:
	b	.L11
.L13:
	.align	2
.L12:
	.word	537000960
	.word	task1_handler
	.word	task_handlers
	.word	task2_handler
	.word	task3_handler
	.word	task4_handler
	.size	main, .-main
	.align	1
	.global	SysTick_Handler
	.syntax unified
	.thumb
	.thumb_func
	.type	SysTick_Handler, %function
SysTick_Handler:
	@ Naked Function: prologue and epilogue provided by programmer.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	.syntax unified
@ 75 "main.c" 1
	PUSH {LR}
@ 0 "" 2
@ 79 "main.c" 1
	MRS R0, PSP
@ 0 "" 2
@ 80 "main.c" 1
	STMDB R0!, {R4-R11}
@ 0 "" 2
@ 82 "main.c" 1
	BL save_psp_value
@ 0 "" 2
@ 86 "main.c" 1
	BL update_next_task
@ 0 "" 2
@ 88 "main.c" 1
	BL get_psp_value
@ 0 "" 2
@ 90 "main.c" 1
	LDR R4, [R0], #4
@ 0 "" 2
@ 91 "main.c" 1
	LDR R5, [R0], #4
@ 0 "" 2
@ 92 "main.c" 1
	LDR R6, [R0], #4
@ 0 "" 2
@ 93 "main.c" 1
	LDR R7, [R0], #4
@ 0 "" 2
@ 94 "main.c" 1
	LDR R8, [R0], #4
@ 0 "" 2
@ 95 "main.c" 1
	LDR R9, [R0], #4
@ 0 "" 2
@ 96 "main.c" 1
	LDR R10, [R0], #4
@ 0 "" 2
@ 97 "main.c" 1
	LDR R11, [R0], #4
@ 0 "" 2
@ 100 "main.c" 1
	MSR PSP, R0
@ 0 "" 2
@ 102 "main.c" 1
	POP {LR}
@ 0 "" 2
@ 105 "main.c" 1
	BX LR
@ 0 "" 2
	.thumb
	.syntax unified
	nop
	.size	SysTick_Handler, .-SysTick_Handler
	.align	1
	.global	update_next_task
	.syntax unified
	.thumb
	.thumb_func
	.type	update_next_task, %function
update_next_task:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	add	r7, sp, #0
	ldr	r3, .L16
	ldrb	r3, [r3]	@ zero_extendqisi2
	adds	r3, r3, #1
	uxtb	r2, r3
	ldr	r3, .L16
	strb	r2, [r3]
	ldr	r3, .L16
	ldrb	r3, [r3]	@ zero_extendqisi2
	and	r3, r3, #3
	uxtb	r2, r3
	ldr	r3, .L16
	strb	r2, [r3]
	nop
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L17:
	.align	2
.L16:
	.word	current_task
	.size	update_next_task, .-update_next_task
	.align	1
	.global	save_psp_value
	.syntax unified
	.thumb
	.thumb_func
	.type	save_psp_value, %function
save_psp_value:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	str	r0, [r7, #4]
	ldr	r3, .L19
	ldrb	r3, [r3]	@ zero_extendqisi2
	mov	r1, r3
	ldr	r2, .L19+4
	ldr	r3, [r7, #4]
	str	r3, [r2, r1, lsl #2]
	nop
	adds	r7, r7, #12
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L20:
	.align	2
.L19:
	.word	current_task
	.word	PSP_of_tasks
	.size	save_psp_value, .-save_psp_value
	.align	1
	.global	get_psp_value
	.syntax unified
	.thumb
	.thumb_func
	.type	get_psp_value, %function
get_psp_value:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	add	r7, sp, #0
	ldr	r3, .L23
	ldrb	r3, [r3]	@ zero_extendqisi2
	mov	r2, r3
	ldr	r3, .L23+4
	ldr	r3, [r3, r2, lsl #2]
	mov	r0, r3
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L24:
	.align	2
.L23:
	.word	current_task
	.word	PSP_of_tasks
	.size	get_psp_value, .-get_psp_value
	.align	1
	.global	switch_sp_to_psp
	.syntax unified
	.thumb
	.thumb_func
	.type	switch_sp_to_psp, %function
switch_sp_to_psp:
	@ Naked Function: prologue and epilogue provided by programmer.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	.syntax unified
@ 124 "main.c" 1
	PUSH {LR}
@ 0 "" 2
@ 127 "main.c" 1
	BL get_psp_value
@ 0 "" 2
@ 129 "main.c" 1
	MSR PSP,R0
@ 0 "" 2
@ 131 "main.c" 1
	POP {LR}
@ 0 "" 2
@ 135 "main.c" 1
	MOV R0,#0x02
@ 0 "" 2
@ 139 "main.c" 1
	MSR CONTROL, R0
@ 0 "" 2
@ 142 "main.c" 1
	BX LR
@ 0 "" 2
	.thumb
	.syntax unified
	nop
	.size	switch_sp_to_psp, .-switch_sp_to_psp
	.align	1
	.global	enable_processor_faults
	.syntax unified
	.thumb
	.thumb_func
	.type	enable_processor_faults, %function
enable_processor_faults:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	ldr	r3, .L27
	str	r3, [r7, #4]
	ldr	r3, [r7, #4]
	ldr	r3, [r3]
	orr	r2, r3, #65536
	ldr	r3, [r7, #4]
	str	r2, [r3]
	ldr	r3, [r7, #4]
	ldr	r3, [r3]
	orr	r2, r3, #131072
	ldr	r3, [r7, #4]
	str	r2, [r3]
	ldr	r3, [r7, #4]
	ldr	r3, [r3]
	orr	r2, r3, #262144
	ldr	r3, [r7, #4]
	str	r2, [r3]
	nop
	adds	r7, r7, #12
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L28:
	.align	2
.L27:
	.word	-536810204
	.size	enable_processor_faults, .-enable_processor_faults
	.align	1
	.global	init_task_stacks
	.syntax unified
	.thumb
	.thumb_func
	.type	init_task_stacks, %function
init_task_stacks:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #20
	add	r7, sp, #0
	movs	r3, #0
	str	r3, [r7, #8]
	b	.L30
.L33:
	ldr	r2, .L34
	ldr	r3, [r7, #8]
	ldr	r3, [r2, r3, lsl #2]
	str	r3, [r7, #12]
	ldr	r3, [r7, #12]
	subs	r3, r3, #4
	str	r3, [r7, #12]
	ldr	r3, [r7, #12]
	mov	r2, #16777216
	str	r2, [r3]
	ldr	r3, [r7, #12]
	subs	r3, r3, #4
	str	r3, [r7, #12]
	ldr	r2, .L34+4
	ldr	r3, [r7, #8]
	ldr	r2, [r2, r3, lsl #2]
	ldr	r3, [r7, #12]
	str	r2, [r3]
	ldr	r3, [r7, #12]
	subs	r3, r3, #4
	str	r3, [r7, #12]
	ldr	r3, [r7, #12]
	mvn	r2, #2
	str	r2, [r3]
	movs	r3, #0
	str	r3, [r7, #4]
	b	.L31
.L32:
	ldr	r3, [r7, #12]
	subs	r3, r3, #4
	str	r3, [r7, #12]
	ldr	r3, [r7, #12]
	movs	r2, #0
	str	r2, [r3]
	ldr	r3, [r7, #4]
	adds	r3, r3, #1
	str	r3, [r7, #4]
.L31:
	ldr	r3, [r7, #4]
	cmp	r3, #12
	ble	.L32
	ldr	r2, [r7, #12]
	ldr	r1, .L34
	ldr	r3, [r7, #8]
	str	r2, [r1, r3, lsl #2]
	ldr	r3, [r7, #8]
	adds	r3, r3, #1
	str	r3, [r7, #8]
.L30:
	ldr	r3, [r7, #8]
	cmp	r3, #3
	ble	.L33
	nop
	nop
	adds	r7, r7, #20
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L35:
	.align	2
.L34:
	.word	PSP_of_tasks
	.word	task_handlers
	.size	init_task_stacks, .-init_task_stacks
	.align	1
	.global	init_scheduler_stack
	.syntax unified
	.thumb
	.thumb_func
	.type	init_scheduler_stack, %function
init_scheduler_stack:
	@ Naked Function: prologue and epilogue provided by programmer.
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	mov	r3, r0
	.syntax unified
@ 191 "main.c" 1
	MSR MSP,r3
@ 0 "" 2
@ 193 "main.c" 1
	BX LR
@ 0 "" 2
	.thumb
	.syntax unified
	nop
	.size	init_scheduler_stack, .-init_scheduler_stack
	.align	1
	.global	init_systick_timer
	.syntax unified
	.thumb
	.thumb_func
	.type	init_systick_timer, %function
init_systick_timer:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #28
	add	r7, sp, #0
	str	r0, [r7, #4]
	ldr	r3, .L38
	str	r3, [r7, #20]
	ldr	r3, .L38+4
	str	r3, [r7, #16]
	ldr	r2, .L38+8
	ldr	r3, [r7, #4]
	udiv	r3, r2, r3
	subs	r3, r3, #1
	str	r3, [r7, #12]
	ldr	r3, [r7, #20]
	movs	r2, #0
	str	r2, [r3]
	ldr	r3, [r7, #20]
	ldr	r2, [r3]
	ldr	r3, [r7, #12]
	orrs	r2, r2, r3
	ldr	r3, [r7, #20]
	str	r2, [r3]
	ldr	r3, [r7, #16]
	ldr	r3, [r3]
	orr	r2, r3, #2
	ldr	r3, [r7, #16]
	str	r2, [r3]
	ldr	r3, [r7, #16]
	ldr	r3, [r3]
	orr	r2, r3, #4
	ldr	r3, [r7, #16]
	str	r2, [r3]
	ldr	r3, [r7, #16]
	ldr	r3, [r3]
	orr	r2, r3, #1
	ldr	r3, [r7, #16]
	str	r2, [r3]
	nop
	adds	r7, r7, #28
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L39:
	.align	2
.L38:
	.word	-536813548
	.word	-536813552
	.word	16000000
	.size	init_systick_timer, .-init_systick_timer
	.section	.rodata
	.align	2
.LC0:
	.ascii	"in task 1 handler\012\000"
	.text
	.align	1
	.global	task1_handler
	.syntax unified
	.thumb
	.thumb_func
	.type	task1_handler, %function
task1_handler:
	@ args = 0, pretend = 0, frame = 56
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #56
	add	r7, sp, #0
.L41:
	adds	r3, r7, #4
	ldr	r2, .L42
	movs	r1, #50
	mov	r0, r3
	bl	snprintf
	adds	r3, r7, #4
	mov	r0, r3
	bl	ITM_SendString
	b	.L41
.L43:
	.align	2
.L42:
	.word	.LC0
	.size	task1_handler, .-task1_handler
	.section	.rodata
	.align	2
.LC1:
	.ascii	"in task 2 handler\012\000"
	.text
	.align	1
	.global	task2_handler
	.syntax unified
	.thumb
	.thumb_func
	.type	task2_handler, %function
task2_handler:
	@ args = 0, pretend = 0, frame = 56
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #56
	add	r7, sp, #0
.L45:
	adds	r3, r7, #4
	ldr	r2, .L46
	movs	r1, #50
	mov	r0, r3
	bl	snprintf
	adds	r3, r7, #4
	mov	r0, r3
	bl	ITM_SendString
	b	.L45
.L47:
	.align	2
.L46:
	.word	.LC1
	.size	task2_handler, .-task2_handler
	.section	.rodata
	.align	2
.LC2:
	.ascii	"in task 3 handler\012\000"
	.text
	.align	1
	.global	task3_handler
	.syntax unified
	.thumb
	.thumb_func
	.type	task3_handler, %function
task3_handler:
	@ args = 0, pretend = 0, frame = 56
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #56
	add	r7, sp, #0
.L49:
	adds	r3, r7, #4
	ldr	r2, .L50
	movs	r1, #50
	mov	r0, r3
	bl	snprintf
	adds	r3, r7, #4
	mov	r0, r3
	bl	ITM_SendString
	b	.L49
.L51:
	.align	2
.L50:
	.word	.LC2
	.size	task3_handler, .-task3_handler
	.section	.rodata
	.align	2
.LC3:
	.ascii	"in task 4 handler\012\000"
	.text
	.align	1
	.global	task4_handler
	.syntax unified
	.thumb
	.thumb_func
	.type	task4_handler, %function
task4_handler:
	@ args = 0, pretend = 0, frame = 56
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	sub	sp, sp, #56
	add	r7, sp, #0
.L53:
	adds	r3, r7, #4
	ldr	r2, .L54
	movs	r1, #50
	mov	r0, r3
	bl	snprintf
	adds	r3, r7, #4
	mov	r0, r3
	bl	ITM_SendString
	b	.L53
.L55:
	.align	2
.L54:
	.word	.LC3
	.size	task4_handler, .-task4_handler
	.section	.rodata
	.align	2
.LC4:
	.ascii	"exception in hard fault\000"
	.text
	.align	1
	.global	HardFault_Handler
	.syntax unified
	.thumb
	.thumb_func
	.type	HardFault_Handler, %function
HardFault_Handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r0, .L58
	bl	puts
.L57:
	b	.L57
.L59:
	.align	2
.L58:
	.word	.LC4
	.size	HardFault_Handler, .-HardFault_Handler
	.section	.rodata
	.align	2
.LC5:
	.ascii	"exception in MemManage_Handler\000"
	.text
	.align	1
	.global	MemManage_Handler
	.syntax unified
	.thumb
	.thumb_func
	.type	MemManage_Handler, %function
MemManage_Handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r0, .L62
	bl	puts
.L61:
	b	.L61
.L63:
	.align	2
.L62:
	.word	.LC5
	.size	MemManage_Handler, .-MemManage_Handler
	.section	.rodata
	.align	2
.LC6:
	.ascii	"exception in BusFault_Handlern\000"
	.text
	.align	1
	.global	BusFault_Handler
	.syntax unified
	.thumb
	.thumb_func
	.type	BusFault_Handler, %function
BusFault_Handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	ldr	r0, .L66
	bl	printf
.L65:
	b	.L65
.L67:
	.align	2
.L66:
	.word	.LC6
	.size	BusFault_Handler, .-BusFault_Handler
	.ident	"GCC: (15:13.2.rel1-2) 13.2.1 20231009"
