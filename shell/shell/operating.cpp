

#include "stdafx.h"
#include <afxmt.h>
#include "fileoperating.h"
#include "operating.h"



	//分析struct operat数组，找到需要进行的操作的相关函数
     //当又错误时返回一个负数，就是错误位置在struct operat数组中的序号
   //返回》0时表示一切正常
int haveToDo(int countINFact,struct operat * p,struct dodo * todo)
{
	int res=0;

	if(countINFact <1 || p == NULL || todo == NULL)
		return res;
    int i=0;
	struct operat *currentDo;
	struct dodo * justDoIt;
	for(;i<countINFact;i++)
	{
		currentDo=&p[i];
		justDoIt=&todo[i];
		
		if(currentDo->shelltype.Compare(_T(LEFTmouseClick)) ==0)
		{
			if(currentDo->ParameterNum != 2)
				return (-1)*i;
			justDoIt->funcID=1;
			justDoIt->paramet.p1.delyTime=currentDo->time;

			int loct=currentDo->Parameter.Find(_T(","));
			CString x=currentDo->Parameter.Left(loct);
			CString y=currentDo->Parameter.Right(currentDo->Parameter.GetLength()-loct-1);
			int Y=_wtoi(y);
			int X=_wtoi(x);

			justDoIt->paramet.p1.X=X;
			justDoIt->paramet.p1.Y=Y;
		}
		if(currentDo->shelltype.Compare(_T(InputChar)) ==0)
		{
			if(currentDo->ParameterNum != 1)
				return (-1)*i;
			justDoIt->funcID=2;
			justDoIt->paramet.p2.delyTime=currentDo->time;
			//TCHAR * tchar=currentDo->Parameter.GetAt(1);
			//char  * _char;
			//TcharToChar ( tchar, _char);
			justDoIt->paramet.p2.c=currentDo->Parameter.GetAt(0);
		}


	}

	return i;
}


int runShell(int countINFact,struct dodo *todo)
{
	int res=-1;

	if(countINFact <1  || todo == NULL)
		return res;
    int i=0;
	struct dodo * justDoIt;
	for(;i<countINFact;i++)
	{
		justDoIt=&todo[i];
		switch(justDoIt->funcID)
		{
		case 1:
			sendALeftMuoseClick(justDoIt->paramet.p1.X,justDoIt->paramet.p1.Y ,justDoIt->paramet.p1.delyTime);
			break;
		case 2:
			ToInPutChar(justDoIt->paramet.p2.c,justDoIt->paramet.p2.delyTime);
			break;
		default:break;
		}

	}
	return res;
}


	  void sendALeftMuoseClick(int X,int Y ,int delyTime)  //参数为click的位置，及点击后延迟多少秒
	  {
		  SetCursorPos(X,Y);
		  		    Sleep(400);
			 mouse_event (MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
		    Sleep(delyTime);


	  }
	  /*
const int MOUSEEVENTF_MOVE = 0x0001;      移动鼠标 
const int MOUSEEVENTF_LEFTDOWN = 0x0002; 模拟鼠标左键按下 
const int MOUSEEVENTF_LEFTUP = 0x0004; 模拟鼠标左键抬起 
const int MOUSEEVENTF_RIGHTDOWN = 0x0008; 模拟鼠标右键按下 
const int MOUSEEVENTF_RIGHTUP = 0x0010; 模拟鼠标右键抬起 
const int MOUSEEVENTF_MIDDLEDOWN = 0x0020; 模拟鼠标中键按下 
const int MOUSEEVENTF_MIDDLEUP = 0x0040; 模拟鼠标中键抬起 
const int MOUSEEVENTF_ABSOLUTE = 0x8000; 标示是否采用绝对坐标
		  */
	  void sendARightMuoseClick(int X,int Y ,int delyTime)  //参数为click的位置，及点击后延迟多少秒
	  {
		  SetCursorPos(X,Y);
		  		    Sleep(400);
			 mouse_event (MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0 );
		    Sleep(delyTime);


	  }

	  	  void ToInPutChar(char c,int delyTime)
	  {

		   //为0到9的时候。这是c的值在48到57之间,直接对应
		   int inputKey=0;
		   if(c >47 && c<58)
		   {
			   inputKey=c;
		   }
		   //为a到z的时候。这是c的值在97到122之间,对应VirtualKey的65到90
		   if(c >96 && c<123)
		   {
			   inputKey=c-32;
		   }
		   //为A到Z的时候。这是c的值在65到90之间,对应VirtualKey的
		   //if(c >96 && c<123)
		   //{
			  // inputKey=c;
		   //}
		   //switch (c)
		   //{

		   //case 

		   //}
		    


		    if(inputKey >0)
			{
		  		keybd_event(inputKey,MapVirtualKey(inputKey,0),0,0);//按下inputKey建。关于为何是0x4d---http://msdn.microsoft.com/zh-cn/library/dd375731(v=vs.85)
				Sleep(100);
				keybd_event(inputKey,MapVirtualKey(inputKey,0),KEYEVENTF_KEYUP,0);//按下inputKey建。
			}
		    Sleep(delyTime);
	  }
/*
VK_LBUTTON0x01	Left mouse button
VK_RBUTTON0x02	Right mouse button
VK_CANCEL0x03	Control-break processing
VK_MBUTTON0x04	Middle mouse button (three-button mouse)
VK_XBUTTON10x05	X1 mouse button
VK_XBUTTON20x06	X2 mouse button
-0x07	Undefined
VK_BACK0x08	BACKSPACE key
VK_TAB0x09	TAB key
-0x0A-0B	Reserved
VK_CLEAR0x0C	CLEAR key
VK_RETURN0x0D	ENTER key
-0x0E-0F	Undefined
VK_SHIFT0x10	SHIFT key
VK_CONTROL0x11	CTRL key
VK_MENU0x12	ALT key
VK_PAUSE0x13	PAUSE key
VK_CAPITAL0x14	CAPS LOCK key
VK_KANA0x15	IME Kana mode
VK_HANGUEL0x15	IME Hanguel mode (maintained for compatibility; use VK_HANGUL)
VK_HANGUL0x15	IME Hangul mode
-0x16	Undefined
VK_JUNJA0x17	IME Junja mode
VK_FINAL0x18	IME final mode
VK_HANJA0x19	IME Hanja mode
VK_KANJI0x19	IME Kanji mode
-0x1A	Undefined
VK_ESCAPE0x1B	ESC key
VK_CONVERT0x1C	IME convert
VK_NONCONVERT0x1D	IME nonconvert
VK_ACCEPT0x1E	IME accept
VK_MODECHANGE0x1F	IME mode change request
VK_SPACE0x20	SPACEBAR
VK_PRIOR0x21	PAGE UP key
VK_NEXT0x22	PAGE DOWN key
VK_END0x23	END key
VK_HOME0x24	HOME key
VK_LEFT0x25	LEFT ARROW key
VK_UP0x26	UP ARROW key
VK_RIGHT0x27	RIGHT ARROW key
VK_DOWN0x28	DOWN ARROW key
VK_SELECT0x29	SELECT key
VK_PRINT0x2A	PRINT key
VK_EXECUTE0x2B	EXECUTE key
VK_SNAPSHOT0x2C	PRINT SCREEN key
VK_INSERT0x2D	INS key
VK_DELETE0x2E	DEL key
VK_HELP0x2F	HELP key
0x30	0 key
0x31	1 key
0x32	2 key
0x33	3 key
0x34	4 key
0x35	5 key
0x36	6 key
0x37	7 key
0x38	8 key
0x39	9 key
-0x3A-40	Undefined
0x41	A key
0x42	B key
0x43	C key
0x44	D key
0x45	E key
0x46	F key
0x47	G key
0x48	H key
0x49	I key
0x4A	J key
0x4B	K key
0x4C	L key
0x4D	M key
0x4E	N key
0x4F	O key
0x50	P key
0x51	Q key
0x52	R key
0x53	S key
0x54	T key
0x55	U key
0x56	V key
0x57	W key
0x58	X key
0x59	Y key
0x5A	Z key
VK_LWIN0x5B	Left Windows key (Natural keyboard)
VK_RWIN0x5C	Right Windows key (Natural keyboard)
VK_APPS0x5D	Applications key (Natural keyboard)
-0x5E	Reserved
VK_SLEEP0x5F	Computer Sleep key
VK_NUMPAD00x60	Numeric keypad 0 key
VK_NUMPAD10x61	Numeric keypad 1 key
VK_NUMPAD20x62	Numeric keypad 2 key
VK_NUMPAD30x63	Numeric keypad 3 key
VK_NUMPAD40x64	Numeric keypad 4 key
VK_NUMPAD50x65	Numeric keypad 5 key
VK_NUMPAD60x66	Numeric keypad 6 key
VK_NUMPAD70x67	Numeric keypad 7 key
VK_NUMPAD80x68	Numeric keypad 8 key
VK_NUMPAD90x69	Numeric keypad 9 key
VK_MULTIPLY0x6A	Multiply key
VK_ADD0x6B	Add key
VK_SEPARATOR0x6C	Separator key
VK_SUBTRACT0x6D	Subtract key
VK_DECIMAL0x6E	Decimal key
VK_DIVIDE0x6F	Divide key
VK_F10x70	F1 key
VK_F20x71	F2 key
VK_F30x72	F3 key
VK_F40x73	F4 key
VK_F50x74	F5 key
VK_F60x75	F6 key
VK_F70x76	F7 key
VK_F80x77	F8 key
VK_F90x78	F9 key
VK_F100x79	F10 key
VK_F110x7A	F11 key
VK_F120x7B	F12 key
VK_F130x7C	F13 key
VK_F140x7D	F14 key
VK_F150x7E	F15 key
VK_F160x7F	F16 key
VK_F170x80	F17 key
VK_F180x81	F18 key
VK_F190x82	F19 key
VK_F200x83	F20 key
VK_F210x84	F21 key
VK_F220x85	F22 key
VK_F230x86	F23 key
VK_F240x87	F24 key
-0x88-8F	Unassigned
VK_NUMLOCK0x90	NUM LOCK key
VK_SCROLL0x91	SCROLL LOCK key
0x92-96	OEM specific
-0x97-9F	Unassigned
VK_LSHIFT0xA0	Left SHIFT key
VK_RSHIFT0xA1	Right SHIFT key
VK_LCONTROL0xA2	Left CONTROL key
VK_RCONTROL0xA3	Right CONTROL key
VK_LMENU0xA4	Left MENU key
VK_RMENU0xA5	Right MENU key
		  */