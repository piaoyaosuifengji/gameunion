// HookDll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "HookDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;


//Shared data section����һ���µ����ݶβ����干������
#pragma data_seg("sharedata")  
HHOOK glhHook = NULL;         //���Ӿ����
HINSTANCE glhInstance = NULL; //DLLʵ�������
#pragma data_seg()
#pragma   comment(linker,"/section:sharedata,RWS")

bool ifworkIngProStar = false;









//int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
//{
//	int nRetCode = 0;
//
//	HMODULE hModule = ::GetModuleHandle(NULL);
//
//	if (hModule != NULL)
//	{
//		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
//		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
//		{
//			// TODO:  ���Ĵ�������Է���������Ҫ
//			_tprintf(_T("����:  MFC ��ʼ��ʧ��\n"));
//			nRetCode = 1;
//		}
//		else
//		{
//			// TODO:  �ڴ˴�ΪӦ�ó������Ϊ��д���롣
//		}
//	}
//	else
//	{
//		// TODO:  ���Ĵ�������Է���������Ҫ
//		_tprintf(_T("����:  GetModuleHandle ʧ��\n"));
//		nRetCode = 1;
//	}
//
//	return nRetCode;
//}


void  standardOutput(CString str)
{
	CTime t=::GetCurrentTime();
	//_try
	//{
	CString msg("standardOutput :");
	//msg.Format(_T("%s:%s \t\n"), t.Format(_T(" %X")), str );
	msg.Format(_T("%s\t\n"), str);
	//TRACE(msg);
	WCHAR fileName[150] = _T("C:\\data\\msg.txt");
	CStdioFile f(fileName, CFile::modeWrite);
	//TCHAR buf[] = _T("test string \n\t");
	LONGLONG lOff = 0;
	ULONGLONG lActual = f.Seek(lOff, CFile::end);
	f.WriteString(msg);

	//_finally
	//{
	// AfxMessageBox(_T("error1 "));
	//}
}




void  log(CPoint oldPoint)
{

	CString msg("key pressed at");
	msg.Format(_T("%s %u  %u \t\n"), msg, oldPoint.x, oldPoint.y);

	//TRACE(msg);
	WCHAR fileName[150] = _T("me.txt");
	CStdioFile f(fileName, CFile::modeWrite);

	//TCHAR buf[] = _T("test string \n\t");
	LONGLONG lOff = 0;
	ULONGLONG lActual = f.Seek(lOff, CFile::end);
	f.WriteString(msg);

}

void sendALeftMuoseClick(int X, int Y, int delyTime)  //����Ϊclick��λ�ã���������ӳٶ�����
{
	SetCursorPos(X, Y);
	Sleep(500);

	//mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE,0,0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);


	//mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE,X * 65536 / 1280,
	//Y * 65536 / 800, 0, 0);
	//mouse_event (MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
	Sleep(delyTime);


}
DWORD WINAPI workIngPro(PVOID pvParam)
{
	DWORD  res = 0;
	ifworkIngProStar = true;
	CPoint newPoint, oldPoint;
	GetCursorPos(&oldPoint);

	int X = 500;
	int Y = 500;
	//���ʵ�ִ��롣
	int xianLu = 99;
	for (int i = 0; i<11; i++)
	{
		if (i == 10)
		{
			i = 1;

		}
		Sleep(3500);

		//keybd_event(0x4d,MapVirtualKey(0x4d,0),0,0);//����M����
		//Sleep(100);
		//keybd_event(0x4d,MapVirtualKey(0x4d,0),KEYEVENTF_KEYUP,0);//����M����
		//		    Sleep(2000);
		//sendALeftMuoseClick(500,500,500);//�������


		sendALeftMuoseClick(1248, 36, 500);//����˵�
		sendALeftMuoseClick(637, 368, 500);//������ɫ
		sendALeftMuoseClick(585, 416, 6000);//�ǣ�


		sendALeftMuoseClick(1147, 99 + 20 * (i - 1), 500);//��·λ��
		sendALeftMuoseClick(706, 706, 29000);//��ʼ��Ϸ

		SetCursorPos(500, 500);
		Sleep(500);

		int x = 627;
		int y = 582;
		//sendALeftMuoseClick(x,y,3500);//�ɼ�
		SetCursorPos(x, y);
		//mouse_event (MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
		Sleep(500);

		HWND pWndPrev;
		pWndPrev = ::FindWindow(_T("WFElementClient Window"), NULL);
		if (NULL != pWndPrev)
		{
			POINT point;
			point.x = x;
			point.y = y;
			LPARAM lparam = (point.y << 16) + point.x;
			::SendMessage(pWndPrev, WM_LBUTTONDOWN, 0, lparam);
			::SendMessage(pWndPrev, WM_LBUTTONUP, 0, lparam);
		}
		else  AfxMessageBox(_T("fail to get game's window"));

	}
	//SetCursorPos(oldPoint.x,oldPoint.y);
	ifworkIngProStar = false;
	return res;
}


extern "C" LRESULT WINAPI KeyboardProc(int nCode, WPARAM wParam, LPARAM
	lParam)
{
	if (nCode >= 0)
	{
		if (wParam == VK_F10 && ifworkIngProStar == false)//������F10��ʱ��������ҡ�
		{
			//AfxMessageBox(_T("������F10��ʱ��������ҡ�"));
			CPoint oldPoint;
			GetCursorPos(&oldPoint);
			CString ss;
			ss.Format(_T(" ddd   x=%u  y=%u \t\n"), oldPoint.x, oldPoint.y);

			AfxMessageBox(ss);

		}
		/* else
		AfxMessageBox(_T(" wParam is "));*/

	}
	return CallNextHookEx(glhHook, nCode, wParam, lParam);
}

//��¼������Ϣ
CTime lastOpTime;
int lastVirtualKey;
CString lastVirtualKeyShellName;
//CPoint lastPoint;
int  lastParameterNum;
CString lastParameterStr;

CTime currentOpTime;
int currentVirtualKey;
CString currentVirtualKeyShellName;
CPoint currentPoint;
int  currentParameterNum;
CString currentParameterStr;

int recordCounts;
extern "C" LRESULT WINAPI RecordKeyboardProc(int nCode, WPARAM wParam, LPARAM
	lParam)
{

	 int recordTimes = 0;
	int timeBetweenShell,tmpi;
	CTimeSpan span;
	if (nCode >= 0 ) 
	{
		//if (wParam == VK_F10 && ifworkIngProStar == false)//������F10��ʱ��������ҡ�
		//{
		//	//AfxMessageBox(_T("������F10��ʱ��������ҡ�"));
		//	CPoint oldPoint;
		//	GetCursorPos(&oldPoint);
		//	CString ss;
		//	ss.Format(_T(" ddd   x=%u  y=%u \t\n"), oldPoint.x, oldPoint.y);

		//	AfxMessageBox(ss);

		//}
		/* else
		AfxMessageBox(_T(" wParam is "));*/

		//CString str("mouse down");
		//standardOutput(str);



		//���ǵ���������Ϊ�˰Ѽ�¼�Ķ���ת�����Զ���shell��
		//����ò��keybd_event��������������Գ��������⣬
		//���Դ����������еİ������������¼����Ϣ����ֱ����
		//keybd_event�����õ�������ֵ���պö�Ӧ  KeyBoardKey   "keyboard"  shell
		//ֻ��VK_LBUTTON  VK_RBUTTON��Ҫ���⴦��
		CPoint oldPoint;
		CString posStr;
		CString shellStr;
		//��������GetCurrentTime��������������������ʱ���������ٶȰٿƣ�
		//��Ȼ��һ�����Ǽ�¼ÿ�����������ͣ�ʱ���������Ϣ
		//����ÿ�μ�¼�µ�ǰ������Ϣ֮�󣬾Ϳ��Լ�����ϴΰ�����ʱ�����������Ϳ��Դ�ӡ�ϴε�shell��


		//����wParam��ʾ���ǰ����ĸ�����lParam�����ĵ�31λ���Ƿ��ǰ��»���
		//lParam >> 31 == 0  ˵���ǰ��£�����Ϊ����

		recordTimes = recordCounts;
		currentOpTime=CTime::GetCurrentTime();
		switch (wParam)
		{
		case  VK_LBUTTON:
		case  VK_RBUTTON://��������޷���¼�����Ϣ,���ô���
			currentVirtualKey = wParam;
			currentVirtualKeyShellName.Format(_T("LeftMouse"));
			GetCursorPos(&currentPoint);
			//posStr.Format(_T(" button clicked   x=%u  y=%u \t\n"), oldPoint.x, oldPoint.y);
			//LeftMouse:10500 : 2 : 1144, 123
			//standardOutput(posStr);
			currentParameterNum=2;
			currentParameterStr.Format(_T("%d,%d"), currentPoint.x,currentPoint.y);
			
			
			
			recordTimes++;//��ʵ�ʼ�¼�İ���������
			break;
		case  VK_CANCEL:
		
		
		case  VK_SHIFT:
		case  VK_CONTROL:
		
			break;
		case  VK_BACK:		//�س������Ǹ���	08
		case	VK_OEM_3://���������Ͻǡ�Esc���±ߡ�~��������			192
		case  VK_TAB:
		case  VK_ESCAPE:			//27
		case  VK_HOME:	//36
		case  VK_F1:
		case  VK_F2:
		case  VK_F3:
		case  VK_F4:
		case  VK_F5:
		case  VK_F6:
		case  VK_F7:
			break;
		case  VK_F8:
			//���ٹ����������


			break;
		case  VK_F9:
			exit(0);
			break;
		case  VK_F10:
		case  VK_F11:
		case  VK_F12://ע��Ĭ�ϲ��������������Ϊ�������Ϊ��صĽ�������ȻҲ���Լ�أ���Ϊ��Ҳ����ָ��һ����ť
					//�����Ƽ�صĽ����������������ű�����󼸸�shell����û�õģ���Ҫȥ��
		case  0x30://48
		case  0x31:
		case  0x32:
		case  0x33:
		case  0x34:
		case  0x35:
		case  0x36:
		case  0x37:
		case  0x38:
		case  0x39:
		case  0x41:
		case  0x42:
		case  0x43:
		case  0x44://	D key   68
		case  0x45://	E key
		case  0x46://	F key
		case  0x47://	G key
		case  0x48://	H key
		case  0x49://	I key
		case  0x4A://	J key
		case  0x4B://	K key
		case  0x4C://	L key
		case  0x4D://	M key  77
		case  0x4E://	N key
		case  0x4F://	O key
		case  0x50://	P key
		case  0x51://	Q key
		case  0x52://	R key
		case  0x53://	S key
		case  0x54://	T key
		case  0x55://	U key
		case  0x56://	V key
		case  0x57://	W key
		case  0x58://	X key
		case  0x59://	Y key
		case  0x5A://	Z key			keyboard:21200:1:27
		case  VK_NUMPAD0://	60	Numeric keypad 0 key
		case  VK_NUMPAD1://	61	Numeric keypad 1 key
		case  VK_NUMPAD2://	62	Numeric keypad 2 key
		case  VK_NUMPAD3://	63	Numeric keypad 3 key
		case  VK_NUMPAD5://	65	Numeric keypad 5 key
		case  VK_NUMPAD6://	66	Numeric keypad 6 key
		case  VK_NUMPAD7://	67	Numeric keypad 7 key
		case  VK_NUMPAD8://	68	Numeric keypad 8 key
		case  VK_NUMPAD9://	69	Numeric keypad 9 key
		case  VK_MULTIPLY://	6A	Multiply key
		case  VK_ADD://6B	Add key
		case  VK_SEPARATOR://	6C	Separator key
		case  VK_SUBTRACT://	6D	Subtract key
		case  VK_DECIMAL://	6E	Decimal key
		case  VK_DIVIDE://	6F	Divide key




			//if ((lParam & 0x40000000)  == 1)//����ǰ������º��͵���Ϣ��30λΪ1������ǰ���̧���30λΪ0��
			{

				currentVirtualKey = wParam;
				currentVirtualKeyShellName.Format(_T("keyboard"));

				currentParameterNum = 1;
				currentParameterStr.Format(_T("%d"), wParam);
				//currentParameterStr.Format(_T("%d.  %x   VirtualKey = %d"), wParam, lParam, currentVirtualKey);

				recordTimes++;//��ʵ�ʼ�¼�İ���������
			}
				
			//
			break;
		default:break;
		}

		//�ж��Ƿ�������shell�ű�
		//���ǰ���һ����������������������һ��down һ��up

		/*���Դ��룺
		if (recordTimes >1)
		{
			
			span = currentOpTime - lastOpTime;
			timeBetweenShell = span.GetTotalSeconds();
			tmpi = timeBetweenShell;
			//���һ���ڰ��˶��ͬһ��������ֻ��¼һ�Σ����ǵ����ǵ�ʱ�侫�����⣬��ʵ
			//�������ɿ��ܻ�©��һЩ����
			if (timeBetweenShell != 0  ||  (currentVirtualKey != lastVirtualKey ))
			{
			//��ΪtimeBetweenShell��λ���룬��Ҫת��
				timeBetweenShell = timeBetweenShell * 1000 +1000;

			shellStr.Format(_T("%s:%d:%d:%s"), lastVirtualKeyShellName, timeBetweenShell, lastParameterNum, lastParameterStr);
				//shellStr.Format(_T("%s:%d:%d:%s   %d"), lastVirtualKeyShellName, timeBetweenShell, lastParameterNum, lastParameterStr, tmpi);
			standardOutput(shellStr);
			}
			
		}
		*/
	}
	recordCounts = recordTimes;


	 lastOpTime = currentOpTime;
	 lastVirtualKey = currentVirtualKey;
	 lastVirtualKeyShellName = currentVirtualKeyShellName;
	 //lastPoint = currentPoint;
	 lastParameterNum = currentParameterNum;
	 lastParameterStr = currentParameterStr;
	return CallNextHookEx(glhHook, nCode, wParam, lParam);
}

CString oldlpWindowName("HookPaint");

void SetWindowTitleBypass(int line)  //����HookPaint�ı���
{
	LPCTSTR lpWindowName = (LPCTSTR)oldlpWindowName;
	CString  title;
	title.Format(_T("%d"), line);
	if (title.GetLength() <= 0)
		return;

	HWND pWndPrev;

	pWndPrev = ::FindWindow(NULL, lpWindowName);  //#32770 (Dialog)

	if (NULL == pWndPrev)
	{
		//AfxMessageBox(_T("fail to get HookPaint's window"));
		return;
	}

	::SetWindowText(pWndPrev, title);


	oldlpWindowName = title;

}

HCURSOR hcuOld;
static int CursurCount = 0;

extern "C" LRESULT WINAPI MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	//if( HC_ACTION != nCode) return 0;
	//AfxMessageBox(_T("wParam id ")+wParam);

	hcuOld = GetCursor();
	int ii = CursurCount;
	if (wParam == WM_LBUTTONUP)
	{
		CPoint newPoint;
		GetCursorPos(&newPoint);
		HCURSOR hcu = GetCursor();

		/*	if(hcu ==hcuOld)
		return 0;
		else hcuOld=hcu;*/

		if (CursurCount<65530)
			CursurCount++;
		else
			CursurCount = 0;
		ii = CursurCount;
		//SetWindowTitleBypass(ii);
		CString str("11");
		standardOutput(str);
	}


	return 0;
}
//��¼�����Ϣ
//����lParam����������λ�ã����е�λΪx���꣬��λΪy���꣬��Щ����ֵ��������ڴ��ڿͻ��������Ͻǵ�ֵ��wParam�����������갴ť��״̬.
extern "C" LRESULT WINAPI RecordMouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	//if( HC_ACTION != nCode) return 0;
	//AfxMessageBox(_T("wParam id ")+wParam);
	int recordTimes ;
	int outputFlag = 1;
	int timeBetweenShell;
	CTimeSpan span;
	hcuOld = GetCursor();
	int ii = CursurCount;
	CString shellStr,unknowStr;

	recordTimes = recordCounts;
	//if (  (wParam == WM_LBUTTONUP || wParam == WM_RBUTTONDOWN)    &&  wParam != WM_MOUSEMOVE)
	if (wParam != WM_MOUSEMOVE)
	{
		currentOpTime = CTime::GetCurrentTime();
		currentVirtualKey = wParam;

		if (wParam == WM_LBUTTONUP)
			currentVirtualKeyShellName.Format(_T("LeftMouse"));
		else if (wParam == WM_RBUTTONDOWN)
			currentVirtualKeyShellName.Format(_T("RightMouse"));
		//else if (wParam == 0x20b)
		//	currentVirtualKeyShellName.Format(_T("first X button"));
		//else if (wParam == 0x201)
		//	currentVirtualKeyShellName.Format(_T("second X button"));
		else
		{
			outputFlag = 0;
			unknowStr.Format(_T("unknowStr:%d"), wParam);
		}
			
	
		

		GetCursorPos(&currentPoint);
		currentParameterNum = 2;
		currentParameterStr.Format(_T("%d,%d"), currentPoint.x, currentPoint.y);

		recordTimes++;//��ʵ�ʼ�¼�İ���������

		//�ж��Ƿ�������shell�ű�
		//���ǰ���һ����������������������һ��down һ��up
		if (recordTimes >1)
		{

			span = currentOpTime - lastOpTime;
			timeBetweenShell = span.GetTotalSeconds();
			//��ΪtimeBetweenShell��λ���룬��Ҫת��

					timeBetweenShell = timeBetweenShell * 1000 +1000;
			shellStr.Format(_T("%s:%d:%d:%s"), lastVirtualKeyShellName, timeBetweenShell, lastParameterNum, lastParameterStr);
			if (outputFlag == 1)
				standardOutput(shellStr);
			else
				standardOutput(unknowStr);

		}

		recordCounts = recordTimes;


		lastOpTime = currentOpTime;
		lastVirtualKey = currentVirtualKey;
		lastVirtualKeyShellName = currentVirtualKeyShellName;
		//lastPoint = currentPoint;
		lastParameterNum = currentParameterNum;
		lastParameterStr = currentParameterStr;


	}


	return 0;
}

CHookDll::CHookDll(){}
CHookDll::~CHookDll()
{
	if (glhHook)
		Stop();
}

 HHOOK CHookDll::RecordMouseAndKeyboard() //��װ������깳�ӣ�����¼
{
	 CString tmp;
	 tmp.Format(_T("new  shell::"));
	 standardOutput(tmp);
	 recordCounts = 0;
	glhHook = SetWindowsHookEx(WH_KEYBOARD, RecordKeyboardProc, glhInstance, 0);//���ü��̹��ӡ�
	if (glhHook == NULL)
		AfxMessageBox(_T("glhHook == NULL1111"));


	glhHook = SetWindowsHookEx(WH_MOUSE, RecordMouseProc, glhInstance, 0);//
	if (glhHook == NULL)
	{
		AfxMessageBox(_T("glhHook == NULL1111"));
	}

	return glhHook;
}

//��װȫ�ֹ��ӡ�
HHOOK CHookDll::Start()
{
	//AfxMessageBox(_T(":Start()"));
	glhHook = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, glhInstance, 0);//���ü��̹��ӡ�
	if (glhHook == NULL)
		AfxMessageBox(_T("glhHook == NULL1111"));
	return glhHook;
}


//��װȫ����깳�ӡ�
HHOOK CHookDll::StartMouse()
{


	glhHook = SetWindowsHookEx(WH_MOUSE, MouseProc, glhInstance, 0);//
	if (glhHook == NULL)
	{
		AfxMessageBox(_T("glhHook == NULL1111"));
		//Sleep(1000);
		//goto xxxx;
	}
	return glhHook;
}
//ж��ȫ�ֹ��ӡ�
BOOL CHookDll::Stop()
{
	BOOL bResult = TRUE;
	if (glhHook)
		bResult = UnhookWindowsHookEx(glhHook);//ж�ؼ��̹��ӡ�
	return bResult;
}

void CHookDll::tryDiao()
{
	AfxMessageBox(_T("succese to load dll"));

}
void  CHookDll::getCurrentMousePos()
{
	StartMouse();

}

void CHookDll::setglhInstance(HINSTANCE _glhInstance)
{
	glhInstance = _glhInstance;
}


void  CHookDll::MoveRole()
{

	DWORD dwTheadID;
	int x = 0;
	HANDLE htherad = CreateThread(NULL, 0, workIngPro, (PVOID)&x, 0, &dwTheadID);



}
