#include "Mecanum.h"

//��ʼ��PC13��PE5Ϊ�����.��ʹ���������ڵ�ʱ��		    
//LED IO��ʼ��
void Mecanum_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);	 //ʹ��PA�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;				 //PA.0~7 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOC.13
 GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);	 //PA.0~7�����
}


void leftFrontForward(void)		//��ǰ����ǰת
{
	GPIO_SetBits(GPIOA,GPIO_Pin_0);
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}

void leftFronBackward(void)		//��ǰ�����ת
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
	GPIO_ResetBits(GPIOA,GPIO_Pin_0);
}

void rightFrontForward(void)		//��ǰ����ǰת
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
	GPIO_ResetBits(GPIOA,GPIO_Pin_3);
}

void rightFronBackward(void)		//��ǰ�����ת
{
	GPIO_SetBits(GPIOA,GPIO_Pin_3);
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}

void leftRearForward(void)		//�������ǰת
{
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
}

void leftRearBackward(void)		//��������ת
{
	GPIO_SetBits(GPIOA,GPIO_Pin_5);
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
}

void rightRearForward(void)		//�Һ�����ǰת
{
	GPIO_SetBits(GPIOA,GPIO_Pin_6);
	GPIO_ResetBits(GPIOA,GPIO_Pin_7);
}

void rightRearBackward(void)		//�Һ������ת
{
	GPIO_SetBits(GPIOA,GPIO_Pin_7);
	GPIO_ResetBits(GPIOA,GPIO_Pin_6);
}

void go(void)	//��ǰ
{
	leftFrontForward();		//��ǰ����ǰת
	rightFrontForward();	//��ǰ����ǰת
	leftRearForward();		//�������ǰת
	rightRearForward();		//�Һ�����ǰת
}

void back(void)		//���
{
	leftFronBackward();		//��ǰ�����ת
	rightFronBackward();	//��ǰ�����ת
	leftRearBackward();		//��������ת
	rightRearBackward();	//�Һ������ת
}

void left(void)		//��
{
	leftFronBackward();		//��ǰ�����ת
	rightFrontForward();	//��ǰ����ǰת
	leftRearForward();		//�������ǰת
	rightRearBackward();	//�Һ������ת
}

void right(void)		//��
{
	
	leftFrontForward();		//��ǰ����ǰת
	rightFronBackward();	//��ǰ�����ת
	leftRearBackward();		//��������ת
	rightRearForward();		//�Һ�����ǰת
}

void leftGo(void)		//��ǰ
{
	rightFrontForward();	//��ǰ����ǰת
	leftRearForward();		//�������ǰת
}

void rightGo(void)		//��ǰ
{
	
	leftFrontForward();		//��ǰ����ǰת
	rightRearForward();		//�Һ�����ǰת
}

void leftBack(void)		//���
{
	leftFronBackward();		//��ǰ�����ת
	rightRearBackward();	//�Һ������ת
}

void rightBack(void)		//�Һ�
{
	rightFronBackward();	//��ǰ�����ת
	leftRearBackward();		//��������ת
}

void clockwise(void)		//˳ʱ��
{
	leftFronBackward();		//��ǰ�����ת
	rightFrontForward();	//��ǰ����ǰת
	leftRearBackward();		//��������ת
	rightRearForward();		//�Һ�����ǰת
}

void reverse(void)		//��ʱ��,��Ϊcounterclockwise̫���ˣ�����������������
{
	leftFrontForward();		//��ǰ����ǰת
	rightFronBackward();	//��ǰ�����ת
	leftRearForward();		//�������ǰת
	rightRearBackward();	//�Һ������ת
}

void stop(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);	 //PA.0~7�����
}




