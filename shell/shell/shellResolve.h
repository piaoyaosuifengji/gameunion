




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
#define  RightmouseDOWN   "RightMouseDown"
#define  LEFTmouseClick   "LeftMouse"
#define  RightmouseClick   "RightMouse"
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
#define  TaskId_Mainline_3	  10010003		//主线任务子任务--接取第2个任务
#define  TaskId_Mainline_4	  10010004		//主线任务子任务--福州城 人靠衣装
#define  TaskId_Mainline_5	  10010005		//主线任务子任务--福州城 风云起，人挡杀人
#define  TaskId_Mainline_6	  10010006		//主线任务子任务--剑jiong
#define  TaskId_Mainline_7	  10010007		//主线任务子任务--风云起，福兮祸兮
#define  TaskId_Mainline_8	  10010008		//主线任务子任务--风云起，提剑御强敌
#define  TaskId_Mainline_9	  10010009		//主线任务子任务--风云起决战翻云摊
#define  TaskId_Mainline_10	  10010010		//主线任务子任务--唐门见血封侯
#define  TaskId_Mainline_11   10010011		//主线任务子任务--武当受精不争
#define  TaskId_Mainline_12   10010012		//主线任务子任务--武当受精不争
#define  TaskId_Mainline_13   10010013		//主线任务子任务--武当受精不争
#define  TaskId_Mainline_14   10010014		//主线任务子任务--武当受精不争
#define  TaskId_Mainline_15   10010015		//主线任务子任务--武当受精不争
#define  TaskId_Mainline_16   10010016		//主线任务子任务--武当受精不争
#define  TaskId_Mainline_17   10010017		//主线任务子任务--武当受精不争
#define  TaskId_Mainline_18   10010018		//主线任务子任务--沧海笑，追凶
#define  TaskId_Mainline_19   10010019		//主线任务子任务--沧海笑，争执