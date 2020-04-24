#include "Mecanum.h"

//初始化PC13和PE5为输出口.并使能这两个口的时钟		    
//LED IO初始化
void Mecanum_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	 //使能PA端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;				 //PA.0~7 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOC.13
 GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);	 //PA.0~7输出高
}


void leftFrontForward(void)		//左前轮向前转
{
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}

void leftFronBackward(void)		//左前轮向后转
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
}

void rightFrontForward(void)		//右前轮向前转
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
	GPIO_ResetBits(GPIOA,GPIO_Pin_3);
}

void rightFronBackward(void)		//右前轮向后转
{
	GPIO_SetBits(GPIOA,GPIO_Pin_3);
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}

void leftRearForward(void)		//左后轮向前转
{
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
}

void leftRearBackward(void)		//左后轮向后转
{
	GPIO_SetBits(GPIOA,GPIO_Pin_5);
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
}

void rightRearForward(void)		//右后轮向前转
{
	GPIO_SetBits(GPIOA,GPIO_Pin_6);
	GPIO_ResetBits(GPIOA,GPIO_Pin_7);
}

void rightRearBackward(void)		//右后轮向后转
{
	GPIO_SetBits(GPIOA,GPIO_Pin_7);
	GPIO_ResetBits(GPIOA,GPIO_Pin_6);
}

void go(void)	//向前
{
	leftFrontForward();		//左前轮向前转
	rightFrontForward();	//右前轮向前转
	leftRearForward();		//左后轮向前转
	rightRearForward();		//右后轮向前转
}

void back(void)		//向后
{
	leftFronBackward();		//左前轮向后转
	rightFronBackward();	//右前轮向后转
	leftRearBackward();		//左后轮向后转
	rightRearBackward();	//右后轮向后转
}

void left(void)		//左
{
	leftFronBackward();		//左前轮向后转
	rightFrontForward();	//右前轮向前转
	leftRearForward();		//左后轮向前转
	rightRearBackward();	//右后轮向后转
}

void right(void)		//右
{
	
	leftFrontForward();		//左前轮向前转
	rightFronBackward();	//右前轮向后转
	leftRearBackward();		//左后轮向后转
	rightRearForward();		//右后轮向前转
}

void leftGo(void)		//左前
{
	rightFrontForward();	//右前轮向前转
	leftRearForward();		//左后轮向前转
}

void rightGo(void)		//右前
{
	
	leftFrontForward();		//左前轮向前转
	rightRearForward();		//右后轮向前转
}

void leftBack(void)		//左后
{
	leftFronBackward();		//左前轮向后转
	rightRearBackward();	//右后轮向后转
}

void rightBack(void)		//右后
{
	rightFronBackward();	//右前轮向后转
	leftRearBackward();		//左后轮向后转
}

void clockwise(void)		//顺时针
{
	leftFronBackward();		//左前轮向后转
	rightFrontForward();	//右前轮向前转
	leftRearBackward();		//左后轮向后转
	rightRearForward();		//右后轮向前转
}

void reverse(void)		//逆时针,因为counterclockwise太长了，超出蓝牙传输限制
{
	leftFrontForward();		//左前轮向前转
	rightFronBackward();	//右前轮向后转
	leftRearForward();		//左后轮向前转
	rightRearBackward();	//右后轮向后转
}

void stop(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);	 //PA.0~7输出高
}




