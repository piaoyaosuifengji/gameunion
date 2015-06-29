#pragma once
class tianyuShell
{
public:
	tianyuShell();
	~tianyuShell();
};



//#define TianYuDeBug   1
//#define TianYuDeBug2   2
DWORD WINAPI autoAttack_LingLongZuDui(PVOID pvParam);
DWORD WINAPI autoAttack_LingLong(PVOID pvParam);
//判断是否需要回血
int ifNeedToRecoveryBlood(CString Environment, CPoint  * ParameterPoints, struct WindowPosMsg msg);
//判断是否需要回蓝
int ifNeedToRecoveryBlue(CString Environment, CPoint  * ParameterPoints, struct WindowPosMsg msg);
//判断是否需要切怪
int ifNeedToFindNewMonster(CString Environment, CPoint  * ParameterPoints, struct WindowPosMsg msg);