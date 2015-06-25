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
	//标志当前究竟是哪个角色在打。0是未知。1是玲珑，2是DPS
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
	//读取shell文本

	int count = lineCount(fileName);
	struct operat *p = new struct operat[count];
	int countINFact = ReadTxtToGetShellByName2(fileName, count, p);
	//分析命令
	//就是得出该执行的操作，以及相应的参数
	struct dodo *todo = new struct dodo[countINFact];
	res = haveToDo(countINFact, p, todo);
	//最后检查操作
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
			ToInPutKeyboardKey(9, 100);//切怪

		qieguai++;
		//ruguo如果是峨眉那么美循环5次可以加一下血
		//if(cycle == 3  && autoAttackType == 1 )
		//	ToInPutChar('q',500);
		//选怪
		c = 'e';
		delyTime = 500;
		//ToInPutChar(c, delyTime);
		//2：技能释放-
		res = runShell(countINFact, todo);

		/*
		//3：判断是否打死了怪
		*/
		//自动加血蓝内气
		//res=ifNeedToNeiLi(CString Environment,CPoint  * ParameterPoints);
		//int need = ifNeedToNeiLi(Environment, ParameterPoints);
		if (cycle == 39)
		{
			ToInPutKeyboardKey(57, 100);//默认9回内力
			ToInPutKeyboardKey(70, 100);//默认f捡东西

		}
		if (cycle == 39)
		{
			ToInPutKeyboardKey(48, 100);//默认0回血

		}
		//need = ifNeedToHuiXue(Environment, ParameterPoints);
		//if (need == 1)
		//{
		//	ToInPutKeyboardKey(VK_F4, 200);//默认f2回内红

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
	//标志当前究竟是哪个角色在打。0是未知。1是玲珑，2是其他
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
	//读取shell文本

	int count = lineCount(fileName);
	struct operat *p = new struct operat[count];
	int countINFact = ReadTxtToGetShellByName2(fileName, count, p);
	//分析命令
	//就是得出该执行的操作，以及相应的参数
	struct dodo *todo = new struct dodo[countINFact];
	res = haveToDo(countINFact, p, todo);
	//最后检查操作
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
			ToInPutKeyboardKey(9, 100);//切怪
		
		qieguai++;
		//ruguo如果是峨眉那么美循环5次可以加一下血
		//if(cycle == 3  && autoAttackType == 1 )
		//	ToInPutChar('q',500);
		//选怪
		c = 'e';
		delyTime = 500;
		//ToInPutChar(c, delyTime);
		//2：技能释放-
		res = runShell(countINFact, todo);

		/*
		//3：判断是否打死了怪
		*/
		//自动加血蓝内气
		//res=ifNeedToNeiLi(CString Environment,CPoint  * ParameterPoints);
		//int need = ifNeedToNeiLi(Environment, ParameterPoints);
		if (cycle == 19)
		{
			ToInPutKeyboardKey(57, 100);//默认9回内力
			ToInPutKeyboardKey(70, 100);//默认f捡东西

		}
		if (cycle == 19 || cycle == 9)
		{
			ToInPutKeyboardKey(48, 100);//默认0回血

		}
		//need = ifNeedToHuiXue(Environment, ParameterPoints);
		//if (need == 1)
		//{
		//	ToInPutKeyboardKey(VK_F4, 200);//默认f2回内红

		//}

		
	}
	delete[] p;
	delete[] todo;
	return res;
}