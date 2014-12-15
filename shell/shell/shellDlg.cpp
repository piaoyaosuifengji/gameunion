
// shellDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "shell.h"
#include "shellDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "xiaoaoshell.h"

#include "fileoperating.h"
#include "operating.h"
//extern operat lin;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

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

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CshellDlg 对话框




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



void CshellDlg::OnBnClickedButton1()
{
	Sleep(3500);

	CString fileName("shell.txt");
	//int x=198;
	//int y=842;
	//sendALeftMuoseClick(x,y,1500);//点击菜单
	//char c='0';
	//int i=0;
	//for(;i<=9;i++)
	//{
	//	ToInPutChar(c+i);
	//}


	//读取shell文本

	int count=lineCount( fileName);
	struct operat *p=new struct operat[count];
	int countINFact=ReadTxtToGetShellByName2(fileName,count,p);


	//分析命令
	//就是得出该执行的操作，以及相应的参数
	struct dodo *todo=new struct dodo[countINFact];

	int res=haveToDo( countINFact, p,  todo);

	//最后执行操作
	if(res >0)
	{

		int res=runShell( countINFact, todo);


	}


	  CString  zuobiao1,shi,zuobiao2;
	  zuobiao1.Format(_T("time=%d"),count);
	//  zuobiao2.Format(_T("ParameterNum=%d"),op->ParameterNum);
	//  shi=(op->shelltype)+zuobiao1+zuobiao2+(op->Parameter);
		//AfxMessageBox(zuobiao1)/*;*/
	delete[] p;
		delete[] todo;
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


	Sleep(3000);
	CPoint start, end;
	start.x=406;
	start.y=751;
	end.x=593;
	end.y=752;
//struct colourRGB  lin=	CalculateAverageValueRBG( start, end,3);

	int width = GetSystemMetrics ( SM_CXSCREEN ); 
	int height= GetSystemMetrics ( SM_CYSCREEN ); 



	 CString file(_T("D:\\data\\1280800\\FindMatrixMsg.txt"));
	 CPoint startPoint;
	 struct colourRGB AverageValueRBG;
	 CPoint LeftPoint, RightPoint;
	 getMsgForFindMatrix( file,&startPoint,&AverageValueRBG);
	 int res=FindMatrix(startPoint,AverageValueRBG,& LeftPoint,& RightPoint);


}


//这个按钮用来运行一些小脚本，在文件littleshell.txt中指定的脚本
void CshellDlg::OnBnClickedButton4()
{
	Sleep(3000);
	//CString  littleshellfile(_T("D:\\data\\littleshell.txt"));
	CString  littleshellfile(_T("D:\\data\\testTaskShell.txt"));
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
