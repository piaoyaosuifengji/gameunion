

#include "stdafx.h"
#include <afxmt.h>
#include "fileoperating.h"
#include "operating.h"

	struct colourRGB colourNow[10];
	struct colourRGB colourListOld[10];


	CString mapNames[] = {
		_T("������"),
		_T("���ݳ�"),
		_T(","),
		_T(","),
		_T(",")
	};
	
	int cityPos[][2] = {
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
	};


#define BUFFER_SIZE_KILO    300


	// ��Char���ַ�ת��ΪUnicode�ַ�
	int CharToUnicode(char *pchIn, CString *pstrOut)
	{
		int nLen;
		WCHAR *ptch;

		if (pchIn == NULL)
		{
			return 0;
		}

		nLen = MultiByteToWideChar(CP_ACP, 0, pchIn, -1, NULL, 0);
		ptch = new WCHAR[nLen];
		MultiByteToWideChar(CP_ACP, 0, pchIn, -1, ptch, nLen);
		pstrOut->Format(_T("%s"), ptch);

		delete[] ptch;

		return nLen;
	}


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ��Unicode�ַ�ת��ΪChar���ַ�
	int UnicodeToChar(CString &strIn, char *pchOut, int nCharLen)
	{
		if (pchOut == NULL)
		{
			return 0;
		}

		int nLen = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)strIn.GetBuffer(BUFFER_SIZE_KILO), -1, NULL, 0, NULL, NULL);
		nLen = min(nLen, nCharLen);
		WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)strIn.GetBuffer(BUFFER_SIZE_KILO), -1, pchOut,
			nLen, NULL, NULL);

		if (nLen < nCharLen)
		{
			pchOut[nLen] = 0;
		}


		return nLen;


	}
	//��char�ַ�������һ����������
	void luanmaChuLi(CString &str)
	{
		char *szBuf = new char[str.GetLength()+1];

		for (int i = 0; i < str.GetLength(); i++)
		{
			szBuf[i] = str.GetAt(i);
		}
		szBuf[str.GetLength()] = 0;
		CharToUnicode(szBuf, &str);

		delete[]szBuf;
	}





	//����struct operat���飬�ҵ���Ҫ���еĲ�������غ���
     //���ִ���ʱ����һ�����������Ǵ���λ����struct operat�����е����
   //���ء�0ʱ��ʾһ������
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
		if (currentDo->shelltype.Compare(_T(RightmouseClick)) == 0)
		{
			if (currentDo->ParameterNum != 2)
				return (-1)*i;
			justDoIt->funcID = 6;
			justDoIt->paramet.p6.delyTime = currentDo->time;

			int loct = currentDo->Parameter.Find(_T(","));
			CString x = currentDo->Parameter.Left(loct);
			CString y = currentDo->Parameter.Right(currentDo->Parameter.GetLength() - loct - 1);
			int Y = _wtoi(y);
			int X = _wtoi(x);
			justDoIt->paramet.p6.X = X;
			justDoIt->paramet.p6.Y = Y;
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
		if(currentDo->shelltype.Compare(_T(KeyDown)) ==0)
		{
			if(currentDo->ParameterNum != 1)
				return (-1)*i;
			justDoIt->funcID=3;
			justDoIt->paramet.p3.delyTime=currentDo->time;
			//TCHAR * tchar=currentDo->Parameter.GetAt(1);
			//char  * _char;
			//TcharToChar ( tchar, _char);
			justDoIt->paramet.p3.c=currentDo->Parameter.GetAt(0);
		}


		
		if (currentDo->shelltype.Compare(_T(KeyBoardKey)) == 0)
		{
			if (currentDo->ParameterNum != 1)
				return (-1)*i;
			justDoIt->funcID = 5;
			justDoIt->paramet.p5.delyTime = currentDo->time;
			//TCHAR * tchar=currentDo->Parameter.GetAt(1);
			//char  * _char;
			//TcharToChar ( tchar, _char);
			justDoIt->paramet.p5.c = _ttoi(currentDo->Parameter);
		}








		if (currentDo->shelltype.Compare(_T(Location)) == 0)
		{
			if (currentDo->ParameterNum != 3)
				return (-1)*i;
			justDoIt->funcID = 4;
			justDoIt->paramet.p4.delyTime = currentDo->time;
			//TCHAR * tchar=currentDo->Parameter.GetAt(1);
			//char  * _char;
			//TcharToChar ( tchar, _char);
			//justDoIt->paramet.p4.c = currentDo->Parameter.GetAt(0);

			int loct = currentDo->Parameter.Find(_T(","));
			CString mapName = currentDo->Parameter.Left(loct);
			luanmaChuLi(mapName);
			CString zhong = currentDo->Parameter.Right(currentDo->Parameter.GetLength() - loct - 1);
			loct = zhong.Find(_T(","));
			CString x = zhong.Left(loct);
			CString y = zhong.Right(zhong.GetLength() - loct - 1);
			int Y = _wtoi(y);
			int X = _wtoi(x);

			justDoIt->paramet.p4.X = X;
			justDoIt->paramet.p4.Y = Y;
			//justDoIt->paramet.p4.
			int ii = 0;
			int sizeOfMaps = sizeof(mapNames) / sizeof(CString);
			for (;ii<sizeOfMaps;ii++)
			{
				if (mapNames[ii].Compare(mapName) == 0)
				{
					break;
				}


			}
			//����iֵ���õ�Ŀ�ĵص�ͼ������
			if (ii < sizeOfMaps)
			{
				justDoIt->paramet.p4.mapNameID = ii;//i�����������е��±�
			}
			else
				
				justDoIt->paramet.p4.mapNameID = -1;//i�����������е��±�


		}
	}

	return i;
}
void locationToMapPos(int mapNameID, int x, int y, int delyTime)//��ָ����ͼ��ָ��λ��
{


	//���ȶ�ȡһЩ�̶��ĵ�ͼ����

	int res = 0;
	int i;
	CPoint  movePointsP[400];
	//�ļ��ĸ�ʽ���£���Ȼ���Ե�ĸ�ʽ���棬�����岻ͬ��
	//��һ����startPoint��
	//������3�еĵ�һ������ΪAverageValueRBG��3��ֵ
	CString file(_T("D:\\data\\1440900\\mapPos.txt"));
	ReadTxtToGetPointsB(file, movePointsP);

	Sleep(1000);
	//����ȥָ����ͼm

		//����M
	ToInPutChar('m',  1260);
		//�������ͼ
	i = 1;
	sendALeftMuoseClick(movePointsP[i].x, movePointsP[i].y, 1250);
		//�㿪 mapNameID��ָʾ�����ӵ�ͼ
	i = mapNameID+2;
	sendALeftMuoseClick(movePointsP[i].x, movePointsP[i].y, 1250);
		//quȥָ������
	sendALeftMuoseClick(x, y, delyTime);
	//�ص���ͼm
	ToInPutChar('m', 260);



	//switch (funcID)
	//{
	//case 1:
	//	sendALeftMuoseClick(justDoIt->paramet.p1.X, justDoIt->paramet.p1.Y, justDoIt->paramet.p1.delyTime);
	//	break;
	//case 2:
	//	ToInPutChar(justDoIt->paramet.p2.c, justDoIt->paramet.p2.delyTime);
	//	break;
	//case 3:
	//	PutKeyDown(justDoIt->paramet.p3.c, justDoIt->paramet.p3.delyTime);
	//	break;
	//case 4:
	//	locationToMapPos(justDoIt->paramet.p4.mapNameID, justDoIt->paramet.p4.X, justDoIt->paramet.p4.Y, justDoIt->paramet.p3.delyTime);
	//	break;
	//default:break;
	//}





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
		case 3:
			PutKeyDown(justDoIt->paramet.p3.c,justDoIt->paramet.p3.delyTime);
			break;
		case 4:
			locationToMapPos(justDoIt->paramet.p4.mapNameID, justDoIt->paramet.p4.X, justDoIt->paramet.p4.Y, justDoIt->paramet.p3.delyTime);
			break;
		case 5:
			ToInPutKeyboardKey(justDoIt->paramet.p5.c, justDoIt->paramet.p5.delyTime);
			break;
		case 6:
			sendRightMuoseClick(justDoIt->paramet.p6.X, justDoIt->paramet.p6.Y, justDoIt->paramet.p6.delyTime);
			break;
		default:break;
		}

	}
	return 0;
}
void sendRightMuoseClick(int X, int Y, int delyTime)  //����Ϊclick��λ�ã���������ӳٶ�����
{
	SetCursorPos(X, Y);
	Sleep(400);
	mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
	
	Sleep(delyTime);


}

	  void sendALeftMuoseClick(int X,int Y ,int delyTime)  //����Ϊclick��λ�ã���������ӳٶ�����
	  {
		  SetCursorPos(X,Y);
		  		    Sleep(400);
			 mouse_event (MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
		    Sleep(delyTime);


	  }
	  /*
const int MOUSEEVENTF_MOVE = 0x0001;      �ƶ���� 
const int MOUSEEVENTF_LEFTDOWN = 0x0002; ģ������������ 
const int MOUSEEVENTF_LEFTUP = 0x0004; ģ��������̧�� 
const int MOUSEEVENTF_RIGHTDOWN = 0x0008; ģ������Ҽ����� 
const int MOUSEEVENTF_RIGHTUP = 0x0010; ģ������Ҽ�̧�� 
const int MOUSEEVENTF_MIDDLEDOWN = 0x0020; ģ������м����� 
const int MOUSEEVENTF_MIDDLEUP = 0x0040; ģ������м�̧�� 
const int MOUSEEVENTF_ABSOLUTE = 0x8000; ��ʾ�Ƿ���þ�������
		  */
	  void sendARightMuoseClick(int X,int Y ,int delyTime)  //����Ϊclick��λ�ã���������ӳٶ�����
	  {
		  SetCursorPos(X,Y);
		  		    Sleep(400);
			 mouse_event (MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0 );
		    Sleep(delyTime);


	  }
	void PutKeyDown(char c,int delyTime)
	{

		   //Ϊ0��9��ʱ������c��ֵ��48��57֮��,ֱ�Ӷ�Ӧ
		   int inputKey=0;
		   if(c >47 && c<58)
		   {
			   inputKey=c;
		   }
		   //Ϊa��z��ʱ������c��ֵ��97��122֮��,��ӦVirtualKey��65��90
		   if(c >96 && c<123)
		   {
			   inputKey=c-32;
		   }
		   //ΪA��Z��ʱ������c��ֵ��65��90֮��,��ӦVirtualKey��

		    if(inputKey >0)
			{
		  		keybd_event(inputKey,MapVirtualKey(inputKey,0),0,0);//����inputKey��������Ϊ����0x4d---http://msdn.microsoft.com/zh-cn/library/dd375731(v=vs.85)
				Sleep(delyTime);
				keybd_event(inputKey,MapVirtualKey(inputKey,0),KEYEVENTF_KEYUP,0);//����inputKey����
			}
	}
//��asicc�����������ת��ʱ���������
void ToInPutChar(char c,int delyTime)
	  {

		   //Ϊ0��9��ʱ������c��ֵ��48��57֮��,ֱ�Ӷ�Ӧ
		   int inputKey=0;
		   if(c >47 && c<58)
		   {
			   inputKey=c;
		   }
		   //Ϊa��z��ʱ������c��ֵ��97��122֮��,��ӦVirtualKey��65��90
		   if(c >96 && c<123)
		   {
			   inputKey=c-32;
		   }
		   //ΪA��Z��ʱ������c��ֵ��65��90֮��,��ӦVirtualKey��
		   //if(c >96 && c<123)
		   //{
			  // inputKey=c;
		   //}
		   //switch (c)q
		   //{

		   //case 

		   //}
		    
		    if(inputKey >0)
			{
		  		keybd_event(inputKey,MapVirtualKey(inputKey,0),0,0);//����inputKey��������Ϊ����0x4d---http://msdn.microsoft.com/zh-cn/library/dd375731(v=vs.85)
				Sleep(100);
				keybd_event(inputKey,MapVirtualKey(inputKey,0),KEYEVENTF_KEYUP,0);//����inputKey����
			}
		    Sleep(delyTime);
	  }
	//ֱ��������������
void ToInPutKeyboardKey(int c,int delyTime)
	  {

		  		keybd_event(c,MapVirtualKey(c,0),0,0);//����inputKey��������Ϊ����0x4d---http://msdn.microsoft.com/zh-cn/library/dd375731(v=vs.85)
				Sleep(100);
				keybd_event(c,MapVirtualKey(c,0),KEYEVENTF_KEYUP,0);//����inputKey����
				if (delyTime > 0)
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

	void  standardOutput(CString str)
	{
		//CTime t=::GetCurrentTime();
		//_try
		//{
		CString msg("standardOutput :");
		//msg.Format(_T("%s    %s \t\n"),str,t.Format(_T(" %X")));
		msg.Format(_T("%s   %s  \t\n"),msg,str);
		//TRACE(msg);
		WCHAR fileName[150]=_T("C:\\data\\msg.txt") ;
		CStdioFile f(fileName,CFile::modeWrite );
		//TCHAR buf[] = _T("test string \n\t");
		LONGLONG lOff =  0;
		ULONGLONG lActual = f.Seek(lOff, CFile::end);
		 f.WriteString(msg);
	}
	//����
void GetCurrentRGB(CPoint pt)//��ȡ��ǰ���λ�õ����أ�������ȫ�ֱ���RGB��
{
		Sleep(2000);

		DWORD  res=0;
		HDC hDC;//��ȡ��ĻDC
	    GetCursorPos(&pt);//�õ���ǰ�������λ��
				
		int i=0;
		int satrt=pt.x ;
		int end=satrt+50;
		i=satrt;
		int count=0;
		while(true)
		{

			count++;
		
			if(count>2)
			{
				break;}
		hDC=::GetDC(NULL);
		Sleep(200);
		COLORREF clr = ::GetPixel(hDC,i,pt.y); //��ȡ��ǰ��������ֵ

		i=i+5;


		CString ClrText("");
		
		BYTE r = GetRValue(clr);
		BYTE g = GetGValue(clr);
		BYTE b = GetBValue(clr);
		colourNow[count].R=r;
		colourNow[count].G=g;
		colourNow[count].B=b;


		ClrText.Format(_T("x=%d correntPoint: %d  %d  RGB  is   %d  %d   %d"),i,pt.x,pt.y,colourNow[count].R,colourNow[count].G,colourNow[count].B); //�ֽ����ɫֵ
		////AfxMessageBox(ClrText);
		standardOutput(ClrText);
		
		::ReleaseDC(NULL, hDC); //�ͷ���ĻDC

		}
		//return res;
}

void GetPointRGB(CPoint *pt,struct colourRGB * obColour)//��ȡָ�����λ�õ����أ�������obColour
{
		//Sleep(2000);

		DWORD  res=0;
		HDC hDC;//��ȡ��ĻDC
	    //GetCursorPos(pt);//�õ���ǰ�������λ��
		//SetCursorPos(pt->x,pt->y);		

		hDC=::GetDC(NULL);
		//Sleep(200);
		COLORREF clr = ::GetPixel(hDC,pt->x,pt->y); //��ȡ��ǰ��������ֵ
		
		BYTE r = GetRValue(clr);
		BYTE g = GetGValue(clr);
		BYTE b = GetBValue(clr);
		obColour->R=r;
		obColour->G=g;
		obColour->B=b;
		::ReleaseDC(NULL, hDC); //�ͷ���ĻDC
}

//��a��bֵ��Ӻ󸳸�a
int addRGB(struct colourRGB *a,struct colourRGB *b)
{
	int res=-1;
	a->B=a->B+b->B;
		a->R=a->R+b->R;
			a->G=a->G+b->G;
	return res;
}
//��ʼ��һ��rgb
 int initRGB(struct colourRGB *a)
{
	int res=-1;

	if(a)
	{
	a->B=0;
	a->R=0;
	a->G=0;
	res=1;
	}

	return res;
}



//���������㣬�������������Ϊ��ʼ��������ƽ��rgbֵ----����������ֵ����ΪK�����ж�Ѫ��λ��
//Thickness,��ʾ�����ߵĴ�ϸ�����ǿ�ȣ���λ�����أ�
//�������start��end��ͬһˮƽ���ϣ��������ǵ�����y��ͬ,��������޼�
struct colourRGB  	CalculateAverageValueRBG(CPoint start,CPoint end,int Thickness)
{

	struct colourRGB res;
	struct colourRGB AverageValue;
	initRGB(&AverageValue);
	res.B=-1;
	res.G=-1;
	res.R=-1;
	//int x=
	if(Thickness <=0 || start.x<0  || start.y<0  || end.x<0  || end.y<0 || start.x==end.x  )
		return res;
	int xOFstart=start.x;
	int xOFend=end.x;
	int y=(start.y+end.y)/2;
	int RGBcount=0;
	int x=xOFstart;
	//��֤xOFstartֵ��С
	if(xOFstart >xOFend)
	{
		x=xOFend;
		xOFend=xOFstart;
		xOFstart=x;
	}

		HDC hDC;//��ȡ��ĻDC
		hDC=::GetDC(NULL);
		//Sleep(200);
		COLORREF clr;		
		BYTE r;
		BYTE g;
		BYTE b;


	CPoint pt;
	struct colourRGB obColour;
	int j=0;
	for(;x <= xOFend;x++)
	{
		pt.x=x;
		pt.y=y;

		 clr = ::GetPixel(hDC,pt.x,pt.y); //��ȡ��ǰ��������ֵ		
		 r = GetRValue(clr);
		 g = GetGValue(clr);
		 b = GetBValue(clr);
		obColour.R=r;
		obColour.G=g;
		obColour.B=b;

		addRGB(&AverageValue,&obColour);
		RGBcount++;
		for(j=1;j<=(Thickness/2);j++)
		{
			pt.x=x;
			pt.y=y+(j)*1;
				 clr = ::GetPixel(hDC,pt.x,pt.y); //��ȡ��ǰ��������ֵ		
				 r = GetRValue(clr);
				 g = GetGValue(clr);
				 b = GetBValue(clr);
				obColour.R=r;
				obColour.G=g;
				obColour.B=b;
			addRGB(&AverageValue,&obColour);
			RGBcount++;

			pt.x=x;
			pt.y=y-(j)*1;
				 clr = ::GetPixel(hDC,pt.x,pt.y); //��ȡ��ǰ��������ֵ		
				 r = GetRValue(clr);
				 g = GetGValue(clr);
				 b = GetBValue(clr);
				obColour.R=r;
				obColour.G=g;
				obColour.B=b;
			addRGB(&AverageValue,&obColour);
			RGBcount++;
		}

	}
	AverageValue.B=AverageValue.B/RGBcount;
	AverageValue.R=AverageValue.R/RGBcount;
	AverageValue.G=AverageValue.G/RGBcount;

	::ReleaseDC(NULL, hDC); //�ͷ���ĻDC
	return AverageValue;
}

//2����һ����ʼλ����Ѱ����K���Ƶĵ㣬��Ѱ��Ѫ����������ҵ�Ѫ���ľ���λ��

//���������ʼ�㣬�Լ�K�㣨����һ��RGBֵ��
//��������֤�����ϽǺ����½ǵ�����
int FindMatrix(CPoint startPoint,struct colourRGB obColour,CPoint *LeftPoint,CPoint *RightPoint)
{

	int res=-1;

	
	//��������startPoint�����������Ѱλ�õ����Ϸ�
	//���������Դ������ң����ϵ��µ�˳��Ѱ��Ŀ��rgb



	return res;
}
//FindMatrix�ĸ������������ǻ�ȡCPoint *startPoint,struct colourRGB * obColour
int getMsgForFindMatrix(CString file,CPoint *startPoint,struct colourRGB * AverageValueRBG)
{
	int res=0;
	CPoint  movePointsP[40];
	//�ļ��ĸ�ʽ���£���Ȼ���Ե�ĸ�ʽ���棬�����岻ͬ��
	//��һ����startPoint��
	//������3�еĵ�һ������ΪAverageValueRBG��3��ֵ
	ReadTxtToGetPointsB( file,movePointsP);

	startPoint->x=movePointsP[1].x;
	startPoint->y=movePointsP[1].y;
	AverageValueRBG->R=movePointsP[2].x;
	AverageValueRBG->G=movePointsP[3].x;
	AverageValueRBG->B=movePointsP[4].x;


	return res;
}

//wu����������������
void tianxiawuyouTaskHandle(void)
{



	//CString ClrText("");

	//ClrText.Format(_T("ffffffffffff")); 
	//AfxMessageBox(ClrText);


	//���ȶ�ȡһЩ�̶��ĵ�ͼ����

	int res = 0;
	int i;
	CPoint  movePointsP[400];
	//�ļ��ĸ�ʽ���£���Ȼ���Ե�ĸ�ʽ���棬�����岻ͬ��
	//��һ����startPoint��
	//������3�еĵ�һ������ΪAverageValueRBG��3��ֵ
	CString file(_T("D:\\data\\1440900\\zuobiao.txt"));
	ReadTxtToGetPointsB(file, movePointsP);




	//0:��һ����ָ��������λ��
	locationToMapPos(MapNameID_LUOYANG, movePointsP[5].x, movePointsP[5].y, 2200);//��ָ����ͼ��ָ��λ��
	//1:������
	AccessTask(movePointsP);

	//2���жϵ�ǰ������
		//ʡ��

	//3������������ű�
		

	///4��ji�������� ����������0





}



//��ȡ����
void AccessTask(CPoint * poss)//ca����Ϊȫ��λ�����飬һЩ����λ������
{

	if (poss == NULL)
		return;
	sendALeftMuoseClick(poss[3].x, poss[3].y,200);  //����Ϊclick��λ�ã���������ӳٶ�����

	sendALeftMuoseClick(poss[4].x, poss[4].y, 200);  //����Ϊclick��λ�ã���������ӳٶ�����





}

struct WindowPosMsg  getGameWindowSize(LPCTSTR   windowClassName, LPCTSTR   windowTitle)
{

	struct WindowPosMsg windowMsg;
	HWND hWnd; // hWnd : ���Ӵ��� handle
	DWORD dwx; // dwx : Ϊ����� ProcessID �ı���λַ
	HANDLE hProc; //Process handle
	CRect rect;
	CString  zuobiao1;
	windowMsg.Width = 0;
	windowMsg.Height = 0;//��ʱ������Ч


	if (windowClassName == NULL    &&   windowTitle == NULL)
		return windowMsg;
	//hWnd = ::FindWindow(_T("NETEASE-TY-APP"), NULL);
	hWnd = ::FindWindow(windowClassName, windowTitle);
	//lpszClassName:����������lpszWindowName:���ڱ��⡣����Ҫһ���Ϳ����ˣ���Ȼ������׼ȷ
	zuobiao1.Format(_T("�Ҳ�������"));
	if (hWnd == false)
	{

		AfxMessageBox(zuobiao1);
		return windowMsg;
	}
	::GetWindowRect(hWnd, &rect);

	//AfxMessageBox(str);
	windowMsg.Width = rect.Width();
	windowMsg.Height = rect.Height();
	windowMsg.TopLeftPoint.x = rect.TopLeft().x;
	windowMsg.TopLeftPoint.y = rect.TopLeft().y;
	windowMsg.BottomRightPoint.x = rect.BottomRight().x;
	windowMsg.BottomRightPoint.y = rect.BottomRight().y;

	return windowMsg;
}

//zuhe��ϼ�����SHIFT+f1����mainKeyΪf1
void KeyboardCombination(int mainKey, int auxiliaryKey)
{


	//��ϼ�
	keybd_event(auxiliaryKey, MapVirtualKey(auxiliaryKey, 0), 0, 0);
	//Sleep(10);
	keybd_event(mainKey, MapVirtualKey(mainKey, 0), 0, 0);
	//Sleep(10);
	keybd_event(mainKey, MapVirtualKey(mainKey, 0), KEYEVENTF_KEYUP, 0);
	//Sleep(10);
	keybd_event(auxiliaryKey, MapVirtualKey(auxiliaryKey, 0), KEYEVENTF_KEYUP, 0);




}

