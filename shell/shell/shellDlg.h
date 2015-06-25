
// shellDlg.h : 头文件
//

#pragma once


#include "resource.h"		// main symbols
#include "HookDll.h"
class _declspec(dllimport) CKeyHook;
#pragma comment(lib,"HookDll.lib")


// CshellDlg 对话框
class CshellDlg : public CDialogEx
{
// 构造
public:
	CshellDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SHELL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
private:
	bool  bSetup;
	CHookDll *m_hook;
	HINSTANCE glhInstance;

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void getMousePosAndOutput();
	afx_msg void TaskHandleClickedButton();
	afx_msg void OnBnClickedHotKeyRecord();
	afx_msg void OnBnClickedLingLong();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg LRESULT OnHotKey(WPARAM wParam, LPARAM lParam);
};

/*


三、系统级热键：

1.在.h中添加afx_msg LRESULT OnHotKey(WPARAM wParam,LPARAM lParam);

2.在.cpp中添加函数： LRESULT CshellDlg::OnHotKey(WPARAM wParam,LPARAM lParam) { // TODO: Add your code here

return 0; } 在 BEGIN_MESSAGE_MAP 和 END_MESSAGE_MAP 间添加消息映射： ON_MESSAGE(WM_HOTKEY,OnHotKey)

3.在创建/进入程序的时候注册热键： RegisterHotKey(m_hWnd, 1001, MOD_ALT, 0x41);//用Alt+A作为快捷键，第二个参数必须系统唯一

4.在销毁/退出程序的时候注销热键： UnregisterHotKey(m_hWnd,1001);



*/