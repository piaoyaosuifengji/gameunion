
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
};
