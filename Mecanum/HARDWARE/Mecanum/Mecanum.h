#ifndef __MECANUM_H
#define __MECANUM_H	 
#include "sys.h"

void Mecanum_Init(void);	//初始化
void go(void);				//向前
void back(void);			//向后
void left(void);			//左
void right(void);			//右
void leftGo(void);			//左前
void rightGo(void);			//右前
void leftBack(void);		//左后
void rightBack(void);		//右后
void clockwise(void);		//顺时针
void reverse(void);		//逆时针
void stop(void);
		 				    
#endif


