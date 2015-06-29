
// shellDlg.cpp : 实现文件
//
//#include "HookDll.h"
#include "stdafx.h"
#include "shell.h"
#include "shellDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "xiaoaoshell.h"
#include "taskHandle.h"
#include "fileoperating.h"
#include "operating.h"
#include "tianyuShell.h"
//extern operat lin;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
//#pragma comment(lib,"HookDll.lib")
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	//BOOL CAboutDlg::PreTranslateMessage(MSG* pMsg);////////////自己加的
// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

//
//BOOL CAboutDlg::PreTranslateMessage(MSG* pMsg)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//	if ((VK_F1 == pMsg->wParam && WM_KEYDOWN == pMsg->message) || (pMsg->message == 77))
//		return TRUE;
//	return CDialog::PreTranslateMessage(pMsg);
//}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CshellDlg 对话框
LRESULT CshellDlg::OnHotKey(WPARAM wParam, LPARAM lParam) 
{ // TODO: Add your code here
	//AfxMessageBox(_T("test"));
	CString  littleshellfile(_T("C:\\data\\testTaskShell.txt"));
	CStdioFile openfile(littleshellfile, CFile::modeRead);				//构造CStdioFile对象
	CString str;
	int keyID;
	int count = 0;
	if (openfile.ReadString(str))							//读一行数据
	{

		count++;
	}
	else
	{
		CString  zuobiao1;
		zuobiao1.Format(_T("找不到shell脚本"));
		//  zuobiao2.Format(_T("ParameterNum=%d"),op->ParameterNum);
		//  shi=(op->shelltype)+zuobiao1+zuobiao2+(op->Parameter);
		AfxMessageBox(zuobiao1);

	}
	//我擦，在这个函数里面lParam的高位才是实际的按键ID
	keyID = lParam >> 16;
	if (keyID == VK_F2)
	{
		if (count == 1)//e0e0
		{
			readAndRunShell(str);

		}

	}
	else if (keyID == VK_F3)
	{
		CString  zuobiao1;
		//zuobiao1.Format(_T("f3"));
		//AfxMessageBox(zuobiao1);
		HWND hWnd; // hWnd : 该视窗的 handle
		DWORD dwx; // dwx : 为存放内 ProcessID 的变数位址
		HANDLE hProc; //Process handle
		CRect rect;
		hWnd = ::FindWindow(_T("NETEASE-TY-APP"), NULL);
		//lpszClassName:窗口类名，lpszWindowName:窗口标题。两个要一个就可以了，当然两个更准确
		zuobiao1.Format(_T("找不到窗口"));
		if (hWnd == false)
		{

			AfxMessageBox(zuobiao1);
			return  0;
		}
		::GetWindowThreadProcessId(hWnd, &dwx);


		CString str;
		TCHAR Title[100];
		int ret = 0;
		::GetWindowText(hWnd, Title, sizeof(Title));
		//ret = CompareText(title, IETitle);
		str.Format(_T("%s"), Title);
		//AfxMessageBox(str);

		//如果你想要得到句柄的那个窗口就是当前活动窗口的话，那就用GetActiveWindow()
		//该函数获取窗口客户区的坐标。客户区坐标指定客户区的左上角和右下角。由于客户区坐标是相对窗口客户区的左上角而言的，因此左上角坐标为（0，0）
		//::GetClientRect(hWnd, &rect);//以窗口左上角位原点
		::GetWindowRect(hWnd, &rect);
		//GetWindowRect获取的区域要比GetClientRect获取的区域大，因为包含了标题栏的区域。
		//str.Format(_T("宽度：%d,高度:%d,左上角:%d.%d,右下角：%d.%d"), rect.Width(), rect.Height(), rect.TopLeft().x, rect.TopLeft().y, rect.BottomRight().x, rect.BottomRight().y);
		//AfxMessageBox(str);



		// 呼叫 GetWindowThreadProcessID 这个 Win32 API 来取得 ProcessID
		// 正常执行无误後,会将 Process ID 存入 dwx 这个位址中
		zuobiao1.Format(_T("找不到ProcessID"));
		hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwx);
		if (hProc == false) return  0;


		HWND hwndAfter = NULL;
		while (hwndAfter = ::FindWindowEx(hWnd, hwndAfter, NULL, NULL))
		{
			//memset(szText, 0, 256);
			//::SendMessage(hwndAfter, WM_GETTEXT, (WPARAM)256, (LPARAM)szText);
			//printf("%s\t", szText);
			//myEnumWindow(hwndAfter);
			//zuobiao1.Format(_T("找到控件ID：%d"), );
			TCHAR szBuf[280];
			memset(szBuf, 0, sizeof(str));
			::GetWindowText(hWnd, szBuf, sizeof(str));
		}
	}





	return 0;
}


CshellDlg::CshellDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CshellDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CshellDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CshellDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CshellDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CshellDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CshellDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CshellDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CshellDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CshellDlg::getMousePosAndOutput)
	ON_BN_CLICKED(IDC_BUTTON7, &CshellDlg::TaskHandleClickedButton)
	ON_BN_CLICKED(IDC_BUTTON8, &CshellDlg::OnBnClickedHotKeyRecord)
	ON_BN_CLICKED(IDC_BUTTON9, &CshellDlg::OnBnClickedLingLong)
	ON_BN_CLICKED(IDC_BUTTON10, &CshellDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CshellDlg::OnBnClickedButton11)
	ON_MESSAGE(WM_HOTKEY, OnHotKey)
END_MESSAGE_MAP()


// CshellDlg 消息处理程序

BOOL CshellDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	// TODO: Add extra initialization here
	bSetup = false;
	//CKeyHook *m_hook;
	glhInstance = LoadLibrary(L"HookDll.dll");
	//RegisterHotKey(m_hWnd, 1001, MOD_ALT, VK_F8);//用Alt+f8作为快捷键，第二个参数必须系统唯一
	RegisterHotKey(m_hWnd, 1001, 0, VK_F2);//用f8作为快捷键，第二个参数必须系统唯一
	RegisterHotKey(m_hWnd, 1002, 0, VK_F3);//用f8作为快捷键，第二个参数必须系统唯一
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CshellDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CshellDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CshellDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

bool  bSetup = false;
CKeyHook *m_hook;


HINSTANCE glhInstance = NULL;

void CshellDlg::OnBnClickedButton1()
{

	if (glhInstance == NULL)
	{
		FreeLibrary(glhInstance);
		AfxMessageBox(_T("fail to load dll in app"));
		return;
	}
	m_hook = new CHookDll;
	if (m_hook != NULL)
	{
		m_hook->setglhInstance(glhInstance);
		m_hook->Start();//激活全局钩子。

		//afxmessagebox(_t("succese to load dll"));

	}
	else AfxMessageBox(_T("fail to get lei"));

}





//自动打怪
void CshellDlg::OnBnClickedButton2()
{
	DWORD dwTheadID;
	int x=1;
	int *p=&x;
	struct AttackType t;
	t.type=1;
	HANDLE htherad=CreateThread(NULL,0,autoAttack,(PVOID)x,0,&dwTheadID);
}


void CshellDlg::OnBnClickedButton3()
{

	CString  zuobiao1;

	//Sleep(3000);
//	CPoint start, end;
//	start.x=406;
//	start.y=751;
//	end.x=593;
//	end.y=752;
////struct colourRGB  lin=	CalculateAverageValueRBG( start, end,3);
//
//	int width = GetSystemMetrics ( SM_CXSCREEN ); 
//	int height= GetSystemMetrics ( SM_CYSCREEN ); 
//
//
//
//	 CString file(_T("D:\\data\\1280800\\FindMatrixMsg.txt"));
//	 CPoint startPoint;
//	 struct colourRGB AverageValueRBG;
//	 CPoint LeftPoint, RightPoint;
//	 getMsgForFindMatrix( file,&startPoint,&AverageValueRBG);
//	 int res=FindMatrix(startPoint,AverageValueRBG,& LeftPoint,& RightPoint);




	//查找窗口中的控件ID，用FindWindowEx
	
	
		HWND hWnd; // hWnd : 该视窗的 handle
	DWORD dwx; // dwx : 为存放内 ProcessID 的变数位址
	HANDLE hProc; //Process handle
	CRect rect;
	hWnd = ::FindWindow(_T("NETEASE-TY-APP"), NULL);
	//lpszClassName:窗口类名，lpszWindowName:窗口标题。两个要一个就可以了，当然两个更准确
	zuobiao1.Format(_T("找不到窗口"));
	if (hWnd == false)
	{

		AfxMessageBox(zuobiao1);
		return;
	}
	::GetWindowThreadProcessId(hWnd, &dwx);


	CString str;
	TCHAR Title[100];
	int ret = 0;
	::GetWindowText(hWnd, Title, sizeof(Title));
	//ret = CompareText(title, IETitle);
	str.Format(_T("%s"), Title);
	//AfxMessageBox(str);

	//如果你想要得到句柄的那个窗口就是当前活动窗口的话，那就用GetActiveWindow()
	//该函数获取窗口客户区的坐标。客户区坐标指定客户区的左上角和右下角。由于客户区坐标是相对窗口客户区的左上角而言的，因此左上角坐标为（0，0）
	//::GetClientRect(hWnd, &rect);//以窗口左上角位原点
	::GetWindowRect(hWnd, &rect);
	//GetWindowRect获取的区域要比GetClientRect获取的区域大，因为包含了标题栏的区域。
	//str.Format(_T("宽度：%d,高度:%d,左上角:%d.%d,右下角：%d.%d"), rect.Width(), rect.Height(), rect.TopLeft().x, rect.TopLeft().y, rect.BottomRight().x, rect.BottomRight().y);
	//AfxMessageBox(str);
	
	

	// 呼叫 GetWindowThreadProcessID 这个 Win32 API 来取得 ProcessID
	// 正常执行无误後,会将 Process ID 存入 dwx 这个位址中
	zuobiao1.Format(_T("找不到ProcessID"));
	hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwx);
	if (hProc == false) return ;


	HWND hwndAfter = NULL;
	while (hwndAfter = ::FindWindowEx(hWnd, hwndAfter, NULL, NULL))
	{
		//memset(szText, 0, 256);
		//::SendMessage(hwndAfter, WM_GETTEXT, (WPARAM)256, (LPARAM)szText);
		//printf("%s\t", szText);
		//myEnumWindow(hwndAfter);
		//zuobiao1.Format(_T("找到控件ID：%d"),);
	}



	// 呼叫 OpenProcess 这个 Win32 API 来取得 Process handle
	// 正常执行无误後,会将 Process handle 存入 hProc

}


//这个按钮用来运行一些小脚本，在文件littleshell.txt中指定的脚本
void CshellDlg::OnBnClickedButton4()
{
	Sleep(3000);
	//CString  littleshellfile(_T("D:\\data\\littleshell.txt"));
	CString  littleshellfile(_T("C:\\data\\testTaskShell.txt"));
	CStdioFile openfile(littleshellfile,CFile::modeRead);				//构造CStdioFile对象
	CString str;
	int count=0;
	if(openfile.ReadString(str))							//读一行数据
	{

			count++;
	}
	else
	{
		CString  zuobiao1;
		zuobiao1.Format(_T("找不到shell脚本"));
		//  zuobiao2.Format(_T("ParameterNum=%d"),op->ParameterNum);
		//  shi=(op->shelltype)+zuobiao1+zuobiao2+(op->Parameter);
		AfxMessageBox(zuobiao1);

	}

	if(count ==1)//e0e0
	{	
		readAndRunShell(str);

	}



		

}

//唐门自动打怪
void CshellDlg::OnBnClickedButton5()
{
	DWORD dwTheadID;
	int x=2;
	HANDLE htherad=CreateThread(NULL,0,autoAttack,(PVOID)x,0,&dwTheadID);
}


void CshellDlg::getMousePosAndOutput()
{
	// TODO:  在此添加控件通知处理程序代码












}


void CshellDlg::TaskHandleClickedButton()
{
	Sleep(3000);
	//CString  littleshellfile(_T("D:\\data\\testTaskShell.txt"));

	//调用无忧函数
	//tianxiawuyouTaskHandle();

	//现在开始做主线任务
	//TaskId_Mainline_Hangdle_fuc(TaskId_Mainline_4);
	//TaskId_Mainline_Hangdle_fuc(TaskId_Mainline_2);
	//TaskId_Mainline_Hangdle_fuc(TaskId_Mainline_3);
	//TaskId_Mainline_Hangdle_fuc(TaskId_Mainline_5);


	CString fileName;
	fileName.Format(_T("D:\\data\\process.txt"));
	CStdioFile openfile(fileName, CFile::modeRead);				//构造CStdioFile对象
	CString str;
	openfile.ReadString(str);					//读一行数据

	//从文本中读取该执行的shell进度

	//另外第一次进入游戏需要做一些每次进入游戏的操作，如隐藏其他玩家，收取登入奖励
	SignInTaskFuc();
	TaskId_Mainline_Hangdle_fuc(int ( _ttoi(str)));



}

void CshellDlg::OnBnClickedHotKeyRecord()
{
	if (glhInstance == NULL)
	{
		FreeLibrary(glhInstance);
		AfxMessageBox(_T("fail to load dll in app"));
		return;
	}
	m_hook = new CHookDll;
	if (m_hook != NULL)
	{
		m_hook->setglhInstance(glhInstance);
		m_hook->RecordMouseAndKeyboard();//激活全局钩子。kaishi开始记录按键

		//afxmessagebox(_t("succese to load dll"));

	}
	else AfxMessageBox(_T("fail to get lei"));
}


void CshellDlg::OnBnClickedLingLong()//玲珑刷怪
{
	// 首先添加按键监听处理：按F9退出程序
	if (glhInstance == NULL)
	{
		FreeLibrary(glhInstance);
		AfxMessageBox(_T("fail to load dll in app"));
		return;
	}
	m_hook = new CHookDll;
	if (m_hook != NULL)
	{
		m_hook->setglhInstance(glhInstance);
		m_hook->RecordMouseAndKeyboard();//激活全局钩子。kaishi开始记录按键

		//afxmessagebox(_t("succese to load dll"));

	}
	else AfxMessageBox(_T("fail to get lei"));

	//

	//运行刷怪脚本：
	DWORD dwTheadID;
	int x = 1;
	HANDLE htherad = CreateThread(NULL, 0, autoAttack_LingLong, (PVOID)x, 0, &dwTheadID);


}


void CshellDlg::OnBnClickedButton10()
{
	// 首先添加按键监听处理：按F9退出程序
	if (glhInstance == NULL)
	{
		FreeLibrary(glhInstance);
		AfxMessageBox(_T("fail to load dll in app"));
		return;
	}
	m_hook = new CHookDll;
	if (m_hook != NULL)
	{
		//m_hook->setglhInstance(glhInstance);
		//m_hook->RecordMouseAndKeyboard();//激活全局钩子。kaishi开始记录按键

		//afxmessagebox(_t("succese to load dll"));

	}
	else AfxMessageBox(_T("fail to get lei"));

	//

	//运行刷怪脚本：
	DWORD dwTheadID;
	int x = 1;
	HANDLE htherad = CreateThread(NULL, 0, autoAttack_LingLongZuDui, (PVOID)x, 0, &dwTheadID);
}


void CshellDlg::OnBnClickedButton11()
{
	// 首先添加按键监听处理：按F9退出程序
	if (glhInstance == NULL)
	{
		FreeLibrary(glhInstance);
		AfxMessageBox(_T("fail to load dll in app"));
		return;
	}
	m_hook = new CHookDll;
	if (m_hook != NULL)
	{
		//m_hook->setglhInstance(glhInstance);
		//m_hook->RecordMouseAndKeyboard();//激活全局钩子。kaishi开始记录按键

	}
	else AfxMessageBox(_T("fail to get lei"));

	//

	//运行刷怪脚本：
	DWORD dwTheadID;
	int x = 2;
	HANDLE htherad = CreateThread(NULL, 0, autoAttack_LingLongZuDui, (PVOID)x, 0, &dwTheadID);
}
