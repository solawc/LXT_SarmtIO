#include "dht11.h"


/****************************************************************
*@function: dht11_gpio_init
*@input   : none
*@output  : none
*@describe: DHT11 GPIO 初始化
*@author  : lxt
****************************************************************/
void dht11_gpio_init(void)
{ 

}

/****************************************************************
*@function: dht11_mode
*@input   : mode    0/1
*@output  : none
*@describe: DHT11 GPIO 模式切换
*@author  : lxt
****************************************************************/
void dht11_mode(uint8_t mode)
{
	// gpio_pin_config_t dht11_Config;
	uint32_t pin_status;

	// pin_status = GPIO_PinRead(DHT11_PORT, DHT11_PIN);

	// GPIO_read
	if(mode == 0)
	{

	}
	else if(mode == 1)
	{

	}
}

/****************************************************************
*@function: dht11_delay
*@input   : n (MHz)  
*@output  : none
*@describe: 延时
*@author  : lxt
****************************************************************/
void wait(unsigned long n)
{   
	do{
	n--;
	}while(n);
}

/****************************************************************
*@function: dht11_init
*@input   : none
*@output  : none
*@describe: DHT11 GPIO初始化--应用层
*@author  : sola
****************************************************************/
void dht11_config(void)
{
    __DHT11_GPIO_INIT();
}


/****************************************************************
*@function: ReadByte
*@input   : none
*@output  : temp
*@describe: ��һ���ֽ�
*@author  : sola
****************************************************************/
uint8_t ReadByte(void) {

	uint8_t i, temp = 0;

	for(i=0;i<8;i++) {

		while(__DHT11_READ() == 0);
		
		// CPU_TS_Tmr_Delay_US(60);//rt_thread_udelay(40);//__DHT11_DELAY_US(40);               //40us

		if(__DHT11_READ() == 1) {

			while(__DHT11_READ() == 1);

			temp |= (uint8_t)(0x01<<(7-i));
		}
		else {
			
			temp &= (uint8_t)~(0x01<<(7-i));
		}
	}	
	return temp;
} 