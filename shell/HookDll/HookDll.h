// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 HOOKDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// HOOKDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的



// 符号视为是被导出的。

#ifndef _KEYDLL_H
#define _KEYDLL_H


#ifdef HOOKDLL_EXPORTS
#define HOOKDLL_API __declspec(dllexport)
#else
#define HOOKDLL_API __declspec(dllimport)
#endif

// 此类是从 HookDll.dll 导出的
class HOOKDLL_API CHookDll {
public:
	CHookDll(void);
public:
	~CHookDll();
	HHOOK Start(); //安装键盘钩子
	HHOOK RecordMouseAndKeyboard(); //安装键盘鼠标钩子，并记录
	HHOOK StartMouse(); //安装鼠标钩子
	BOOL Stop();   //卸载钩子
	void tryDiao();
	void setglhInstance(HINSTANCE glhInstance);
	void  getCurrentMousePos();//获取鼠标点击时当前坐标
	//void  writeToTxt(CString word);
	void MoveRole();
private:
	bool ifMoving;  //记录是否正在移动
};

extern HOOKDLL_API int nHookDll;

HOOKDLL_API int fnHookDll(void);
#endif