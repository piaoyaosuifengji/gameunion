




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
	范例：    LeftMouseDown:1500:1:198,842,
	含义：模拟鼠标左键单击等待1.5秒,后面俩个数据就是单击位置的坐标
3:字符按下。包括24个字母，和数字。
	范例：    KeyDown:1500:1:m
	含义：表示输入一个字符m按下，并持续保持1.5秒不放开
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


4：自动寻路。自动定位到指定地图的指定坐标（注意：参数之间用逗号隔开）
	范例：    location:1500:3:福州城，x，y
*/

/*
MapName   ID  定义，用于location的字符串地名和ID的转化，
*/

#define MapNameID_LUOYANG			0		//洛阳城
#define MapNameID_FUZHOU			1		//福州城



#define  LEFTmouseUP   "LeftMouseUP"
#define  LEFTmouseDOWN   "LeftMouseDown"
#define  LEFTmouseClick   "LeftMouse"
#define  InputChar   "char"
#define  KeyDown   "KeyDown"   //某个键按下，但不放开
#define  Location   "location"
#define  KeyBoardKey   "keyboard"			//直接输入键盘码











//任务ID宏,有主任务ID和子任务ID之分，不同的主任务有不同的ID，高4位不同
//同一个主任务里面可以有不同的子任务，不同的子任务也有相应的ID
//他们的高4位相同，底四位不同
//主线任务ID，低四位为0
#define  TaskId_Mainline_0	  10010000		
#define  TaskId_Mainline_1	  10010001		//主线任务子任务--进入游戏
#define  TaskId_Mainline_2	  10010002		//主线任务子任务--接取第一个任务