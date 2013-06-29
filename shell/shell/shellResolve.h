




//解析命令文件
//命令格式
//命令类型：命令执行时间：参数个数：参数
//其中参数可以有多个，用逗号分开
//'#'开头表示注释行

//命令类型：
/*
1:字符输入。包括24个字母，和数字。
	范例：    char:1500:1:m
	含义：表示输入一个字符m并等待1.5秒

2：鼠标操作
	范例：    LeftMouse:1500:1:198,842,
	含义：模拟鼠标左键单击等待1.5秒,后面俩个数据就是单击位置的坐标


const int MOUSEEVENTF_MOVE = 0x0001;      移动鼠标 
const int MOUSEEVENTF_LEFTDOWN = 0x0002; 模拟鼠标左键按下 
const int MOUSEEVENTF_LEFTUP = 0x0004; 模拟鼠标左键抬起 
const int MOUSEEVENTF_RIGHTDOWN = 0x0008; 模拟鼠标右键按下 
const int MOUSEEVENTF_RIGHTUP = 0x0010; 模拟鼠标右键抬起 
const int MOUSEEVENTF_MIDDLEDOWN = 0x0020; 模拟鼠标中键按下 
const int MOUSEEVENTF_MIDDLEUP = 0x0040; 模拟鼠标中键抬起 
const int MOUSEEVENTF_ABSOLUTE = 0x8000; 标示是否采用绝对坐标

LEFTmouse ; 模拟鼠标左键单击
RIGHT ; 模拟鼠标右键单击

*/

#define  LEFTmouseClick   "LeftMouse"
#define  InputChar   "char"