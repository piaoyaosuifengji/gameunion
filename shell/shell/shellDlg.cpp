
// shellDlg.cpp : ʵ���ļ�
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
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

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

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CshellDlg �Ի���




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



void CshellDlg::OnBnClickedButton1()
{
	Sleep(3500);

	CString fileName("shell.txt");
	//int x=198;
	//int y=842;
	//sendALeftMuoseClick(x,y,1500);//����˵�
	//char c='0';
	//int i=0;
	//for(;i<=9;i++)
	//{
	//	ToInPutChar(c+i);
	//}


	//��ȡshell�ı�

	int count=lineCount( fileName);
	struct operat *p=new struct operat[count];
	int countINFact=ReadTxtToGetShellByName2(fileName,count,p);


	//��������
	//���ǵó���ִ�еĲ������Լ���Ӧ�Ĳ���
	struct dodo *todo=new struct dodo[countINFact];

	int res=haveToDo( countINFact, p,  todo);

	//���ִ�в���
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


//�����ť��������һЩС�ű������ļ�littleshell.txt��ָ���Ľű�
void CshellDlg::OnBnClickedButton4()
{
	Sleep(3000);
	//CString  littleshellfile(_T("D:\\data\\littleshell.txt"));
	CString  littleshellfile(_T("D:\\data\\testTaskShell.txt"));
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
