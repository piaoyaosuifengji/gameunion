// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� HOOKDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// HOOKDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���



// ������Ϊ�Ǳ������ġ�

#ifndef _KEYDLL_H
#define _KEYDLL_H


#ifdef HOOKDLL_EXPORTS
#define HOOKDLL_API __declspec(dllexport)
#else
#define HOOKDLL_API __declspec(dllimport)
#endif

// �����Ǵ� HookDll.dll ������
class HOOKDLL_API CHookDll {
public:
	CHookDll(void);
public:
	~CHookDll();
	HHOOK Start(); //��װ���̹���
	HHOOK RecordMouseAndKeyboard(); //��װ������깳�ӣ�����¼
	HHOOK StartMouse(); //��װ��깳��
	BOOL Stop();   //ж�ع���
	void tryDiao();
	void setglhInstance(HINSTANCE glhInstance);
	void  getCurrentMousePos();//��ȡ�����ʱ��ǰ����
	//void  writeToTxt(CString word);
	void MoveRole();
private:
	bool ifMoving;  //��¼�Ƿ������ƶ�
};

extern HOOKDLL_API int nHookDll;

HOOKDLL_API int fnHookDll(void);
#endif