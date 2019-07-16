#include "stm32f4xx.h"                  // Device header

uint32_t SysTickCounter;

void delay_ms(uint32_t delay)
{
		SysTickCounter=delay;
		while(SysTickCounter!=0){}
}
void SysTick_Handler()
{
		if(SysTickCounter !=0x00)
	  {
	     SysTickCounter--;
	  }
}
int main()
{
	RCC->AHB1ENR|=0x08;
	GPIOD->MODER|=0x1000000;
	
	SysTick_Config(SystemCoreClock/1000);
	
	while(1)
	{
		GPIOD->ODR^=1<<12;
		delay_ms(1000);
	}
}
