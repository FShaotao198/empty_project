#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "wdg.h"
 



 int main(void)
 {		
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
 	LED_Init();
	KEY_Init();          //按键初始化	 
	LED0=0;
	delay_ms(300);	  
	WWDG_Init(0X7F,0X5F,WWDG_Prescaler_8);//计数器值为7f,窗口寄存器为5f,分频数为8	   
 	while(1)
	{
		LED0=1;			  	   
	}   
}
  

