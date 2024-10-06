#include <stdint.h>

#define SRAM_START 0x20000000U
#define SRAM_SIZE ((128) * (1024)) // 128 Kb
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))

#define STACT_START SRAM_END

// external symbols from the ld file
extern uint32_t _end_of_text_section;
extern uint32_t _start_of_data_section;
extern uint32_t _end_of_data_section;
extern uint32_t _start_of_bss_section;
extern uint32_t _end_of_bss_section;



// main's prototype
int main();

/*
VMA - virtual memory address is the address which is mapped to the specific hardware
LMA - load memory address is the address that the compiler compiles to first before linking
      and relocation
*/

void Reset_Handler();

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));
void WWDG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ADC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN1_TX_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN1_RX0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN1_SCE_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FSMC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SDIO_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void UART5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ETH_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ETH_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN2_TX_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN2_RX0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN2_RX1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CAN2_SCE_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void OTG_HS_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DCMI_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void CRYP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void HASH_RNG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FPU_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

// 1. create the vector table
/*
the __attribute__((section(...))) instructs the compiler to store this constant in a section
in the assembly code called ".isr_vector". Typically this is stored in .data but as this is the
startup code and we need to intialize the vector table in the SRAM_START address as per ARM spec.
*/
uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
    STACT_START,
    (uint32_t)(uintptr_t)Reset_Handler,
    (uint32_t)(uintptr_t)NMI_Handler,
    (uint32_t)(uintptr_t)HardFault_Handler,
    (uint32_t)(uintptr_t)MemManage_Handler,
    (uint32_t)(uintptr_t)BusFault_Handler,
    (uint32_t)(uintptr_t)UsageFault_Handler,
    0,
    0,
    0,
    0,

    (uint32_t)(uintptr_t)SVC_Handler,
    (uint32_t)(uintptr_t)DebugMon_Handler,
    0,
    (uint32_t)(uintptr_t)PendSV_Handler,
    (uint32_t)(uintptr_t)SysTick_Handler,
    (uint32_t)(uintptr_t)WWDG_IRQHandler,
    (uint32_t)(uintptr_t)PVD_IRQHandler,
    (uint32_t)(uintptr_t)TAMP_STAMP_IRQHandler,
    (uint32_t)(uintptr_t)RTC_WKUP_IRQHandler,
    0,
    (uint32_t)(uintptr_t)RCC_IRQHandler,
    (uint32_t)(uintptr_t)EXTI0_IRQHandler,
    (uint32_t)(uintptr_t)EXTI1_IRQHandler,
    (uint32_t)(uintptr_t)EXTI2_IRQHandler,
    (uint32_t)(uintptr_t)EXTI3_IRQHandler,
    (uint32_t)(uintptr_t)EXTI4_IRQHandler,
    (uint32_t)(uintptr_t)DMA1_Stream0_IRQHandler,
    (uint32_t)(uintptr_t)DMA1_Stream1_IRQHandler,
    (uint32_t)(uintptr_t)DMA1_Stream2_IRQHandler,
    (uint32_t)(uintptr_t)DMA1_Stream3_IRQHandler,
    (uint32_t)(uintptr_t)DMA1_Stream4_IRQHandler,
    (uint32_t)(uintptr_t)DMA1_Stream5_IRQHandler,
    (uint32_t)(uintptr_t)DMA1_Stream6_IRQHandler,
    (uint32_t)(uintptr_t)ADC_IRQHandler,
    (uint32_t)(uintptr_t)CAN1_TX_IRQHandler,
    (uint32_t)(uintptr_t)CAN1_RX0_IRQHandler,
    (uint32_t)(uintptr_t)CAN1_RX1_IRQHandler,
    (uint32_t)(uintptr_t)CAN1_SCE_IRQHandler,
    (uint32_t)(uintptr_t)EXTI9_5_IRQHandler,
    (uint32_t)(uintptr_t)TIM1_BRK_TIM9_IRQHandler,
    (uint32_t)(uintptr_t)TIM1_UP_TIM10_IRQHandler,
    (uint32_t)(uintptr_t)TIM1_TRG_COM_TIM11_IRQHandler,
    (uint32_t)(uintptr_t)TIM1_CC_IRQHandler,
    (uint32_t)(uintptr_t)TIM2_IRQHandler,
    (uint32_t)(uintptr_t)TIM3_IRQHandler,
    (uint32_t)(uintptr_t)TIM4_IRQHandler,
    (uint32_t)(uintptr_t)I2C1_EV_IRQHandler,
    (uint32_t)(uintptr_t)I2C1_ER_IRQHandler,
    (uint32_t)(uintptr_t)I2C2_EV_IRQHandler,
    (uint32_t)(uintptr_t)I2C2_ER_IRQHandler,
    (uint32_t)(uintptr_t)SPI1_IRQHandler,
    (uint32_t)(uintptr_t)SPI2_IRQHandler,
    (uint32_t)(uintptr_t)USART1_IRQHandler,
    (uint32_t)(uintptr_t)USART2_IRQHandler,
    (uint32_t)(uintptr_t)USART3_IRQHandler,
    (uint32_t)(uintptr_t)EXTI15_10_IRQHandler,
    (uint32_t)(uintptr_t)RTC_Alarm_IRQHandler,
    (uint32_t)(uintptr_t)OTG_FS_WKUP_IRQHandler,
    (uint32_t)(uintptr_t)TIM8_BRK_TIM12_IRQHandler,
    (uint32_t)(uintptr_t)TIM8_UP_TIM13_IRQHandler,
    (uint32_t)(uintptr_t)TIM8_TRG_COM_TIM14_IRQHandler,
    (uint32_t)(uintptr_t)TIM8_CC_IRQHandler,
    (uint32_t)(uintptr_t)DMA1_Stream7_IRQHandler,
    (uint32_t)(uintptr_t)FSMC_IRQHandler,
    (uint32_t)(uintptr_t)SDIO_IRQHandler,
    (uint32_t)(uintptr_t)TIM5_IRQHandler,
    (uint32_t)(uintptr_t)SPI3_IRQHandler,
    (uint32_t)(uintptr_t)UART4_IRQHandler,
    (uint32_t)(uintptr_t)UART5_IRQHandler,
    (uint32_t)(uintptr_t)TIM6_DAC_IRQHandler,
    (uint32_t)(uintptr_t)TIM7_IRQHandler,
    (uint32_t)(uintptr_t)DMA2_Stream0_IRQHandler,
    (uint32_t)(uintptr_t)DMA2_Stream1_IRQHandler,
    (uint32_t)(uintptr_t)DMA2_Stream2_IRQHandler,
    (uint32_t)(uintptr_t)DMA2_Stream3_IRQHandler,
    (uint32_t)(uintptr_t)DMA2_Stream4_IRQHandler,
    (uint32_t)(uintptr_t)ETH_IRQHandler,
    (uint32_t)(uintptr_t)ETH_WKUP_IRQHandler,
    (uint32_t)(uintptr_t)CAN2_TX_IRQHandler,
    (uint32_t)(uintptr_t)CAN2_RX0_IRQHandler,
    (uint32_t)(uintptr_t)CAN2_RX1_IRQHandler,
    (uint32_t)(uintptr_t)CAN2_SCE_IRQHandler,
    (uint32_t)(uintptr_t)OTG_FS_IRQHandler,
    (uint32_t)(uintptr_t)DMA2_Stream5_IRQHandler,
    (uint32_t)(uintptr_t)DMA2_Stream6_IRQHandler,
    (uint32_t)(uintptr_t)DMA2_Stream7_IRQHandler,
    (uint32_t)(uintptr_t)USART6_IRQHandler,
    (uint32_t)(uintptr_t)I2C3_EV_IRQHandler,
    (uint32_t)(uintptr_t)I2C3_ER_IRQHandler,
    (uint32_t)(uintptr_t)OTG_HS_EP1_OUT_IRQHandler,
    (uint32_t)(uintptr_t)OTG_HS_EP1_IN_IRQHandler,
    (uint32_t)(uintptr_t)OTG_HS_WKUP_IRQHandler,
    (uint32_t)(uintptr_t)OTG_HS_IRQHandler,
    (uint32_t)(uintptr_t)DCMI_IRQHandler,
    (uint32_t)(uintptr_t)CRYP_IRQHandler,
    (uint32_t)(uintptr_t)HASH_RNG_IRQHandler,
    (uint32_t)(uintptr_t)FPU_IRQHandler,
};

void Default_Handler()
{
    while (1)
    {
    };
}

void Reset_Handler()
{
    // 1. copy .data section to SRAM
    uint32_t SRAM_size = &_end_of_data_section - &_start_of_data_section;

    uint8_t *pSource_Addr = (uint8_t*) &_end_of_text_section; // in FLASH
    uint8_t *pDestination_Addr = (uint8_t*)(uintptr_t) &_start_of_data_section; // in SRAM


    for (uint32_t i = 0; i < SRAM_size; i++)
    {
        // copy data from FLASH to SRAM
        *pDestination_Addr++ = *pSource_Addr++;
    }
    

    // 2. initialise the .bss section to zero in SRAM
    uint32_t bss_size = &_end_of_bss_section - &_start_of_bss_section;
    pDestination_Addr = (uint8_t*)(uintptr_t) &_start_of_bss_section; // in SRAM

    for (uint32_t i = 0; i < bss_size; i++)
    {
        // set the dest addr to 0 and increment
        *pDestination_Addr++ = 0;
    }
    


    // call init functoin of standard library
    // call main()
    main();

}

