# Moses

## 简介

一个麦克纳姆轮的四驱智能小车。可以通过蓝牙来控制小车的前进、后退等10个动作。后期会加入摄像头、机械臂等功能（待议）。

A four-wheel drive smart car with Mecanum wheels. 10 actions such as forward and backward of the car can be controlled via Bluetooth.

## 项目寓意

根据《圣经·出埃及记》的记载：
>他带领希伯来人经过红海的时候，神使海水分开，露出一片干地，海水在他们的左右作了墙壁。希伯来人渡海如履平地。
>
>在埃及兵追入红海的时候，神使海水合起来，淹没了追赶他们的追兵，使得他们顺利逃脱。

摩西受上帝之命率领被奴役的以色列人逃离古埃及，前往一块富饶之地迦南，经历40多年的艰难跋涉，他就要到达目的地的时候就去世了。在摩西的带领下古以色列人摆脱了被奴役的悲惨命运，学会遵守十诫，并成为历史上首个尊奉一神宗教的民族。

## 硬件组成

主控芯片：STM32F103C8T6

电机驱动：L298N

蓝牙模块：HC-05

电动机：TT电机（减速比1：48）

电池：18650 * 2

## TODOLIST

- 安卓 APP
- PWM 调速