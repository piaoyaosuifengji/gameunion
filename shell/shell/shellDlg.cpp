
// shellDlg.cpp : ʵ���ļ�
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
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
//#pragma comment(lib,"HookDll.lib")
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	//BOOL CAboutDlg::PreTranslateMessage(MSG* pMsg);////////////�Լ��ӵ�
// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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
//	// TODO: �ڴ����ר�ô����/����û���
//	if ((VK_F1 == pMsg->wParam && WM_KEYDOWN == pMsg->message) || (pMsg->message == 77))
//		return TRUE;
//	return CDialog::PreTranslateMessage(pMsg);
//}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CshellDlg �Ի���
LRESULT CshellDlg::OnHotKey(WPARAM wParam, LPARAM lParam) 
{ // TODO: Add your code here
	//AfxMessageBox(_T("test"));
	CString  littleshellfile(_T("C:\\data\\testTaskShell.txt"));
	CStdioFile openfile(littleshellfile, CFile::modeRead);				//����CStdioFile����
	CString str;
	int keyID;
	int count = 0;
	if (openfile.ReadString(str))							//��һ������
	{

		count++;
	}
	else
	{
		CString  zuobiao1;
		zuobiao1.Format(_T("�Ҳ���shell�ű�"));
		//  zuobiao2.Format(_T("ParameterNum=%d"),op->ParameterNum);
		//  shi=(op->shelltype)+zuobiao1+zuobiao2+(op->Parameter);
		AfxMessageBox(zuobiao1);

	}
	//�Ҳ����������������lParam�ĸ�λ����ʵ�ʵİ���ID
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
		HWND hWnd; // hWnd : ���Ӵ��� handle
		DWORD dwx; // dwx : Ϊ����� ProcessID �ı���λַ
		HANDLE hProc; //Process handle
		CRect rect;
		hWnd = ::FindWindow(_T("NETEASE-TY-APP"), NULL);
		//lpszClassName:����������lpszWindowName:���ڱ��⡣����Ҫһ���Ϳ����ˣ���Ȼ������׼ȷ
		zuobiao1.Format(_T("�Ҳ�������"));
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

		//�������Ҫ�õ�������Ǹ����ھ��ǵ�ǰ����ڵĻ����Ǿ���GetActiveWindow()
		//�ú�����ȡ���ڿͻ��������ꡣ�ͻ�������ָ���ͻ��������ϽǺ����½ǡ����ڿͻ�����������Դ��ڿͻ��������ϽǶ��Եģ�������Ͻ�����Ϊ��0��0��
		//::GetClientRect(hWnd, &rect);//�Դ������Ͻ�λԭ��
		::GetWindowRect(hWnd, &rect);
		//GetWindowRect��ȡ������Ҫ��GetClientRect��ȡ���������Ϊ�����˱�����������
		//str.Format(_T("��ȣ�%d,�߶�:%d,���Ͻ�:%d.%d,���½ǣ�%d.%d"), rect.Width(), rect.Height(), rect.TopLeft().x, rect.TopLeft().y, rect.BottomRight().x, rect.BottomRight().y);
		//AfxMessageBox(str);



		// ���� GetWindowThreadProcessID ��� Win32 API ��ȡ�� ProcessID
		// ����ִ��������,�Ὣ Process ID ���� dwx ���λַ��
		zuobiao1.Format(_T("�Ҳ���ProcessID"));
		hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwx);
		if (hProc == false) return  0;


		HWND hwndAfter = NULL;
		while (hwndAfter = ::FindWindowEx(hWnd, hwndAfter, NULL, NULL))
		{
			//memset(szText, 0, 256);
			//::SendMessage(hwndAfter, WM_GETTEXT, (WPARAM)256, (LPARAM)szText);
			//printf("%s\t", szText);
			//myEnumWindow(hwndAfter);
			//zuobiao1.Format(_T("�ҵ��ؼ�ID��%d"), );
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


// CshellDlg ��Ϣ�������

BOOL CshellDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	// TODO: Add extra initialization here
	bSetup = false;
	//CKeyHook *m_hook;
	glhInstance = LoadLibrary(L"HookDll.dll");
	//RegisterHotKey(m_hWnd, 1001, MOD_ALT, VK_F8);//��Alt+f8��Ϊ��ݼ����ڶ�����������ϵͳΨһ
	RegisterHotKey(m_hWnd, 1001, 0, VK_F2);//��f8��Ϊ��ݼ����ڶ�����������ϵͳΨһ
	RegisterHotKey(m_hWnd, 1002, 0, VK_F3);//��f8��Ϊ��ݼ����ڶ�����������ϵͳΨһ
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CshellDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
		m_hook->Start();//����ȫ�ֹ��ӡ�

		//afxmessagebox(_t("succese to load dll"));

	}
	else AfxMessageBox(_T("fail to get lei"));

}





//�Զ����
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




	//���Ҵ����еĿؼ�ID����FindWindowEx
	
	
		HWND hWnd; // hWnd : ���Ӵ��� handle
	DWORD dwx; // dwx : Ϊ����� ProcessID �ı���λַ
	HANDLE hProc; //Process handle
	CRect rect;
	hWnd = ::FindWindow(_T("NETEASE-TY-APP"), NULL);
	//lpszClassName:����������lpszWindowName:���ڱ��⡣����Ҫһ���Ϳ����ˣ���Ȼ������׼ȷ
	zuobiao1.Format(_T("�Ҳ�������"));
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

	//�������Ҫ�õ�������Ǹ����ھ��ǵ�ǰ����ڵĻ����Ǿ���GetActiveWindow()
	//�ú�����ȡ���ڿͻ��������ꡣ�ͻ�������ָ���ͻ��������ϽǺ����½ǡ����ڿͻ�����������Դ��ڿͻ��������ϽǶ��Եģ�������Ͻ�����Ϊ��0��0��
	//::GetClientRect(hWnd, &rect);//�Դ������Ͻ�λԭ��
	::GetWindowRect(hWnd, &rect);
	//GetWindowRect��ȡ������Ҫ��GetClientRect��ȡ���������Ϊ�����˱�����������
	//str.Format(_T("��ȣ�%d,�߶�:%d,���Ͻ�:%d.%d,���½ǣ�%d.%d"), rect.Width(), rect.Height(), rect.TopLeft().x, rect.TopLeft().y, rect.BottomRight().x, rect.BottomRight().y);
	//AfxMessageBox(str);
	
	

	// ���� GetWindowThreadProcessID ��� Win32 API ��ȡ�� ProcessID
	// ����ִ��������,�Ὣ Process ID ���� dwx ���λַ��
	zuobiao1.Format(_T("�Ҳ���ProcessID"));
	hProc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwx);
	if (hProc == false) return ;


	HWND hwndAfter = NULL;
	while (hwndAfter = ::FindWindowEx(hWnd, hwndAfter, NULL, NULL))
	{
		//memset(szText, 0, 256);
		//::SendMessage(hwndAfter, WM_GETTEXT, (WPARAM)256, (LPARAM)szText);
		//printf("%s\t", szText);
		//myEnumWindow(hwndAfter);
		//zuobiao1.Format(_T("�ҵ��ؼ�ID��%d"),);
	}



	// ���� OpenProcess ��� Win32 API ��ȡ�� Process handle
	// ����ִ��������,�Ὣ Process handle ���� hProc

}


//�����ť��������һЩС�ű������ļ�littleshell.txt��ָ���Ľű�
void CshellDlg::OnBnClickedButton4()
{
	Sleep(3000);
	//CString  littleshellfile(_T("D:\\data\\littleshell.txt"));
	CString  littleshellfile(_T("C:\\data\\testTaskShell.txt"));
	CStdioFile openfile(littleshellfile,CFile::modeRead);				//����CStdioFile����
	CString str;
	int count=0;
	if(openfile.ReadString(str))							//��һ������
	{

			count++;
	}
	else
	{
		CString  zuobiao1;
		zuobiao1.Format(_T("�Ҳ���shell�ű�"));
		//  zuobiao2.Format(_T("ParameterNum=%d"),op->ParameterNum);
		//  shi=(op->shelltype)+zuobiao1+zuobiao2+(op->Parameter);
		AfxMessageBox(zuobiao1);

	}

	if(count ==1)//e0e0
	{	
		readAndRunShell(str);

	}



		

}

//�����Զ����
void CshellDlg::OnBnClickedButton5()
{
	DWORD dwTheadID;
	int x=2;
	HANDLE htherad=CreateThread(NULL,0,autoAttack,(PVOID)x,0,&dwTheadID);
}


void CshellDlg::getMousePosAndOutput()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������












}


void CshellDlg::TaskHandleClickedButton()
{
	Sleep(3000);
	//CString  littleshellfile(_T("D:\\data\\testTaskShell.txt"));

	//�������Ǻ���
	//tianxiawuyouTaskHandle();

	//���ڿ�ʼ����������
	//TaskId_Mainline_Hangdle_fuc(TaskId_Mainline_4);
	//TaskId_Mainline_Hangdle_fuc(TaskId_Mainline_2);
	//TaskId_Mainline_Hangdle_fuc(TaskId_Mainline_3);
	//TaskId_Mainline_Hangdle_fuc(TaskId_Mainline_5);


	CString fileName;
	fileName.Format(_T("D:\\data\\process.txt"));
	CStdioFile openfile(fileName, CFile::modeRead);				//����CStdioFile����
	CString str;
	openfile.ReadString(str);					//��һ������

	//���ı��ж�ȡ��ִ�е�shell����

	//�����һ�ν�����Ϸ��Ҫ��һЩÿ�ν�����Ϸ�Ĳ�����������������ң���ȡ���뽱��
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
		m_hook->RecordMouseAndKeyboard();//����ȫ�ֹ��ӡ�kaishi��ʼ��¼����

		//afxmessagebox(_t("succese to load dll"));

	}
	else AfxMessageBox(_T("fail to get lei"));
}


void CshellDlg::OnBnClickedLingLong()//����ˢ��
{
	// ������Ӱ�������������F9�˳�����
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
		m_hook->RecordMouseAndKeyboard();//����ȫ�ֹ��ӡ�kaishi��ʼ��¼����

		//afxmessagebox(_t("succese to load dll"));

	}
	else AfxMessageBox(_T("fail to get lei"));

	//

	//����ˢ�ֽű���
	DWORD dwTheadID;
	int x = 1;
	HANDLE htherad = CreateThread(NULL, 0, autoAttack_LingLong, (PVOID)x, 0, &dwTheadID);


}


void CshellDlg::OnBnClickedButton10()
{
	// ������Ӱ�������������F9�˳�����
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
		//m_hook->RecordMouseAndKeyboard();//����ȫ�ֹ��ӡ�kaishi��ʼ��¼����

		//afxmessagebox(_t("succese to load dll"));

	}
	else AfxMessageBox(_T("fail to get lei"));

	//

	//����ˢ�ֽű���
	DWORD dwTheadID;
	int x = 1;
	HANDLE htherad = CreateThread(NULL, 0, autoAttack_LingLongZuDui, (PVOID)x, 0, &dwTheadID);
}


void CshellDlg::OnBnClickedButton11()
{
	// ������Ӱ�������������F9�˳�����
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
		//m_hook->RecordMouseAndKeyboard();//����ȫ�ֹ��ӡ�kaishi��ʼ��¼����

	}
	else AfxMessageBox(_T("fail to get lei"));

	//

	//����ˢ�ֽű���
	DWORD dwTheadID;
	int x = 2;
	HANDLE htherad = CreateThread(NULL, 0, autoAttack_LingLongZuDui, (PVOID)x, 0, &dwTheadID);
}
