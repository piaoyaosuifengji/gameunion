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
//�ж��Ƿ���Ҫ��Ѫ
int ifNeedToRecoveryBlood(CString Environment, CPoint  * ParameterPoints, struct WindowPosMsg msg);
//�ж��Ƿ���Ҫ����
int ifNeedToRecoveryBlue(CString Environment, CPoint  * ParameterPoints, struct WindowPosMsg msg);
//�ж��Ƿ���Ҫ�й�
int ifNeedToFindNewMonster(CString Environment, CPoint  * ParameterPoints, struct WindowPosMsg msg);
//�ж������Ƿ���Ҫ�����Ѽ�Ѫ������0���ã�����1.2.3.4��ֱ����Ӧλ�ö��Ѽ�Ѫ
int ifNeedToGainBlood(CString Environment, CPoint  * ParameterPoints, struct WindowPosMsg msg);

DWORD WINAPI dandiancaijiForTianYu(PVOID pvParam);