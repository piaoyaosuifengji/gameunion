#include "StdAfx.h"
#include "xiaoaoshell.h"
#include "fileoperating.h"
#include "operating.h"
xiaoaoshell::xiaoaoshell(void)
{
}


xiaoaoshell::~xiaoaoshell(void)
{
}

DWORD WINAPI autoAttack(PVOID pvParam)
{
	//读取shell文本
	CString fileName("autoAttack.txt");
	int count=lineCount( fileName);
	struct operat *p=new struct operat[count];
	int countINFact=ReadTxtToGetShellByName2(fileName,count,p);
	//分析命令
	//就是得出该执行的操作，以及相应的参数
	struct dodo *todo=new struct dodo[countINFact];
	int res=haveToDo( countINFact, p,  todo);
	//最后检查操作
	if(res <=0)
	{
		CString  zuobiao1(_T("some wrong"));
		AfxMessageBox(zuobiao1);
		//int res=runShell( countINFact, todo);

	}


	Sleep(4000);
	char c;
	int delyTime;
	int continueAutoAttack=1;
	while(continueAutoAttack)
	{

		//选怪
		c='e';
		delyTime=500;
		ToInPutChar( c, delyTime);
		//2：技能释放-
		res=runShell( countINFact, todo);







	}
	delete[] p;
	delete[] todo;
	return 0;
}
