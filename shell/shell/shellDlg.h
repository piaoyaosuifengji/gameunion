
// shellDlg.h : ͷ�ļ�
//

#pragma once


#include "resource.h"		// main symbols
#include "HookDll.h"
class _declspec(dllimport) CKeyHook;
#pragma comment(lib,"HookDll.lib")


// CshellDlg �Ի���
class CshellDlg : public CDialogEx
{
// ����
public:
	CshellDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SHELL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
private:
	bool  bSetup;
	CHookDll *m_hook;
	HINSTANCE glhInstance;

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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


����ϵͳ���ȼ���

1.��.h�����afx_msg LRESULT OnHotKey(WPARAM wParam,LPARAM lParam);

2.��.cpp����Ӻ����� LRESULT CshellDlg::OnHotKey(WPARAM wParam,LPARAM lParam) { // TODO: Add your code here

return 0; } �� BEGIN_MESSAGE_MAP �� END_MESSAGE_MAP �������Ϣӳ�䣺 ON_MESSAGE(WM_HOTKEY,OnHotKey)

3.�ڴ���/��������ʱ��ע���ȼ��� RegisterHotKey(m_hWnd, 1001, MOD_ALT, 0x41);//��Alt+A��Ϊ��ݼ����ڶ�����������ϵͳΨһ

4.������/�˳������ʱ��ע���ȼ��� UnregisterHotKey(m_hWnd,1001);



*/