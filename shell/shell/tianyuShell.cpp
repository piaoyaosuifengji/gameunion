#include "stdafx.h"
#include "tianyuShell.h"
#include "fileoperating.h"
#include "operating.h"

tianyuShell::tianyuShell()
{
}


tianyuShell::~tianyuShell()
{
}

DWORD WINAPI autoAttack_LingLongZuDui(PVOID pvParam)
{
	int res = 0;
	CString fileName;
	//��־��ǰ�������ĸ���ɫ�ڴ�0��δ֪��1�����磬2��DPS
	struct AttackType *t = (struct AttackType *)pvParam;
	int autoAttackType = (int)pvParam;
	//int cccc=(int)autoAttackType;
	if (autoAttackType == 1)
	{
		fileName.Format(_T("C:\\data\\tianyu\\autoAttackLingLongZuDui.txt"));
	}
	else if (autoAttackType == 2)
	{
		fileName.Format(_T("C:\\data\\tianyu\\autoAttackforDPS.txt"));
	}
	else{
		CString  zuobiao1(_T(" wrong autoAttackType"));
		AfxMessageBox(zuobiao1);
		return res;
	}
	//��ȡshell�ı�

	int count = lineCount(fileName);
	struct operat *p = new struct operat[count];
	int countINFact = ReadTxtToGetShellByName2(fileName, count, p);
	//��������
	//���ǵó���ִ�еĲ������Լ���Ӧ�Ĳ���
	struct dodo *todo = new struct dodo[countINFact];
	res = haveToDo(countINFact, p, todo);
	//��������
	if (res <= 0)
	{
		CString  zuobiao1(_T("some wrong"));
		AfxMessageBox(zuobiao1);
		//int res=runShell( countINFact, todo);

	}
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	CString fileName2("C:\\data\\1440900\\zuobiao.txt");
	CPoint  *ParameterPoints;
	CString Environment = for1440and900;

	if (width == 1440 && height == 900)
	{
		fileName2.Format(_T("C:\\data\\1440900\\zuobiao.txt"));
		ParameterPoints = ReadTxtToGetPoints(fileName2);
		Environment = for1440and900;
	}
	else if (width == 1280 && height == 800)
	{
		fileName2.Format(_T("C:\\data\\1280800\\zuobiao.txt"));
		ParameterPoints = ReadTxtToGetPoints(fileName2);
		Environment = for1280and800;
	}
	//else
	//	return res;

	Sleep(4000);
	char c;
	int delyTime;
	int continueAutoAttack = 1;
	int cycle = 0;

	int  qieguai = 1;
	while (continueAutoAttack)
	{
		cycle++;
		if (cycle >= 40)
			cycle = 0;
		if (qieguai >= 10)
			qieguai = 1;
		if (qieguai == 1)
			ToInPutKeyboardKey(9, 100);//�й�

		qieguai++;
		//ruguo����Ƕ�ü��ô��ѭ��5�ο��Լ�һ��Ѫ
		//if(cycle == 3  && autoAttackType == 1 )
		//	ToInPutChar('q',500);
		//ѡ��
		c = 'e';
		delyTime = 500;
		//ToInPutChar(c, delyTime);
		//2�������ͷ�-
		res = runShell(countINFact, todo);

		/*
		//3���ж��Ƿ�����˹�
		*/
		//�Զ���Ѫ������
		//res=ifNeedToNeiLi(CString Environment,CPoint  * ParameterPoints);
		//int need = ifNeedToNeiLi(Environment, ParameterPoints);
		if (cycle == 39)
		{
			ToInPutKeyboardKey(57, 100);//Ĭ��9������
			ToInPutKeyboardKey(70, 100);//Ĭ��f����

		}
		if (cycle == 39)
		{
			ToInPutKeyboardKey(48, 100);//Ĭ��0��Ѫ

		}
		//need = ifNeedToHuiXue(Environment, ParameterPoints);
		//if (need == 1)
		//{
		//	ToInPutKeyboardKey(VK_F4, 200);//Ĭ��f2���ں�

		//}


	}
	delete[] p;
	delete[] todo;
	return res;
}
DWORD WINAPI autoAttack_LingLong(PVOID pvParam)
{
	int res = 0;
	CString fileName;
	//��־��ǰ�������ĸ���ɫ�ڴ�0��δ֪��1�����磬2������
	struct AttackType *t = (struct AttackType *)pvParam;
	int autoAttackType = (int)pvParam;
	//int cccc=(int)autoAttackType;
	if (autoAttackType == 1)
	{
		fileName.Format(_T("C:\\data\\tianyu\\autoAttack.txt"));
	}
	else if (autoAttackType == 2)
	{
		//fileName.Format(_T("D:\\data\\shell\\autoAttackfortangmeng.txt"));
	}
	else{
		CString  zuobiao1(_T(" wrong autoAttackType"));
		AfxMessageBox(zuobiao1);
		return res;
	}
	//��ȡshell�ı�

	int count = lineCount(fileName);
	struct operat *p = new struct operat[count];
	int countINFact = ReadTxtToGetShellByName2(fileName, count, p);
	//��������
	//���ǵó���ִ�еĲ������Լ���Ӧ�Ĳ���
	struct dodo *todo = new struct dodo[countINFact];
	res = haveToDo(countINFact, p, todo);
	//��������
	if (res <= 0)
	{
		CString  zuobiao1(_T("some wrong"));
		AfxMessageBox(zuobiao1);
		//int res=runShell( countINFact, todo);

	}
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);

	CString fileName2("C:\\data\\1440900\\zuobiao.txt");
	CPoint  *ParameterPoints;
	CString Environment = for1440and900;

	if (width == 1440 && height == 900)
	{
		fileName2.Format(_T("C:\\data\\1440900\\zuobiao.txt"));
		ParameterPoints = ReadTxtToGetPoints(fileName2);
		Environment = for1440and900;
	}
	else if (width == 1280 && height == 800)
	{
		fileName2.Format(_T("C:\\data\\1280800\\zuobiao.txt"));
		ParameterPoints = ReadTxtToGetPoints(fileName2);
		Environment = for1280and800;
	}
	//else
	//	return res;

	Sleep(4000);
	char c;
	int delyTime;
	int continueAutoAttack = 1;
	int cycle = 0;

	int  qieguai = 1;
	while (continueAutoAttack)
	{
		cycle++;
		if (cycle >= 20)
			cycle = 0;
		if (qieguai >= 10)
			qieguai = 1;
		if (qieguai == 1)
			ToInPutKeyboardKey(9, 100);//�й�
		
		qieguai++;
		//ruguo����Ƕ�ü��ô��ѭ��5�ο��Լ�һ��Ѫ
		//if(cycle == 3  && autoAttackType == 1 )
		//	ToInPutChar('q',500);
		//ѡ��
		c = 'e';
		delyTime = 500;
		//ToInPutChar(c, delyTime);
		//2�������ͷ�-
		res = runShell(countINFact, todo);

		/*
		//3���ж��Ƿ�����˹�
		*/
		//�Զ���Ѫ������
		//res=ifNeedToNeiLi(CString Environment,CPoint  * ParameterPoints);
		//int need = ifNeedToNeiLi(Environment, ParameterPoints);
		if (cycle == 19)
		{
			ToInPutKeyboardKey(57, 100);//Ĭ��9������
			ToInPutKeyboardKey(70, 100);//Ĭ��f����

		}
		if (cycle == 19 || cycle == 9)
		{
			ToInPutKeyboardKey(48, 100);//Ĭ��0��Ѫ

		}
		//need = ifNeedToHuiXue(Environment, ParameterPoints);
		//if (need == 1)
		//{
		//	ToInPutKeyboardKey(VK_F4, 200);//Ĭ��f2���ں�

		//}

		
	}
	delete[] p;
	delete[] todo;
	return res;
}