#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "Mecanum.h"
#include "string.h"
#include "led.h"




int main(void)
{
    u8 reclen=0;
    delay_init();	    //延时函数初始化
    uart_init(9600);	 //串口初始化为9600
    Mecanum_Init();	  	//初始化与LED连接的硬件接口
	LED_Init();
    GPIO_ResetBits(GPIOC,GPIO_Pin_13);  //LED0对应引脚GPIOC.13拉低，亮
	//delay_ms(3000);
	stop();
    while(1)
    {
        if(USART_RX_STA&0x8000)
        {
            reclen=USART_RX_STA&0X7FFF;	//得到数据长度
            USART_RX_BUF[reclen]=0;	 	//加入结束符
			if(strcmp((const char*)USART_RX_BUF,"go")==0)
			{
				go();
			}
			if(strcmp((const char*)USART_RX_BUF,"back")==0)
			{
				back();
			}
			if(strcmp((const char*)USART_RX_BUF,"left")==0)
			{
				left();
			}
			if(strcmp((const char*)USART_RX_BUF,"right")==0)
			{
				right();
			}
			if(strcmp((const char*)USART_RX_BUF,"leftGo")==0)
			{
				leftGo();
			}
			if(strcmp((const char*)USART_RX_BUF,"rightGo")==0)
			{
				rightGo();
			}
			if(strcmp((const char*)USART_RX_BUF,"leftBack")==0)
			{
				leftBack();
			}
			if(strcmp((const char*)USART_RX_BUF,"rightBack")==0)
			{
				rightBack();
			}
			if(strcmp((const char*)USART_RX_BUF,"clockwise")==0)
			{
				clockwise();
			}
			if(strcmp((const char*)USART_RX_BUF,"reverse")==0)
			{
				reverse();
			}
			if(strcmp((const char*)USART_RX_BUF,"stop")==0)
			{
				stop();
			}
            USART_RX_STA=0;
        }
    }
}





